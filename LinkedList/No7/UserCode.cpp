#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
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
		tmp->prev = cur;
	}
	else {
		tmp->prev = cur;
		cur->next->prev = tmp;
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
		tmp->prev = cur;
	}
	else {
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = tmp;
		tmp->prev = cur;
	}

}

void addNode2Num(int data, int num)
{
	Node* cur = head;
	Node* tmp = getNode(data);
	while (--num) {
		if (cur->next == nullptr) break;
		cur = cur->next;
	}
	tmp->next = cur->next;
	if (tmp->next != nullptr)
		tmp->next->prev = tmp;
	cur->next = tmp;
	tmp->prev = cur;

}

int findNode(int data)
{
	Node* cur =head;
	int num=0;
	while (1) {
		cur = cur->next;
		num++;
		if (cur->data == data) {
			return num;
		}
	}
}

void removeNode(int data)
{
	Node* cur = head;
	while (1) {
		if (cur->next == nullptr)
			break;
		else if (cur->next->data == data) {
			Node* erase = cur->next;
			cur->next = cur->next->next;
			if (cur->next != nullptr)
				cur->next->prev = cur;
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

int getReversedList(int output[MAX_NODE])
{
	Node* cur = head;
	int idx = 0, ret = 0;
	while (1) {
		if (cur->next == nullptr) break;
		cur = cur->next;
	}
	while (1) {
		output[idx++] = cur->data;
		ret++;
		cur = cur->prev;
		if (cur->prev == nullptr) break;
	}
	return ret;
} 

