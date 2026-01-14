#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* pre;
}Node;

typedef struct List{
    Node* head;
    Node* tail;
    int elemcount;
}List;

void createList(List* list){
    list->elemcount=0;
    list->head=NULL;
    list->tail=NULL;
}

void addElement(List* list, int data){
    Node* node=(Node*)malloc(sizeof(Node));
    if(!node)return;

    node->data=data;
    node->pre=NULL;
    if(!list->head)list->tail=node;
    else{
        list->head->pre=node;
    }
    node->next=list->head;
    list->head=node;
    list->elemcount++;
}

void removeElement(List* list){
    Node* old=list->head;
    list->head=old->next;
    free(old);
    list->elemcount--;
}

void addToPosition(List* list, int data, int position){
    Node* cur=list->head;
    Node* prev=NULL;

    for(int i=0; i<position; i++){
        prev=cur;
        cur=cur->next;
    }

    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=cur;
    prev->next=node;
    node->pre=prev;
    cur->pre=node; 
    list->elemcount++;   
}

void addBack(List* list, int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    node->pre=NULL;

    if(list->tail==NULL)list->head=node;
    else{
        list->tail->next=node;
    }

    node->pre=list->tail;
    list->tail=node;
    list->elemcount++;
}

void removeFromPosition(List* list, int position){
    Node* cur=list->head;
    Node* prev=NULL;

    for(int i=0; i<position; i++){
        prev=cur;
        cur=cur->next;
    }

    Node* old=cur;
    prev->next=cur->next;
    cur->next->pre=prev;
    free(old);
    list->elemcount--;
}

void removeBack(List* list){
    Node* old=list->tail;
    list->tail=old->pre;
    if(list->tail)list->tail->next=NULL;
    else{
        list->head=NULL;
    }
    free(old);
    list->elemcount--;
}

int main(){
    List* mylist=(List*)malloc(sizeof(List));
    createList(mylist);

    addElement(mylist, 5);
    addElement(mylist, 4);
    addElement(mylist, 3);
    addElement(mylist, 2);
    addElement(mylist, 1);

    removeElement(mylist);

    addToPosition(mylist, 67, 3);

    removeFromPosition(mylist, 2);

    addBack(mylist, 38);



    Node* current=mylist->head;
    while (current !=NULL){
        printf(" %d -> ", current->data);
        current=current->next;
    }
    printf("finish!");
    free(mylist);
}
