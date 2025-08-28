#include <iostream>
using namespace std;

class DistinctCounter {
    int n;
    int *arr;
public:
    DistinctCounter(int size){
        n = size;
        arr = new int[n];
        for(int i=0;i<n;i++) cin >> arr[i];
    }

    int countDistinct() {
        int count = 0;
        for(int i=0;i<n;i++){
            bool isDistinct = true;
            for(int j=0;j<i;j++){
                if(arr[i]==arr[j]){
                    isDistinct = false;
                    break;
                }
            }
            if(isDistinct) count++;
        }
        return count;
    }

    ~DistinctCounter(){
        delete[] arr;
    }
};

int main() {
    int n;
    cin >> n;
    DistinctCounter dc(n);
    cout << "Total distinct elements: " << dc.countDistinct() << endl;
    return 0;
}