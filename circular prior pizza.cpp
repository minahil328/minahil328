#include<iostream>
using namespace std;

struct pizza{
	string order;
	int age;
	struct pizza *next=NULL;
};
	struct pizza *front=NULL;
	struct pizza *rear=NULL;

void place_order(string o,int a){
	
	struct pizza *neworder=new pizza;
	neworder->order=o;
	neworder->age=a;
	neworder->next=NULL;
	//if circular queue is empty
	if(front==NULL && rear==NULL){
		front=rear=neworder;
		neworder->next=front;
	}
	//if there is some order placed in the queue
	else{
	
	if(neworder->age < rear->age){
		rear->next=neworder;
		neworder->next=front;
		rear=neworder;
		
		
		}
	else if(neworder->age == rear->age){
		rear->next=neworder;
		neworder->next=front;
		rear=neworder;
		
		
		}
	
	else if(neworder->age>front->age){
		
			rear->next=neworder;
			neworder->next=front;
			front=neworder;
			
	}
	
	else if(neworder->age==front->age){
		
			
			neworder->next=front->next;
			front->next=neworder;
			
	}
	
	else{
	struct 	pizza *temp=front;
		while(temp->next->age>=neworder->age){
			temp=temp->next;
		}
		neworder->next=temp->next;
		temp->next=neworder;
		
		
	}
		
	
}

			
			
}


			
   
void remove_served_order(){
	struct pizza *temp=new pizza;
	temp=front;
	if(front==NULL && rear==NULL){
		cout<<"all the orders are served and completed";
	
	}
	else if(front==rear){
				cout<<"the order of "<<front->order<<"  has been served"<<endl;

		front=rear=NULL;
		delete temp;
	}
	else{
				cout<<"the order of "<<front->order<<"  has been served"<<endl;

		front=front->next;
		rear->next=front;
		delete temp;
	}
	
	
	
	
	
}

void view_placed_order(){
	struct pizza *temp=new pizza;
	temp=front;
	if(front==NULL && rear==NULL){
		cout<<"your cart is empty"<<endl;
	}
	else{
		while(temp->next!=front){
			cout<<temp->order<<endl;
			temp=temp->next;
		}
		cout<<temp->order<<endl;

	}
}

int main(){
	string key;
	int key1;
	
		int opt;
do{

	cout<<"\n Enter 1 to place order, \nEnter 2 to view your placed order \n enter 0 to exit from order placing"<<endl; 
    cin>>opt;
switch(opt)
{
	case 1:
		cout<<"enter your order: ";
		cin>>key;
		cout<<"enter your age: ";
		cin>>key1;
		
		place_order(key,key1);
			break;
	case 2:	
	cout<<"your order is: "<<endl;
	view_placed_order();
	break;
	case 3:	
	 remove_served_order();
	 break;
	default:
		break;
	
}
}while(opt!=0);
struct pizza *temp=front;
while(temp->next!=front){
	 		cout<<"remaining orders: "<<endl;

		view_placed_order();

				 remove_served_order();

			temp=temp->next;
		}
		 		cout<<"remaining orders: "<<endl;

	view_placed_order();

	 remove_served_order();

      	
return 0;

}


