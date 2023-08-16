#include <iostream>
using namespace std;

struct node {
	char alpha;
	node *left, *right;
};

constexpr size_t MAX_NODE = 1000;

int node_count = 0;
node node_pool[MAX_NODE];

node* new_node (char alpha)
{
	node_pool[node_count].alpha = alpha;
	node_pool[node_count].left = nullptr;
	node_pool[node_count].right = nullptr;
	
	return &node_pool[node_count++];
}

void inorder (node* cur)
{
	if (cur != nullptr)
	{
		inorder(cur->left);
		cout << cur->alpha;
		inorder(cur->right);
	}
}

int N, number, lt, rt; 
char alpha;

int main() 
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> number;
			if (N % 2 == 0)
			{
				if (N / 2 > number)
				{
					cin >> alpha >> lt >> rt;
					node* newNode = new_node(alpha);
					newNode->left = &node_pool[lt - 1];
					newNode->right = &node_pool[rt - 1];
				}
				else if (N / 2 == number)
				{
					cin >> alpha >> lt;
					node* newNode = new_node(alpha);
					newNode->left = &node_pool[lt - 1];
					newNode->right = nullptr;
				}
				else
				{
					cin >> alpha;
					node* newNode = new_node(alpha);
					newNode->left = nullptr;
					newNode->right = nullptr;					
				}
			}
			else
			{
				if (N / 2 >= number)
				{
					cin >> alpha >> lt >> rt;
					node* newNode = new_node(alpha);
					newNode->left = &node_pool[lt - 1];
					newNode->right = &node_pool[rt - 1];
				}
				else
				{
					cin >> alpha;
					node* node_new = new_node(alpha);
					node_new->left = nullptr;
					node_new->right = nullptr;
				}
			}
		}
		
		cout << "#" << test_case << " ";
		inorder(&node_pool[0]);
		cout << '\n';
		node_count = 0;
	}
	
	
	return 0;
}

