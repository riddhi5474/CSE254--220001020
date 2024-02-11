#include <bits/stdc++.h>
using namespace std;

bool exist(int N, int a, int b)
{
    if (a < 0 || b < 0 || a >= N || b >= N)
    {
        return false;
    }
    return true;
}

int solve(vector<vector<int>> graph, int xcell, int ycell)
{
    int n = graph.size();
    vector<int> x = {-1, 1, 0, -1, 1, -1, 1, 0};
    vector<int> y = {-1, -1, -1, 0, 0, 1, 1, 1};

    int maxConnected = 1;
    stack<pair<int,int>> stk;
    stk.push({xcell, ycell});
    graph[xcell][ycell] = 0;

    while (!stk.empty())
    {
        pair<int,int> temp = stk.top();
        int a = temp.first;
        int b = temp.second;
        stk.pop();

        for (int k = 0; k < 8; k++)
        {
            if (exist(n, a + x[k], b + y[k]) && graph[a + x[k]][b + y[k]] == 1)
            {
                stk.push({a + x[k], b + y[k]});
                graph[a + x[k]][b + y[k]] = 0;
                maxConnected++;
            }
        }
    }
    return maxConnected;
}

int maxConnectedCell(vector<vector<int>> graph)
{
    int globalMax = 0;
    int n = graph.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                int localMax = solve(graph, i, j);

                globalMax = max(localMax, globalMax);
            }
        }
    }
    return globalMax;
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 0, 0}, {1, 1, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    cout << maxConnectedCell(graph);
    return 0;
}