#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
string H, N;
 
vector<int> getPartialMatch (const string &N)
{
	int m = N.size();
	vector<int> pi(m, 0);
 
	int begin = 1, matched = 0;
	while (begin + matched < m)
	{
		if (N[begin + matched] == N[matched])
		{
			++matched;
			pi[begin + matched - 1]	= matched;
		}
		else
		{
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
 
int kmpSearch (const string& H, const string& N)
{
	int n = H.size(), m = N.size();
	vector<int> pi = getPartialMatch(N);
 
	int cnt = 0;
	int begin = 0, matched = 0;
	while (begin <= n - m)
	{
		if (matched < m && H[begin + matched] == N[matched])
		{
			++matched;
			if (matched == m)
				++cnt;
		}
		else
		{
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return cnt;
}
 
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int test_case;;
	int T;
 
	cin >> T;
 
	for (test_case = 1; test_case <= T; test_case++)
	{
		cin >> H >> N;
 
		cout << "#" << test_case << " " << kmpSearch(H, N) << '\n';
	}
 
	return 0;
}
