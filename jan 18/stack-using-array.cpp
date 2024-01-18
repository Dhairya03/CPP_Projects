#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    unsigned capacity;
    int* array;
};

struct stack* createStack(unsigned capacity){
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int*)malloc(stack->capacity*sizeof(int));
    return stack;
    
}

int isFull(struct stack* stack){
    return stack->top ==stack->capacity-1;
}

int isEmpty(struct stack* stack){
    return stack->top==-1;
}

void push(struct stack* stack, int value){
    if(isFull(stack)){
        printf("Stack Overflow");
        return;
    }
    stack->array[++stack->top]=value;
    printf("value is pushed");
}

int pop(struct stack* stack){
    if(isEmpty(stack)){
        printf("stack underflow");
        return 9999999;
    }
    int val=stack->array[stack->top--];
    return val;
}

int peek(struct stack*stack){
    if(isEmpty(stack)){
        printf("Stack underflow");
        return 9999999;
    }
    return stack->array[stack->top];
}
int main(){
    struct stack* stack = createStack(100); 
  
    push(stack, 10); 
    push(stack, 20); 
    push(stack, 30); 
  
    printf("%d popped from stack\n", pop(stack)); 
  
    return 0; 

}