#ifndef _SEARCH_C_
#define _SEARCH_C_
#include <stdio.h>
#include <string.h>
#include "phone.h"

extern Contact* head;
void searchByName()
{
    int is_found=0;
    char name[20];
    Contact* cur=head->next;
    printf("Enter a name to seach:");
    scanf("%s", name);
    while(cur !=NULL)
    {
        if(strcmp(cur->Name,name)==0)
        {
            printf("%s\t%s\n",cur->Name,cur->PhoneNumber);
            is_found=1;
            break;
        }
        cur=cur->next;
    }
    if(!(is_found))   printf("Oops! %s is not in the PhoneBook.\n",name);
    printf("\n");
}
#endif
