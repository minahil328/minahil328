#include <iostream>
using namespace std;
struct node{
	int id;
	 node* prev=NULL;
	 node* next=NULL;
};

node *first1=NULL;
node *last1=NULL;
node *first2=NULL;
node *last2=NULL;

node *first3=NULL;
node *last3=NULL;

void insert1(node *firstt, node* lastt){

	
	node* current=new node;
	cout<<"Enter ID: ";
	cin>>current->id;
		
	
	
if (firstt==first1 && lastt==last1){
	

	if (first1==NULL){
		first1=last1=current;
//		first=current;
//		last=current;
////		last->next=NULL;
		
	}else{
		node *p=firstt;
		int k;
		while (p!=NULL){
			if (p->id==current->id){
			k=p->id;
			break;
	} 
	else{
		p=p->next;
	}
		}
		
		
		
		if (k==current->id){
			return;
		}else{
			node *p=firstt;
		int k;
		while (p!=NULL){
			if (p->id==current->id){
			k=p->id;
			break;
	} 
	else{
		p=p->next;
	}
}
		
		last1->next=current;
		current->prev=last1;
		last1=current;
		last1->next=NULL;
	}
		
	}
}else {
	
	if (first2==NULL){
		first2=last2=current;

	}
	else{
		node *p=firstt;
		int k;
		while (p!=NULL){
			if (p->id==current->id){
			k=p->id;
			break;
	} 
	else{
		p=p->next;
	}
		}
		
		
		
		if (k==current->id){
			return;
		}else{
			node *p=firstt;
		int k;
		while (p!=NULL){
			if (p->id==current->id){
			k=p->id;
			break;
	} 
	else{
		p=p->next;
	}
}
		
	
	
		last2->next=current;
		current->prev=last2;
		last2=current;
		last2->next=NULL;
	
	
}
}
}
}


void display(node *firstt){
	node *p=firstt;
	if (p==NULL){
		cout<<"\nNo value to display\n";
	}else{
		while (p!=NULL){
				if (p->next==NULL){
			
			cout<<p->id;
		}else{
			cout<<p->id<<" -> ";
		}
			p=p->next;
		}
	}
	cout<<endl;
}




void insert3(int newId){
	node* current=new node;
	current->id=newId;
	node *p=first3;
	
	while (p!=NULL){
		if (newId==p->id){
			return;
		}
		p=p->next;
		
	}
	if (first3==NULL){
		first3=last3=current;
		
	}else{
		last3->next=current;
		current->prev=last3;
		last3=current;
		last3->next=NULL;
		
		
	}
	
}

node *disjunction(node *head1, node *head2){

	node *p=head1;
	int count=0;
	int count1=0;
       
	while (p!=NULL){
			node *q=head2;
		while (q!=NULL){
			if (p->id==q->id){
				count++;
			}
					q=q->next;
				}
				if (count==0){
					insert3(p->id);
				}else{
					count=0;
				}
			
			
				p=p->next;
			}
	
	
	node *r=head2;
	while (r!=NULL){
			node *q=head1;
		while (q!=NULL){
			if (r->id==q->id){
					
            count1++;
			}
			q=q->next;
			
			
			
		}
		if (count1==0){
				insert3(r->id);
		}else {
			count1=0;
		}
		r=r->next;
		
	}
}
	

	
	
	
////////////////////main function///////////////////////////////




int main(){
	int opt;
	do{
		cout<<"Press 1 to insert in list 1\nPress 2 to display list 1 \nPress 3 to insert in list 2\nPress 4 to display list 2\nPress 5 to take disjunction two lists\nPress 6 to display result after disjunction\n";
		cin>>opt;
		switch (opt){
			case 1:
				insert1(first1,last1);
				break;
			case 2:
					cout<<"\nDISPLAY LIST 1\n";
				display(first1);
				break;
			case 3:
				insert1(first2,last2);
				break;
				
			case 4:
				cout<<"\nDISPLAY LIST 2\n";
				display(first2);
				break;
			case 5:
				{
				
				disjunction(first1,first2);
				
				break;
			}
			case 6:
				cout<<"\nTHE DISJUNCTION OF TWO LISTS IS\n";
				display(first3);
				break;
			
				
			
		}
	}
	while (opt!=0);
	return 0;

}
