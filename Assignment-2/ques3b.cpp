// (b) Using binary search.

#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int left = 0, right = n - 2; 

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; 
    int n = 6; 

    cout << "Missing number: " << findMissingNumber(arr, n) << endl;
    return 0;
}
