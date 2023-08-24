typedef struct node{
	int money;
	int id;
}Node;

Node heap[11] ;
int heap_idx;
void init()
{
	for (int i = 0; i < 11; i++) {
		heap[i].id = 0;
		heap[i].money = 0;
	}
	heap_idx = 0;
}
bool priority(Node a, Node b) {
	if (a.money == b.money) {
		return a.id < b.id;
	}
	return a.money > b.money;
}
void adjust(int idx) {
	while (idx/2 > 0 && priority(heap[idx], heap[idx/2])) {
		Node tmp = heap[idx / 2];
		heap[idx / 2] = heap[idx];
		heap[idx] = tmp;
		idx = idx / 2;
	}
}

Node heap_pop(Node heap[],int _idx){
	Node ret = heap[1];
	heap[1] = heap[_idx--];
	int cur = 1,child=1;
	while ((cur*2) <= _idx ) {
		if (priority(heap[cur * 2], heap[cur * 2 + 1])) {
			child = cur * 2;
		}
		else 
			child = cur * 2 + 1;
		
		if (priority(heap[child], heap[cur])) {
			Node tmp = heap[cur];
			heap[cur] = heap[child];
			heap[child] = tmp;
			cur = child;
		}
		else break;
	}
	return ret;
}

void addUser(int uID, int income)
{
	
	if (heap_idx < 10) {
		heap[++heap_idx].id = uID;
		heap[heap_idx].money = income;
		adjust(heap_idx);
	}
	else {
		int thres = 987654321, thres_id=0,thres_idx = 0;
		for (int i = 1; i <= heap_idx; i++) {
			if (thres >= heap[i].money) {
				if (thres == heap[i].money) {
					if (thres_id > heap[i].id)
						continue;
				}
				thres = heap[i].money;
				thres_id = heap[i].id;
				thres_idx = i;
			}
		}

		if (income <= thres)
			return;
		heap[thres_idx].id = uID;
		heap[thres_idx].money = income;
		
		adjust(thres_idx);
	}	

}

int getTop10(int result[10])
{
	int T = heap_idx;
	Node tmp_heap[11] = { 0 };
	for (int i = 1; i <= T; i++) {
		tmp_heap[i] = heap[i];
	}
	int sum = 0;
	for (int i = 0; i < T; i++) {
		Node res = heap_pop(tmp_heap,T-i);
		result[i] = res.id;
		sum += result[i];
	}
	
	return T;
} 
