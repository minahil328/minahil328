#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct order{
	string id;
	float cost;
	string destination;
};

order* orderIslamabad[500];
int firstIsb=-1, lastIsb=-1;
order* orderLahore[500];
int firstLhr=-1, lastLhr=-1;
order* orderKarachi[500];
int firstKhi=-1, lastKhi=-1;

struct edge{
	string name;
	int costD;
	edge *next=NULL;
};

struct vertex{
	string cityName;
	bool isBranch = false;
	int costD=-1;
	vertex *next=NULL;
	edge *firstE=NULL;
};
vertex* startVertex=NULL, *lastVertex=NULL;

string adminUsername = "bhfm123", adminPassword = "service@falcon";
order* deliveredOrders[500];
int topOrders=-1;
string arrCities[10];
int topCities=-1;
float earningIsb=0, earningLhr=0, earningKhi=0;

bool login();
void mapGenerate();
void display();
int shortestPathFind(string source, string destination);
bool findVertex(string city);
vertex* findVertex(string city, vertex *start, vertex *last);
vertex* minCostCity(vertex* fixN);
void push(vertex* city);
void takeOrder(order* temp, order* branch [], int &first, int &last);
void balance(int index, order* branch[]);
bool isEmpty(int front);
void swap(int front, int rear, order* orderBranch[]);
void createShipment();
void trackOrder();
void locateUs();
bool isCorrectSource(string source);
bool isCorrectDestination(string destination);
void earnings();
void admin();
void dispatchOrders();
void displayOrderDetails(order* orderBranch[], int &start, int &last);
void displayDeliveredOrder(order* orderBranch[], int &start);
string id_generator();
void displayCities(int code);
void customer();
void deliverOrder(order* arr[],int &front, int &rear);
string setInitialCapital(string city);
void resetBranchCosts(string source);
void addDeliveredOrders(order *temp);

int main(){
	mapGenerate();
	srand(time(NULL));
    int opt;

	while(true){
		string openingOption;
		cout<<"\n+-------------------------------------------------------------------------------------------------------------+\n";
		cout<<"|                               ***Welcome to Falcon Courier Service!***                                      |\n";
		cout<<"|                                                                                                             |\n";
		cout<<"|           +-------------------------+                               +-------------------------+             |\n";
		cout<<"|           | Press 1: Customer Block |                               |  Press 2:  Admin Block  |             |\n";
		cout<<"|           +-------------------------+                               +-------------------------+             |\n";
		cout<<"|                                                                                                             |\n";
		cout<<"+-------------------------------------------------------------------------------------------------------------+";
		do{
			cout<<"\n  -->Choice: ";
			cin>>openingOption;
			if(openingOption=="1"){
				customer();
				break;
			}
			else if(openingOption=="2"){
				if(login()){
					admin();
				}		
			}
			else{
				cout<<"ERROR: INVALID OPTION SELECTED!\n";
			}	
		}while(openingOption!="1" && openingOption!="2");
				
	}
	return 0;	
}

void customer(){
	string customerOption;
	cout<<"+-----------------------------------------------------------+\n";
	cout<<"|               C U S T O M E R     B L O C K               |\n";
	cout<<"+-----------------------------------------------------------+\n";
	do{
		cout<<"\n------------------------> MAIN MENU <------------------------\n";
		cout<<"  Press 1: CREATE SHIPMENT\n";
		cout<<"  Press 2: TRACK YOUR ORDER\n";
		cout<<"  Press 3: LOCATE US\n";
		cout<<"  Press 0: EXIT\n";
		cout<<"-------------------------------------------------------------\n";
		cout<<"  -->Choice: ";
		cin>>customerOption;

		if(customerOption=="0"){
			cout<<"\n+------------------------------------------------------------------------------------------+\n";
			cout<<"|                               ***Thank you for choosing us!***                           |\n";
			cout<<"+------------------------------------------------------------------------------------------+\n";
		}	
		else if(customerOption=="1"){
			createShipment();
		}
		else if(customerOption=="2"){
			trackOrder();

		}
		else if(customerOption=="3")		
			locateUs();
		else
			cout<<"ERROR: INVALID OPTION SELECTED!\n";
		
	}while(customerOption!="0");
}

string id_generator(){
	string id;
	char characters[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B',
	'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0'};
	
	for(int i=0;i<6;i++){
		id=id+ characters[rand()%(sizeof(characters)/sizeof(characters[0]))];
	}
	return id;
}

void mapGenerate(){
	//Islamabad 
	vertex *city1 = new vertex;
	city1->cityName = "Islamabad";
	city1->isBranch = true;
	startVertex = city1;
	
	//Islamabad edges
	edge* e1I = new edge;
	e1I->name = "Attock";
	e1I->costD = 70;
	city1->firstE = e1I;
	
	edge* e2I = new edge;
	e2I->name = "Faisalabad";
	e2I->costD = 100;
	e1I->next = e2I;
	
	edge* e3I = new edge;
	e3I->name = "Sialkot";
	e3I->costD = 120;
	e2I->next = e3I;
	
	
	//Lahore
	vertex *city2 = new vertex;
	city2->cityName = "Lahore";
	city2->isBranch = true;
	city1->next = city2;
	
	//Lahore edges
	edge* e1L = new edge;
	e1L->name = "Sialkot";
	e1L->costD = 100;
	city2->firstE = e1L;
	
	edge* e2L = new edge;
	e2L->name = "Faisalabad";
	e2L->costD = 100;
	e1L->next = e2L;
	
	edge* e3L = new edge;
	e3L->name = "Multan";
	e3L->costD = 90;
	e2L->next = e3L;
	
	
	//Karachi
	vertex *city3 = new vertex;
	city3->cityName = "Karachi";
	city3->isBranch = true;
	city2->next = city3;
	
	//Karachi edges
	edge* e1K = new edge;
	e1K->name = "Multan";
	e1K->costD = 150;
	city3->firstE = e1K;
	
	edge* e2K = new edge;
	e2K->name = "Hyderabad";
	e2K->costD = 90;
	e1K->next = e2K;
	
	
	//Peshawar
	vertex *city4 = new vertex;
	city4->cityName = "Peshawar";
	city3->next = city4;
	
	//Peshawar edges
	edge* e1P = new edge;
	e1P->name = "Attock";
	e1P->costD = 90;
	city4->firstE = e1P;
	
	
	
	//Quetta
	vertex *city5 = new vertex;
	city5->cityName = "Quetta";
	city4->next = city5;
	
	//Quetta edges
	edge* e1Q = new edge;
	e1Q->name = "Hyderabad";
	e1Q->costD = 200;
	city5->firstE = e1Q;
	
	edge* e2Q = new edge;
	e2Q->name = "Multan";
	e2Q->costD = 300;
	e1Q->next = e2Q;

	
	//Multan
	vertex *city6 = new vertex;
	city6->cityName = "Multan";
	city5->next = city6;
	
	//Multan edges
	edge* e1M = new edge;
	e1M->name = "Lahore";
	e1M->costD = 90;
	city6->firstE = e1M;
	
	edge* e2M = new edge;
	e2M->name = "Faisalabad";
	e2M->costD = 120;
	e1M->next = e2M;
	
	edge* e3M = new edge;
	e3M->name = "Karachi";
	e3M->costD = 150;
	e2M->next = e3M;
	
	edge* e4M = new edge;
	e4M->name = "Quetta";
	e4M->costD = 300;
	e3M->next = e4M;
	
	
	//Sialkot
	vertex *city7 = new vertex;
	city7->cityName = "Sialkot";
	city6->next = city7;
	
	//Sialkot edges
	edge* e1S = new edge;
	e1S->name = "Islamabad";
	e1S->costD = 120;
	city7->firstE = e1S;
	
	edge* e2S = new edge;
	e2S->name = "Lahore";
	e2S->costD = 100;
	e1S->next = e2S;
	
	
	
	//Hyderabad
	vertex *city8 = new vertex;
	city8->cityName = "Hyderabad";
	city7->next = city8;
	
	//Hyderabad edges
	edge* e1H = new edge;
	e1H->name = "Karachi";
	e1H->costD = 90;
	city8->firstE = e1H;
	
	edge* e2H = new edge;
	e2H->name = "Quetta";
	e2H->costD = 200;
	e1H->next = e2H;
	
	
	//Attock
	vertex *city9 = new vertex;
	city9->cityName = "Attock";
	city8->next = city9;
	
	//Attock edges
	edge* e1A = new edge;
	e1A->name = "Peshawar";
	e1A->costD = 100;
	city9->firstE = e1A;
	
	edge* e2A = new edge;
	e2A->name = "Islamabad";
	e2A->costD = 70;
	e1A->next = e2A;
	
	
	//Faisalabad
	vertex *city10 = new vertex;
	city10->cityName = "Faisalabad";
	city9->next = city10;
	lastVertex = city10;
	
	//Faisalabad edges
	edge* e1F = new edge;
	e1F->name = "Islamabad";
	e1F->costD = 100;
	city10->firstE = e1F;
	
	edge* e2F = new edge;
	e2F->name = "Lahore";
	e2F->costD = 100;
	e1F->next = e2F;
	
	edge* e3F = new edge;
	e3F->name = "Multan";
	e3F->costD = 120;
	e2F->next = e3F;
}

void display(){
	vertex *i=startVertex;
	while(i!=NULL){
		cout<<i->cityName<<", costd: "<<i->costD<<", branch? "<<i->isBranch<<endl;
		edge* j=i->firstE;
		while(j!=NULL){
			cout<<j->name<<", cost: "<<j->costD<<", "<<endl;
			j=j->next;
		}
		cout<<endl;
		i=i->next;
	}
	cout<<endl;
}

int shortestPathFind(string source, string destination){
	vertex *i=findVertex(source, startVertex, lastVertex), *y;
	topCities=-1;
	while(i->cityName!=destination){
		push(i);	
		edge *j = i->firstE;
		while(j!=NULL){
			if(!findVertex(j->name)){
				y=findVertex(j->name, startVertex, lastVertex);

				if(i->costD+j->costD<y->costD || y->costD==-1){
					y->costD=i->costD+j->costD;
				}
			}
			j=j->next;
		}
		y=minCostCity(i);
		
		i=y;		
	}

	return i->costD;
}

void push(vertex *city){
	arrCities[++topCities]=city->cityName;
}

bool findVertex(string city){
	for(int i=0; i<=topCities; i++){
		if(arrCities[i]==city){
			return true;
		}
	}
	return false;
}

vertex* findVertex(string city, vertex *start, vertex *last){
	vertex *i=start;
	while(i->next!=NULL && i->cityName!=city){
		i=i->next;
	}


	if(i==last && i->cityName!=city){
		return NULL;
	}
	else{
		return i;
	}	
}

vertex* minCostCity(vertex* fixN){
	vertex* i=startVertex, *min=NULL;
	while(i!=NULL){
		if(!findVertex(i->cityName) && i->costD!=-1){
			if(min==NULL){
				min=i;
			}
			else if(i->costD<min->costD){
				min=i;
			}
		}
		i=i->next;
	}
	return min;	
}

bool isEmpty(int front){
	if(front==-1)
		return true;
	else
		return false;
}

void takeOrder(order* temp, order* branch [], int &first, int &last){
    if(last == 500){
        cout<<"Can not take more orders";
    }
    else if (first == -1){
        first = last = 0;
        branch[first] = temp;
    }
    else{
        last++;
        branch[last] = temp;
        balance(last, branch);
    }
}

void balance(int index, order* branch[]){
    while((branch[(index-1)/2]->cost)>(branch[index]->cost)){
        swap(((index-1)/2), index, branch);
        index = (index-1)/2;
    }
}

void swap(int front, int rear, order* orderBranch[]){
	order* temp = orderBranch[front];
	orderBranch[front] = orderBranch[rear];
	orderBranch[rear]=temp;
}

void deliverOrder(order* arr[],int &front, int &rear){
	if(isEmpty(front)){
		cout<<"No orders to deliver\n";
	}
	else{
		arr[front]=arr[rear];
		if(front==rear){
			front = rear = -1;
		}
        else{
            rear--;
        }
		
		int newValInd = front;
		int lc=2*(newValInd)+1, rc=2*(newValInd)+2;
		
		while((lc<=rear || rc<=rear) && newValInd>=0){
			if(lc>rear && rc<=rear && arr[rc]->cost<arr[newValInd]->cost){
				swap(rc,newValInd,arr);
				newValInd = rc;
			}
			else if(lc<=rear && rc>rear && arr[lc]->cost<arr[newValInd]->cost){
				swap(lc,newValInd,arr);
				newValInd = lc;
			}
			else if(lc<=rear && rc<=rear){
				int minInd = (arr[lc]->cost < arr[rc]->cost)? lc:rc;
				swap(minInd,newValInd,arr);
				newValInd = minInd;
			}
			else{
				newValInd=-1;
			}
			lc=2*(newValInd)+1, rc=2*(newValInd)+2;
			
		} 
	}

}

bool isCorrectSource(string source){
	if((source=="Islamabad") || (source=="Lahore" ) || (source=="Karachi")){
		return true;
	}
	else{
		return false;
	}
}

bool isCorrectDestination(string destination){
	if((destination=="Peshawar" )||(destination=="Quetta" )||(destination=="Multan")||(destination=="Sialkot" )||(destination=="Attock" )||(destination=="Hyderabad" )
	||(destination=="Faisalabad")||(destination=="Islamabad")||(destination=="Lahore" )||(destination=="Karachi")){
		return true;
	}
	else{
		return false;
	}
}

string setInitialCapital(string city){
	if((city=="Islamabad")  || (city=="islamabad")){
		return "Islamabad";
	}
	else if((city=="Karachi")||(city=="karachi")){
		return "Karachi";
	}
	else if((city=="Lahore" )||(city=="lahore" )){
		return "Lahore";
	}
	else if((city=="Faisalabad")||(city=="faisalabad")){
		return "Faisalabad";	
	}
	else if((city=="Hyderabad" )||(city=="hyderabad" )){
		return "Hyderabad";
	}
	else if((city=="Attock" )||(city=="attock" )){
		return "Attock";
	}
	else if((city=="Sialkot" )||(city=="sialkot" )){
		return "Sialkot";
	}
	else if((city=="Multan")||(city=="multan")){
		return "Multan";
	}
	else if((city=="Quetta" )||(city=="quetta" )){
		return "Quetta";
	}
	else if((city=="Peshawar" )||(city=="peshawar" )){
		return "Peshawar";
	}
	return city;
}

void trackOrder(){
	string orderID, branchName;
	cout<<"+-----------------------------------------------------------+\n";
	cout<<"|                      T R A C K I N G                      |\n";
	cout<<"+-----------------------------------------------------------+\n";
	
	cout<<"  ENTER ORDER ID: ";
	cin>>orderID;	
	do{	
		cout<<"  ENTER ORDER PLACEMENT BRANCH NAME: ";
		cin>>branchName;
		branchName=setInitialCapital(branchName);
		if(!isCorrectSource(branchName)){
			cout<<"ERROR: THIS BRANCH DOES NOT EXIST!\n";
		}
	}while(!isCorrectSource(branchName));
	
	cout<<"\n----------------------> ORDER DETAILS <----------------------";
	if(branchName=="Islamabad" ){
		for(int i=0; i<=topOrders && topOrders!=-1; i++){
			if(orderID == deliveredOrders[i]->id){
				cout<<"\n BRANCH NAME:       ISLAMABAD";
				cout<<"\n ORDER ID:          "<<orderIslamabad[i]->id;
				cout<<"\n DELIVERY STATUS:   DELIVERED";
				cout<<"\n TOTAL ORDER COST:  "<<orderIslamabad[i]->cost;
				cout<<"\n ORDER DESTINATION: "<<orderIslamabad[i]->destination;	
				cout<<"\n-------------------------------------------------------------\n";
				return;
			}
		}
		for(int i=firstIsb; i<=lastIsb && firstIsb!=-1; i++){
			if(orderID==orderIslamabad[i]->id){
				cout<<"\n BRANCH NAME:       ISLAMABAD";
				cout<<"\n ORDER ID:          "<<orderIslamabad[i]->id;
				cout<<"\n DELIVERY STATUS:   NOT DELIVERED";
				cout<<"\n TOTAL ORDER COST:  "<<orderIslamabad[i]->cost;
				cout<<"\n ORDER DESTINATION: "<<orderIslamabad[i]->destination;	
				cout<<"\n-------------------------------------------------------------\n";
				return;
			}		
		}
	}
	else if(branchName=="Lahore"){
		for(int i=0; i<=topOrders && topOrders!=-1; i++){
			if(orderID == deliveredOrders[i]->id){
				cout<<"\n BRANCH NAME:       LAHORE";
				cout<<"\n ORDER ID:          "<<orderLahore[i]->id;
				cout<<"\n DELIVERY STATUS:   DELIVERED";
				cout<<"\n TOTAL ORDER COST:  "<<orderLahore[i]->cost;
				cout<<"\n ORDER DESTINATION: "<<orderLahore[i]->destination;
				cout<<"\n-------------------------------------------------------------\n";
				return;
			}
		}	
		for(int i=firstLhr; i<=lastLhr && firstLhr!=-1; i++){
			if(orderID==orderLahore[i]->id){
				cout<<"\n----------------------> ORDER DETAILS <----------------------";
				cout<<"\n BRANCH NAME:       LAHORE";
				cout<<"\n ORDER ID:          "<<orderLahore[i]->id;
				cout<<"\n DELIVERY STATUS:   NOT DELIVERED";
				cout<<"\n TOTAL ORDER COST:  "<<orderLahore[i]->cost;
				cout<<"\n ORDER DESTINATION: "<<orderLahore[i]->destination;	
				cout<<"\n-------------------------------------------------------------\n";
				return;
			}		
		}
	}			
	else if(branchName=="Karachi"){
		for(int i=0; i<=topOrders && topOrders!=-1; i++){
			if(orderID == deliveredOrders[i]->id){
				cout<<"\n BRANCH NAME:       KARACHI";
				cout<<"\n ORDER ID:          "<<orderKarachi[i]->id;
				cout<<"\n DELIVERY STATUS:   DELIVERED";
				cout<<"\n TOTAL ORDER COST:  "<<orderKarachi[i]->cost;
				cout<<"\n ORDER DESTINATION: "<<orderKarachi[i]->destination;
				cout<<"\n-------------------------------------------------------------\n";
				return;
			}
		}
		for(int i=firstKhi; i<=lastKhi  && firstKhi!=-1; i++){
			if(orderID==orderKarachi[i]->id){
				cout<<"\n----------------------> ORDER DETAILS <----------------------";
				cout<<"\n BRANCH NAME:       KARACHI";
				cout<<"\n ORDER ID:          "<<orderKarachi[i]->id;
				cout<<"\n DELIVERY STATUS:   NOT DELIVERED";
				cout<<"\n TOTAL ORDER COST:  "<<orderKarachi[i]->cost;
				cout<<"\n ORDER DESTINATION: "<<orderKarachi[i]->destination;	
				cout<<"\n-------------------------------------------------------------\n";
				return;
			}		
		}
	} 
	cout<<"\nERROR: ORDER NOT FOUND!\n";
}

void createShipment(){
	float weight;
	string branchName, destination;
	cout<<"+-----------------------------------------------------------+\n";
	cout<<"|              C R E A T E    S H I P M E N T               |\n";
	cout<<"+-----------------------------------------------------------+\n";
	
	cout<<"  ENTER ORDER WEIGHT: ";
	cin>>weight;		
	do{	
		cout<<"  ENTER ORDER PLACEMENT BRANCH NAME: ";
		cin>>branchName;
		branchName=setInitialCapital(branchName);
		if(!isCorrectSource(branchName)){
			cout<<"ERROR: THIS BRANCH DOES NOT EXIST!\n";
		}
	}while(!isCorrectSource(branchName));
	
	do{
		cout<<"  ENTER DESTINATION: ";
		cin>>destination;
		destination=setInitialCapital(destination);
		if(!isCorrectDestination(destination)){
			cout<<"ERROR: THIS DESTINATION DOES NOT EXIST!\n";
		}
	}while(!isCorrectDestination(destination));
	
	resetBranchCosts(branchName);
	float cost;
	if(branchName == destination){
		cost=50;
		cout<<"\n---------------------> PAYMENT DETAILS <---------------------";
		cout<<"\n DELIVERY CHARGES: Rs."<<cost;
	}
	else{
		cost = shortestPathFind(branchName, destination);
		cout<<"\n---------------------> PAYMENT DETAILS <---------------------";
		cout<<"\n DELIVERY CHARGES: Rs."<<cost;		
	}
	cost+=(weight*100);
	cout<<"\n YOUR TOTAL IS:    Rs."<<cost;
	float payment;
	do{
		cout<<"\n-------------------------------------------------------------";
		cout<<"\n ENTER PAYMENT:    Rs.";
		cin>>payment;
		if(payment!=cost){
			cout<<"\nERROR: INVALID AMOUNT ENTERED!";
		}
	}while(payment!=cost);
	cout<<"\n-------------------------------------------------------------";
	
	//order creation
	order* newOrder = new order;
	newOrder->cost = payment;
	newOrder->destination = destination; 
	newOrder->id=id_generator();
	
	if(branchName=="Islamabad"){
		takeOrder(newOrder, orderIslamabad, firstIsb, lastIsb);	
	}
	else if(branchName=="Lahore"){
		takeOrder(newOrder, orderLahore, firstLhr, lastLhr);
	}
	else if(branchName=="Karachi"){
		takeOrder(newOrder, orderKarachi, firstKhi, lastKhi);
	}

	cout<<"\n         ****YOUR SHIPMENT HAS BEEN CREATED!****";
	cout<<"\n          ***        ORDER ID: "<<newOrder->id<<"       ***\n";
	cout<<"\n-------------------------------------------------------------";
}

void locateUs(){
	string locateOption;
	cout<<"+-----------------------------------------------------------+\n";
	cout<<"|                     L O C A T E    U S                    |\n";
	cout<<"+-----------------------------------------------------------+\n";
	
	do{
		cout<<"\n------------------------> MAIN MENU <------------------------\n";
		cout<<"  Press 1: OUR BRANCHES\n";
		cout<<"  Press 2: DELIVERY LOCATIONS\n";
		cout<<"  Press 0: GO BACK\n";
		cout<<"-------------------------------------------------------------\n";
		cout<<"  -->Choice: ";
		cin>>locateOption;

		if(locateOption=="0")
			return;
		else if(locateOption=="1"){
			cout<<"\n-----------------------> OUR BRANCHES <----------------------\n";
			displayCities(2);
			cout<<"\n-------------------------------------------------------------\n";	
		}
		else if(locateOption=="2"){
			cout<<"\n-------------------> DELIVERY LOCATIONS <--------------------\n";
			displayCities(1);
			cout<<"\n-------------------------------------------------------------\n";	
		}
		else
			cout<<"ERROR: INVALID OPTION SELECTED!\n";
	}while(locateOption!="0");
	
}

void displayCities(int code){
	int sNo=1;
	vertex *i=startVertex;
	switch(code){
		case 1:{
			while(i!=NULL){
				cout<<" "<<sNo<<": "<<i->cityName<<endl;
				sNo++;
				i=i->next;
			}
			break;
		}
		case 2:{
			while(i!=NULL){
				if(i->isBranch){
					cout<<" "<<sNo<<": "<<i->cityName<<endl;
					sNo++;
				}
				i=i->next;
			}
			break;
		}
	}
}

void earnings(){
	string branchN;

	do{	
		cout<<"  ENTER BRANCH NAME: ";
		cin>>branchN;
		branchN=setInitialCapital(branchN);
		if(!isCorrectSource(branchN)){
			cout<<"ERROR: THIS BRANCH DOES NOT EXIST!\n";
		}
	}while(!isCorrectSource(branchN));
	
	cout<<"\n---------------------> EARNING  DETAILS <--------------------";
	if(branchN=="Islamabad"){		
		cout<<"\n TOTAL EARNINGS OF ISLAMABAD BRANCH :  "<<earningIsb;				
	}
	
	else if(branchN=="Lahore"){	
		cout<<"\n TOTAL EARNINGS OF LAHORE BRANCH:  "<<earningLhr;
	}			
	else if(branchN=="Karachi"){	
		cout<<"\n TOTAL EARNINGS OF KARACHI BRANCH:  "<<earningKhi;	
	} 
	cout<<"\n-------------------------------------------------------------\n";
}

void admin(){
    string adminOption;
	cout<<"+-----------------------------------------------------------+\n";
	cout<<"|                   A D M I N    B L O C K                  |\n";
	cout<<"+-----------------------------------------------------------+\n";
	
	do{
		cout<<"\n------------------------> MAIN MENU <------------------------\n";
		cout<<"  Press 1: DISPATCH ORDERS\n";
		cout<<"  Press 2: DISPLAY UNDELIVERED ORDERS\n";
		cout<<"  Press 3: DISPLAY DELIVERED ORDERS\n";
		cout<<"  Press 4: DISPLAY BRANCH-WISE EARNINGS\n";
		cout<<"  Press 5: DISPLAY TOTAL DELIVERIES\n";
		cout<<"  Press 0: EXIT\n";
		cout<<"-------------------------------------------------------------\n";
		cout<<"  -->Choice: ";
		cin>>adminOption;

		if(adminOption=="0"){
			cout<<"\n+------------------------------------------------------------------------------------------+\n";
			cout<<"|                               ***Thank you for choosing us!***                           |\n";
			cout<<"+------------------------------------------------------------------------------------------+\n";	
		}	
		else if(adminOption=="1"){
			dispatchOrders();
		}
		else if(adminOption=="2"){
			string branchName;
			do{	
				cout<<"  ENTER BRANCH NAME: ";
				cin>>branchName;
				branchName=setInitialCapital(branchName);
				if(!isCorrectSource(branchName)){
					cout<<"ERROR: THIS BRANCH DOES NOT EXIST!\n";
				}
			}while(!isCorrectSource(branchName));
            
            if (branchName=="Islamabad"){
                displayOrderDetails(orderIslamabad, firstIsb, lastIsb);
            }
            else if(branchName == "Lahore"){
                displayOrderDetails(orderLahore, firstLhr, lastLhr);
            }
            else if (branchName=="Karachi"){
                displayOrderDetails(orderKarachi, firstKhi, lastKhi);
            }				
		}
		else if(adminOption=="3"){
			cout<<"\n--------------------> DELIVERED ORDERS <---------------------";
		    if (topOrders==-1){
		        cout<<"\nNo Orders Delivered yet!";
		    }
		    else{
		    	for(int i=0; i<=topOrders; i++){
		    		cout<<"\nOrder # "<<i+1<<":";
		    		cout<<"\nOrder ID: "<<deliveredOrders[i]->id;
				    cout<<"\nOrder Cost: "<<deliveredOrders[i]->cost;
				    cout<<"\nOrder Destination: "<<deliveredOrders[i]->destination; 
				} 
			}
		    cout<<"\n-------------------------------------------------------------\n";	
		}
		else if(adminOption=="4")		
			earnings();
		else if(adminOption=="5"){
			cout<<"\n--------------------> TOTAL DELIVERIES <---------------------";
			cout<<"\n  COUNT: "<<(topOrders+1);
			cout<<"\n-------------------------------------------------------------\n";
		}
		else
			cout<<"ERROR: INVALID OPTION SELECTED!\n";
	}while(adminOption!="0");
}

void displayDeliveredOrder(order* orderBranch[], int &start){
	cout<<"\n--------------------> DELIVERED ORDERS <---------------------";
    if (orderBranch[start]==NULL){
        cout<<"\nNo Orders Pending";
    }
    cout<<"\nOrder ID: "<<orderBranch[start]->id;
    cout<<"\nOrder Cost: "<<orderBranch[start]->cost;
    cout<<"\nOrder Destination: "<<orderBranch[start]->destination; 
    cout<<"\n-------------------------------------------------------------\n";
}

void displayOrderDetails(order* orderBranch[], int &start, int &last){
	cout<<"\n---------------------> ORDER DETAILS <-----------------------";
	if(start!=-1){
		for(int i=start;i<=last;i++){
			cout<<"\nOrder # "<<i+1<<":";
	        cout<<"\nOrder ID: "<<orderBranch[i]->id;
	        cout<<"\nOrder Cost: "<<orderBranch[i]->cost;
	        cout<<"\nOrder Destination: "<<orderBranch[i]->destination;
    	} 
	}
    else{
    	cout<<"\nNO PENDING ORDERS!";
	}
    cout<<"\n-------------------------------------------------------------\n";
    
}

void dispatchOrders(){
	string userOption, x;	
	do{
		cout<<"+-----------------------------------------------------------+\n";
		cout<<"|                D I S P A T C H   O R D E R                |\n";
		cout<<"+-----------------------------------------------------------+\n";
		cout<<" PRESS 1: ISLAMABAD \n PRESS 2: KARACHI \n PRESS 3: LAHORE\n PRESS 0: BACK";
		cout<<"\n-------------------------------------------------------------\n";
		cout<<"  -->Choice: ";
    	cin>>userOption;
    	if(userOption=="0"){
    		return;
		}
		else if(userOption!="1" && userOption!="2" && userOption!="3"){
			cout<<"ERROR: INVALID OPTION SELECTED!\n";
		}
	}while(userOption!="1" && userOption!="2" && userOption!="3");
    
    if(userOption=="1"){
		if(lastIsb!=-1){
			do{
	    	cout<<"\n PRESS 1: DISPATCH ALL ORDERS \n PRESS 2: DISPATCH ORDER NEXT IN-LINE";
	    	cout<<"\n-------------------------------------------------------------\n";
	    	cout<<"  -->Choice: ";
	    	cin>>x;
			}while(x!="1" && x!="2");
    		
    		// Islamabad
	        if (x=="1"){
	            while (lastIsb!=-1){
	            	earningIsb+=orderIslamabad[firstIsb]->cost;
					deliveredOrders[++topOrders] = orderIslamabad[firstIsb];
	                displayDeliveredOrder(orderIslamabad, firstIsb);
	                deliverOrder(orderIslamabad, firstIsb, lastIsb);
	            }
	        }
	        else if (x=="2"){
        		earningIsb+=orderIslamabad[firstIsb]->cost;
				deliveredOrders[++topOrders] = orderIslamabad[firstIsb];
	            displayDeliveredOrder(orderIslamabad, firstIsb);
	            deliverOrder(orderIslamabad, firstIsb, lastIsb);
					
	        }
	        cout<<"\nALL ORDERS DISPATCHED!";
		}
		else{
	    	cout<<"\nNO PENDING ORDERS!";
		}
		
	}
	else if(userOption=="2"){
		 // Karachi
		 if(lastKhi!=-1){
			do{
	    	cout<<" PRESS 1: DISPATCH ALL ORDERS \n PRESS 2: DISPATCH ORDER NEXT IN-LINE";
	    	cout<<"\n-------------------------------------------------------------\n";
	    	cout<<"  -->Choice: ";
	    	cin>>x;
			}while(x!="1" && x!="2");
	        if (x=="1"){
	            while (lastKhi!=-1){
			    	earningKhi+=orderKarachi[firstKhi]->cost;
					deliveredOrders[++topOrders] = orderKarachi[firstKhi];
	                displayDeliveredOrder(orderKarachi, firstKhi);
	                deliverOrder(orderKarachi, firstKhi, lastKhi);
	            }
	            
	        }
	        else if (x=="2"){
        		earningKhi+=orderKarachi[firstKhi]->cost;
				deliveredOrders[++topOrders] = orderKarachi[firstKhi];
	            displayDeliveredOrder(orderKarachi, firstKhi);
	            deliverOrder(orderKarachi, firstKhi, lastKhi);
				
	        }
	        cout<<"\nALL ORDERS DISPATCHED!";
	    }
	    else{
	    	cout<<"\nNO PENDING ORDERS!";
		}
	}
	else if(userOption=="3"){
		// Lahore
		if(lastLhr!=-1){
			do{
	    	cout<<" PRESS 1: DISPATCH ALL ORDERS \n PRESS 2: DISPATCH ORDER NEXT IN-LINE";
	    	cout<<"\n-------------------------------------------------------------\n";
	    	cout<<"  -->Choice: ";
	    	cin>>x;
			}while(x!="1" && x!="2");
	        if (x=="1"){
	            while (lastLhr!=-1){
	            	earningLhr+=orderLahore[firstLhr]->cost;
					deliveredOrders[++topOrders] = orderLahore[firstLhr];
	                displayDeliveredOrder(orderLahore, firstLhr);
	                deliverOrder(orderLahore, firstLhr, lastLhr);
	            }
	        }
	        else if (x=="2"){
        		earningLhr+=orderLahore[firstLhr]->cost;
				deliveredOrders[++topOrders] = orderLahore[firstLhr];
	            displayDeliveredOrder(orderLahore, firstLhr);
	            deliverOrder(orderLahore, firstLhr, lastLhr);
	        }
	        cout<<"\nALL ORDERS DISPATCHED!";
	    }
	    else{
	    	cout<<"\nNO PENDING ORDERS!";
		}
	}	
	cout<<"\n-------------------------------------------------------------\n";
}

void resetBranchCosts(string source){
	vertex *i = startVertex;
	while(i!=NULL){
		if(i->cityName==source){
			i->costD=0;
		}
		else{
			i->costD=-1;
		}
		i=i->next;
	}
}

bool login(){
	string username, password, opt;
	do{
		cout<<"                            +--------------------------------------------------+                              \n";
		cout<<"                                               ***L O G I N***                                                 \n";
		cout<<"                            +--------------------------------------------------+                              \n";
		cout<<"                      		 ENTER USERNAME: ";
		cin>>username;
		cout<<"                      		 ENTER PASSWORD: ";
		cin>>password;
		if(username!=adminUsername && password!=adminPassword){
			cout<<"\n                                        Invalid Username/Password!\n";
			do{
				cout<<"                            +--------------------------------------------------+                              \n";
				cout<<"                                      PRESS 0 TO GO BACK, ELSE PRESS 1\n";
				cout<<"                               CHOICE: ";
				cin>>opt;
				if(opt=="0"){
					return false;
				}
				else if(opt!="1"){
					cout<<"                                       ERROR: INVALID OPTION SELECTED!\n";
				}
			}while(opt!="1");
			
		}	
	}while(username!=adminUsername && password!=adminPassword);
	cout<<"\n                                             Login Successful!\n";
	cout<<"                                                                                                              \n";
	cout<<"                            +--------------------------------------------------+                              \n";
	cout<<"\n+-------------------------------------------------------------------------------------------------------------+\n";
	return true;
}

void addDeliveredOrders(order *temp){
	deliveredOrders[++topOrders] = temp;
	
}


