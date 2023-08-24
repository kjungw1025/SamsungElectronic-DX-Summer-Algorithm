#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define MAX 105
using namespace std;

int N;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int dp[MAX][MAX];
int board[MAX][MAX];
bool visited[MAX][MAX];
string str;

int bfs ()
{
	queue<pair<int, int>> q;
	
	dp[0][0] = 0;
	visited[0][0] = true;
	
	q.push({0, 0});
	
	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		
		for (int way = 0; way < 4; way++)
		{
			int ii = i + dy[way];
			int jj = j + dx[way];
			
			if (ii >= 0 && jj >= 0 && ii < N && jj < N)
			{
				if (!visited[ii][jj] || dp[i][j] + board[ii][jj] < dp[ii][jj])
				{
					dp[ii][jj] = dp[i][j] + board[ii][jj];
					visited[ii][jj] = true;
					q.push({ii, jj});
				}				
			}
		}
	}
	return dp[N - 1][N - 1];
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; test_case++)
	{
		memset(board, 0, sizeof(board));
		memset(dp, 0, sizeof(dp));
		memset(visited, false, sizeof(visited));
		
		cin >> N;
		
		for (int i = 0; i < N; i++)
		{
			cin >> str;
			for (int j = 0; j < N; j++)
				board[i][j] = str[j] - '0';
		}
		
		cout << "#" << test_case << " " << bfs() << '\n';
	}
	
	return 0;
} 
