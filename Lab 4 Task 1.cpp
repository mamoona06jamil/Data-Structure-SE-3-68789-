#include <iostream>
using namespace std;

struct Node{
	string brandname;
	int unit;
	float price;
	Node* next;
};

Node* head= NULL;

void addMobile(){
	Node* newNode = new Node();
	cout<<"Enter the Mobile Phone's Brand: "<<endl;
	cin>>newNode->brandname;
	
	cout<<"Enter the Mobile Phone's Units in Stock: "<<endl;
	cin>>newNode->unit;
	
	cout<<"Enter the Mobile Phone's Price: "<<endl;
	cin>>newNode->price;
	
	newNode->next= NULL;
	
	if (head == NULL){
		head=newNode;
	}
	else{
		Node* temp=head;
		while(temp->next !=NULL){
			temp=temp->next;
		}
		temp->next = newNode;
	}
		cout<<"Mobile Added Successfully..."<<endl;
}

void deleteMobile(){
	if (head==NULL){
		cout<<"Inventory Empty..."<<endl;
	return;	
}
	string brand;
	cout<<"Enter Brand Name to Delete: "<<endl;
	cin>>brand;
	
	Node* temp=head;
	Node* prev= NULL;
	
	if (temp!=NULL && temp->brandname==brand){
		head = temp->next;
		delete temp;
		cout<<"Deleted..."<<endl;
		return;
	}
	while (temp!=NULL && temp->brandname !=brand){
		prev=temp;
		temp=temp->next;
	}
	
	if (temp==NULL){
		cout<<"Not found"<<endl;
		return;
	}
	
	prev->next=temp->next;
	delete temp;
	cout<<"Mobile Phone Deleted..."<<endl;
}

void displayMobile(){
	
	if (head==NULL){
		cout<<"Inventory Empty"<<endl;
		return;
	}
	Node* temp=head;
	cout<<"Display List"<<endl;
	
	while(temp!=NULL){
		cout<<"Brand:"<<temp->brandname<<endl;
		cout<<"Units:"<<temp->unit<<endl;
		cout<<"Price:"<<temp->price<<endl;
		cout<<"====================="<<endl;
		temp=temp->next;
		
	}
}

int main(){
	int choices;
	
	do{
		cout<<"1.Add Mobile Phone"<<endl;
		cout<<"2.Delete Mobile Phone"<<endl;
		cout<<"3.Display Mobile Phone"<<endl;
		cout<<"4.Exit!"<<endl;
		cout<<"Enter Your Choice"<<endl;
		cin>>choices;
		
		switch(choices){
			case 1:
				addMobile();
				break;
			case 2:
				deleteMobile();
				break;
			case 3:
				displayMobile();
				break;
			case 4:
			cout<<"Exiting the Program"<<endl;
				break;
			default:
				cout<<"Invalid Option"<<endl;
		}
		
	}	while (choices!=4);
		return 0;
}








