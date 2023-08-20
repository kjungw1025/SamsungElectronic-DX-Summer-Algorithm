#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int N, M, K;
long long answer;

long long power (long long x, long long K)
{
	long long result = 1;
	while (K != 0)
	{
		if (K & 1)
			result = (result * x) % (N + M);
		x = (x * x) % (N + M);
		K = (K >> 1);
	}
	return result;
}

int divAndCon (int K)
{
	long long result = (power(2, K) * N) % (N + M);
	return result < (N + M - result) ? result : (N + M - result);
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
		answer = 0;
		
		cin >> N >> M >> K;
		if (K == 1)
		{
			if (N < M)
				answer = min(2 * N, M - N);
			else
				answer = min(2 * M, N - M);
		}
		else
			answer = divAndCon(K);
		
		cout << "#" << test_case << ' ' << answer << '\n';
	}
	
	return 0;
} 
