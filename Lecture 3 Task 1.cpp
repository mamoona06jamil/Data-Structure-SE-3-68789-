#include <iostream>
using namespace std;

struct Product{
	int code;
	string name;
	float price;
};

int main(){
	int n;
	cout<<"Enter no. of Products: "<<endl;
	cin>>n;
	
	Product* products = new Product;
	
	for (int i=0; i<n; ++i){
		cout<<"Enter detauls for product"<<i+1<<"."<<endl;
		cout<<"Name: "<<endl;
		cin>>products[i].name;
		cout<<"Code: "<<endl;
		cin>>products[i].code;
		cout<<"Price: "<<endl;
		cin>>products[i].price;
	}
	
	cout<<"PRODUCT DETAILS"<<endl;
	for (int i=0; i<n; ++i){
	cout<<"Product"<<i+1<<" : "<<endl;
	cout<<"Name:"<<products[i].name<<endl;
	cout<<"Code:"<<products[i].code<<endl;
	cout<<"Price: "<<products[i].price;
}

delete[] products;
products = nullptr;

return 0;
}