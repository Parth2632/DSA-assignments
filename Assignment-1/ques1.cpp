// 1) Developa Menudrivenprogramtodemonstrate the followingoperations of Arrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT

#include <iostream>
using namespace std;

int arr[100];   
int n = 0;      


void create() {
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
}

void display() {
    cout << "Array elements are: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void insert() {
    int pos, val;
    cout << "Enter position where to insert: ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;

    for(int i=n; i>pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;
}


void del() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    cout << "Deleted: " << arr[pos] << endl;
    for(int i=pos; i<n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
}


void search() {
    int key, flag=0;
    cout << "Enter element to search: ";
    cin >> key;

    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            cout << "Element found at position " << i << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        cout << "Element not found\n";
    }
}

int main() {
    int ch;
    while(true) {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch(ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: search(); break;
            case 6: 
                cout << "Exiting...\n"; 
                return 0;  
            default: cout << "Invalid choice!\n";
        }
    }
}
