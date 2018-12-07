#include<iostream>

using namespace std;

int n,m;
int *vcolor;
bool **W;

bool promising(int i){
    bool switch1 = true;
    for(int j=1;j<i && switch1;j++){
        if(W[i][j]&&vcolor[i]==vcolor[j]){
            switch1 = false;
        }
    }
    return switch1;
}

void m_coloring(int i){
    if(promising(i)){
        if(i==n){
            for(int k=1;k<=n;k++){
                cout<<vcolor[k];
            }
            cout<<endl;
        }
        else{
            for(int color = 1;color<=m;color++){
                vcolor[i+1] = color;
                m_coloring(i+1);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    
    vcolor = new int[n+1];
    W = new bool*[n+1];
    for(int i=1;i<=n;i++){
        W[i] = new bool[n+1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>W[i][j];
        }
    }
    
    m_coloring(0);
    
    return 0;
}
