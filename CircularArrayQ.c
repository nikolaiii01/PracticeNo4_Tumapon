#include <stdio.h>
#include <string.h>
#include "CircularArrayQ.h"

CircularArrayQueue create_array_queue(){
    CircularArrayQueue caq;

    return caq;
}

void init_array_queue(CircularArrayQueue *list){
    int i;

    for(i=0;i<MAX;i++){
        caq.data[i]=0;
    }

    caq.front = 0;
    caq.rear = MAX-1;
}

bool enqueue(CircularArrayQueue *list, Type p){
    if(!is_full(*list)){
        list->rear = (list->rear + 1) % MAX;
        list->data[list->rear] = item;
    }
}

bool dequeue(CircularArrayQueue *list){
    if(!is_empty(*list))){
        list->front (list->front + 1) % MAX;
    }
}

bool is_empty(CircularArrayQueue list){
    return (list.rear+1)%MAX == list.front;
}

bool is_full(CircularArrayQueue list){
    return (list.rear+2)%MAX == list.front;
}

Type front(CircularArrayQueue list){
    return list->front;
}