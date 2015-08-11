#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

int main(int argc, char const *argv[])
{
    FILE *fp;
    char line[MAX_LAST_NAME_SIZE];

    /* check file opening*/     
    fp = fopen("./dictionary/all-names.txt", "r");
    if (fp == NULL){
        printf("cannot open the file\n");
        return 0;
    }

    /* build the phonebook */
    int i = 0;
    PhoneBook *pHead, *entry;
    pHead = (PhoneBook *) malloc(sizeof(PhoneBook));
    entry = pHead;
    entry->pNext = NULL;
    while (fgets(line, sizeof(line), fp)){
        /* first, cut non-alphanumeric characters */    
        while (((line[i]>='a'&&line[i]<='z') || (line[i]>='A'&&line[i]<='Z'))){
            i++;
        }
        line[i]='\0';
        i = 0;
        insert(pHead, line);
    }

    /* print the phonebook 
    entry = pHead;
    while(entry->pNext != NULL){
        printf("%s", entry->lastName);
        entry = entry->pNext;
    }*/

    /* find that whether the input lastName exists or not */
    while(1){
        char input[MAX_LAST_NAME_SIZE]; 
        printf("search the last name (lowercase): ");
        scanf("%s", input);
        entry = pHead;
        findName(input, entry);
    }
    return 0;
}