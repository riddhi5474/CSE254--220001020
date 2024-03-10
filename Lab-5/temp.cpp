#include <bits/stdc++.h>
using namespace std;


// A Clique is a subgraph of a graph such that all vertices in the subgraph are completely connected


bool isBipartite(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    queue<int> q;
    q.push(0);
    color[0] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        // if(graph[temp][temp]==1){
        //     return false;
        // }
        for (int v = 0; v < n; ++v)
        {
            if (graph[temp][v] && color[v] == -1)
            {
                color[v] = 1 - color[temp];
                q.push(v);
            }
            else if (graph[temp][v] && color[v] == color[temp])
                // cout<<"false";
                return false;
        }
    }
    // cout<<"true";
    return true;
}

//O(V^2) time....
//O(n) color vector, queue for bfs

bool canBeDividedinTwoCliques(vector<vector<int>> graph){
    int n=graph.size();
    vector<vector<int>> complement(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){

            complement[i][j]=1-graph[i][j];
            }
        }
    }
    return isBipartite(complement);
}



int main()
{
    vector<vector<int>> graph = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};

    cout << (canBeDividedinTwoCliques(graph) ? "Yes" : "No") << endl;

}