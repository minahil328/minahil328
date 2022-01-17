#include<iostream>
using namespace std;

struct node{
	int id;
	struct node* nextlink=NULL;
	
};
struct node* head=NULL;
struct node* tail=NULL;

void insert_start(int x){
struct 	node*curr;
	curr =new node;
	curr->id=x;
	
	if(head==NULL){
		head=tail=curr;
		
	}
	else{
		curr->nextlink=head;
		head=curr;
	}
}

void insert_end(int x){
struct 	node *temp;
	temp=new node;

	temp->id=x;
	
	if(head==NULL){
		head=tail=temp;
		
	}
	else{
		tail->nextlink=temp;
		tail=temp;
	}
}

void sortedinsert(){
struct 	node* newnode=new node;
node* temp=head;
int x;
cout<<"enter id: ";
cin>>x;
	//case 1: if list is empty i.e head=null

	newnode->id=x;
	if(head==NULL){
		
		head=tail=newnode;
		
	}
	//case2: key is less than the minimum
	
	else{
		node* temp=head;
		
		if(x<temp->id){
			insert_start(x);
			
		}
	
		else{
		
		//in between case
		while(temp->nextlink!=NULL){
			if(x>temp->nextlink->id){
				temp=temp->nextlink;
			}
			else{
			node* newnode=new node;
			newnode->id=x;
			newnode->nextlink=temp->nextlink;
			temp->nextlink=newnode;
			return;
		}
	}
}
	
	
	
	if(x>temp->id){
		
		
		insert_end(x);
	}
}

	
 
	
	
}

void display_list(){
		

	node* p=new node;
	p=head;
		
		
		if (p==NULL){
			cout<<"*****empty*****";
		}
		while(p!=NULL){
			cout<<"id:"<<p->id<<endl;
			
			p=p->nextlink;
		}
	}
	
////////////////////////////main function///////////////////////////	
	
	int main(){
		int opt;
do{

	cout<<"\n Enter 1 to insert data in list, \n Enter 2 to view the list,"<<endl; 
    cin>>opt;
switch(opt)
{
	case 1:
		
	sortedinsert();
	break;

			
	case 2:
		cout<<"THE SORTEDLY INSERTED ID'S ARE:"<<endl;
	display_list();
		break;

		
	default:
	break;
}
}while(opt!=0);
return 0;


}
	
