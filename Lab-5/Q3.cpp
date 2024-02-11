#include <bits/stdc++.h>
using namespace std;

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
        for (int v = 0; v < n; ++v)
        {
            if (graph[temp][v] && color[v] == -1)
            {
                color[v] = 1 - color[temp];
                q.push(v);
            }
            else if (graph[temp][v] && color[v] == color[temp])
                return false;
        }
    }
    return true;
}

bool canBeDividedinTwoCliques(vector<vector<int>> graph){
    int n=graph.size();
    vector<vector<int>> complement(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            complement[i][j]=1-graph[i][j];
        }
    }
    return isBipartite(complement);
}



int main()
{

    vector<vector<int>> graph = {{0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};

    if(canBeDividedinTwoCliques(graph)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}