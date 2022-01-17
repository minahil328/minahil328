#include<iostream>
using namespace std;

struct palindrome{
	int id;
	struct palindrome *next=NULL;
	struct palindrome *prev=NULL;

};
struct palindrome *first=NULL;
struct palindrome *last=NULL;

 struct palindrome *top=NULL;
 struct palindrome *bottom=NULL;


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
		temp->prev=last;
		last=temp;
		last->next=NULL;
		
	}
}
void pushStart(int x){
	struct palindrome *newnode=new palindrome;
		struct palindrome *t= top;
	newnode->id=x;
	if(top==NULL){
		top=bottom=newnode;
	}
	else{
		bottom->next=newnode;
		newnode->prev=bottom;
		bottom=newnode;
	}


}
void popStart(){
	struct palindrome *temp=NULL;
	temp=top;
	
	
	
		top=temp->next;
		delete(temp);	
	
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


bool Palindrome_stack_dll(){
	
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
		int key;
do{

	cout<<"\n Enter 1 to push data in stack ,\n Enter 2 to check if it is a palindrome "<<endl; 
    cin>>opt;
    
switch(opt)
{
	
	case 1:
		insert_end();
		break;
	case 2:
	
   Palindrome_stack_dll();
	if(Palindrome_stack_dll()==true){
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
	

