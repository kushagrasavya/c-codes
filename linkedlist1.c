#include<stdio.h>
typedef struct node{
    int data;
    node* next;
}node;
void insertbegin(node** phead, int item){
    node* new_node;
    new_node=(node*)malloc(sizeof(node));
    new_node->data=item;
    new_node->next=NULL;
    if(*phead==NULL){
         *phead=new_node;
    }
    else{
        new_node->next=*phead;
        *phead=new_node;
    }
}
void append(node** phead, int item){
    node* new_node;
    new_node=(node*)malloc(sizeof(node));
    new_node->data=item;
    new_node->next=NULL;
    if(*phead==NULL){
        *phead=new_node;
    }
    else{
        node* ptr;
        ptr=*phead;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }
}
node* searchkey(node** phead, int key){
    node* ptr=*phead;
    while(ptr->next!=NULL && ptr->data!=key){
      ptr=  ptr->next;
    }
    if(ptr->data==key){
        return ptr;
    }
    else
    return NULL;
}
node* seachposition(node** phead, int posit){
    node* ptr=*phead;
    for(int i=0; i<posit;i++){
        if((posit-1)!=i){
            ptr=ptr->next;
        }
    }
    if(ptr!=NULL){
        return ptr;
        else
        return NULL;
    }
}
void insertafter(node* pre_node, int item){
    node* new_node;
    new_node=(node*)malloc(sizeof(node));
    new_node->data=item;
    new_node->next=NULL;
    new_node->next=pre_node->next;
    pre_node->next=new_node;
}
void insertpositon(node** phead, int pos, int item){
   int i;
   node* new_node;
   new_node=(node*)malloc(sizeof(node));
   new_node->data=item;
   node* ptr=*phead;
   node* pre_node=*phead;
   for(i=0;i<pos;i++){
    if(i==0 && pos==1){
        new_node->next=*phead;
        *phead=new_node;
    }
    else{ 
       if((pos-1)==i && ptr!=NULL){
        new_node->next=ptr->next;
        pre_node->node=new_node;
       }
     else{
          pre_node=ptr;
          ptr=ptr->next;

       }
    }
   }
}
void deletebegin(node** phead){
    node* ptr=*phead;
    if(!*phead==NULL){
       *phead=(ptr->next)->next;
       free(ptr);
    }
    else
    printf("linked list is empty!");
}
void deleteend(node** phead){
    node* ptr;
    node* pre_node;
    while(ptr->next!=NULL){
        pre_node=ptr;
        ptr=ptr->next;
    }
    pre_node->next=NULL;
    free(ptr);
}
void delete_after_key(node* pre_node){
    node* ptr=pre_node->next;
    pre_node->next=(pre_node->next)->next;
    free(ptr);
}
void delete_after_position(node** phead, int posi){
       node* pre_node=*phead;
       node* ptr=*phead;
       if(posi==1){
        *phead=*phead->next;
        free(ptr);
       }
       else{
        for(int i=0;i!=(posi-1) && ptr!=NULL){
            pre_node=ptr;
            ptr=ptr->next;
        }
        pre_node->next=(pre_node->next)->next;
        free(ptr);
       }
}
void delete_by_data(node** phead, int item){
    node* ptr=*phead;
    node* pre_node=*phead;
    while(ptr->data!=item){
        pre_node->next=ptr;
        ptr=ptr->next;
    }
    pre_node->next=pre_node->next->next;
    free(ptr);
}
void display(node** phead){
    node* ptr=*phead;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("\n\n");
}
void reverse(node** phead){
    node* pre=NULL;
    node* current=*phead;
    node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=pre;
        pre=current;
        current=next
    }
    *phead=pre;
}
int main(){

}