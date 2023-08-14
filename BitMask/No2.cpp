#include<iostream>
using namespace std;
 
int N, M;
 
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
		cin >> N >> M;
 
		bool flag = true;
		for (int i = 0; i < N; i++)
		{
			if (!(M & (1 << i)))
			{
				flag = false;
				break;
			}
		}
 
		if (flag)
			cout << "#" << test_case << " " << "ON" << '\n';
		else
			cout << "#" << test_case << " " << "OFF" << '\n';
	}
	return 0;
} 
