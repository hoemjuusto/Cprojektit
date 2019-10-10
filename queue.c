#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "queue.h"


int enqueue(struct studentqueue *q, const char *name){

    while(q->next!=NULL){
        q=q->next;
    }


    struct studentqueue *new = malloc(sizeof(struct studentqueue));
    new->name=malloc(strlen(name)+1);

    strcpy(new->name,name);
    if(new->name==NULL){
        return 0;
    }

    new->next=NULL;
    q->next=new;

    return 1;
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size){

    if(q->next!=NULL){
        strncpy(buffer, q->next->name,size-1);
        q->next=q->next->next;
        
        free(q->next);
        return 1;
    } else{
        return 0;
    }


}



