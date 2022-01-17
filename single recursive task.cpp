#include<iostream>
using namespace std;

void insert_start();
void display();
void PrintRI(struct stu * p);
void PrintRR(struct stu * p);
void CopyPrintRR(struct stu * p);
void reverseLinklist(struct stu* current);

int x,y;


struct stu{
	int id;
	struct stu *nextlink=NULL;
};
struct stu *faddress=NULL;
struct stu *laddress;
 

void insert_end(){
struct 	stu *temp;
	temp=new stu;
	cout<<"enter id";
	cin>>temp->id;

	if(faddress==NULL){
		faddress=laddress=temp;
		
	}
	else{
		laddress->nextlink=temp;
		laddress=temp;
	}
}

void PrintRI(struct stu * p){
	p=faddress;
	stu* k=laddress;
	while(k!=faddress){
		p=faddress;
	while(p->nextlink!=k){
		p=p->nextlink;
	}
	cout<<k->id<<" ";

	k=p;}
	cout<<p->id<<" ";
	
	
	
}

void PrintRR(struct stu * p){

	
	
	if(p!=NULL){
		PrintRR(p->nextlink);
		cout<<p->id<<" ";
	}
	
}
//swapping only values
void CopyPrintRR(struct stu * p){
	stu*  m=p;
	while(m!=NULL){
		stu* n=m;
		while(n!=NULL){
			int l=m->id;
			
			m->id=n->id;
			n->id=l;
			n=n->nextlink;
		}
		m=m->nextlink;
	}
}
//reverse linked list without changing address 
//and values(moving first node to last and 2 to 2 last and so on...)
void reverseLinklist(struct stu* current){
	
	struct stu*previous,*next;
	current=faddress;
	previous=NULL;
	stu*c=current;
	if(current==NULL){
			cout<<"empty linklist"<<endl;
		}
	while(current!=NULL){
		
		next=current->nextlink;
		current->nextlink=previous;
		previous=current;
		current=next; 
	}
	
	faddress=previous;
	
}


 	
	void display(){
		struct stu *p;
		p=faddress;
		if (p==NULL){
			cout<<"nothing to display";
		}
		while(p!=NULL){
			cout<<&(p->id)<<" "<<p->id<<" ";
			p=p->nextlink;
		}
	}
	int main(){
		
		int opt;
do{

	cout<<"\n Enter 1 to insert at end in the linked list, \n Enter 2 to display the linked list,\n Enter 3 to  the reverse linked list iteratively,\n Enter 4 to  the reverse linked list recursively,\n Enter 5 to  perform copy reverse ,\n Enter 6 to  reverse linklist without changing addresses\n Enter 0 to exit"; 
    cin>>opt;
switch(opt)
{
	case 1:
		insert_end();
		display();
		break;
	case 2:
	display();
		break;
	case 3:
			cout<<"After reversing linklist by iteration"<<endl;

		
	 PrintRI(  faddress);

		break;
	case 4:
		 cout<<"After reversing linklist by recursion"<<endl;

	 PrintRR( faddress);
	 
		break;
	case 5:
		
	 CopyPrintRR( faddress);
	 display();
		break;
	case 6:
		
	 reverseLinklist( faddress);
	 display();
		break;


	default:
		break;
		
}
}while(opt!=0);
return 0;
}
	