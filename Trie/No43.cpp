#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define ALPHABETS 26
using namespace std;

int K, cnt, flag;
vector<char> result;

int toNumber (char ch)	{ return ch - 'a'; }
struct TrieNode {
	TrieNode* children[ALPHABETS];
	
	TrieNode()
	{
		memset(children, 0, sizeof(children));
	}
	
	~TrieNode()
	{
		for (int i = 0; i < ALPHABETS; i++)
			if (children[i])
				delete children[i];
	}
	
	void insert (const char* key, int st, int ed)
	{
		if (st == ed)	return;
		int next = toNumber(key[st]);
		if (children[next] == NULL)	
			children[next]	= new TrieNode();
		children[next]->insert(key, st + 1, ed);
	}
	
	void find (TrieNode *root)
	{
		if (cnt == K)
		{
			flag = 1;
			return;
		}
		
		for (int i = 0; i < ALPHABETS; i++)
		{
			if (root->children[i])
			{
				result.push_back(i + 'a');
				cnt++;
				find(root->children[i]);
				if (flag)	return;
				result.pop_back();
			}
		}
	}
};

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
		char arr[405];
		result.clear();
		cnt = flag = 0;
		
		cin >> K >> arr;
		int len = strlen(arr);
		
		TrieNode* root = new TrieNode();
		for (int i = 0; i < len; i++)
			root->insert(arr, i, len);
			
		root->find(root);
		
		if (result.size())
		{
            cout << "#" << test_case << " ";
			for (int i = 0; i < result.size(); i++)
				cout << result[i];
			cout << '\n';
		}
		else
		{
			cout << "#" << test_case << " none" << '\n';
		}
	}
	
	return 0;
} 
