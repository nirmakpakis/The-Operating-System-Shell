/**
* Nihal Irmak Pakis
* 260733837
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char *key;
    char *value;
    struct node *next;
} node;

node *head = NULL;

// Find key
node *find(char *key)
{
    if (head == NULL)
        return NULL;
    node *current = head;
    while (strcmp(current->key, key) != 0)
    {
        if (current->next == NULL)
            return NULL;
        current = current->next;
    }
    return current;
}

//Get value
void get(char *key)
{
    if (head == NULL)
    {
        printf("Variable does not exist\n");
        return;
    }

    node *current = head;

    while (strcmp(current->key, key) != 0)
    {
        if (current->next == NULL)
        {
            printf("ERROR: Variable does not exist\n");
            return;
        }
        current = current->next;
    }
    printf("%s\n", strdup(current->value));
    return;
}

// Add node
void insert(char *key, char *value)
{
    if (find(key) == NULL)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->key = strdup(key);
        newNode->value = strdup(value);
        newNode->next = head;
        head = newNode;
    }
    else
    {
        node *aNode = find(key);
        aNode->value = strdup(value);
    }
}

// Print memory
void printMemory()
{
    node *ptr = head;
    printf("\n[ ");
    while (ptr != NULL)
    {
        printf("(%s,%s)", strdup(ptr->key), strdup(ptr->value));
        ptr = ptr->next;
    }
    printf(" ]\n");
}
