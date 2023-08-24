#include <iostream>
#include <queue>
#include <vector>
#define MAX 11
using namespace std;

int N, K, result;
int arr[MAX];

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
			cin >> arr[i];
		cin >> K;
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, K});
		
		while (pq.top().second)
		{
			pair<int, int> cur = pq.top();
			pq.pop();
			
			pq.push(make_pair(cur.first + cur.second, 0));
			for (int i = 0; i < N; i++)
				pq.push({cur.first + cur.second % arr[i], cur.second / arr[i]});
		}
		result = pq.top().first;
		
		cout << "#" << test_case << " " << result << '\n';
	}
	
	return 0;
} 
