#include<iostream>
#include<vector>
using namespace std;

struct edge{
    int first;
    int second;
    int weight;
};

void dijkstra(int n, vector< vector<int> > W, vector<struct edge> &F){
    int vnear;
    struct edge e;
    vector<int> touch(n+1,0),length(n+1,0);
    F.clear();
    for(int i=2;i<=n;i++){
        touch[i] = 1;
        length[i] = W[1][i];
    }
    
    for(int repeat = 0;repeat<n-1;repeat++){
        unsigned int min = -1;
        for(int i=2;i<=n;i++){
            if(length[i] >=0 && length[i] <=min){
                min = length[i];
                vnear = i;
            }
        }
        e.first = touch[vnear];
        e.second = vnear;
        e.weight = W[touch[vnear]][vnear];
        F.push_back(e);
        for(int i=2;i<=n;i++){
            if(length[vnear] + W[vnear][i] < length[i]){
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        }
        length[vnear] = -1;
    }
}
int main(){
    int n; cin>>n;
    vector< vector<int> > W(n+1,vector<int>(n+1,0));
    vector<struct edge> F;
    
    dijkstra(n,W,F);
    return 0;
}
