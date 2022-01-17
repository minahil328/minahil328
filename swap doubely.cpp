#include<iostream>
using namespace std;

struct stu{
	int id;
	struct stu *next=NULL;
	struct stu *prev=NULL;

};
	struct stu *first=NULL;
	struct stu *last=NULL;


void insert_end(){
struct stu* newnode=new stu;
cout<<"\nenter id";
	cin>>newnode->id;
	if(first==NULL){
		
		

		first=last=newnode;
	}
	else{
		last->next=newnode;
		newnode->prev=last;
		last=newnode;
		last->next=NULL;
	}
}

//method to search exactly the searched node

stu *searchExact(int x){
stu *p=first;
stu *p1=first;
	if(x==p->id){
		return p;
	}
	else{
	

while(p!=NULL && p->id!=x){
	
	p=p->next;
	p1=p;
}
return p1;
}
}

//method to search the node before the searched node

stu * searchBefore(int key){
	
	stu* p = first;
	stu* p2 = first;
	if (key==p->id){
		return p;
		
	}else{
		
	
	while( p->next!=NULL && p->next->id!= key){
		p=p->next;
		p2 = p;
	}

	return p2;
}
}

void swapTwoNodes(int x,int y){
	stu *xx=searchExact(x);
	stu *yy=searchExact(y);
	
	
	
	//if x is first node and y is last node


	if(xx==first && yy==last){
		
		stu *k=searchBefore(y);
		stu *l=xx->next;
		stu *g=xx;
		
		xx->next=yy;
		first=yy;
		yy->next=l;
		yy->prev=NULL;
		g->next=l;
		k->next=xx;
		last=xx;
		xx->next=NULL;
		xx->prev=k;
		
	}

	

		//if y is first node and x is last node

  else if(xx==last && yy==first){

		
		
		stu *k=searchBefore(x);
		stu *l=yy->next;
		stu *g=yy;
		
		yy->next=xx;
		first=xx;
		xx->next=l;
		xx->prev=NULL;
		g->next=l;
		
		k->next=yy;
		last=yy;
		yy->next=NULL;
		yy->next=NULL;
		
	}

	
	//consecutive cases
	//if x is first node and y is next of x
 else if(xx==first && yy==xx->next){

		stu* qt=yy->next;
		stu* xxx=xx;
		stu* yyy=yy;
		
		yy->next=xxx;
		xxx->next=qt;
		
		xx->next==yyy;
		yyy->next=xxx;
		first=yyy;
		
	}
	
	
	//consecutive cases
	//if y is first node and x is next of y
 else if(yy==first && xx==yy->next){

		stu* qt=xx->next;
		stu* xxx=xx;
		stu* yyy=yy;
		
		xx->next=yyy;
		yyy->next=qt;
		
		yy->next==xxx;
		xxx->next=yyy;
		first=xx;
		
	}
	//consecutive cases
	//if x is second last node and y is last node


	else  if(xx->next==last && yy==last){
	 	stu* befseclast=searchBefore(xx->id);
		stu* secondlast=befseclast->next;
	stu* lastt=yy;

		
		
		befseclast->next=yy;
		yy->next=secondlast;
		secondlast->next=NULL;
		last=secondlast;
		
		
		
	}
	
	//consecutive cases
	//if y is second last node and x is last node
	
	else  if(yy->next==last && xx==last){
	 	stu* befseclast=searchBefore(yy->id);
		stu* secondlast=befseclast->next;
	stu* lastt=xx;

		
		
		befseclast->next=xx;
		xx->next=secondlast;
		secondlast->next=NULL;
		last=secondlast;
		
		
		
	}
	
	//any two consecutive nodes other than above two cases (yy is the next of xx)


	 else if(xx!=first && yy!=first && xx!=last && yy!=last && yy==xx->next){
	 	stu* xbefore=searchBefore(xx->id);
	stu* xxx=xbefore->next;
	stu* ynext=yy->next;

	
	xbefore->next=yy;
	yy->next=xxx;
	xxx->next=ynext;
	
}

	//any two consecutive nodes other than above two cases (xx is the next of yy)


	 else if(xx!=first && yy!=first && xx!=last && yy!=last && xx==yy->next){
	 	stu* xbefore=searchBefore(yy->id);
	stu* xxx=xbefore->next;
	stu* ynext=xx->next;

	
	xbefore->next=xx;
	xx->next=xxx;
	xxx->next=ynext;
	
}

//if x is first and y is any other node but not last



 else if(xx==first && yy!=last){
			
	
	stu* ybefore=searchBefore(yy->id);
	stu* yafter=ybefore->next->next;
	stu* xafter=xx->next;
		
	
	first=ybefore->next;
	first->next=xafter;
	ybefore->next=xx;
	xx->next=yafter;
	
}
//if y is first and x is any other node but not last


else if(yy==first && xx!=last){
			
	
	stu* ybefore=searchBefore(xx->id);
	stu* yafter=ybefore->next->next;
	stu* xafter=yy->next;
		
	
	first=ybefore->next;
	first->next=xafter;
	ybefore->next=yy;
	yy->next=yafter;
	
}
//x is last and y is any other node but not first
else if(xx==last && yy!=first){
	stu* beforex=searchBefore(xx->id);
	stu* beforey=searchBefore(yy->id);
	stu* orignal_y=beforey->next;
	stu* p=beforey->next->next;
	stu* lst=beforex->next;
	
	beforex->next=orignal_y;
	last=orignal_y;
	orignal_y->next=NULL;
	beforey->next=lst;
	lst->next=p;
}

//y is last and x is any other node but not first
else if(yy==last && xx!=first){
	stu* beforex=searchBefore(yy->id);
	stu* beforey=searchBefore(xx->id);
	stu* orignal_y=beforey->next;
	stu* p=beforey->next->next;
	stu* lst=beforex->next;
	
	beforex->next=orignal_y;
	last=orignal_y;
	orignal_y->next=NULL;
	beforey->next=lst;
	lst->next=p;
}

}

	
	void display(){
		struct stu *p;
		p=first;
		if (p==NULL){
			cout<<"nothing to display";
		}
		while(p!=NULL){
			cout<<&(p->id)<<" "<<p->id<<" ";
			p=p->next;
		}
	}

int main(){
	int a;
	int b;
	
	
	int opt;
do{

	cout<<"\n Enter 1 to insert at end in the linked list, \n Enter 2 to display the linked list,\n Enter 3 to  the swap two nodes,\n Enter 0 to exit"<<endl; 
    cin>>opt;
switch(opt)
{
	case 1:
		insert_end();
		break;
	case 2:
	display();
		break;
	case 3:
		cout<<"enter the node id to be swap: ";
	cin>>a;
	cout<<"enter the node id to be swap: ";
	cin>>b;
		swapTwoNodes( a, b);
		display();
		

		break;

		
	default:
		break;
		
}
}while(opt!=0);
return 0;
	
	
}

