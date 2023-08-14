#define MAX_NODE 10000

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = getNode(-1);
}

void addNode2Head(int data)
{
	Node* cur = head;
	Node* tmp = getNode(data);
	if (cur->next == nullptr) {
		cur->next = tmp;
	}
	else {
		tmp->next = cur->next;
		cur->next = tmp;
	}
}

void addNode2Tail(int data)
{
	Node* cur = head;
	Node* tmp = getNode(data);
	if (cur->next == nullptr) {
		cur->next = tmp;
	}
	else {
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = tmp;
	}
}

void addNode2Num(int data, int num)
{
	Node* cur = head;
	while (--num) {
		if (cur->next == nullptr) break;
		cur = cur->next;
	}
	Node* tmp = getNode(data);
	tmp->next = cur->next;
	cur->next = tmp;
}

void removeNode(int data)
{
	Node* cur = head;
	while (1) {
		if (cur->next == nullptr)
			break;
		if (cur->next->data == data) {
			cur->next = cur->next->next;
			break;
		}
		cur = cur->next;
	}
}

int getList(int output[MAX_NODE])
{
	Node* cur = head;
	int idx = 0, ret = 0;
	while (1) {
		if (cur->next == nullptr) break;
		output[idx++] = cur->next->data;
		ret++;
		cur = cur->next;
	}
	return ret;
} 
