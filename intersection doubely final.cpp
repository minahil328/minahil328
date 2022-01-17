# include<iostream>
using namespace std;
struct node{
	int id;
	struct node* nextlink=NULL;
	struct node* prevlink=NULL;

};
struct node* head=NULL;
struct node* tail=NULL;
struct node* head2=NULL;
struct node* tail2=NULL;
struct	node* newhead=NULL;
struct	node* newtail=NULL;


void insert_list1(){
	struct node* newnode=new node;
cout<<"\nenter id";
	cin>>newnode->id;
	if(head==NULL){
		
		

		head=tail=newnode;
	}
	else{
			
		
		
		
		tail->nextlink=newnode;
		newnode->prevlink=tail;
		tail=newnode;
		tail->nextlink=NULL;
			
		
	
	
	
}
}





void insert_intersectionlist(int newid){
	struct node* newnode=new node;

	newnode->id=newid;
	if(newhead==NULL){
		
		newhead=newtail=newnode;
	}
	else{
			
		
		
		
		newtail->nextlink=newnode;
		newnode->prevlink=newtail;
		newtail=newnode;
		newtail->nextlink=NULL;
			
	
}
}



void insert_list2(){
	struct node* newnode=new node;
	
    cout<<"enter id";
	cin>>newnode->id;
	if(head2==NULL){
		
		

		head2=tail2=newnode;
	}
	else{
			
		
		
		
		tail2->nextlink=newnode;
		newnode->prevlink=tail2;
		tail2=newnode;
		tail2->nextlink=NULL;
			
		
	
	
	
}
}



	void display_list1(){
		
		struct node *p=new node;
		p=head;
		if (p==NULL){
			cout<<"nothing to display";
		}
		while(p!=NULL){
			cout<<"id:"<<&p->id<<" "<<p->id<<endl;
			
		
			
			p=p->nextlink;
		}
	}
	
	
	void display_list2 (){
		struct node *p=new node;
		p=head2;
		if (p==NULL){
			cout<<"nothing to display";
		}
		while(p!=NULL){
			cout<<"id:"<<&p->id<<" "<<p->id<<endl;
		 
			
			p=p->nextlink;
		}
	}
void intersection(node *head, node *head2){
	
	 
		node* p=head;
	

		while(p!=NULL){
				node* k=head2;
			while(k!=NULL){
			
			if(p->id==k->id){

				insert_intersectionlist( p->id);
				
			}
			k=k->nextlink;
		}
		p=p->nextlink;
	}
}
			
	void display_intersectionlist(){
		struct node *p=new node;
		p=newhead;
		if (p==NULL){
			cout<<"*****NO COMMON NODES AMONG TWO LINKED LISTS*****";
		}
		while(p!=NULL){
			cout<<"id:"<<&p->id<<" "<<p->id<<endl;
			
			p=p->nextlink;
		}
	}
	
////////////////////////////main function///////////////////////////	
	
	int main(){
	
		int opt;
do{

	cout<<"\n Enter 1 to insert data in list1, \n Enter 2 to view the list1,\n Enter 3 to insert in the list2,\n Enter 4 to view list2, \n Enter 5 to take the intersection of two lists,\n Enter 6 to view the intersection of two lists"<<endl; 
    cin>>opt;
switch(opt)
{
	case 1:
		
		
		insert_list1();
	break;

			
	case 2:
	display_list1();
		break;
	case 3:
	insert_list2();

		break;
	
	case 4:
		
	display_list2( );
		break;
	case 5:
		
  intersection(head,head2);
  break;
	
	case 6:
		cout<<"\nlinked list1: "<<endl;
			display_list1( );
			cout<<"linked list2: "<<endl;
				display_list2( );
				cout<<"intersection of two linked lists is:"<<endl;
	
	display_intersectionlist();
	
		break;
		
	default:
		break;
}
}while(opt!=0);
return 0;


}
	
