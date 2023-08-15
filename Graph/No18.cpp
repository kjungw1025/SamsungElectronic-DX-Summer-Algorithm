#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 1005
using namespace std;

int N;
int parent[MAX];
double E;
long long x, y;
vector<long long> xPos;
vector<long long> yPos;
vector<pair<long long, double>> adj[MAX];

struct UnionFind
{
	int getParent(int x)
	{
		if (parent[x] == x)	return x;
		return parent[x] = getParent(parent[x]);
	}
	
	void unionParent(int a, int b)
	{
		a = getParent(a);
		b = getParent(b);
		
		if (a < b)	parent[b] = a;
		else	parent[a] = b;
	}
	
	int findParent(int a, int b)
	{
		a = getParent(a);
		b = getParent(b);
		
		if (a == b)	return 1;
		else	return 0;
	}
};

double kruskal ()
{
	double ret = 0;
	
	vector<pair<double, pair<int, int>>> edges;
	for (int u = 1; u <= N; u++)
	{
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first;
			double cost = adj[u][i].second;
			edges.push_back({cost, {u, v}});	
		}
	}
	
	sort(edges.begin(), edges.end());
	
	UnionFind uf;
	for (int i = 0; i < edges.size(); i++)
	{
		double cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		
		if (uf.findParent(u, v))
			continue;
		
		uf.unionParent(u, v);
		ret += cost;
	}
	return ret;
}

int main()
{
	int test_case;
	int T;

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		xPos.clear();
		yPos.clear();
		
		for (int i = 0; i < MAX; i++)
			adj[i].clear();		
		
		cin >> N;
		
		for (int i = 1; i <= N; i++)
			parent[i] = i;
		
		for (int i = 0; i < N; i++)
		{
			cin >> x;
			xPos.push_back(x);
		}
		
		for (int i = 0; i < N; i++)
		{
			cin >> y;
			yPos.push_back(y);
		}
		
		cin >> E;
		for (int i = 1; i <= N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				if (i != j)
				{
					double w = E * (pow(xPos[i - 1] - xPos[j - 1], 2) + pow(yPos[i - 1] - yPos[j - 1], 2));
					adj[i].push_back({j, w});
					adj[j].push_back({i, w});
				}
			}
		}
		
		cout << "#" << test_case << " " << (long long)(round(kruskal())) << '\n';
	}
	return 0;
}

