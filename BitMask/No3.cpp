#include <iostream>
#include <cstring>
#include <string>
#define MAX 10001
#define MOD 1000000007
using namespace std;

int result;
int dp[MAX][16];

// 첫 번째 날에는 A가 열쇠를 가지고 있다!
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
		string str;
		cin >> str;
		
		result = 0;
		memset(dp, 0, sizeof(dp));
		
		for (int day = 0; day < str.size(); day++)
		{
			int master = 1 << (str[day] - 'A');
			
			// 아무도 참여를 하지 않는 경우는 제외하므로 j = 1부터
			for (int j = 1; j < 16; j++)
			{
				if (day == 0)
				{
					// j번째 경우에 관리자와 A가 포함된다면
					if (((master & j) != 0) && ((j & 1) != 0))
						dp[day][j] = 1;
				}
				else
				{
					// 전날(day - 1)까지의 경우의 수가 0이 아니라면 
                    if (dp[day - 1][j] != 0)
                    {
                    	for (int k = 1; k < 16; k++)
						{
							// k번째 경우에 관리자가 있고(master & k != 0) 
							// 전날(day - 1)에 있던 사람이 다음날(day)에도 있는 경우(j & k != 0) 
							if (((master & k) != 0) && ((j & k) != 0))
							{
								dp[day][k] += dp[day - 1][j];
								dp[day][k] %= MOD;
							}
						}	
                    }
				}
			}
		}
		
		for (int i = 1; i < 16; i++)
		{
			result += dp[str.size() - 1][i];
			result %= MOD;
		}
		
		cout << "#" << test_case << " " << result << '\n';
	}
	return 0;
} 
