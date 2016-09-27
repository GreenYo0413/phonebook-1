#include <stdlib.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    static int restNode=0;
    static entry *pBlockHead=0;
    if(restNode == 0){
	pBlockHead = (entry *) calloc(MAX_NODE_SIZE,sizeof(entry));
	restNode=MAX_NODE_SIZE;
    }
    e->pNext = (entry *) (&(pBlockHead[MAX_NODE_SIZE-restNode]));
    restNode--;
    
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    
    return e;
}
