#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Comparator
{
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {}
 
	bool operator() (int a, int b)
	{
		if(group[a] != group[b])
			return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

vector<int> getSuffixArray (const string& s)
{
	int n = s.size();
	int t = 1;
	
	vector<int> group(n + 1);
	for (int i = 0; i < n; i++)	group[i] = s[i];
	group[n] = -1;
	
	vector<int> perm(n);
	for (int i = 0; i < n; i++)
		perm[i] = i;
		
	while (t < n)
	{
		Comparator compareUsing2T = Comparator(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		
		t *= 2;
		if (t >= n)	break;
		
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		}
		group = newGroup;
	}
	
	return perm;
}

string s;
int K;

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
		cin >> K;
		cin >> s;
		
		vector<int> arr = getSuffixArray(s);
		if (arr.size() < K)
			cout << "#" << test_case << " none" << '\n';
		else
		{
			cout << "#" << test_case << " " << s.substr(*(arr.begin() + K - 1))<< '\n';
		}
	}
	
	return 0;
}
