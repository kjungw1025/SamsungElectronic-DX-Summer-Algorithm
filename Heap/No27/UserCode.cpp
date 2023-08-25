#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_POST 100001
#define MAX 1001
using namespace std;

struct Info {
    int pID;
    int timestamp;
    int like;
    int uID;

    bool operator<(const Info& other) const {
        if (like != other.like) {
            return like < other.like; // like가 큰 순서대로 정렬
        }
        return timestamp < other.timestamp; // like가 같으면 timestamp가 큰 순서대로 정렬
    }
};

Info post[100001]; // pID별로
int connected_cnt[MAX];	// 각 유저별 팔로우한 개수 저장
int connected[MAX][MAX]; // 각 유저별 저장한 팔로우 목록 
priority_queue<Info> max_pq; // time차이가 1000미만으로 나면 여기 저장
queue<int> time_max_queue; // time차이가 1000초과라면 여기 저장
int num_post; // 추후에 getFeed 함수에서 num_post부터 역순으로 돌림

void init(int N)
{
	memset(connected_cnt, 0, sizeof(connected_cnt));
    memset(connected, 0, sizeof(connected));
    
    // 팔로우에 본인 포함하기
    for (int i = 1; i <= N; i++)
    {
        connected[i][0] = i;
        connected_cnt[i]++;
    }
	
	if (max_pq.size() > 0)
	{
		while (!max_pq.empty()) 
		{
			max_pq.pop();
		}	
	}
	
	if (time_max_queue.size() > 0) 
	{
		while (!time_max_queue.empty()) 
		{
			time_max_queue.pop();
		}	
	}
    
    for (int i = 0; i < MAX_POST; i++)
        post[i] = {0};
	
	num_post = 0;
}

void follow(int uID1, int uID2, int timestamp)
{
    int index = connected_cnt[uID1];
    connected[uID1][index] = uID2;
    connected_cnt[uID1]++;
}

void makePost(int uID, int pID, int timestamp)
{
    Info info;
    info.pID = pID;
    info.timestamp = timestamp;
    info.like = 0;
    info.uID = uID;
    
    num_post++;
	post[num_post] = info;
}

void like(int pID, int timestamp)
{
	post[pID].like++;
}

void getFeed(int uID, int timestamp, int pIDList[])
{
	max_pq = priority_queue<Info>();
    time_max_queue = queue<int>();
    bool time_gap = false; // 시간 차이가 1000초과로 나는가?
    int total = 0; // 누적으로 저장한 값이 총 몇개인가
	
	for (int i = num_post; i > 0; --i)
	{
		// time차이가 1000이상 나기 시작했는데(더 이상max_pq에 들어갈 값이 없음) 값을 10개 이상 뽑았다면
        if(time_gap == true && total > 9) 
			break;

        if(time_gap == false) // 지금 보는 곳이 1000초 차이 미만
        { 
            for(int j = 0; j < connected_cnt[uID]; j++) // uID가 팔로우중인 계정들 순회
            { 
                if(post[i].uID == connected[uID][j]) // post[i]가 follow하는 계정이 올린 게시글일때
                {
                    if(timestamp - post[i].timestamp > 1000) // time차이가 1000 초과라면 time max pq에 저장
                    {
                        time_max_queue.push(post[i].pID);
                        time_gap = true;
                        total++;
                    }
                    else // 아니라면 max_pq에 저장
                    {
                        max_pq.push(post[i]);
                        total++;
                    }
                    break;
                }
            }
        }

        else // 지금 보는곳이 1000초 차이 이상
        {
            for(int j = 0; j < connected_cnt[uID]; j++) // uID가 팔로우중인 계정들 순회
            {
                if(post[i].uID == connected[uID][j]) // post[i]가 follow하는 계정이 올린 게시글일때
                {
                    time_max_queue.push(post[i].pID);
                    total++;
                    break;
                }
            }
        }
    }
    
	int num = 0; // 지금까지 pIDList에 집어넣은 개수, 인덱스 역할

	// max_pq가 비거나 pIDList를 다 채울때까지
    while(num < 10 && !max_pq.empty())
    {
        pIDList[num++] = max_pq.top().pID;
        max_pq.pop();
    }

	// pIDList를 다 채울때까지
    while(num < 10) 
    {
        pIDList[num++] = time_max_queue.front();
        time_max_queue.pop();
    }
}

