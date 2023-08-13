#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define MAX 12
using namespace std;

int N, maxCon, minLen;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int arr[MAX][MAX];
vector<pair<int, int>> v;

void dfs (int idx, int len, int connect)
{
	if (idx == v.size())
	{
		if (connect > maxCon)
		{
			minLen = len;
			maxCon = connect;
		}
		else if (connect == maxCon)
			minLen = min(minLen, len);
		return;
	}
	
	for (int way = 0; way < 4; way++)
	{
		int ii = v[idx].first;
		int jj = v[idx].second;
		int cnt = 0;
		
		while (1)
		{
			ii += dy[way];
			jj += dx[way];
			cnt++;
			
			if (arr[ii][jj] == 1 || arr[ii][jj] == -1)
			{
				cnt = 0;
				break;
			}
			
			if (arr[ii][jj] == 0 && (ii == 0 || jj == 0 || ii == N - 1 || jj == N - 1))
				break;
		}
		
		if (cnt > 0)
		{
			ii = v[idx].first;
			jj = v[idx].second;
			
			while (1)
			{
				ii += dy[way];
				jj += dx[way];
				if (ii < 0 || jj < 0 || ii > N - 1 || jj > N - 1)
					break;
				arr[ii][jj] = -1;	// -1 : 전선 표시
			}
			
			dfs(idx + 1, len + cnt, connect + 1);
			
			ii = v[idx].first;
			jj = v[idx].second;
			while (1)
			{
				ii += dy[way];
				jj += dx[way];
				
				if (ii < 0 || jj < 0 || ii > N - 1 || jj > N - 1)
					break;
				arr[ii][jj] = 0;
			}
		}
	}
	dfs(idx + 1, len, connect);
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
		maxCon = 0;
		minLen = INT_MAX;
		
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				
				if (arr[i][j] == 1)
				{
					if (i == 0 || j == 0 || i == N - 1 || j == N - 1)
						continue;
					v.push_back({i, j});
				}
			}
		}
		
		dfs(0, 0, 0);
		
		cout << "#" << test_case << " " << minLen << '\n';
		
		v.clear();
	}
	
	return 0;
} 
