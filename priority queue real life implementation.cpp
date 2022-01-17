#include<iostream>
using namespace std;

struct queue{
	int sugarlevel;
	struct queue *next=NULL;
	
};
struct queue *front=NULL;
struct queue *rear=NULL;

queue * searchBefore(int key){
	
	queue* p = front;
	queue* p2 = front;
	if (key==p->sugarlevel){
		return p;
		
	}else{
		
	
	while( p->next!=NULL && p->next->sugarlevel!= key){
		p=p->next;
		p2 = p;
	}

	return p2;
}
}

void enqueue(int x){
	
		struct queue *newnode=new queue;
		newnode->sugarlevel=x;
		newnode->next=NULL;
		//if queue is empty
		if(front==NULL && rear==NULL){
			front=rear=newnode;
		}
		//if queue is not empty
		
		else{
			if(newnode->sugarlevel>front->sugarlevel){
			newnode->next=front;
			front=newnode;
		}
			else if(newnode->sugarlevel<rear->sugarlevel){
				rear->next=newnode;
				rear=newnode;
			}
			else{
				struct queue *temp=front;
			
			while(temp->next->sugarlevel>newnode->sugarlevel){
				temp=temp->next;
			}
			
			newnode->next=temp->next;			
			temp->next=newnode;
			
		
	}

			
    }


}


void dequeue(){
	
	
	struct queue * temp=front;
	if(front==NULL && rear==NULL){
		cout<<"queue is empty";
		
	}
	else{
		front=front->next;
		delete temp;
	}
}
void displayqueue(){
	
	if(front==NULL && rear==NULL){
		cout<<"no more patients "<<endl;
	}
	else{
		struct queue *temp=front;
		while(temp!=NULL){
			cout<<temp->sugarlevel<<"  mg/dl" <<"  ";
			temp=temp->next;
		}
			

		
	}
}

int main(){
	int key;
	
		int opt;
do{

	cout<<"\n Enter 1 to enqueue data in quueue \n Enter 2 to display the queue  \n Enter 3 to remove the patient from queue who has injected with insulin"<<endl; 
    cin>>opt;
switch(opt)
{
	case 1:
		cout<<"ENTER THE PATIENT SUGAR LEVEL: "<<endl;
		cin>>key;
		enqueue(key);
			break;
	case 2:
	
			cout<<"INJECT INSULIN TO THE PATIENT WITH HIGHER SUGAR LEVEL"<<endl;
			displayqueue();
		break;
		
	
				
	case 3:
		
		dequeue();
		break;
	default:
		break;

}
}while(opt!=0);
return 0;

}





