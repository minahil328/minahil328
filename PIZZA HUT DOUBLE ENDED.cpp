#include<iostream>
using namespace std;

int const size=100;
struct pizza{
string queue [size];
}st;

int front=-1;
int rear=-1;

void enquefront(string x){
	 if(((rear+1)%size)==front){
	cout<<"maximum number of orders have reached!!! No more orders";
}

else if( front==-1 && rear==-1){
	front=rear=0;
	st.queue[front]=x;
	
}

else if(front==0){
	front=size-1;
	st.queue[front]=x;
}


else{
	front--;
	st.queue[front]=x;
}
}



void enquerear(string x){
	 if(((rear+1)%size)==front){
	cout<<"maximum number of orders have reached!!! No more orders";
}

else if(front==-1 && rear==-1){
	front=rear=0;
	st.queue[front]=x;
	
}

else if(rear==size-1){
	rear=0;
	st.queue[rear]=x;
}


else{
	rear++;
	st.queue[rear]=x;
}
}


void dequefront(){
	if (front==-1 && rear==-1){
		cout<<"all orders are served";
	}
	else if(front==rear){
				cout<<"the order of "<<st.queue[front]<<"  has been served"<<endl;

		front=rear=-1;
	}
	else if(front==size-1){
				cout<<"the order of "<<st.queue[front]<<"  has been served"<<endl;

		front=0;
	}
	else{
				cout<<"the order of "<<st.queue[front]<<"  has been served"<<endl;

		front++;
	}
}


void dequerear(){
	if (front==-1 && rear==-1){
		cout<<"all orders are served";
	}
	else if(front==rear){
				cout<<"the order of "<<st.queue[front]<<"  has been served"<<endl;

		front=rear=-1;
	}
	else if(rear==0){
				cout<<"the order of "<<st.queue[front]<<"  has been served"<<endl;

		rear=size-1;
	}
	else{
				cout<<"the order of "<<st.queue[front]<<"  has been served"<<endl;

		rear--;
	}
}


void displayorder(){
	
if (front==-1 && rear==-1){
cout<<"all orders are served";

	
}

else{
	int i=front;
	while(i!=rear){
		
		
		cout<<st.queue[i]<<endl;
		
		i=(i+1)% size;
	}
 
      cout<<st.queue[rear]<<endl;
      	
}
	
}










int main(){
	string s;

	
		int opt;
do{

	cout<<"\n Enter 1 to place order and stand at the front of the waiting line \n Enter 2 place the order and stand at the end of the waiting line, \n enter 0 to exit from order placing  "<<endl; 
    cin>>opt;
switch(opt)
{
	case 1:
		cout<<"enter your  order";
		cin>>s;
		 enquefront(s);
		 break;
	case 2:
			cout<<"enter your  order";
		cin>>s;
	 enquerear(s);
	 break;
	
	
	default:
		break;
	}

}while(opt!=0);
int i=front;
	while(i!=rear){
		cout<<"remaining orders: "<<endl;
		displayorder();
		dequefront();
		//dequerear();
		i=(i+1)% size;
	}
 		cout<<"remaining orders: "<<endl;

      displayorder();
	  dequefront();
      	


return 0;

}






