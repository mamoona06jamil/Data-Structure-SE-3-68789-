#include <iostream>
using namespace std;

int main(){
	int row,col;
	int** matrix;
	
	cout<<"Enter No. of Rows: "<<endl;
	cin>>row;
	cout<<"Enter No. of Columns: "<<endl;
	cin>>col;
	
	matrix = new int*[row];
		for (int i=0; i<row; ++i){
			matrix[i] = new int [col];
		}
	
	cout<<"Enter Elements of Matrix: "<<endl;
		for (int i=0; i<row; ++i){
		for (int j=0; j<col; ++j){
			cout<<"Matrix["<<i<<"]["<<j<<"]: ";
			cin>>matrix[i][j];
}	
}
	cout<<"The matrix is: "<<endl;
	for (int i=0; i<row; ++i){
	for (int j=0; j<col; ++j){
		cout<<matrix[i][j]<<" ";
}
cout<<endl;
}
	for (int i=0; i<row; ++i){
	delete [] matrix [i];
	}
		delete [] matrix;
		matrix = nullptr;
		
		return 0;
}
	