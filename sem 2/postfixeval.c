#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct stcak{
    char* arr;
    int top;
    int capacity;
}stack;
void init(stack* st, int size){
    st->arr=(char*)malloc(size*sizeof(char));
    st->top=-1;
    st->capacity=size;
}
int isfull(stack* st){
    if(st->top==st->capacity-1)
    return 0;
    else
    return 1;
}
int isempty(stack* st){
    return (st->top==-1);
}
char push(stack* st, char item){
    int x;
    x=isfull(st);
    if(x==1){
        st->arr[++st->top]=item;
      
    }
    else {
             printf("stack is full!!");
    }
}
char pop(stack* st){
    if(isempty(st)){
        printf("stack is empty!!");
    }
    else {
        char y;
        y=st->arr[st->top--];
        return y;
    }
}
int isoperator(int x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 1;
    }
    else 
    return 0;
}
int calcu(char item, char e, char f){
    int c; char o,d; int a=e-'0'; int b=f-'0'; 
    if(item=='*'){
       c=a*b;
        d=c+'0';
      return d;
    }
   else if(item=='/'){
    
        c=a/b;
          d=c+'0';
 
        return d;
    }
    else if(item=='+'){       
        c=a+b;
         d=c+'0';
        return d;
    }
    else if(item=='-'){         
        c=a-b;
        d=c+'0';
        return d;
    }
    else 
    return 0;
}
char* postfix_evaluation(char* infix, stack* st){
    int j,size; char x,y; char z; char *ptr;
    j=-1;
    size=strlen(infix);
   for(int i=0; i<size; i++){
    if(infix[i]==' ' || infix[i]=='\t'){
        continue;
    }
   else if(isalnum(infix[i]))
    {
       push(st, infix[i]);
    }
   else if(isoperator(infix[i])){     
         x=pop(st);
         y=pop(st);
       z= calcu(infix[i], x, y);
      push(st, z);
   } 
   }
    return st;
}
int main(){
    stack str; stack* pt;
    int x;
    printf("Enter the size of the expression: ");
    scanf("%d", &x);
    char ar[x];
    printf("Enter the expression: ");
    scanf("%s", ar);
    init(&str, x);
    pt = postfix_evaluation(ar, &str);
    printf("The required postfix expression: %c", pt->arr[pt->top]);
    free(str.arr);
    return 0;
}
