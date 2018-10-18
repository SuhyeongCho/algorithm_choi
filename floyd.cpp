#include<iostream>
#include<vector>

using namespace std;

void floyd(const int n,const vector< vector<int> > W,vector< vector<int> > &D,vector< vector<int> > &P){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            P[i][j] = 0;
        }
    }
    D = W;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(D[i][k] + D[k][j] < D[i][j]){
                    P[i][j] = k+1;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

void path(const vector< vector<int> > P,int q,int r){
    if(P[q][r] != 0){
        path(P,q,P[q][r]-1);
        cout<<"v"<<P[q][r];
        path(P,P[q][r]-1,r);
    }
}

int main(){
    int n;
    cin>>n;
    vector< vector<int> > W(n,vector<int>(n,0)),D(n,vector<int>(n,0)),P(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>W[i][j];
        }
    }
    floyd(n,W,D,P);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<D[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<P[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    int q,r;
    cin>>q>>r;
    path(P,q-1,r-1);
    return 0;
}
