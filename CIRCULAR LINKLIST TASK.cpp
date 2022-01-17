#include<iostream>
using  namespace std;


struct circle{
	int id;
	struct circle *next=NULL;
};
struct circle* tail1=NULL;
struct circle* tail2=NULL;
struct circle* tail3=NULL;


void insert_end(circle*taill1){
	
	struct circle* node=new circle;
	cout<<"ENTER ID";
	cin>>node->id;
	if (taill1==tail1){
		if(tail1==NULL){
			tail1=node;
			tail1->next=node;
		}
		
		else{
			node->next=tail1->next;
			tail1->next=node;
			tail1=node;
		}
		
	}
	
	else{
		if(tail2==NULL){
			tail2=node;
			tail2->next=node;
		}
		
		else{
			node->next=tail2->next;
			tail2->next=node;
			tail2=node;
		}
		
	}
}

void insert_list3(int newid){
	
	struct circle* node=new circle;
	
	
	node->id=newid;
	
		if(tail3==NULL){
			tail3=node;
			tail3->next=node;
		}
		
		else{
			node->next=tail3->next;
			tail3->next=node;
			tail3=node;
		}
		
	}
	



void displaylist1(){
	circle* p=NULL;
	p=tail1->next;
	if(p==NULL){
		cout<<"EMPTY LIST";
	}
	else{
		while(p!=tail1){
			cout<<p->id<<" -> ";
					p=p->next;

		}
		cout<<tail1->id<<endl;
			}
			
}



void displaylist2(){
	circle* p=NULL;
	p=tail2->next;
	if(p==NULL){
		cout<<"EMPTY LIST";
	}
	else{
		while(p!=tail2){
			cout<<p->id<<" -> ";
					p=p->next;

		}
		cout<<tail2->id<<endl;
			}
}


void displaylist3(){
	circle* p=NULL;
	p=tail3->next;
	if(p==NULL){
		cout<<"EMPTY LIST";
	}
	else{
		while(p!=tail3){
			cout<<p->id<<" -> ";
					p=p->next;

		}
		cout<<tail3->id<<endl;
			}
			
			
}
circle* search1(int key){
	circle* first=tail1->next;
	circle* firrst=tail1->next;
	while(first!=NULL && first->id!=key){
		first=first->next;
		firrst=first;
	}
	return firrst;
}


circle* search2(int key){
	circle* first=tail2->next;
	circle* firrst=tail2->next;
	while(first!=NULL && first->id!=key){
		first=first->next;
		firrst=first;
	}
	return firrst;
}
void circular1(){
	int high1;
	circle* h=tail1;
	circle* head=h->next;
	
	high1=head->id;
	do{
	
		if(high1<head->id){
			high1=head->id;
			}
			head=head->next;
			
			
}while(head!=h->next);
	insert_list3(high1);
	
circle* k=	search1( high1);

k->id=-1;

}


void circular2(){
	int high2;
	circle* h=tail2;
	circle* head=h->next;
	
	high2=head->id;
	do{
	  
	
		if(high2<head->id){
			high2=head->id;
			}
			head=head->next;
			
			
}while(head!=h->next);
	insert_list3(high2);
	
circle* k=	search2( high2);
k->id=-1;

}
void resultant_circular_list(){
	circle* h=tail2;
	circle* head=h->next;
	
	
	do{
		circular1();
		circular2();
		
	head=head->next;
	
			
}while(head!=h->next);
	
	
}

int main(){
	int opt;
	int delid;
	do{
		cout<<"Press 1 to insert in list 1\nPress 2 to display list 1 \nPress 3 to insert in list 2\nPress 4 to display list 2\nPress 5 to merge highest of both lists list 2\nPress 6 to display resultant highests of two list's list'2\n";
		cin>>opt;
		switch (opt){
			case 1:
			insert_end(tail1);
			
							
			break;
			case 2:
					cout<<"\nDISPLAY LIST 1\n";
				displaylist1();
				break;
			case 3:
					insert_end(tail2);
				
				break;
			case 4:
				cout<<"\nDISPLAY LIST 2\n";
				displaylist2();
				
				break;
				
			case 5:
			
			resultant_circular_list();
		
			break;
			case 6:
			
			displaylist3();
							
			break;
			default:
				break;
				
		
				
			
		}
	}
	while (opt!=0);
	return 0;

}
