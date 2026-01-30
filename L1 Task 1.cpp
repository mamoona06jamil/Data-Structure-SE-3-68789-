#include <iostream>
using namespace std;

int main() {
    int arr[3] = {5, 10, 15};
    int key = 15;
    bool found = false;

    for (int i = 0; i < 3; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i;
            found = true;
            break;
        }
    }

    
	if (!found) {
        cout << "Element not found in the array.";
    }
    
    return 0;
}
