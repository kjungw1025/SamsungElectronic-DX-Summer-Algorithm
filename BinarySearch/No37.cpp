#include <iostream>
#include <vector>
#define MAX 200001
using namespace std;

int n, p, day, maxPeriod;
int days[MAX];
vector<int> blanks;

int binarySearch (int n, int p)
{
	for (int i = 0; i < n; i++)
	{
		int start = i, end = n - 1;
		int answer = 0;
		while (end >= start)
		{
			int mid = start + (end - start) / 2;
			int notStudying = 0, curP = p;
			notStudying = blanks[mid] - blanks[i];
			
			curP = (p - notStudying > 0) ? p - notStudying : 0;
			
			if (notStudying > p)
				end = mid - 1;
			else
			{
				answer = days[mid] - days[i] + 1 + curP;
                // 1 ≤ n, p ≤ 200,000 즉, p는 1이상이므로 + 1을 해줌
				start = mid + 1;
			}
		}
		if (maxPeriod < answer)
			maxPeriod = answer;
	}
	return maxPeriod;
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
		cin >> n >> p;
		
		for (int i = 0; i < n; i++)
		{
			cin >> day;
			days[i] = day;
		}
		
		int blankSum = 0;
		blanks.clear();
		blanks.push_back(0);
		
		for (int i = 0; i < n - 1; i++)
		{
			// blankSum에 현재의 날짜와 그 다음 날짜 사이의 공백을 누적한 후,
			// blanks vector에 삽입
			blankSum += days[i + 1] - days[i] - 1;
			blanks.push_back(blankSum);
		}
		
		cout << "#" << test_case << " " << binarySearch(n, p) << '\n';
		maxPeriod = 0;
	}
	
	return 0;
}
