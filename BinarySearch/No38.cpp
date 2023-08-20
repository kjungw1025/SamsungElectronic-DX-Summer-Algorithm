#include <iostream>
#include <cmath>
using namespace std;

long long N;

int check(long long x, long long N)
{
	if (((x * x) + x) == N)
		return 1;
	else if (((x * x) + x) > N)
		return -1;
	else
		return 0;
}

long long binarySearch(long long N)
{
	long long start = 1;
	long long end = sqrt(N);	// 2N 값을 받으므로 end는 루트 2N임
	long long mid;
	long long value = 0;
	
	while (start <= end)
	{
		mid = (start + end) / 2;
		int flag = check(mid, N);
		
		if (flag == 1)	return mid;
		
		else if (flag == -1)
			end = mid - 1;
		
		else
			start = mid + 1;
	}
	return - 1;
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
		N *= 2;
		cout << "#" << test_case << " " << binarySearch(N) << '\n';
	}
	
	return 0;
}
