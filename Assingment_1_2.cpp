#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 5, 2, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                    for (int k = j; k < n - 1; k++) {
                        arr[k] = arr[k + 1];
                }
                n--; 
            } else {
                j++; 
            }
        }
    }

    cout << "Unique elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}