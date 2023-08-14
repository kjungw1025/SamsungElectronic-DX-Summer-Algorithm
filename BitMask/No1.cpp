#include<iostream>
using namespace std;

int N;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int test_case;
	int T;

	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		
		int cnt = 0, chk = 0, num = N;
		while (++cnt)
		{
			num = N * cnt;
			while (num)
			{
				chk |= (1 << (num % 10));
				num /= 10;
			}
			
			if (chk == (1 << 10) - 1)
			{
				cout << "#" << test_case << " " << N * cnt << '\n';
				break;
			}
		}
	}
	return 0;
}
