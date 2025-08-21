#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    int A[m][n];

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nSum of each row:\n";
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += A[i][j];
        }
        cout << "Row " << i + 1 << " = " << rowSum << endl;
    }

    // Column sums
    cout << "\nSum of each column:\n";
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += A[i][j];
        }
        cout << "Column " << j + 1 << " = " << colSum << endl;
    }

    return 0;
}