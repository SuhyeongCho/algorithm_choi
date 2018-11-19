#include<iostream>
#include<vector>

using namespace std;
class Disjoint_Set{
private:
    struct nodetype{
        int parent;
        int depth;
    };
    struct nodetype *universe;
public:
    
    void makeset(int i){
        universe[i].parent = i;
        universe[i].depth = 0;
    }
    
    int find(int i){
        int j = i;
        while(universe[j].parent != j)
            j = universe[j].parent;
        return j;
    }
    
    void merge(int p,int q){
        if(universe[p].depth == universe[q].depth){
            universe[p].depth += 1;
            universe[q].parent = p;
        }
        else if(universe[p].depth < universe[q].depth){
            universe[p].parent = q;
        }
        else{
            universe[q].parent = p;
        }
    }
    
    bool equal(int p,int q){
        if(p == q) return true;
        else return false;
    }
    
    void initial(int n){
        universe = new struct nodetype[n];
        for(int i=1;i<=n;i++){
            makeset(i);
        }
    }
};

struct edge{
    int first;
    int second;
    int weight;
};

bool operator <(const struct edge &a, const struct edge &b){
    return a.weight < b.weight;
}

void kruskal(int n, int m, vector<struct edge> E,vector<struct edge> &F,Disjoint_Set ds){
    int i,j;
    int p,q;
    struct edge e;
    sort(E.begin(),E.end());
    F.clear();
    
    ds.initial(n);
    int pos = 0;
    while(F.size() < n-1){
        e = E[pos];
       
        i = e.first;
        j = e.second;
        p = ds.find(i);
        q = ds.find(j);
        if(!ds.equal(p,q)){
            ds.merge(p,q);
            F.push_back(e);
        }
        pos++;
    }
    
}

int main(){
    int n,m;
    vector<struct edge> E,F;
    Disjoint_Set ds;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int first,second,weight;
        cin>>first>>second>>weight;
        struct edge e = {first,second,weight};
        E.push_back(e);
    }
    kruskal(n,m,E,F,ds);
    
    for(int i=0;i<F.size();i++){
        int first = F[i].first;
        int second = F[i].second;
        int weight = F[i].weight;
        
        cout<<"f:"<<first<<", s:"<<second<<", w:"<<weight<<endl;
    }
    return 0;
}
