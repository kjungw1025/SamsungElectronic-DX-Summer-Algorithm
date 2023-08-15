#include <iostream>
#define MAX_NODE 10000
using namespace std;

struct Node 
{
	int data;
	Node *next;
};

int node_count = 0;
Node node_pool[MAX_NODE];
Node *head;

Node* new_node (int data)
{
	node_pool[node_count].data = data;
	node_pool[node_count].next = nullptr;
	
	return &node_pool[node_count++];
}

int N, M, L;
int num, x, y;
char ch;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		head = nullptr;
		node_count = 0;
		Node *ptr = nullptr;
		
		cin >> N >> M >> L;
		
		int tot_node_count = N;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			Node *newNode = new_node(num);
			if (head == nullptr)
			{
				head = newNode;
				ptr = head;
			}
			else
			{
				ptr->next = newNode;
				ptr = ptr->next;
			}
		}
		
		for (int i = 0; i < M; i++)
		{
			cin >> ch;
			
			switch (ch)
			{
				case 'I':
				{
					cin >> x >> y;
					if (x + 1 <= tot_node_count)
					{
						tot_node_count++;
						Node *ptr = head;
						Node *newNode = new_node(y);
						int cnt = x;
						if (x == 0)
						{
							newNode->next = head;
							head = newNode;
						}
						else
						{
							while (cnt > 1)
							{
								ptr = ptr->next;
								cnt--;
							}
							
							newNode->next = ptr->next;
							ptr->next = newNode;							
						}
						
					}
					break;
				}
				
				case 'D':
				{
					cin >> x;
					if (x + 1 <= tot_node_count)
					{
						Node *ptr = head;
						int cnt = x;
						if (x == 0)
						{
							head = head->next;
							ptr = head;
						}
						else
						{
							while (cnt > 1)
							{
								ptr = ptr->next;
								cnt--;
							}
							if (ptr->next == nullptr)
							{
								ptr = nullptr;
							}
							else
							{
								ptr->next = ptr->next->next;
							}
						}
						tot_node_count--;
					}
					break;
				}
				
				case 'C':
				{
					cin >> x >> y;
					if (x + 1 <= tot_node_count)
					{
						Node *ptr = head;
						int cnt = x;
						while (cnt > 0)
						{
							ptr = ptr->next;
							cnt--;
						}
						
						ptr->data = y;						
					}
					break;
				}
			}
		}
		
		Node *tmp = head;
		int cnt = L;
		while (cnt > 0)
		{
			if (tmp->next != nullptr)
			{
				tmp = tmp->next;
				cnt--;
			}
			else
			{
				break;
			}
		}
		
		if (tot_node_count < L + 1)
		{
			cout << "#" << test_case << " " << -1 << '\n';
		}
		else
		{
			cout << "#" << test_case << " " << tmp->data << '\n';
		}
	}
	return 0;
} 
