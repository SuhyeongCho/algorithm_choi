#include<iostream>

using namespace std;


int n;
int *vindex;
bool **W;


bool promising(int i){
    
    bool switch1;
    
    if(i == n-1 && !W[vindex[n-1]][vindex[0]])
        switch1 = false;
    else if(i > 0 && !W[vindex[i-1]][vindex[i]])
        switch1 = false;
    else{
        switch = true;
        for(int j=1;j<i && switch1;j++){
            if(vindex[i] == vindex[j])
                switch1 = false;
        }
    }
    
    return switch1;
}

void hamiltonian(int i){
    if(promising(i)){
        if(i == n-1){
            for(int k=0;k<n;k++){
                cout<<vindex[k];
            }
            cout<<endl;
        }
        else{
            for(int j=1;j<n;j++){
                vindex[i+1] = j;
            }
            hamiltonian(i+1);
        }
    }
}


int main(){
    cin>>n;
    
    vindex = new int[n];
    vindex[0] = 1;
    W = new bool*[n];
    
    for(int i=0;i<n;i++){
        W[i] = new bool[n];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>W[i][j];
        }
    }
    
    hamiltonian(-1);
    return 0;
}
