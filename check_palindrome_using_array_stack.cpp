#include<iostream>
using namespace std;

int const size=100;
struct palindrome{
	char array[size];
char stack [size];
}st;

int top=-1;
int front=0;

//basic operations top be performed on stack
//->push     (insert data in the stack)
//->pop      (delete from the top)
//->top      (returns the index of the top element of stack)
//->isEmpty  (check if the stack is empty)
//->isFull   (check if the stack is full)


bool isStackEmpty(){
	if(top==-1){
	return true;
	}
	else{
		return false;
	}
	
}
bool isStackFull(){
	if(top==size-1){
		return true;
	}
	else{
		return false;
	}
}

void push(char x){
	
	if(isStackFull()==true){
		cout<<"stack is full";
	}
	else{
		top++;
		st.stack[top]=x;
	}
}

void pop(){
	
	if(isStackEmpty()==true){
		cout<<"\nstack is empty";
	}
	else
	
		top--;
	
}

void check_palindrome(){
	

    cout << "Enter a string: ";
    cin >> st.array;
	for(int i=0;st.array[i]!='\0';i++){
		char a;
		a=st.array[i];
		push(a);
		
	}
	
	for(int j=0;j<((strlen(st.array))/2);j++){
		if(st.stack[top]==st.stack[front]){
			pop();
			front++;
		}
		else{
			cout<<"this is not a palindrome";
			break;
		}
		
	}
	if(((strlen(st.array))/2)==front){
					cout<<"this is  a palindrome";

		front=0;
		top=-1;
	}
}



void displayStack(){
	if(isStackEmpty()==true){
		cout<<"\nStack is empty";
	}
	
	else{
		cout<<"\nelements of stack are: ";
		for(int i=top;i>=0;i--){
			cout<<st.stack[i];
		}
	}
}
int main(){
	check_palindrome();
	
}
