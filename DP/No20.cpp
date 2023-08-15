#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int dp[1001][1001];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int test_case;
	int T;

	cin >> T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(dp, 0, sizeof(dp));
		
	    string a, b;
	
	    cin >> a >> b;
	    for (int i = 1; i <= a.length(); i++) {
	        for (int j = 1; j <= b.length(); j++) {
	            if (a[i - 1] == b[j - 1]) {
	                dp[i][j] = dp[i - 1][j - 1] + 1;
	            }
	            else {
	                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	            }
	
	        }
	    }
	
	    cout << "#" << test_case << " " << dp[a.length()][b.length()] << '\n';
	}

    return 0;
} 
