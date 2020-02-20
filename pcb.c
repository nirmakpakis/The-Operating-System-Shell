/**
 *
 * @author Irmak Pakis
 * @dateCreated  18th February 2020
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pcb.h"

typedef struct ReadyQueueNode
{
    PCB *pcb;
    struct ReadyQueueNode *next;
} ReadyQueueNode;

ReadyQueueNode *head = NULL;
ReadyQueueNode *tail = NULL;

PCB *makePCB(int start, int end)
{
    PCB *pcb = (PCB *)malloc(sizeof(PCB));
    pcb->PC = start;
    pcb->start = start;
    pcb->end = end;
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
        exit(1);
    }
    if (head == tail)
    {
        PCB *tmp = head;
        head = NULL;
        tail = NULL;
        return tmp;
    }
    PCB *tmp = head;
    head = head->next;
    return tmp;
}
