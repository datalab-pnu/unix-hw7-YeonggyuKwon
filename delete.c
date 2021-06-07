#ifndef _DELETE_C_
#define _DELETE_C_
#include "phone.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern int size;
extern Contact* head;
void removeFront(Contact* root)
{
    Contact* front=root->next;
    root->next=front->next;
    free(front);
}

void deleteByName()
{
    int is_found=0;
    char name[20];
    Contact* cur=head->next;
    Contact* front=head;
    printf("Enter a name to seach:");
    scanf("%s", name);
    while(cur !=NULL)
    {
        if(strcmp(cur->Name,name)==0)
        {
            removeFront(front);
            is_found=1;
            size--;
            break;
        }
        cur=cur->next;
        front=front->next;
    }
    if(!(is_found))   printf("Oops! %s is not in the PhoneBook.\n",name);
    printf("\n");
}
#endif
