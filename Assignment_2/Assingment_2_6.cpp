#include <iostream>
using namespace std;

class SparseMatrix {
    int m, n, num; // rows, columns, number of non-zero elements
    int *row, *col, *val;

public:
    SparseMatrix(int rows, int cols, int nonZero) {
        m = rows;
        n = cols;
        num = nonZero;
        row = new int[num];
        col = new int[num];
        val = new int[num];

        for(int i = 0; i < num; i++) {
            cin >> row[i] >> col[i] >> val[i]; // user input: row col value
        }
    }

    void displayTriplet() {
        cout << "Row Col Value\n";
        for(int i = 0; i < num; i++) {
            cout << row[i] << " " << col[i] << " " << val[i] << "\n";
        }
        cout << "\n";
    }

    SparseMatrix transpose() {
        SparseMatrix t(n, m, num);
        for(int k = 0; k < num; k++) {
            t.row[k] = col[k];
            t.col[k] = row[k];
            t.val[k] = val[k];
        }
        return t;
    }

    SparseMatrix add(SparseMatrix &s) {
        if(m != s.m || n != s.n) {
            cout << "Matrix dimensions mismatch!\n";
            return SparseMatrix(0,0,0);
        }

        int tempSize = num + s.num;
        int *r = new int[tempSize];
        int *c = new int[tempSize];
        int *v = new int[tempSize];

        int i=0, j=0, k=0;
        while(i<num && j<s.num) {
            int pos1 = row[i]*1000 + col[i];
            int pos2 = s.row[j]*1000 + s.col[j];
            if(pos1 < pos2) {
                r[k]=row[i]; c[k]=col[i]; v[k]=val[i]; i++; k++;
            }
            else if(pos1 > pos2) {
                r[k]=s.row[j]; c[k]=s.col[j]; v[k]=s.val[j]; j++; k++;
            }
            else { // same position
                int sum = val[i]+s.val[j];
                if(sum!=0) { r[k]=row[i]; c[k]=col[i]; v[k]=sum; k++; }
                i++; j++;
            }
        }
        while(i<num) { r[k]=row[i]; c[k]=col[i]; v[k]=val[i]; i++; k++; }
        while(j<s.num) { r[k]=s.row[j]; c[k]=s.col[j]; v[k]=s.val[j]; j++; k++; }

        SparseMatrix result(m, n, k);
        for(int p=0;p<k;p++){
            result.row[p]=r[p];
            result.col[p]=c[p];
            result.val[p]=v[p];
        }

        delete[] r; delete[] c; delete[] v;
        return result;
    }

    ~SparseMatrix() {
        delete[] row;
        delete[] col;
        delete[] val;
    }
};

int main() {
    int m, n, num;
    cin >> m >> n >> num;
    SparseMatrix s1(m,n,num);
    cout << "Original Sparse Matrix:\n";
    s1.displayTriplet();

    SparseMatrix t = s1.transpose();
    cout << "Transpose of Sparse Matrix:\n";
    t.displayTriplet();

    cin >> m >> n >> num;
    SparseMatrix s2(m,n,num);
    SparseMatrix sum = s1.add(s2);
    cout << "Addition of Sparse Matrices:\n";
    sum.displayTriplet();

    return 0;
}