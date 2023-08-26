#include <iostream>
#include <cstring>
#define MAX 50005
#define HASH_SIZE (1 << 15)
using namespace std;

struct Node {
	int idx;
	Node* prev;
	Node* next;
	
	Node* init(int _idx, Node* _prev, Node* _next)
	{
		idx = _idx;
		prev = _prev;
		next = _next;
		
		if (_next) 
			_next->prev = this;
		if (_prev)
			_prev->next = this;
			
		return this;
	}
	
} node[MAX];

char str[MAX];
int N;
Node hashTable[HASH_SIZE];

int getHash(char* A)
{
	int hash = *A++ - 'a';
	hash = (hash << 5) + (*A++ - 'a');
	hash = (hash << 5) + (*A - 'a');
	return hash;
}

int getPrev(int hash, char *A) 
{
    hash = hash >> 5;
    hash += (*A - 'a') << 10;

    return hash;
}

int getNext(int hash, char *A)
{
	hash &= (1 << 10) - 1;
	hash = (hash << 5) + (*(A + 3) - 'a');
	
	return hash;
}

void inputHash (Node* nd, int hash)
{
	Node* pivot = &hashTable[hash];
	
	while (pivot->next)
	{
		if (pivot->next->idx > nd->idx)
			break;
		pivot = pivot->next;
	}
	
	nd->next = pivot->next;
	pivot->next = nd;
	nd->prev = pivot;
	
	if (nd->next)
		nd->next->prev = nd;
}

void init(int N, char init_string[])
{
	::N = N;
	strcpy(str, init_string);
	
	for (int i = 0; i < HASH_SIZE; i++)
		hashTable[i].init(-1, nullptr, nullptr);
	
	int hash = getHash(init_string + N - 3);
	hashTable[hash].next = node[N - 3].init(N - 3, &hashTable[hash], hashTable[hash].next);
	
	for (int i = N - 4; i >= 0; i--)
	{
		hash = getPrev(hash, &init_string[i]);
		hashTable[hash].next = node[i].init(i, &hashTable[hash], hashTable[hash].next);
	}
}

int change(char A[], char B[])
{
	int hashA = getHash(A);
	
	Node *pivot = hashTable[hashA].next;
    hashTable[hashA].next = nullptr;
    int prevIdx = -3;
    
    int cnt = 0;
    while (pivot) 
    {
        pivot->prev = nullptr;
        if(prevIdx + 3 > pivot->idx) 
        {
            Node* tmp = pivot->next;
            inputHash(pivot, hashA);
            pivot = tmp;
            continue;
        }
        
        cnt++;
        prevIdx = pivot->idx;
        str[pivot->idx] = B[0];
        str[pivot->idx+1] = B[1];
        str[pivot->idx+2] = B[2];
        Node* tmp = pivot->next;
        while(tmp && prevIdx + 3 > tmp->idx) 
        {
            tmp = tmp->next;
        }
        
        int hash = -1;
        for(int i = pivot->idx - 2; i <= pivot->idx + 2; i++) 
        {
            if(i < 0) 
            	continue;
            else if(i == N - 2) 
            	break;
            	
            if(hash == -1) 
            	hash = getHash(str + i);
            else 
            	hash = getNext(hash, str + i - 1);

            if(node[i].prev) node[i].prev->next = node[i].next;
            if(node[i].next) node[i].next->prev = node[i].prev;
            Node* aa = &hashTable[33];

            inputHash(node + i, hash);
        }
        pivot = tmp;
    }

    return cnt;
}

void result(char ret[])
{
	strcpy(ret, str);
}

