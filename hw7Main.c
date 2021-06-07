#ifndef _HW7MAIN_C_
#define _HW7MAIN_C_
#include <stdio.h>
#include <stdlib.h>
#include "phone.h"

extern void registerPhoneData();
extern void print();
// print() invokes printArray()
extern void searchByName();
extern void deleteByName();
extern void sort();
// array of function pointers.
void (* pFuncs[5])()={registerPhoneData, print, searchByName, deleteByName,sort};

// function pointer declaration


// Sorting PhoneBook using bubble sort
// 3rd parameter cmp cfn: a pointer to function
// 4th parameter swap sfn: a pointer to function

static int count_service = 0;	// Total number of service requests
Contact* head;

void freeAll(Contact* root)
{
    Contact* cur= head->next;
    while(cur!=NULL)
    {
        Contact* next=cur->next;
        free(cur);
        cur=next;
    }
}
int main()
{
    head=(Contact*) malloc(sizeof(Contact));
    head->next=NULL;
	int service;// a variable for storing user's request

	do
	{
        printf("============ Telephone Book Management ============");
        printf("\n <<<1. Register\t 2. Print All \t 3. Search by ID \t 4. Delete \t 5. Sort \t 6. Exit >>>\n");
        printf(" Please enter your service number (1-6)> ");
		scanf("%d", &service);
		if ( service > 0 && service <= 5 )
		{
			pFuncs[service-1]();
		}
		else if( service ==0 || service > 6)
		{
			printf("You choose a wrong service number\n");
		}
	} while (service != 6);	// if Exit is not entered, the loop continues
	freeAll(head);
	return 0;
}
#endif // _HW7MAIN_C_



