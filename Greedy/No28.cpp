#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 3001
#define MAX_M 101
using namespace std;

int N, M;
int arr_n[MAX_N], arr_m[MAX_M];
int dp[MAX_N][MAX_M][MAX_M][2];

// dp[nidx][midx][skip][get]
// nidx : N 봉지의 과자 중, nidx번 째를 보고 있는 상태
// midx : M 봉지의 과자 중, 고른 과자의 수
// skip : M 봉지 중 스킵한 개수
// get : 위 상태일 때 바로 직전에 과자를 get 했는지 (했으면 1, 아니면 0)
int func (int nidx, int midx, int skip, int get)
{
	if (nidx == N && midx + skip == M)	return 0;
	
	int &ret = dp[nidx][midx][skip][get];
	if (ret != -1)	return ret;
	
	ret = 0;
	
	if (get == 0)	// 고르지 않은 경우
	{
		if (nidx < N)	// N 봉지를 다 고르지 않은 상태이라면
		{
			ret = max(ret, func(nidx + 1, midx, skip, 1) + arr_n[nidx]);	// 고르거나
			ret = max(ret, func(nidx + 1, midx, skip, 0)); 	// 고르지 않거나
		}
		
		if (midx + skip < M)	// M 봉지를 다 고르지 않은 상태라면 
		{
			ret = max(ret, func(nidx, midx + 1, skip, 1) + arr_m[midx]);	// 고르거나
			ret = max(ret, func(nidx, midx, skip + 1, 0));	// 고르지 않거나
		}
	}
	else	// 이미 고른 경우 -> 어디를 스킵할지
	{
		if (nidx < N)	// N 봉지를 다 고르지 않은 상태 일 때
			ret = max(ret, func(nidx + 1, midx, skip, 0));	// 고르지 않거나
		if (midx + skip < M)	// M 봉지를 다 고르지 않은 상태 일 때 
			ret = max(ret, func(nidx, midx, skip + 1, 0));	// 고르지 않거나 
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
	for (test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr_n[i];
		
		cin >> M;
		for (int i = 0; i < M; i++)
			cin >> arr_m[i];
			
		sort(arr_m, arr_m + M, greater<int>());
		
		memset(dp, -1, sizeof(dp));
		
		cout << "#" << test_case << " " << func(0, 0, 0, 0) << '\n';
	}
	
	return 0;
} 
