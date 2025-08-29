// (c) Write a program to delete all the vowels from the string.


#include <iostream>
using namespace std;

int main() {
    char str[100];
    int i = 0;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    cout << "String after deleting vowels: ";
    while (str[i] != '\0') {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            cout << str[i];
        }
        i++;
    }

    cout << endl;
    return 0;
}
