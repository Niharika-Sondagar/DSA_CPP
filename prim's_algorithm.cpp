// #include<iostream>
// using namespace std;
// #define V 5
// void prim_mst(int graph[V][V]){
//     int parent[V];
//     int visited[V];
//     int mindist[V];

//     for(int i=0;i<V;i++){
//         mindist[i]=9999999;
//         visited[i]=0;
//     }
//     mindist[0]=0;
//     parent[0]=-1;

//     for(int i=0;i<V-1;i++){
//         int u=-1;
//         int minval=9999999;
//         for(int j=0;j<V;j++){
//             if(!visited[j] && mindist[i]<minval){
//                 minval=mindist[j];
//                 u=j;
//             }
//         }
//         visited[u]=1;
//         for(int v=0;v<V;v++){
//             if(graph[u][v]&&!visited[v]&&graph[u][v]<mindist[v]){
//                 parent[v]=u;
//                 mindist[v]=graph[u][v];
//             }
//         }
//     }
//     cout<<"Edge \t Weight\n";
//     for(int i=0;i<V;i++){
//         cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<endl;
//     }
// }
// int main(){
//      int graph[V][V] = {
//         {0, 2, 3, 0, 0},
//         {2, 0, 1, 4, 0},
//         {3, 1, 0, 5, 6},
//         {0, 4, 5, 0, 7},
//         {0, 0, 6, 7, 0}
//     };

//     prim_mst(graph);
//     return 0;
// }
#include <iostream>
using namespace std;

#define V 5   // number of vertices

void primMST(int graph[V][V]) {
    int parent[V];      // to store MST edges
    int mindist[V];     // min distance to connect each vertex
    bool visited[V];    // visited[] = true if vertex already in MST

    // Step 1: initialize
    for (int i = 0; i < V; i++) {
        mindist[i] = 999999;   // infinity
        visited[i] = false;
    }

    // Step 2: start from vertex 0
    mindist[0] = 0;    // source has 0 weight
    parent[0] = -1;    // root of MST

    // Step 3: repeat (V-1) times to build MST
    for (int count = 0; count < V - 1; count++) {
        // Pick vertex u with minimum mindist[] not visited yet
        int u = -1;
        int minVal = 999999;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && mindist[i] < minVal) {
                minVal = mindist[i];
                u = i;
            }
        }

        visited[u] = true; // include u in MST

        // Step 4: update neighbors of u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < mindist[v]) {
                parent[v] = u;
                mindist[v] = graph[u][v];
            }
        }
    }

    // Step 5: print MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 1, 4, 0},
        {3, 1, 0, 5, 6},
        {0, 4, 5, 0, 7},
        {0, 0, 6, 7, 0}
    };

    primMST(graph);
    return 0;
}
