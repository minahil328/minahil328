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
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
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

bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
bool isOperand(char c)  
{  
if( c >= 'A' && c <= 'Z') 
return true;  
if (c >= 'a' && c <= 'z')   
return true;  
if(c >= '0' && c <= '9')    
return true;
else{
	return false;  

}  
}  

char *infixTopostfix(char *infix){
	struct stack * sp = new stack;
    sp->size = 10; 
    sp->top = -1;
    sp->arr = new char[sp->size];
    char * postfix = new char[100];
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    for(int i=0;i<strlen(infix);i++){
    	if(isOperand(infix[i]))
		{
		postfix[j] = infix[i];
            j++;		
			}
		else if(infix[i] == '(')
		{
			push(sp,infix[i]);
		}
		else if(infix[i] == ')')
		{
			while((stackTop(sp)!='(') && (!isEmpty(sp)))
			{
				char temp=stackTop(sp);
				postfix[j]=temp;
				j++;
				pop(sp);
			}
			if(stackTop(sp)=='(')
			{
				pop(sp);
			}
			
		}
		
		else if(isOperator(infix[i]))
		{
			if(isEmpty(sp))
			{
				push(sp,infix[i]);
			}
			else
			{
				if(precedence(infix[i])>precedence(stackTop(sp)))
				{
					push(sp,infix[i]);
				}	
				else if((precedence(infix[i])==precedence(stackTop(sp)))&&(infix[i]=='^'))
				{
					push(sp,infix[i]);
				}
				else
				{
					while((!isEmpty(sp))&&( precedence(infix[i])<=precedence(stackTop(sp))))
					{
						postfix[j]=stackTop(sp);
						j++;
					    pop(sp);
					}
					push(sp,infix[i]);
				}
			}
    	
	}
    
    	
}

while(!isEmpty(sp))
	{
		postfix[j]=stackTop(sp);
		j++;
		pop(sp);
	}
	postfix[j] = '\0';
    return postfix;
	
}

int main(){
char *infix;
infix = new char[25];
cout<<"enter infix expression";
cin >> infix; 
 cout<<"postfix expression is "<<infixTopostfix(infix);
    return 0;
}














