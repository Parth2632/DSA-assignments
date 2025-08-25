// 2) Design the logic to remove the duplicate elements from an Array and after the
// deletion the array should containtheunique elements.


#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j] && arr[i] != -999) {
                arr[j] = -999; 
            }
        }
    }
    
    int m = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] != -999) {
            arr[m++] = arr[i];
        }
    }


    cout << "Array after removing duplicates: ";
    for(int i=0; i<m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
