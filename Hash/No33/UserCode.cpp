#include <iostream>
#include <list>
#include <string>
#include <cstring>
#define MAX_USER 1001
#define MAX_TITLE 10002
#define MAX_HASH 0x7fffffff
using namespace std;

pair<int, list<int>> user[MAX_USER];
int title[MAX_TITLE];
int substring[MAX_TITLE][11];

int n, k, titleCnt, userCnt = 0;

int hash_str (char* str, int power, int titleCnt = -1) 
{
	unsigned long long hash = 0;
	unsigned long long partHash = 0;
	
	string temp;
	int idx = 0;
	while (*str)
	{
	    if (*str == ' ')
	    {
	    	if (titleCnt != -1)
				substring[titleCnt][idx++] = partHash % MAX_HASH;
			partHash = 0;
	    }
	    else
	    {
			partHash = (partHash << power) + partHash + *str;
	    }
		hash = (hash << power) + hash + *str;
		
		str++;
	}
	if (titleCnt != -1)
		substring[titleCnt][idx++] = partHash % MAX_HASH;
	
	return hash % MAX_HASH;
}

void init(int N, int K)
{
	k = K;
	titleCnt = 0;
	
	for (int i = 0; i < userCnt; i++)
	{
		user[i].first = 0;
		user[i].second.clear();
	}
	memset(title, -1, sizeof(title));
	memset(substring, -1, sizeof(substring));
		
	userCnt = N;
}

int getCount(int uID)
{
	return user[uID].first;
}

void sendMail(char subject[], int uID, int cnt, int rIDs[])
{
	for (int i = 0; i < cnt; i++)
	{
		int recv = rIDs[i];
		int recvMailCnt = getCount(recv);
		
		if (recvMailCnt >= k)
		{
			user[recv].first--;
			user[recv].second.pop_front();
		}
		
		user[recv].first++;
		user[recv].second.push_back(titleCnt);
	}
	title[titleCnt] = hash_str(subject, 13, titleCnt);
	titleCnt++;
}

int deleteMail(int uID, char subject[])
{
	int cntDel = 0;
	int hash = hash_str(subject, 13);
	
	if (!user[uID].second.empty())
	{
		list<int>::iterator iter;
		for (iter = user[uID].second.begin(); iter != user[uID].second.end();)
		{
			int targetHash = title[*iter];
			
			if (hash == targetHash)
			{
				cntDel++;
				user[uID].first--;
				iter = user[uID].second.erase(iter);
			}
			else
				++iter;
		}
	}
	return cntDel;
}

int searchMail(int uID, char text[])
{
	int hash = hash_str(text, 13);
	
	int cntSearch = 0;
	for (int idx: user[uID].second)
	{
		for (int i = 0; i < 11; i++)
		{
			if (substring[idx][i] == hash)
			{
				cntSearch++;
				break;				
			}
		}
	}
	
	return cntSearch;
}
