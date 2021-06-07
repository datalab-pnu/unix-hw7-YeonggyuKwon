#ifndef _PRINT_C_
#define _PRINT_C_
#include "phone.h"
#include<stdio.h>
extern Contact* head;
void showAll(Contact* root)
{
    Contact* cur=head->next;
    while(cur!=NULL)
    {
        printf("Name=%s\t Phone=%s\n", cur->Name, cur->PhoneNumber);
        cur=cur->next;
    }
    printf("\n");
}
void print()
{
    printf("Print all contants in the PhoneBook\n");
	showAll(head);

}
#endif // _PRINT_C_
