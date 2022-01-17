#include<iostream>
#include<string>
using namespace std;

int const size=100;
struct pizza{
string queue [size];
}st;

int front=-1;
int rear=-1;

void place_order(string a ){

		
    
if (front==-1 && rear==-1){
	front=rear=0;
	st.queue[rear]=a;
	
}
else if(((rear+1)%size)==front){
	cout<<"maximum number of orders have reached!!! No more orders";
}
else{
	rear=(rear+1)%size;
	st.queue[rear]=a;
}
}

void serve_order(){
	if(front==-1 && rear==-1){
		cout<<"all orders have been served"<<endl;
	}
	else if(front==rear){
		cout<<"the order of "<<st.queue[front]<<"  has been served"<<endl;
		front=rear=-1;
	}
	else{
		cout<<"the order of "<<st.queue[front]<<"  has been served"<<endl;
		front=(front+1)%size;
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

	cout<<"\n Enter 1 to place order \n Enter 2 to view  the order, \n enter 0 to exit from order placing  "<<endl; 
    cin>>opt;
switch(opt)
{
	case 1:
		cout<<"enter your  order";
		cin>>s;
 place_order( s );
 
 	break;
	
	default:
		break;
		
	
				


}

}while(opt!=0);
int i=front;
	while(i!=rear){
		cout<<"remaining orders: "<<endl;
displayorder();
 serve_order();		
		i=(i+1)% size;
	}
 		cout<<"remaining orders: "<<endl;

      displayorder();
 serve_order();
      	


return 0;

}





