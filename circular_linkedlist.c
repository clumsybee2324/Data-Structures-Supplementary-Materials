#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Circle{
    int elementcount;
    Node* cursor;
}Circle;

void createCircularList(Circle* circularlist){
    circularlist->cursor=NULL;
    circularlist->elementcount=0;
}

void addBackElement(Circle* circularlist, int num){
    if(circularlist == NULL){
        createCircularList(circularlist);
    }
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=num;
    if(circularlist->cursor==NULL){
        node->next=node;
        circularlist->cursor=node;
    }else{
        node->next=circularlist->cursor->next;  //think like adding at a position, position&previous node
        circularlist->cursor->next=node;       //10->20 becomes 10->15->20, 10 was our cursor
        circularlist->cursor=node;             //our new cursor is 15
    }
    circularlist->elementcount++;
}

void removeFrontElement(Circle* circularlist){
    if(circularlist==NULL) return;
    Node* old=circularlist->cursor->next;
    if(circularlist->elementcount==1){    //if there is only cursor, cursor->next becomes cursor
        circularlist->cursor=NULL;
    }
    circularlist->cursor->next=old->next;
    free(old);
    circularlist->elementcount--;
}

int main(){
    Circle* circularlist;
    createCircularList(circularlist);
    for (int i = 5; i >0; i--){
        addBackElement(circularlist, i);
    }

    removeFrontElement(circularlist);

    Node* temp=circularlist->cursor;
    while(temp !=NULL){
        printf(" %d ", temp->data);
        temp=temp->next;
    }
    
    return 0;
}
