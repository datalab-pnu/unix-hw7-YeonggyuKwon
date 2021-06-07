#ifndef PHONE_H_INCLUDED
#define PHONE_H_INCLUDED
#define MAX 50

typedef struct contact_st
{
    char Name[10];
    char PhoneNumber[13];
    struct contact_st* next;
} Contact;

Contact PhoneBook[MAX];


int size;

#endif // PHONE_H_INCLUDED
