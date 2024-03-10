// C++ program to find minimum number of dice throws
// required to reach last cell from first cell of a given
// snake and ladder board



// number of vertices-->number of cells in the board
// reduction to shortest path in a directed graph
// each vertex have an edge to the next 6 cells+ ladder and snake
// use bfs for the shortest path



#include <iostream>
#include <queue>
using namespace std;

struct queueEntry {
	int v; 
	int dist; 
};


int getMinDiceThrows(vector<int> move, int N)
{
	
	bool* visited = new bool[N];
	for (int i = 0; i < N; i++)
		visited[i] = false;

	
	queue<queueEntry> q;

	
	visited[0] = true;
	queueEntry s
		= { 0, 0 }; 
	q.push(s); 

	// Do a BFS starting from vertex at index 0
	queueEntry qe; // A queue entry (qe)
	while (!q.empty()) {
		qe = q.front();
		int v = qe.v; // vertex no. of queue entry

		if (v == N - 1)
			break;

		q.pop();
		for (int j = v + 1; j <= (v + 6) && j < N; ++j) {
			// If this cell is already visited, then ignore
			if (!visited[j]) {
				queueEntry a;
				a.dist = (qe.dist + 1);
				visited[j] = true;

				
				if (move[j] != -1)
					a.v = move[j];
				else
					a.v = j;
				q.push(a);
			}
		}
	}
	return qe.dist;
}

int main()
{
	int N = 30;
	vector<int> moves(N);
	for (int i = 0; i < N; i++)
		moves[i] = -1;

	// Ladders
	// moves[2] = 21;
	// moves[4] = 7;
	// moves[10] = 25;
	// moves[19] = 28;

	// Snakes
	// moves[26] = 0;
	// moves[20] = 8;
	// moves[16] = 3;
	// moves[18] = 6;

	cout << "Min Dice throws required is "
		<< getMinDiceThrows(moves, 30);


	// freopen("test_cases_Q2.txt","r",stdin);
    // freopen("output_Q2.txt","w",stdout);
    // int t; cin >> t;
    // while(t--){
    //     int n; cin >> n;
    //     vector<int> a(n);
    //     for(int i=0; i<n; i++)
    //         cin >> a[i];
    //     cout << "Minimum number of throws is: "<<  getMinDiceThrows(a, n) << endl;
	// 	}
	return 0;
}


// Complexity Analysis
// Time-->O(N)
// Space-->O(N) for visited array