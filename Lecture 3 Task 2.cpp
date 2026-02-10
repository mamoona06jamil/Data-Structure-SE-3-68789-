#include <iostream>
using namespace std;

int main(){
	char* charPtr=new char;
	*charPtr = 'A';
	cout<<"Stored character: "<<*charPtr<<endl;
	
	delete charPtr;
	charPtr = nullptr;
	
	return 0;
	
}