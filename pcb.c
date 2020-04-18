/**
 *
 * @author Irmak Pakis
 * @dateCreated  18th February 2020
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pcb.h"

typedef struct ReadyQueueNode
{
    PCB *pcb;
    struct ReadyQueueNode *next;
} ReadyQueueNode;

ReadyQueueNode *head = NULL;
ReadyQueueNode *tail = NULL;

PCB *makePCB(FILE *file, char *filename)
{
    PCB *pcb = (PCB *)malloc(sizeof(PCB));
    pcb->PC = 0;
    pcb->PC_page = 0;
    pcb->PC_offset = 0;
    initializePageTable(pcb->pageTable);
    pcb->fileName = filename;
    pcb->pages_max = countTotalPages(file);
    pcb->end = countTotalLines(file);
    return pcb;
}

void clearReadyQueue()
{
    head = NULL;
    tail = NULL;
}

bool readyQueueIsEmpty()
{
    return head == NULL;
}

void push(PCB *pcb)
{
    if (readyQueueIsEmpty())
    {
        head = (ReadyQueueNode *)malloc(sizeof(ReadyQueueNode));
        head->pcb = pcb;
        head->next = NULL;
        tail = head;
        return;
    }
    tail->next = (ReadyQueueNode *)malloc(sizeof(ReadyQueueNode));
    tail->next->pcb = pcb;
    tail->next->next = NULL;
    tail = tail->next;
}

PCB *pop()
{
    if (head == NULL)
    {
        printf("ERROR: the PCB queue is empty\n");
    }
    if (head == tail)
    {
        PCB *tmp = head->pcb;
        head = NULL;
        tail = NULL;
        return tmp;
    }
    PCB *tmp = head->pcb;
    head = head->next;
    return tmp;
}

void updateVictimsPageTable(int frameNumber)
{
    ReadyQueueNode *current = head;
    while (current != NULL)
    {
        PCB *tmp = current->pcb;
        for (int i = 0; i < 10; i++)
        {
            if (tmp->pageTable[i] == frameNumber)
            {
                current->pcb->pageTable[i] = NULL;
            }
        }
        current = current->next;
    }
}

void initializePageTable(int pageTable[])
{
    for (int i = 0; i < 10; i++)
    {
        pageTable[i] = PAGE_NOT_INITIALIZED;
    }
}

int updatePCB(int quanta, PCB *pcb)
{
    if (pcb->PC_page == pcb->pages_max || pcb->end == pcb->PC + 1)
    {
        return END_OF_FILE;
    }
    pcb->PC = pcb->PC + quanta;
    pcb->PC_offset = (pcb->PC) % 4;
    pcb->PC_page = (pcb->PC) / 4;
    return 0;
}

int countTotalLines(FILE *f)
{
    rewind(f);
    int count = 1;
    int ch = 0;
    while (!feof(f))
    {
        ch = fgetc(f);
        if (ch == '\n')
        {
            count++;
        }
    }

    return count;
}