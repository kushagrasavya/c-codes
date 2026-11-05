#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;
}Q;

void init(Q *q, int cap)
{
    q->front=q->rear=-1;
    q->capacity=cap;
    q->size=0;
    q->arr=(int*)malloc(cap*sizeof(int));
}
int isempty(Q *q)
{
    return( q->front==-1);
}

int isfull(Q *q)
{
    return(q->front==0 && q->rear==q->capacity-1 || q->rear==q->front-1);
}

void Rear_enqueue(Q *q, int item)
{
    if(!isfull(q))
    {
        //q->rear=q->rear+1;
        if(q->rear==q->capacity-1)
            q->rear=0;
       else if(q->rear==-1 && q->front==-1)
          {
            q->front=0;
            q->rear = 0;
          }
          else
          {
              q->rear=q->rear+1;
          }

           q->arr[q->rear]=item;
            q->size=q->size+1;
    }
    else
        printf("\n Queue is full");
   
   
}
void Front_Enqueue(Q *q, int item) 
{ 
   if(!isfull(q)){ 
       if(q->rear==-1 && q->front==-1){ 
      q->front=q->rear=0;
                    } 
    else if(q->front==0) 
         { 
      q->front=q->capacity-1; 
         } 
    else 
       { 
    q->front=q->front-1; 
        } 
    q->arr[q->front]=item; 
      q->size=q->size+1; 
      } 
  else { 
return; 
}  

} 
int Rear_Dequeue(Q *q) { 
int item; 
   if(!isempty(q)){ 
     item=q->arr[q->rear]; 
     q->size=q->size-1; 
     if(q->rear== q->front){ 
      q->front=q->rear=-1; 
           } 
    else if(q->rear==0) { 
       q->rear=q->capacity-1; 
        } 
    else 
    { 
      q->rear=q->front-1; 
     }  
return item; 
     } 
   else{ 
return 404; 
}  
} 

int Front_dequeue(Q *q)
{
    int item;
    if(!isempty(q))
    {
        item=q->arr[q->front];
        q->size--;
        if(q->front==q->rear)   //for last element
        {
            q->front=q->rear=-1;
        }
        else if(q->front==q->capacity-1)                   //for normal deletion
        {
                q->front=0;
        }
        else
          q->front++;
        return item;
    }  
    else
        return 404;
}
int show_front(Q *q){
    int item;
    item=q->arr[q->front];
    printf("%d", item);
    
}
int show_rear(Q *q){
     int item;
    item=q->arr[q->rear];
    printf("%d", item);
}
int main()
{
    Q q;
    int n,a ;
    init(&q,4);
    do
    {
      
        printf("\n\n------------------------------------");
        printf("\n 1. Front Enqueue");
        printf("\n 2. Rear Enqueue");
        printf("\n 3. Front Dequeue");
        printf("\n 4. Rear Dequeue");
        printf("\n 5. Show Front");
        printf("\n 6. Show Rear");
        printf("\n 7. Exit");
        printf("\n\n------------------------------------");
        printf("\n Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("\n Enter any number: ");
                scanf("%d",&a);
                Front_Enqueue(&q,a);
                printf("\nItems in Queue: %d",q.size);
                break;
            case 2:
                printf("\n Enter any numner: ");
                scanf("%d",&a);
                Rear_enqueue(&q,a);
                printf("\nItems in Queue: %d",q.size);
                break;
            case 3: Front_dequeue(&q);
                printf("\nItems in Queue: %d",q.size);
                break;
            case 4: Rear_Dequeue(&q);
                printf("\nItems in Queue: %d",q.size);
                break;
            case 5: show_front(&q);
            break;
            case 6: show_rear(&q);
            break;
            case 7:printf("::BYE::");

        }
    }while(n!=7);
   
  
}