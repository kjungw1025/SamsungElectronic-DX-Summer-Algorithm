#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, A, value, result = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int test_case;
	int T;
	
	cin >> T;
	for (test_case = 1; test_case <=  T; test_case++)
	{
		priority_queue<int, vector<int>, less<int>> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;
		result = 0;
		
		cin >> N >> A;
		maxHeap.push(A);
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> value;
				
				if (maxHeap.size() == minHeap.size())
					maxHeap.push(value);
				else
					minHeap.push(value);
					
				if (!maxHeap.empty() && !minHeap.empty() && minHeap.top() < maxHeap.top())
				{
					int a = maxHeap.top(), b = minHeap.top();
					maxHeap.pop(); minHeap.pop();
					maxHeap.push(b);
					minHeap.push(a);
				}
				
			}
			result += maxHeap.top();
            result %= 20171109;
		}
		cout << "#" << test_case << " " << result << '\n';
	}
	
	return 0;
} 
