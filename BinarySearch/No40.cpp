#include <iostream>
#define MAX 100001
using namespace std;

int L, N, st, ed, mid, answer = 0;
int s[MAX], e[MAX];

bool check(int K)
{
	int first = 0, last = 0;
	int peakTime = 0, totalTime = 0;
	
	while (true)
	{
		if (peakTime + (e[last] - s[last]) >= K)
		{
			if (totalTime + (K - peakTime) <= L)
				return true;
			else
			{
				peakTime -= (e[first] - s[first]);
				totalTime -= (s[first + 1] - s[first]);
				first++;
			}
		}
		else
		{
			if (last == N - 1)
				return false;
			peakTime += (e[last] - s[last]);
			totalTime += (s[last + 1] - s[last]);
			last++;
		}
	}
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
		cin >> L >> N;
		
		for (int i = 0; i < N; i++)
			cin >> s[i] >> e[i];
		
		st = 1, ed = L;
		
		while (ed >= st)
		{
			mid = (st + ed) / 2;
			
			if (check(mid))
			{
				answer = mid;
				st = mid + 1;
			}
			else
				ed = mid - 1;
		}
		
		cout << "#" << test_case << " " << answer << '\n';
		answer = 0;
	}
	
	return 0;
} 
