#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 101
#define MAX_K 1001
using namespace std;
 
int N, K;
int volume[MAX_N], need[MAX_N];
int dp[MAX_K][MAX_N];
 
int pack (int capacity, int item)
{
	if (item == N)	return 0;
	int& ret = dp[capacity][item];
	if (ret != -1)	return ret;
 
	ret = pack(capacity, item + 1);
	if (capacity >= volume[item])
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
 
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
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		memset(dp, -1, sizeof(dp));
		memset(volume, 0, sizeof(volume));
		memset(need, 0, sizeof(need));
 
		for (int i = 0; i < N; i++)
			cin >> volume[i] >> need[i];
 
		cout << "#" << test_case << " " << pack(K, 0) << '\n';
	}	
 
	return 0;
} 
