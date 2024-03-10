#include <bits/stdc++.h>
using namespace std;

bool exist(int N, int M, int a, int b)
{
    if (a < 0 || b < 0 || a >= N || b >= M)
    {
        return false;
    }
    return true;
}

int solve(vector<vector<int>> &graph, int xcell, int ycell)
{
    int n = graph.size();
    int m = graph[0].size(); // Get the number of columns
    vector<int> x = {-1, 1, 0, -1, 1, -1, 1, 0};
    vector<int> y = {-1, -1, -1, 0, 0, 1, 1, 1};

    int maxConnected = 1;
    stack<pair<int, int>> stk;
    stk.push({xcell, ycell});
    graph[xcell][ycell] = 0;

    while (!stk.empty())
    {
        pair<int, int> temp = stk.top();
        int a = temp.first;
        int b = temp.second;
        stk.pop();

        for (int k = 0; k < 8; k++)
        {
            if (exist(n, m, a + x[k], b + y[k]) && graph[a + x[k]][b + y[k]] == 1)
            {
                stk.push({a + x[k], b + y[k]});
                graph[a + x[k]][b + y[k]] = 0;
                maxConnected++;
            }
        }
    }
    return maxConnected;
}

int maxConnectedCell(vector<vector<int>> &graph)
{

    int globalMax = 0;
    int n = graph.size();
    int m = graph[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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
    vector<vector<int>> graph = {{0, 1, 0, 0}, {1, 1, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 1}};
    cout << maxConnectedCell(graph);
    // freopen("input_Q1.txt", "r", stdin);
    // freopen("output_Q1.txt", "w", stdout);
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n;
    //     int m;
    //     cin >> n >> m;
    //     vector<vector<int>> g(n, vector<int>(m));
    //     for (int i = 0; i < n; i++)
    //         for (int j = 0; j < m; j++)
    //             cin >> g[i][j];
        
    //     cout << "Size of the largest Region: " << maxConnectedCell(g) << endl;

    // }


    return 0;
}
