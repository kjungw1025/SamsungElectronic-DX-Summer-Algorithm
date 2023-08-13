#include <iostream>
#include <cstring>
#include <queue>
#define MAX 305
using namespace std;

int N, cnt;
int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
char board[MAX][MAX];

bool checkNoMine (int i, int j)
{
	for (int way = 0; way < 8; way++)
	{
		int ii = i + dy[way];
		int jj = j + dx[way];
		
		if (ii < 0 || jj < 0 || ii > N - 1 || jj > N - 1)
			continue;
		
		if (board[ii][jj] == '*')
			return false;
	}
	return true;
}

void bfs (int i, int j)
{
	// board[][] = 'N' : 주변(8곳 모두)에 폭탄이 없고, 이미 방문했다는 의미
	// board[][] = 'Y' : 주변에 폭탄이 존재하고, 이미 방문했다는 의미 
	queue<pair<int, int>> q;
	q.push({i, j});
	
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		board[y][x] = 'N';
		
		for (int way = 0; way < 8; way++)
		{
			int yy = y + dy[way];
			int xx = x + dx[way];
			
			if (yy < 0 || xx < 0 || yy > N - 1 || xx > N - 1)	
				continue;
			
			if (board[yy][xx] == 'N' || board[yy][xx] == 'Y')
				continue;
			
			if (!checkNoMine(yy, xx))
				board[yy][xx] = 'Y';
			else
			{
				board[yy][xx] = 'N';
				q.push({yy, xx});
			}
		}
	}
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
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> board[i][j];
				
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == '.' && checkNoMine(i, j))
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (board[i][j] == '.')
					cnt++;
		
		cout << "#" << test_case << " " << cnt << '\n';
		cnt = 0;
	}
	
	return 0;
}

