#include<iostream>
using namespace std;

struct palindrome{
	int id;
	struct palindrome *next=NULL;
};
struct palindrome *first=NULL;
struct palindrome *last=NULL;
 struct palindrome *top=NULL;


void insert_end(){
struct 	palindrome *temp;
	temp=new palindrome;
	cout<<"enter id";
	cin>>temp->id;

	if(first==NULL){
		first=last=temp;
		
	}
	else{
		last->next=temp;
		last=temp;
	}
}
void pushStart(int x){
	struct palindrome *newnode=new palindrome;
	newnode->id=x;
	newnode->next=top;
	top=newnode;
}
void popStart(){
	struct palindrome *temp=NULL;
	temp=top;
	if(top==NULL){
		cout<<"STACK IS EMPTY"<<endl;
		cout<<"NO NODE TO DELETE"<<endl;
	}
	else{
	
	
		top=temp->next;
		delete(temp);
		
	}
}

int findtop(){
	int t;
	
	if(top==NULL){
		cout<<"STACK IS EMPTY"<<endl;
	}
	else{
		t=top->id;
	
	}
	return t;
}

bool Palindrome_stack_sll(){
	
	struct palindrome *temp=new palindrome;

	temp=first;
	
	while(temp!=NULL){
		pushStart(temp->id);
		temp=temp->next;
		
	}
	
	
	while(first!=NULL){
		int i=findtop();
		popStart();
		if(first->id==i){
			return true;
			
		}
		
		first=first->next;
		
		
	}
	return false;
}

void display(){
	struct palindrome *temp=NULL;
	temp=top;
	if(top==NULL){
		cout<<"STACK IS EMPTY"<<endl;
	}
	else{
	while(temp!=NULL){
		cout<<temp->id<<" ";
		temp=temp->next;
		
	}
	}
}
int main(){
	
	
		int opt;
do{

	cout<<"\n Enter 1 to push data in stack ,\n Enter 2 to check if it is a palindrome "<<endl; 
    cin>>opt;
switch(opt)
{
	
	case 1:
		//insert_end();
		int x;
		cout<<"enter id";
		cin>>x;
		pushStart(x);
		break;
	case 2:
	
   Palindrome_stack_sll();
	if(Palindrome_stack_sll()==true){
		cout<<"IT IS A PALINDROME";
	}
	else{
		cout<<"IT IS NOT A PALINDROME";
	}			
	break;
	

}
}while(opt!=0);
return 0;

}
	

