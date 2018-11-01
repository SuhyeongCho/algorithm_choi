#include<iostream>
#include<vector>

using namespace std;

int minmult(const int n, vector<int> d, vector< vector<int> > &P) {
    
    vector< vector<int> > M(n,vector<int>(n,0));
    
    for(int i=0;i<n;i++){
        M[i][i] = 0;
    }
    for(int diagonal=1;diagonal<n;diagonal++){
        for(int i=0;i<n-diagonal;i++){
            int j=i+diagonal;
            M[i][j] = M[i][i] + M[i+1][j] + d[i]*d[i+1]*d[j+1];
            P[i][j] = i+1;
            for(int k=i+1;k<j;k++){
                if(M[i][k]+M[k+1][j]+d[i]*d[k+1]*d[j+1] <= M[i][j]){
                    M[i][j] = M[i][k]+M[k+1][j]+d[i]*d[k+1]*d[j+1];
                    P[i][j] = k+1;
                }
            }
        }
    }
    return M[0][n-1];
}

void order(const vector< vector<int> > P,const int i,const int j){
    if(i == j){
        cout<<"A"<<i+1;
    }
    else{
        int k = P[i][j];
        cout<<"(";
        order(P,i,k-1);
        order(P,k,j);
        cout<<")";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> d(n+1,0);
    vector< vector<int> > P(n,vector<int>(n,0));
    
    for(int i=0;i<n+1;i++){
        cin>>d[i];
    }
    

    order(P,0,n-1);
    cout<<endl;
}
