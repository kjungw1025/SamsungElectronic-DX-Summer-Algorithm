#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct SegmentTree
{
	int n;
	vector<long long> tree;
	SegmentTree (const vector<long long>& array)
	{
		n = array.size();
		tree.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	
	long long init (const vector<long long>& arr, int start, int end, int node)
	{
		if (start == end)
			return tree[node] = arr[start];
		int mid = (start + end) / 2;
		return tree[node] = init(arr, start, mid, node * 2) + init(arr, mid + 1, end, node * 2 + 1);
	}
	
	long long sum (int start, int end, int node, int left, int right)
	{
		if (left > end || right < start) return 0;
		
		if (left <= start && end <= right)	return tree[node];
		
		int mid = (start + end) / 2;
		return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
	}
	
	void update (int start, int end, int node, int index, long long dif)
	{
		if (index < start || index > end)	return;
		
		tree[node] += dif;
		if (start == end)	return;
		int mid = (start + end) / 2;
		update (start, mid, node * 2, index, dif);
		update (mid + 1, end, node * 2 + 1, index, dif);
	}
	
	long long sum (int left, int right)
	{
		return sum(0, n - 1, 1, left, right);
	}
	
	void update (int index, long long newValue)
	{
		update(0, n - 1, 1, index, newValue);
	}
};

int N, Q, value, x, y, z;
vector<long long> arr;

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
		cin >> N >> Q;
		
		int weight = 1;
		while(N--)
		{
			cin >> value;
			arr.push_back(value * weight);
			weight *= -1;
		}
		
		SegmentTree result(arr);
		
		cout << "#" << test_case << " ";
		while(Q--)
		{
			cin >> x >> y >> z;
			
			if (x == 0)
			{
				if (y % 2 == 1)
				{
					long long dif = -1 * z - arr[y];
					arr[y] = -1 * z;
					result.update(y, dif);
				}
				else
				{
					long long dif = z - arr[y];
					arr[y] = z;
					result.update(y, dif);
				}
			}
			
			else if (x == 1)
			{
				if (y % 2 == 1)
					cout << -1 * result.sum(y, z - 1) << " ";
				else
					cout << result.sum(y, z - 1) << " ";
			}
			
		}
		cout << '\n';
		
		arr.clear();		
	}
	return 0;
}
