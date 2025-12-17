#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct List{
    int elementcount;
    Node* head;
}List;

void createList(List* list){
    list->head=NULL;
    list->elementcount=0;
}

void addNextElement(List* list, int num){
    if(list==NULL){
        createList(list);
    }
    Node* node=(Node*)malloc(sizeof(Node));
    node->data=num;                   //we have created a node to add
    node->next=list->head;            //our baby node becomes the node before the old head, the next node of our baby node is old head
    list->elementcount++;             //adding new node increase the element count
    list->head=node;                  //we make our baby node new head
}

void removeHeadElement(List* list){
    Node* old=list->head;             //firstly we have to detect an old to remove
    list->head=list->head->next;      //we have to decide a new head before deleting the old head (think like a clan)
    free(old);                        //delete it
    list->elementcount--;             //decrease the number of members
}

void addToPosition(List* list, int num, int position){
    if(list==NULL){
        createList(list);
    }
    if(position<0) return;
    if(list->elementcount <= position)return;

    Node* position_node=list->head;       //this is the process swiping until our goal node, new becomes old and newer becomes new
    Node* previous_node=NULL;             //i hope i haven't explained too complex but try to visualize this process

    for(int i=0; i<position; i++){
        previous_node=position_node;
        position_node=position_node->next;
    }

    Node* node=(Node*)malloc(sizeof(Node));   //we need to create a new node to add
    node->data=num;
    previous_node->next=node;                //we make our baby node the next of the previous
    node->next=position_node;                //and the previous of our position node so the next of our baby node is position node
    list->elementcount++;                    //and increase the element count
}

void removeFromPosition(List* list, int position){
    if(list->elementcount <= position)return;
    if(position<0) return;
    
    Node* position_node=list->head;        //same swiping process to reach our position node
    Node* previous_node=NULL;

    for(int i=0; i<position; i++){
        previous_node=position_node;
        position_node=position_node->next;
    }

    Node* old=position_node;                   //before we delete, we should mark our position node as old
    previous_node->next=position_node->next;   //and link the previous node and the old next node of our position node
    free(old);                                 //removing our position node
    list->elementcount--;                      //decreasing the number of elements
}

int main(){
    List list;
    createList(&list);
    for (int i = 5; i>0; i--){
        addNextElement(&list, i);
    }

    removeHeadElement(&list);

    addToPosition(&list, 33, 2);

    removeFromPosition(&list,4);

    Node* temp= list.head;      //to print the data, we need to use temp node,
    while (temp !=NULL){        //we couldn't print when we right only "list", we have to reach all elements on the list to print   
        printf(" %d ", temp->data);       //until we reach NULL, we swipe right(next node) of temp and make it our new temp
        temp=temp->next;
    }
    
    return 0;
}
