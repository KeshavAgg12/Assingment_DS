#include <iostream>
using namespace std;

// Diagonal Matrix
class Diagonal {
    int n;
    int *A;
public:
    Diagonal(int size){
        n = size;
        A = new int[n];
        for(int i=0;i<n;i++){
            cin >> A[i]; // input diagonal elements
        }
    }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) cout<<A[i-1]<<" ";
                else cout<<"0 ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    ~Diagonal(){ delete[] A; }
};

// Tri-diagonal Matrix
class TriDiagonal {
    int n;
    int *A;
public:
    TriDiagonal(int size){
        n = size;
        A = new int[3*n-2];
        for(int i=0;i<3*n-2;i++) cin >> A[i]; // input elements
    }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int val=0;
                if(i-j==1) val=A[i-2];
                else if(i==j) val=A[n-1+i-1];
                else if(i-j==-1) val=A[2*n-1+i-1];
                cout<<val<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    ~TriDiagonal(){ delete[] A; }
};

// Lower Triangular Matrix
class LowerTriangular {
    int n;
    int *A;
public:
    LowerTriangular(int size){
        n=size;
        A = new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) cin >> A[i];
    }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>=j) cout<<A[i*(i-1)/2 + j-1]<<" ";
                else cout<<"0 ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    ~LowerTriangular(){ delete[] A; }
};

// Upper Triangular Matrix
class UpperTriangular {
    int n;
    int *A;
public:
    UpperTriangular(int size){
        n=size;
        A = new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) cin >> A[i];
    }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i<=j) cout<<A[j*(j-1)/2 + (i-1)]<<" ";
                else cout<<"0 ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    ~UpperTriangular(){ delete[] A; }
};

// Symmetric Matrix
class Symmetric {
    int n;
    int *A;
public:
    Symmetric(int size){
        n=size;
        A = new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) cin >> A[i];
    }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>=j) cout<<A[i*(i-1)/2 + j-1]<<" ";
                else cout<<A[j*(j-1)/2 + i-1]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    ~Symmetric(){ delete[] A; }
};

// Main function
int main(){
    cout<<"Enter n as of matrix n*n :";
    int n;
    cin >> n;
    Diagonal d(n);
    d.display();
    cout<<"Enter n as of matrix n*n :";
    cin >> n;
    TriDiagonal t(n);
    t.display();
    cout<<"Enter n as of matrix n*n :";
    cin >> n;
    LowerTriangular l(n);
    l.display();
    cout<<"Enter n as of matrix n*n :";
    cin >> n;
    UpperTriangular u(n);
    u.display();
    cout<<"Enter n as of matrix n*n :";
    cin >> n;
    Symmetric s(n);
    s.display();

    return 0;
}