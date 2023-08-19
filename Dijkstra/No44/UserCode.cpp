#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#define INF 0x7fffffff
#define MAX_N 605
using namespace std;

int n, cityCnt;
vector<pair<int, int>> adj[MAX_N];
vector<pair<int, int>> rev_adj[MAX_N];
unordered_map<int, int> city; // 1 ≤ 도시 ≤ 1,000,000,000 이므로, 입력되는 도시마다 id = 0부터 고유 번호 할당해줌

vector<int> dijkstra (int Value, int src, vector<pair<int, int>> adjacent[])
{
	vector<int> dist(Value + 1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, src});
	
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		
		if (dist[here] < cost)	continue;
		
		for (int i = 0; i < adjacent[here].size(); i++)
		{
			int there = adjacent[here][i].first;
			int nextDist = cost + adjacent[here][i].second;
			
			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push({-nextDist, there});
			}
		}
	}
	return dist;
}

int init(int N, int sCity[], int eCity[], int mCost[]) 
{
	city.clear();	
	for (int i = 0; i < MAX_N; i++)
	{
		adj[i].clear();
		rev_adj[i].clear();
	}
	
	n = N;
	
	int id = 0;
	for (int i = 0; i < n; i++)
	{
		int st = sCity[i];
	    int ed = eCity[i];
	    int cost = mCost[i];
		
		if (city.find(st) == city.end())
		{
			id++;
			city[st] = id;
		}
		
		if (city.find(ed) == city.end())
		{
			id++;
			city[ed] = id;
		}
		
		st = city[st];
		ed = city[ed];
		
		adj[st].push_back({ed, cost});
		rev_adj[ed].push_back({st, cost});
	}
	cityCnt = id;
	
	return id;
}

void add(int sCity, int eCity, int mCost) 
{
	int st = city[sCity];
	int ed = city[eCity];
	
	adj[st].push_back({ed, mCost});
	rev_adj[ed].push_back({st, mCost});
	return;
}

int cost(int mHub) 
{
	vector<int> home = dijkstra(cityCnt, city[mHub], adj);
	vector<int> go = dijkstra(cityCnt, city[mHub], rev_adj);
	int sum = 0;
	for (int i = 1; i <= cityCnt; i++)
	{
		if (i == city[mHub])	continue;
		sum += (go[i] + home[i]);
	}
	return sum;
}

