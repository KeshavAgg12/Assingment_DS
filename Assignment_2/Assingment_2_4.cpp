#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// (a) Concatenate one string to another
void concatenateStrings() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    strcat(str1, str2); // concatenation
    cout << "Concatenated string: " << str1 << endl;
}

// (b) Reverse a string
void reverseString() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;
}

// (c) Delete all vowels
void deleteVowels() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    string result = "";
    for (char c : str) {
        char lower = tolower(c);
        if (lower!='a' && lower!='e' && lower!='i' && lower!='o' && lower!='u') {
            result += c;
        }
    }
    cout << "String without vowels: " << result << endl;
}

// (d) Sort strings alphabetically
void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    string arr[100];

    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n); // sort alphabetically

    cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << endl;
}

// (e) Convert uppercase to lowercase
void convertToLowercase() {
    char c;
    cout << "Enter a character in uppercase: ";
    cin >> c;

    if (isupper(c)) {
        c = tolower(c);
        cout << "Lowercase character: " << c << endl;
    } else {
        cout << "Character is not uppercase." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Concatenate Strings\n";
        cout << "2. Reverse a String\n";
        cout << "3. Delete Vowels from String\n";
        cout << "4. Sort Strings Alphabetically\n";
        cout << "5. Convert Uppercase to Lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: concatenateStrings(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStrings(); break;
            case 5: convertToLowercase(); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}