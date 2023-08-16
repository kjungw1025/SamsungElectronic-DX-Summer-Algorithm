#include <iostream>
using namespace std;

int N, num, lt, rt;
char ch;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		cin >> N;
		
		int answer = 1;
		for (int i = 1; i <= N; i++)
		{
			cin >> num >> ch;
			
			if (N / 2 < num)
			{
				if (!(ch >= '0' && ch <= '9'))	answer = 0;
			}
			else
			{
				if (i == N / 2 && N % 2 == 0)
					cin >> lt;
				else
					cin >> lt >> rt;
					
				if (ch >= '0' && ch <= '9')	answer = 0;
			}
		}
		
		cout << "#" << test_case << ' ' << answer << '\n';
	}
	
	return 0;
} 
