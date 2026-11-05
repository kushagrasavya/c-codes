#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
void insertbegin(node** prear, int data){
      node* new_node=(node*)malloc(sizeof(node));
      new_node->data=data;
      new_node->next=NULL;
      if(*prear==0){
        *prear=new_node;
        new_node->next=*prear;
      }
      else
      new_node->next=(*prear)->next;
      (*prear)->next=new_node;
}