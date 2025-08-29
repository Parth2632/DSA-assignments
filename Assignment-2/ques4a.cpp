// 4) String Related Programs
// (a) Write a program to concatenate one string to another string.

#include <iostream>
using namespace std;

int main() {
    char str1[100], str2[100], str[200];
    int i = 0, j = 0;

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    while (str1[i] != '\0') {
        str[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0') {
        str[i] = str2[j];
        i++;
        j++;
    }

    str[i] = '\0'; 

    cout << "Concatenated string: " << str << endl;
    return 0;
}
