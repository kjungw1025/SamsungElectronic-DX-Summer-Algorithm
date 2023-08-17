#include <iostream>
#define MAX_V 10001
using namespace std;

struct Node {
	int parent, left, right;	
};

Node tree[MAX_V];
bool visited[MAX_V];
int V, E, targetNode1, targetNode2;
int parent, child, cur;

int dfs (int cur)
{
	int ans = 1;
	
	if (tree[cur].left != 0)
		ans += dfs(tree[cur].left);
	
	if (tree[cur].right != 0)
		ans += dfs(tree[cur].right);
	
	return ans;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int test_case;
	int T;

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < MAX_V; i++)
		{
			tree[i].parent = 0;
			tree[i].left = 0;
			tree[i].right = 0;
			visited[i] = false;
		}
		
		cin >> V >> E >> targetNode1 >> targetNode2;
		// E개의 간선 정보
		for (int i = 0; i < E; i++)
		{
			cin >> parent >> child;
			
			// 아직 왼쪽 자식이 존재하지 않는 경우
			if (tree[parent].left == 0)
				tree[parent].left = child;
			// 오른쪽 자식으로 표시
			else
				tree[parent].right = child;
				
			tree[child].parent = parent;
		}
		
		cur = tree[targetNode1].parent;
		while (1)
		{
			visited[cur] = true;
			
			// root 노드에 도달한 경우
			if (cur == 1)	break;
			
			// 부모 노드 거슬러 올라가기
			cur = tree[cur].parent;
		}
		
		cur = tree[targetNode2].parent;
		while (1)
		{
			// targetNode1 조상 노드 탐색 과정에서 방문한 곳인 경우
			if (visited[cur])
			{
				// 처음으로 중복 방문 되는 곳이 가장 가까운 공통 조상
				// 해당 노드를 기준으로 서브트리 크기 조사
				cout << "#" << test_case << " " << cur << " " << dfs(cur) << '\n';
				break;
			}
			cur = tree[cur].parent;
		}
	}	
	
	return 0;
} 
