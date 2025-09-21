#include <iostream>
using namespace std;

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    long long inv_count = 0;
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int idx = left; idx <= right; idx++)
        arr[idx] = temp[idx];

    return inv_count;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if(left < right) {
        int mid = (left + right) / 2;
        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid+1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int temp[n];
    long long inv_count = mergeSortAndCount(arr, temp, 0, n-1);
    cout << inv_count << endl;
}
