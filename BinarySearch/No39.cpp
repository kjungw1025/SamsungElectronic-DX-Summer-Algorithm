#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, M, value;
vector<long long> candies;

long long binarySearch (long long largetNumberOfCandy)
{
	// long long leastNumberOfCandy = candies[0];
	// 가장 작은 캔디 수를 기준으로 하면 안되는 이유 :
	// 가장 작은 캔디를 사용하지 않고 그보다 더 많은 개수로 M 조건을 충족할 수 있는 예외가 존재함
	long long st = 1, ed = largetNumberOfCandy;
	long long answer = 0;
	
	while (ed >= st)
	{
		long long mid = st + (ed - st) / 2;
		long long cnt = 0;
		
		for (int i = 0; i < candies.size(); i++)
		{
			cnt += (candies[i] / mid);
		}
		
		if (cnt < M)
			ed = mid - 1;
		else
		{
			answer = mid;
			st = mid + 1;
		}
	}
	return answer;
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
		cin >> N >> M;
		while (N--)
		{
			cin >> value;
			candies.push_back(value);
		}
		
		sort(candies.begin(), candies.end());
		
		cout << "#" << test_case << " " << binarySearch(candies[candies.size() - 1]) << '\n';
		
		candies.clear();
	}
	
	return 0;
}
