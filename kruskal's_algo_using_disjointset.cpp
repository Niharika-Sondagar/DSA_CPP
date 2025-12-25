#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
    int u,v,wt;
};
class DisjointSet{
    vector<int>parent,rank;
    public:
     DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
     }
     int findUpar(int x){
        if(parent[x]!=x){
            parent[x]=findUpar(parent[x]);
        }
        return parent[x];
     }
     void unionSet(int u,int v){
        int u_p=findUpar(u);
        int v_p=findUpar(v);
        if(u_p==v_p)
        return;
        if(rank[u_p]<rank[v_p]){
             parent[u_p]=v_p;
        }
        else if(rank[u_p]>rank[v_p]){
             parent[v_p]=u_p;
        }
        else{
            parent[v_p]=u_p;
            rank[u_p]++;
        }
     }
};
void sortEdges(vector<Edge>&eg){
    int n=eg.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(eg[j].wt>eg[j+1].wt){
                int temp=eg[j].wt;
                eg[i].wt=eg[j+1].wt;
                eg[j+1].wt=temp;
            }
        }
    }
}
int main(){
    int V,E;
    cin>>V>>E; 
    vector<Edge>edges(E);
    for(int i=0;i<E;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].wt;
    }
     sortEdges(edges);
     DisjointSet ds(V);
     vector<Edge>mst;
     int mstwt=0;
     for(auto &eg:edges){
        if(ds.findUpar(eg.u)!=ds.findUpar(eg.v)){
            ds.unionSet(eg.u,eg.v);
            mst.push_back(eg);
            mstwt+=eg.wt;
        }
     }

    return 0;
}