#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int* arr;
    int front, rear,size;
    int capacity;
}Q;
void init(Q* st, int cap){
    st->arr=(int*)malloc(cap*sizeof(cap));
    st->front=st->rear=-1;
    st->size=0;
    st->capacity=cap;
}
int isfull(Q* st){
    return (st->front==0 && st->rear==st->capacity-1 || st->rear==st->front-1);
}
int isempty(Q* st){
    return (st->front==-1);
}
int enqueue(Q* st, int item){
    if(!isfull(st)){
        if(st->rear==st->capacity-1){
            st->rear=0;
        }
    else if(st->front==-1 && st->rear==-1){
        st->front=0;
        st->rear=0;
    }
    else{
        st->rear=st->rear+1;
    }
    st->arr[st->rear]=item;
    st->size=st->size+1;
  }
  else
  printf("queue is full!!\n");
}
int dequeue(Q* st){
    int x,y; x=st->front; y=st->rear;
    int item;
    if(!isempty(st)){
            item=st->arr[st->front];
            st->size--;
     if(x==y){
        st->front=-1;
        st->rear=-1;
     }
      else if(st->front==st->capacity-1){
          st->front=0;
    }
    
     else{
        st->front=st->front+1;
     }
        return item;
 }
 else
 return 404;
}
int main()
{
    Q q;
    int x;
    printf("enter the size: \n");
    scanf("%d", &x);
    int n,a ;
    init(&q,x);
    do
    {
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Exit");
        printf("\n Enter your choice: ");;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("\n Enter any numner: ");
                scanf("%d",&a);
                enqueue(&q,a);
                printf("\nItems in Queue: %d",q.size);
                printf("\n\nAfter enqueue\n\n");
                printf("front is: %d\n", q.front);
                printf("rear is: %d\n", q.rear);
                break;
                
            case 2:
                printf(" \n Deq Operation: %d",dequeue(&q));
                printf("\n  Items in Queue: %d",q.size);
                 printf("\n\nafter dequeue\n\n");
                 printf("front is: %d\n", q.front);
                printf("rear is: %d\n", q.rear);
                break;
               
            case 3:printf("::BYE::");
        }
    }while(n!=3);
   
}