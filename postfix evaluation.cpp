
#include <string.h>
#include <stdio.h>

#include<iostream>
using namespace std;
#define MAXSTACK 100
struct stack
{
    
   int stack[MAXSTACK];

}st;
int top = -1;


void push(int item)
{

    if (top >= MAXSTACK - 1) {
        printf("stack over flow");
        return;
    }
    else {
        top = top + 1;
        st.stack[top] = item;
    }
}

int pop()
{
    int item;
    if (top < 0) {
        printf("stack under flow");
    }
    else {
        item = st.stack[top];
        top = top - 1;
        return item;
    }
}



void EvalPostfix(char postfix[])
{
	int i;
    char ch;
    int val;
    int A, B;


    for ( i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            /* as an an operand comes,push the digit onto stack
ch - '0' is used for getting digit rather than ASCII code of digit */
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            /* we saw an operator
* pop top element A and next-to-top elemnet B
* from stack and compute B operator A
*/
            A = pop();
            B = pop();

            switch (ch) /* ch is an operator */
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            /* push the value obtained above onto the stack */
            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

int main()
{

    int i;

    /* declare character array to store postfix expression */
    char postfix[100];
    cout<<"enter postfix expression";

    cin>>postfix;

    EvalPostfix(postfix);

    return 0;
}