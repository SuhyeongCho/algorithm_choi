#include<iostream>
#include<vector>

using namespace std;


vector< vector<int> > addMatrix(int n,vector< vector<int> > A,vector< vector<int> > B){
    vector< vector<int> > C(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector< vector<int> > subMatrix(int n,vector< vector<int> > A,vector< vector<int> > B){
    vector< vector<int> > C(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

void strassen(int n,vector< vector<int> > A,vector< vector<int> > B,vector< vector<int> > &C){
    if(n <= 1){
        C[0][0] = A[0][0] * B[0][0];
    }
    else{
        int m = n/2;
        vector< vector<int> > A11(m,vector<int>(m,0)),A12(m,vector<int>(m,0)),A21(m,vector<int>(m,0)),A22(m,vector<int>(m,0));
        vector< vector<int> > B11(m,vector<int>(m,0)),B12(m,vector<int>(m,0)),B21(m,vector<int>(m,0)),B22(m,vector<int>(m,0));
        vector< vector<int> > C11(m,vector<int>(m,0)),C12(m,vector<int>(m,0)),C21(m,vector<int>(m,0)),C22(m,vector<int>(m,0));
       vector< vector<int> > M1(m,vector<int>(m,0)),M2(m,vector<int>(m,0)),M3(m,vector<int>(m,0)),M4(m,vector<int>(m,0)),M5(m,vector<int>(m,0)),M6(m,vector<int>(m,0)),M7(m,vector<int>(m,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j+m];
                A21[i][j] = A[i+m][j];
                A22[i][j] = A[i+m][j+m];
                
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j+m];
                B21[i][j] = B[i+m][j];
                B22[i][j] = B[i+m][j+m];
            }
        }

        strassen(m,addMatrix(m,A11,A22),addMatrix(m,B11,B22),M1);
        strassen(m,addMatrix(m,A21,A22),B11,M2);
        strassen(m,A11,subMatrix(m,B12,B22),M3);
        strassen(m,A22,subMatrix(m,B21,B11),M4);
        strassen(m,addMatrix(m,A11,A12),B22,M5);
        strassen(m,subMatrix(m,A21,A11),addMatrix(m,B11,B12),M6);
        strassen(m,subMatrix(m,A12,A22),addMatrix(m,B21,B22),M7);

        C11 = subMatrix(m,addMatrix(m,M1,M4),subMatrix(m,M5,M7));
        C12 = addMatrix(m,M3,M5);
        C21 = addMatrix(m,M2,M4);
        C22 = subMatrix(m,addMatrix(m,M1,M3),subMatrix(m,M2,M6));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                C[i][j] = C11[i][j];
                C[i][j+m] = C12[i][j];
                C[i+m][j] = C21[i][j];
                C[i+m][j+m] = C22[i][j];
            }
        }
    }
}
int main(){
    int n; cin>>n;
    
    vector< vector<int> > A(n,vector<int>(n,0)),B(n,vector<int>(n,0)),C(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>B[i][j];
        }
    }
    
    strassen(n,A,B,C);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<C[i][j]<<' ';
        }
        cout<<'\n';
    }
    
}
