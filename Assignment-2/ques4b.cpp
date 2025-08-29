// (b) Write a program to reverse a string

#include <iostream>
using namespace std;

int main() {
    char str1[100], str2[100];
    int count = 0, i = 0;

    cout << "Enter a string: ";
    cin.getline(str1, 100);

    while (str1[count] != '\0') {
        count++;
    }

    for (i = 0; i < count; i++) {
        str2[i] = str1[count - 1 - i];  
    }

    str2[i] = '\0';  

    cout << "Reversed string: " << str2 << endl;
    return 0;
}
