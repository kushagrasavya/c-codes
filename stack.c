//stack completed
#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int* arr;
    int top;
    int capacity;
}stack;
void init(stack* str, int size){
    str->arr=(int*)malloc(size*sizeof(int));
    str->top=-1;
    str->capacity=size;
}
int isfull(stack* str){
   if(str->top==str->capacity-1){
    return 1;
   }
   else 
   return 0;
}
int isempty(stack* str){
    if(str->top=-1){
        return 1;
    }
    else 
    return 0;
}
int peek(stack* str){
     if(str->top<0){
        printf("stack is empty!!\n\n");
    }
    printf("the top element is: %d\n", str->arr[str->top]);
}
void push(stack* str, int item){
        str->top++;
        str->arr[str->top]=item;
}
int pop(stack* str){
     if(str->top==-1){
        printf("\n\nstack is empty!!\n\n");
        return 0;
    }
    int x;
    x=str->arr[str->top];
    str->top--;
    printf("the popped element is: %d\n\n", x);
}
int display(stack* str){
    if(str->top<0){
        printf("stack is empty!!\n\n");
    }
    for(int i=str->top; i>=0; i--){
        printf("|  %d  |\n",str->arr[i] );

    }
    printf("_______\n");
}
int main(){
  stack st;
  int n; int k,m, status;
  printf("enter the size of the stack: ");
  scanf("%d", &n);
  init(&st, n);
  do
  {
    printf("PRESS\n");
   printf("1. Push\n");
   printf("2. Pop\n");
   printf("3. Display\n");
   printf("4. Peek\n");
   printf("5. exit\n");
   scanf("%d", &k);
   switch (k)
   {
   case 1:   status=isfull(&st);
             if(status==0){
                 printf("enter the element to push: ");
                  scanf("%d",&m);
                push(&st, m);
             }
              else
              printf("\nstack is full!\n\n");
             
        break;
    case 2: pop(&st);
             break;;
    case 3: display(&st);
             break;
    case 4: peek(&st);
             break;
    case 5:
         break;
   }
  } while (k!=5);
  
}