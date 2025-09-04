#include <iostream>
using namespace std;

class InversionCounter {
    int n;
    int *arr;
public:
    InversionCounter(int size){
        n = size;
        arr = new int[n];
        for(int i=0;i<n;i++) cin >> arr[i];
    }

    int countInversions() {
        int inv = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i] > arr[j]) inv++;
            }
        }
        return inv;
    }

    ~InversionCounter(){
        delete[] arr;
    }
};

int main() {
    int n;
    cin >> n;
    InversionCounter ic(n);
    cout << "Number of inversions: " << ic.countInversions() << endl;
    return 0;
}