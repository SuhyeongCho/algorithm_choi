#include<iostream>
#include<vector>

using namespace std;

void optsearchtree(const int n,const vector<float> p,float &minavg,vector< vector<int> >&R){
    vector< vector<float> > A(n+2,vector<float>(n+1,0));
    for(int i=1;i<=n;i++){
        A[i][i-1] = 0;
        A[i][i] = p[i-1];
        R[i][i] = i;
        R[i][i-1] = 0;
    }
    A[n+1][n] = 0;
    R[n+1][n] = 0;
    for(int diagonal = 1;diagonal <=n-1;diagonal++){
        for(int i=1;i<=n-diagonal;i++){
            float sumP = 0;
            int j = i+diagonal;
            for(int m = i;m<=j;m++){
                sumP += p[m-1];
            }
            A[i][j] = A[i][i-1] + A[i+1][j];
            R[i][j] = i;
            for(int k=i+1;k<=j;k++){
                if(A[i][k-1] + A[k+1][j] < A[i][j]){
                    A[i][j] = A[i][k-1] + A[k+1][j];
                    R[i][j] = k;
                }
            }
            A[i][j] += sumP;
        }
    }
    
    minavg = A[1][n];
}

int main(){
    int n;
    cin>>n;
    vector<float> p(n,0.0);
    vector< vector<int> > R(n+2,vector<int>(n+1,0));
    float minavg = 0.0;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    optsearchtree(n,p,minavg,R);
    cout<<"minavg : "<<minavg<<endl;
    return 0;
}
