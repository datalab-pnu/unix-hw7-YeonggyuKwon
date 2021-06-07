#ifndef _REGISTER_C_
#define _REGISTER_C_
#include "phone.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
extern Contact* head;
extern int size;
void addFront(Contact* root, char* name, char* phonenumber)
{
    Contact* node=(Contact*) malloc(sizeof(Contact));
    strcpy(node->Name,name);
    strcpy(node->PhoneNumber,phonenumber);
    node->next=root->next;
    root->next=node;
    printf("Registered...\n");
}

void registerPhoneData()
{
    char *password="qwerty1234";
    char input[20];
    char name[20];
    char phonenumber[13];
    int dismatch_count=0;
    printf("Ask to type password\n");
    while(dismatch_count<3)
    {
        printf("Password: ");
        scanf("%s",input);
        if(strcmp(password,input)==0)
        {
                printf("New User Name:");
                scanf("%s",name);
                printf("Phone Number:");
                scanf("%s",phonenumber);
                addFront(head, name, phonenumber);
                size++;
                break;
        }
        else    dismatch_count++;

        if(dismatch_count==1)   printf("Not Matched!!!\n");
        else if(dismatch_count==2)  printf("Not matched(twice)!!!\n");
        else if (dismatch_count==3) printf("You are not allowed to access PhoneBook.\n");
    }
}
#endif
