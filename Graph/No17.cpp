#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 100001
using namespace std;

int N, maxLevel, parent;
int dp[MAX][20], depth[MAX];
long long result;
vector<vector<int>> graph;

int LCA (int a, int b)
{
	if (depth[a] != depth[b])
	{
		// b의 깊이가 더 깊게 설정
		if (depth[a] > depth[b])
			swap(a, b);
			
		// b를 올려서 depth 맞춰주기
		for (int i = maxLevel; i >= 0; i--)
		{
			// b의 2^i번째 조상이 a의 depth보다 크거나 같으면 계속 조상을 타고 올라감
			if (depth[a] <= depth[dp[b][i]])
				b = dp[b][i];
		}
	}
	
	int lca = a;
	/*
		a와 b가 다르다면 현재 깊이가 같으므로
		깊이를 계속 올려서 서로 다른 노드의 조상이 같아질 때까지 반복 (공통 조상 찾기)
	*/
	if (a != b)
	{
		for (int i = maxLevel; i >= 0; i--)
		{
			if (dp[a][i] != dp[b][i])
			{
				a = dp[a][i];
				b = dp[b][i];
			}
			lca = dp[a][i];
		}
	}
	
	return lca;
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
		graph.clear();
		graph.resize(N + 2);
		depth[1] = 0;
		result = 0;
		maxLevel = (int)floor(log2(MAX));
		
		for (int i = 2; i <= N; i++)
		{
			cin >> parent;
			graph[parent].push_back(i);
			graph[i].push_back(parent);
			
			depth[i] = depth[parent] + 1;
			dp[i][0] = parent;
		}
		
		for (int i = 2; i <= N; i++)
		{
			for (int j = 1; j <= maxLevel; j++)
			{
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
			}
		}
		
		for (int i = 1; i <= N; i++)
			sort(graph[i].begin(), graph[i].end());
			
		queue<int> q;
		int pre = 1;
		q.push(1);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			int lca = LCA(cur, pre);
			result += depth[cur] - depth[lca];
			result += depth[pre] - depth[lca];
			
			pre = cur;
			for (int i = 0; i < graph[cur].size(); i++)
			{
				if (depth[graph[cur][i]] > depth[cur])
				{
					q.push(graph[cur][i]);
				}
			}
		}
		
		cout << "#" << test_case << " " << result << '\n';
	}
	
	return 0;
}
