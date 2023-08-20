#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

int N, M, c1, c2, c;
vector<int> cows;

int binarySearch (int value)
{
	int st = 0, ed = cows.size() - 1;
	int mid = (st + ed) / 2;
	
	if (value < cows[st])
		return 0;
	if (value > cows[ed])
		return cows.size() - 1;
		
	while (st <= ed)
	{
		mid = (st + ed) / 2;
		
		if (cows[mid] == value)
			return mid;
		else if (cows[mid] < value)
			st = mid + 1;
		else
			ed = mid - 1;
	}
	
	if (cows[mid] < value)
		mid++;
		
	return mid;
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
		cin >> N >> M;
		cin >> c1 >> c2;
		int dx = abs(c1 - c2);
		
		for (int i = 0; i < N; i++)
		{
			cin >> c;
			cows.push_back(c);
		}
		sort(cows.begin(), cows.end());
		
		int min = INT_MAX;
		int count = 0;
		
		for (int i = 0; i < M; i++)
		{
			int horse;
			cin >> horse;
			int cIdx = binarySearch(horse);
			
			if (0 <= cIdx && cIdx < N)
			{
				int cow = cows[cIdx];
				int dz = abs(cow - horse);
				
				if (min > dz)
				{
					min = dz;
					count = 1;
				}
				else if (min == dz)
					count++;
			}
			
			if (0 < cIdx && cIdx < N && cows[cIdx] != horse)
			{
				int cow = cows[cIdx - 1];
				int dz = abs(cow - horse);
				
				if (min > dz)
				{
					min = dz;
					count = 1;
				}
				else if (min == dz)
					count++;
			}
		}
		
		cout << "#" << test_case << " " << dx + min << " " << count << '\n';
		 
		cows.clear();
	}
	
	return 0;
} 
