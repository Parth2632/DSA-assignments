// (d) Write a program to sort the strings in alphabetical order


#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    int n;
    char str[10][50], temp[50];

    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin.getline(str[i], 50);
    }

    for (int i = 0; i < n; i++) {
        toLowerCase(str[i]);
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(str[j], str[j + 1]) > 0) {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }

    cout << "\nStrings in alphabetical order (case-insensitive):\n";
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

    return 0;
}
