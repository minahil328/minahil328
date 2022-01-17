# include<iostream>
using namespace std;
void register_new_car();
void display_cars();
void display_rides();
void display_type2_car();
void add_newride(string  );
void specific_car_earning();
void all_car_earning();

string key;

struct car{
	string drivername;
	string carname;
	int regno;
	int cartype;
	float km;
	struct car* cnext=NULL;
	struct car* cprev=NULL;
	struct rider* rfirst=NULL;
};
car *search_method(string key);
struct car* faddress=NULL;
//struct rider* rfirst=NULL;

struct rider{
	int no_rides;
	float km;
	float charges;
	string ridername;
	struct rider* rnext;
	
};

//register new car

void register_new_car(){
	struct car* node=new car;
	cout<<"enter driver name"<<endl;
	cin>>node->drivername;
	cout<<"enter car name"<<endl;
	cin>>node->carname;
	cout<<"enter registration number"<<endl;
	cin>>node->regno;
	cout<<"enter car type"<<endl;
	cin>>node->cartype;
	cout<<"enter kilometers"<<endl;
	cin>>node->km;
	if(faddress==NULL){
		node->cnext=NULL;
		node->cprev=NULL;

		faddress=node;
	}
	else{
		struct car* temp=faddress;
		while(temp->cnext!=NULL){
			temp=temp->cnext;
			
		}
		temp->cnext=node;
		node->cprev=temp;
		node->cnext=NULL;
	}
	
}
//display all registered cars 
	void display_cars(){
		struct car *p;
		p=faddress;
		if (p==NULL){
			cout<<"nothing to display";
		}
		while(p!=NULL){
			cout<<"driver name:"<<" "<<p->drivername<<endl;
			cout<<"car name:"<<" "<<p->carname<<endl;
			cout<<"registration number:"<<" "<<p->regno<<endl;
			cout<<"car type:"<<" "<<p->cartype<<endl;
			cout<<"kilometers:"<<" "<<p->km<<endl;
			
			p=p->cnext;
		}
	}
	
	//display all rides 
	void display_rides(){
		string driverrname;
		cout<<"enter driver name of which you want to display data";
		cin>>driverrname;
		
		struct car* searchname=search_method( driverrname);
	
		if (searchname->drivername!=driverrname){
			cout<<"nothing to display";
		}
		else{
			
		
		while(searchname->rfirst!=NULL){
		
			cout<<"rider name:"<<" "<<searchname->rfirst->ridername<<endl;
			cout<<"number of rides:"<<" "<<searchname->rfirst->no_rides<<endl;
			cout<<"charges:"<<" "<<searchname->rfirst->charges<<endl;
			cout<<"kilometers:"<<" "<<searchname->rfirst->km<<endl;
					
					searchname->rfirst=searchname->rfirst->rnext;

			
		}
	}
	}
	
	
	//display type-2 cars
	void display_type2_car(){
		struct car* p=faddress;
		if(faddress==NULL){
			cout<<"NO CAR DATA AVAILABLE";
		}
		else{
		
		while(p!=NULL){
				

		if(p->cartype==2){
		
		
			cout<<"CARS WITH TYPE--2"<<endl;
			cout<<"carname "<<p->carname<<endl;
			cout<<"registration number "<<p->regno<<endl;

			
		}
			p=p->cnext;

	}
		
	}
	}
	//add new ride
	void add_newride(string drivername){
		struct car* p=search_method( drivername);
					struct rider* newride=new rider;

		if (p->drivername==drivername){
			cout<<"enter the rider name";
			cin>>newride->ridername;
			cout<<"enter the number of rides";
			cin>>newride->no_rides;
			cout<<"enter the charges ";
			cin>>newride->charges;
			cout<<"enter the kilometers";
			cin>>newride->km;
			
			}
			
			if(p->rfirst==NULL){
				p->rfirst=newride;
				newride->rnext=NULL;
			}
			else{
			
				newride->rnext=p->rfirst;
				p->rfirst=newride;
				newride->rnext=NULL;
		}
			
		}
		//total earning of a specific car
		void specific_car_earning(){
			string driverrname;
		cout<<"enter driver name of which you want to display data";
		cin>>driverrname;
			car *p=search_method(driverrname);
			
			rider* k=p->rfirst;
			float sum;
			if (p->drivername!=driverrname){
			cout<<"nothing to display";
		}
		else{
			while(k!=NULL){
				sum+=k->charges;
				k=k->rnext;
				
			}
			cout<<"Total earning of  "<<p->carname<<"car is "<<sum;
		}
		}
		
		
		//earning of all cars
		void all_car_earning(){
		
			car *p=faddress;
			
			
			float sum;
			if (p->cnext==NULL){
			cout<<"nothing to display";
		}
		else{
			while(p!=NULL ){
			rider* k=p->rfirst;
			while(k!=NULL){
				sum+=k->charges;
				k=k->rnext;
				
			}
		  p=p->cnext;
	}
			cout<<"Total earning of  all cars is "<<sum;
		}
		}
		
		
		
		
		
		
		
		
		
		
	car *search_method(string drivername){
	
	car *pre;
	car *curr;
	pre=curr=faddress;
while(curr!=NULL && pre->drivername!=drivername){
	pre=curr;
	curr=curr->cnext;
}
return pre;
}
int main(){
	
		int opt;
do{

	cout<<"\n Enter 1 to register new car, \n Enter 2 to display the car data,\n Enter 3 to display the type-2 cars,\nEnter 4 to add new rides,\nEnter 5 to display rider data,\nEnter 6 to display specific car earning,\n Enter 7 to display the all car earning,"; 
    cin>>opt;
switch(opt)
{
	case 1:
		register_new_car();
			break;
	case 2:
	display_cars();
		break;
	case 3:
	display_type2_car();
		break;
	
	case 4:
		cout<<"enter the drivername with which u want to book ride";
		cin>>key;
	add_newride( key);
		break;
	case 5:
		
	display_rides();
		break;
	case 6:
		
	specific_car_earning();
		break;
	
	case 7:
		
	all_car_earning();
		break;
	default:
		break;
}
}while(opt!=0);
return 0;


}
	


