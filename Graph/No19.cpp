#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_V 50001
using namespace std;

int V, E, u, v, w;
int parent[MAX_V];
vector<pair<int, int>> adj[MAX_V];

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

int kruskal()
{
	int ret = 0;
	
	vector<pair<int, pair<int, int>>> edges;
	for (int u = 1; u <= V; u++)
	{
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back({cost, {u, v}});
		}
	}
	
	sort(edges.begin(), edges.end());
	UnionFind uf;
	
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int test_case;
	int T;
	
	cin >> T;
	
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> V >> E;
	
		for (int i = 1; i <= V; i++)
			parent[i] = i;
			
		for (int i = 0; i < MAX_V; i++)
			adj[i].clear();
		
		while (E--)
		{
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
		}
		
		cout << "#" << test_case << " " << kruskal() << '\n';
	}
	
	return 0;
}

