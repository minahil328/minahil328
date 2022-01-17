#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
bool isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}




bool AreParanthesesBalanced(char *exp)
{
	
	 struct stack * sp = new stack;
    sp->size = 10; 
    sp->top = -1;
    sp->arr = new char[sp->size];
    
	for(int i=0;i<strlen(exp);i++)
	{
	
		if( exp[i] == '['){
			if(stackTop(sp)=='[' || stackTop(sp)=='{' || stackTop(sp)=='(' ){
			break;			}
		    else{
		    	push(sp,exp[i]);

			}
			
		

		}
		else if(exp[i] == '{'){
			if( stackTop(sp)=='{' || stackTop(sp)=='(' ){
				break;
			}
		    else{
		    	push(sp,exp[i]);


			}
		}
		
		else if(exp[i] == '(' ){
			if(stackTop(sp)=='(' ){
			break;
			} else{
		    	push(sp,exp[i]);


			}
			
			
		
			
			
		}
		else if(exp[i] == ')' )
		{
			if(isEmpty(sp) )
			break;
			else if(stackTop(sp)=='('){
			
				pop(sp);}
		}
		
		else if(exp[i] == '}' )
		{
			if(isEmpty(sp) )
				break;
			else if(stackTop(sp)=='{'){
			
				pop(sp);
				}
		
		
	}
		else if(exp[i] == ']' )
		{
			if(isEmpty(sp) )
				break;
			else if(stackTop(sp)=='['){
			
				pop(sp);
				}
		}
	}
	return isEmpty(sp);
	
}

	
	

int main(){
char *expression;
expression = new char[100];
cout<<"enter  expression";
cin >> expression; 

if (AreParanthesesBalanced(expression)){
	cout<<" expression is balanced ";
	
}
else{
	cout<<"not balanced";
}
 
    return 0;
}














