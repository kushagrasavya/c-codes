//test
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
   struct node* next;
   struct node* prev;
}node;
void insertbegin(node** phead, int item){
    node* new_node; node* ptr=*phead;
    new_node=(node*)malloc(sizeof(node));
    new_node->data=item;
    new_node->next=*phead;
    new_node->prev=NULL;
    if(*phead!=NULL)
    ptr->prev=new_node;
    *phead=new_node;
}
void insertend(node** phead, int item){
    node* new_node;
    new_node=(node*)malloc(sizeof(node));
    new_node->next=NULL;
    node* ptr=*phead;
    if(*phead==NULL){
        new_node->prev=NULL;
        *phead=new_node;
        return;
    }
    while(ptr!=NULL){
        ptr=ptr->next;
    }
    new_node->prev=ptr;
    return;
}
node* searchkey(node** phead, int key){
    node* ptr=*phead;
    node* prenode=*phead;
    if(*phead!=NULL){
    while(ptr!=NULL && ptr->data!=key){
        ptr=ptr->next;
    }
    if(ptr->data==key){
        return ptr;
    }
    else
    return NULL;
 }
 else
 printf("ll is empty!!\n\n");
}
node* searchposi(node** phead, int pos){
       node* ptr=*phead;
       int i=0;
       if(*phead!=NULL){
       
            if(pos==1){
                return ptr;
            }
            else{
                while(ptr!=NULL && i!=pos-1){
                    ptr=ptr->next;
                    i++;
                }
                if(i==pos-1 && ptr!=NULL){
                    return ptr;
                }
                else
                return NULL;
        }
       }
}
void insert_afterkey(node* pre_node, int item){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=item;
    new_node->next=pre_node->next;
    pre_node->next=new_node;
    new_node->prev=pre_node;
    if(new_node->next!=NULL){
        (new_node->next)->prev=new_node;
    }
}
void insert_after_posi(node** phead, int item, int pos){
    node* check=*phead;
    node* ptr=*phead;
    node* prenode = *phead;
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=item;
    int i=0;
    if(pos==1){
        new_node->next=*phead;
        if(*phead!=NULL)
        check->prev=new_node;
        *phead=new_node;
    }
    else{
        while(i!=pos-1 && ptr!=NULL){
            prenode=ptr;
            ptr=ptr->next;
        }
        if(i==pos-1 && ptr!=NULL){
        new_node->next=ptr;
        prenode->next=new_node;
        new_node->prev=prenode;
        ptr->prev=new_node;
        }
        
    }
}
void insert_before(node* prenode, int item){
        node* ptr=prenode->prev;
        node* prepre=prenode->prev;
        node* new_node=(node*)malloc(sizeof(node));
        new_node->data=item;
        new_node->next=prenode;
        new_node->prev=ptr;
        ptr->next=new_node;
        prenode->prev=new_node;
}
void deletebegin(node** phead){
    node* ptr=*phead;
    if(*phead!=NULL){
        *phead=ptr->next;
        ptr->prev=NULL;
        free(ptr);
    }
    else
    printf("ll is empty!!\n\n");
}
void deleteend(node** phead){
    node* ptr= *phead;
    node* prenode=*phead;
    //if(*phead!=NULL){}  else return empty//
    while(ptr!=NULL){
        prenode=ptr;
        ptr=ptr->next;
    }
    prenode->next=NULL;
    free(ptr);
}
void deletebefore(node* prenode){
    node* ptr=prenode->prev;
    node* prepre=(prenode->prev)->prev;
    prepre->next=prenode;
    prenode->prev=prepre;
    free(ptr);
}
void deleteafter(node* prenode){
    node* ptr=prenode->next;
    node* after=prenode->next->next;
    after->prev=prenode;
    prenode->next=after;
    free(ptr);
}
void display(node** phead){
    node* ptr=*phead;
    while(ptr!=NULL){
        printf("%d", ptr->data);
        ptr=ptr->next;
    }
}
void rev_display(node** phead){
    node* head;
    node* ptr=*phead;
    int i=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        i++;
    }
    while(i!=0){
        printf("%d", ptr->data);
        ptr=ptr->prev;
        i--;
    }
}
void reverse(node** phead){
    node* temp=NULL;
    node* curr =*phead;
    while(curr!=NULL){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if(temp!=NULL){
        *phead=temp->prev;
    }
}
int main(){
    node* head;
    head=NULL;
    int data1,data,choice,pos;
    do{
         printf("\nCHOICES-\n1. TO ENTER AT BEGINNING\n2. TO ENTER AT END\n3. TO INSERT AFTER\n4. TO INSERT BEFORE\n5. TO DELETE AT BEGINNING\n6. TO DELETE AT END\n7. TO DELETE AFTER\n8. TO DELETE BEFORE\n9. DISPLAY FORWARD\n10. DISPLAY BACKWARD\n11 REVERSE\n0. EXIT\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice){
        case 1: printf("enter the elemnt: ");
            scanf("%d\n\n", &data);
            insertbegin(&head, data);
            break;
        case 2: printf("enter the element: ");
                scanf("%d", &data);
                insertend(&head, data);
                 break;
        case 3: printf("enter the elemnt: ");
                scanf("%d\n", &data);
                printf("enter after which elementr: ");
                scanf("%d", &data1);
                insert_afterkey(searchkey(&head, data1), data);
                break;
        case 4:printf("enter the elemnt: ");
                scanf("%d\n", &data);
                printf("enter after which elementr: ");
                scanf("%d", &data1);
                insert_before(searchkey(&head,data1), data);
              break;
        case 5: deletebegin(&head);
                 break;
        case 6: deleteend(&head);
              break;
        case 7: printf("enter the element after which:");
                 scanf("%d", &data1);
                 deleteafter(searchkey(&head,data1));
                break;
        case 8:  printf("enter the element after which:");
                 scanf("%d", &data1);
                 deletebefore(searchkey(&head,data1));
                break;
        case 9: display(&head);
                break;
        case 10: rev_display(&head);
                 break;
        case 11: reverse(&head);
        break;

        }

    }while(choice!=0);
}