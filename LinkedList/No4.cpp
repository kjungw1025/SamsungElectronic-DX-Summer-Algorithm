#include<iostream>
#define MAX_NODE 10000
using namespace std;

struct Node
{
	int data;
	Node *next;
};

int node_count = 0;
Node node_pool[MAX_NODE]; // 사용할 노드 미리 정의 (메모리 풀)
Node *head; // 링크드 리스트의 헤

Node* new_node(int data) 
{
	node_pool[node_count].data = data;
	node_pool[node_count].next = nullptr;

	return &node_pool[node_count++];
}

int N, M;
int num, x, y, s;
char ch;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		head = nullptr; // 링크드 리스트 초기화
		node_count = 0; // 메모리 풀 초기화
		Node *ptr = nullptr;

		// 원본 암호문
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			Node* newNode = new_node(num);
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
		
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> ch;
			
			switch (ch)
			{
				// 삽입
				case 'I':
				{
					cin >> x >> y;
					Node *ptr = head;
					int cnt = x;
					while (cnt > 1)
					{
						ptr = ptr->next;	// x번째 위치 찾기
						cnt--;
					}
					
					for (int i = 0; i < y; i++)
					{
						cin >> s;
						Node *newNode = new_node(s);
						// x가 0이면 맨 앞에 집어 넣음
						if (i == 0 && x == 0)
						{
							newNode->next = head;
							head = newNode;
							ptr = head;
							continue;
						}
						newNode->next = ptr->next; // 새 노드의 next는 현재 노드의 next
						ptr->next = newNode; // 현재 노드의 next는 새 노드
						ptr = ptr->next; // 다음 노드 가리킴
					}
					break;
				}
				
				// 삭제 
				case 'D':
				{
					cin >> x >> y;
					Node *ptr = head;
					int cnt = x;
					while (cnt > 1)
					{
						ptr = ptr->next;	// x번째 위치 찾기
						cnt--;
					}
					for (int i = 0; i < y; i++)
					{
						if (ptr->next == nullptr)
						{
							ptr = nullptr; // 다음 노드가 없으면 현재 노드를 nullptr로 만듦
							break;
						}
						if (x == 0)
						{
							head = head->next;
							ptr = head;
							continue;
						}
						ptr->next = ptr->next->next; // 현재 노드의 next를 다음 노드의 next로 지정
					}
					break;
				}
				
				// 추가
				case 'A':
				{
					cin >> y;
					Node* ptr = head;
					
					// 맨 뒤 노드 찾기
					while (ptr->next)
						ptr = ptr->next;
						
					for (int i = 0; i < y; i++)
					{
						cin >> s;
						Node* newNode = new_node(s);
						
						ptr->next = newNode; // 맨 뒤 노드에 새 노드 추가
						ptr = ptr->next; // 다음 노드를 가리킴
					}
					break;
				}
			}
		}
	
		// 수정 후 암호문 10개 출력
		cout << "#" << test_case << " ";
		for (int i = 0; i < 10; i++)
		{
			cout << head->data << " ";
			head = head->next;
		}
		cout << '\n';
	}
	return 0;
} 
