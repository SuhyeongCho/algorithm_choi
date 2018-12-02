#include<iostream>

using namespace std;

int n;
int W;
int *w;
bool *include;

bool promising(int i,int weight,int total){
    return (weight + total >= W) && (weight == W || weight + w[i+1] <= W);
}

void sum_of_subsets(int i,int weight,int total){
    if(promising(i,weight,total)){
        if(weight == W){
            for(int k=0;k<=i;k++){
                cout<<include[k];
            }
            cout<<endl;
        }
        else{
            include[i+1] = true;
            sum_of_subsets(i+1,weight+w[i+1],total - w[i+1]);
            include[i+1] = false;
            sum_of_subsets(i+1,weight,total-w[i+1]);
        }
    }
}

int main(){
    cin>>n>>W;
    
    w = new int[n];
    include = new bool[n];
    
    int total = 0;
    for(int i=0;i<n;i++){
        cin>>w[i];
        total += w[i];
        include[i] = false;
    }
    
    sum_of_subsets(-1,0,total);
    
    return 0;
}
