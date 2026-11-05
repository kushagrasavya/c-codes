
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct stack{
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
    if(st->top==st->capacity-1){
        return 1;
    }
    else {
        return 0;
    }
}
int isempty(stack* st){
     return (st->top==-1);
}
void push(stack* st, char item){
    if(isfull(st)==1){
         printf("Stack is full!\n");
    }
    else{
        st->arr[++st->top]=item;
    }
}
char pop(stack* st){
    if(isempty(st)){
        printf("Stack is empty!");
    }
    else{
     return st->arr[st->top--];
    }
}
void peek(stack* st){
    printf("peeked element: %c\n", st->arr[st->top]);
}
int display(stack* st){
    for(int i=0; i<st->top; i++){
        printf("%c\n", st->arr[i]);
    }
}
int isoperator(char c){
    if(c=='+' || c=='-' || c== '/' || c=='^' || c== '*'){
        return 1;
    }
    else 
    return 0;
}
int precidence(char x){
    if(x=='^')
    return 4;
   else if(x=='%' || x=='*')
    return 3;
    else if (x=='-' || x=='+'){
        return 2;
    }
    else 
    return 0;
}
char* infix_to_postfix(char* infix, stack* st){
    int length; int i;char tc; int j=-1;
    length=strlen(infix);
    char* ptr=(char*)malloc((length+1)*sizeof(char));
    for(i=0; i<length;i++){
        if(infix[i]==' ' || infix[i]=='\t'){
            continue;
        }
        else if(infix[i]=='('){
            push(st, infix[i]);
        }
        else if(infix[i]==')'){
            while(st->top>-1 && infix[i]!='('){
                tc= pop(st);
                j++;
                ptr[j]= tc;
            }
          if(st->top=-1 && infix[i]!='('){
            printf("invalid!!");
          }
        }
        else if(isalnum(infix[i])){
            j++;
          ptr[j]=infix[i];   
        }
        else if(isoperator(infix[i])){
            while(precidence(infix[i])<precidence(st->arr[st->top])){
                if(precidence(infix[i])== precidence(st->top)){
                     tc=pop(st);
                j++;
                ptr[j]=tc;
                break;
                }
                tc=pop(st);
                j++;
                ptr[j]=tc;
            }
            push(st, infix[i]);
        }
    }
    while(st->top!=-1){
        int rc;
       rc= pop(st);
       ptr[++j]=rc;
    }
    ptr[j+1]='\0';
    return ptr;
}
int main() {
    int a;
    stack st;
    printf("Enter the size of the expression: ");
    scanf("%d", &a);
    char arr[a];
    printf("Write the expression: ");
    scanf("%s", arr);

    init(&st, a);
    char* pf = infix_to_postfix(arr, &st);
    printf("Postfix expression: %s\n", pf);

    free(pf); 

    return 0;
}



