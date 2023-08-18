#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int N, M, cnt;
string str;

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
		unordered_map<string, bool> m;
		cnt = 0;
		cin >> N >> M;
		
		for (int i = 0; i < N + M; i++)
		{
			cin >> str;
			if (m[str])
				cnt++;
			else
				m[str] = true;
		}
		cout << "#" << test_case << " " << cnt << "\n";
	}
	
	return 0;
}
