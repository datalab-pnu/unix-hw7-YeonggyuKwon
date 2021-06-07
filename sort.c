#ifndef _SORT_C_
#define _SORT_C_
#include "phone.h"
#include <string.h>
#include <stdio.h>
extern int size;
extern Contact* head;
extern void print();
typedef int (*cmp)(const void*, int, int);
typedef int (*swap)(void*, int, int);

void sortPhoneBook(void *A, int size, cmp cfn, swap sfn);
int contactCmpr(const void*, int, int);
int contactSwap(void*, int, int);

void sort()
{
	printf("Before sorting\n");
	print();
	sortPhoneBook(head, size, contactCmpr, contactSwap);
	printf("After sorting\n");
	print();
}

void sortPhoneBook(void *A, int size, cmp cfn, swap sfn)
{
    int i, j;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(cfn(A, j,j+1)>0)
                sfn(A,j,j+1);
        }
    }
}

int contactCmpr(const void* arr, int i, int j)
{
    int node_count_i=0;
    int node_count_j=0;
    Contact* node_i=((Contact*)arr)->next;
    Contact* node_j=((Contact*)arr)->next;
    while(node_count_i!=i)
    {
        node_count_i++;
        node_i=node_i->next;
    }
    while(node_count_j!=j)
    {
        node_count_j++;
        node_j=node_j->next;
    }
    return strcmp(node_i->Name,node_j->Name);
}

int contactSwap(void* arr, int i, int j)
{
    int node_count_i=0;
    int node_count_j=0;
    Contact* node_i=((Contact*)arr)->next;
    Contact* node_j=((Contact*)arr)->next;
    while(node_count_i!=i)
    {
        node_count_i++;
        node_i=node_i->next;
    }
    while(node_count_j!=j)
    {
        node_count_j++;
        node_j=node_j->next;
    }
    Contact tmp;
    strcpy(tmp.Name, node_j->Name);
    strcpy(tmp.PhoneNumber,node_j->PhoneNumber);
    strcpy(node_j->Name,node_i->Name);
    strcpy(node_j->PhoneNumber,node_i->PhoneNumber);
    strcpy(node_i->Name,tmp.Name);
    strcpy(node_i->PhoneNumber,tmp.PhoneNumber);
    return 1;
}
#endif
