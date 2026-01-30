#include <iostream>
using namespace std;

	int main(){
	int arr[5] = {100, 200, 400, 800, 1600};
	
	int index = 1;
	int newValue = 175;
		
	arr[index] = newValue;
		for(int i = 0; i < 5; i++) {
			cout << arr[i] << " ";
}
	return 0;	
	}