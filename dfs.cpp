#include<iostream>
#include<vector>
using namespace std;

class Graph{

    vector<vector<int>> adj;
    int numVertices;
    int numEdges;
    vector<bool> visited; //for DFS traversal
    public:

    Graph(int data){
        numVertices = data; 
        //initializing all elements to false
        visited.resize(numVertices,false); 
        //initializing all elements to 0
        adj.resize(numVertices,vector<int>(numVertices,0)); 
    }

    void addEdge (int v, int u){  //for undirected graph
        adj[v][u] = 1;
        adj[u][v] = 1;
    }

    void DFS_Traversal (int vertex){

        if (visited[vertex] == true){
            return;
        }
        else{
            cout<<vertex<<" ";
            visited[vertex] = true;
        }

        for (int i=0; i<numVertices; i++){
            if(adj[vertex][i] == 1){
                DFS_Traversal(i); //recurssion for DFS_Traversal
            }
        }
    }
};

int main (){
    
    cout<<"Enter total number of vertices and edges respectively"<<endl;
    int x,y;
    cin>>x>>y;

    Graph g (x);

    cout<<"Enter the pair vertices having an edge between them"<<endl;
    for(int i=0; i<y; i++){
        int v,u;
        cin>>v>>u;
        g.addEdge(v,u);
    }  

    cout<<"Enter the vertex from where you want to start TRAVERSAL:"<<endl;
    int m;
    cin>>m;
    g.DFS_Traversal(m);

    return 0;
}