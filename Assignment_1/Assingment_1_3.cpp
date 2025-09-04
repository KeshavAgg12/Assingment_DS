#include <iostream>
using namespace std;

void reverseArray() {
    int n;
    cout << "\nEnter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int start = 0, end = n - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void matrixMultiplication() {
    int m, n, p;
    cout << "\nEnter dimensions of first matrix (rows cols): ";
    cin >> m >> n;
    cout << "Enter dimensions of second matrix (" << n << " cols must match first rows): ";
    cin >> p;

    int A[m][n], B[n][p], C[m][p];

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];

    // Initialize result matrix with 0
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            C[i][j] = 0;

    // Multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix() {
    int m, n;
    cout << "\nEnter dimensions of matrix (rows cols): ";
    cin >> m >> n;

    int A[m][n], AT[n][m];

    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    // Transpose
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            AT[j][i] = A[i][j];
        }
    }

    cout << "Transpose of Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << AT[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Reverse Array\n";
        cout << "2. Matrix Multiplication\n";
        cout << "3. Transpose of Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: reverseArray(); break;
            case 2: matrixMultiplication(); break;
            case 3: transposeMatrix(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}