#include <iostream>
#define MAX 2001
#define HASH_SIZE (1 << 30)
#define DIV (HASH_SIZE - 1)
using namespace std;

int H, W, N, M, cnt;
int studentPic[MAX][MAX], teacherPic[MAX][MAX];
int teacherHash[MAX][MAX], tmp[MAX][MAX]; // 가로 해시 값 구하고 임시로 tmp에 저장하는 용도
char a;

int GetHash (int* piv, int num, int shift)
{
    unsigned long long hash = 0;
    for (int i = 0; i < num; i++)
    	hash = (hash << shift) + hash + *piv++;
    
    return (int) (hash & DIV);
}

int CalcMul (int num, int shift)
{
	unsigned long long rev = 1;
	for (int i = 1; i < num; i++)
		rev = (rev << shift) + rev;
	return (int) (rev & DIV);
}

int GetNext (int prev, int sub, int mul, int add, int shift)
{
	unsigned long long hash = prev - (sub * mul);
	hash = (hash << shift) + hash + add;
	return (int) (hash & DIV);
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; test_case++)
	{
		cin >> H >> W >> N >> M;
		
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> a;
				if (a == 'o')
					studentPic[i][j] = 1;
				else
					studentPic[i][j] = 0;
			}
		}
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> a;
				if (a == 'o')
					teacherPic[i][j] = 1;
				else
					teacherPic[i][j] = 0;
			}
		}
		
		// 은기꺼 해시
		// 가로 해시값 구하고 나서 세로 해시값 구함
		// 서로 같은 해시 함수를 사용하면 안되므로 4, 5로 다르게 (충돌방지)
		for (int i = 0; i < H; i++)
			tmp[0][i] = GetHash(studentPic[i], W, 4);
		int myHash = GetHash(tmp[0], H, 5);
		
		// 선생님꺼 해시
		int mulC = CalcMul(W, 4);
		int mulR = CalcMul(H, 5);
		for (int i = 0; i < N; i++)
		{
			tmp[0][i] = GetHash(teacherPic[i], W, 4);
			
			for (int j = 1; j < M - W + 1; j++)
				tmp[j][i] = GetNext(tmp[j - 1][i], teacherPic[i][j - 1], mulC, teacherPic[i][j + W - 1], 4);
		}
		for (int i = 0; i < M - W + 1; i++)
		{
			teacherHash[0][i] = GetHash(tmp[i], H, 5);
			for (int j = 1; j < N - H + 1; j++)
				teacherHash[j][i] = GetNext(teacherHash[j - 1][i], tmp[i][j - 1], mulR, tmp[i][j + H - 1], 5);
		}
		
		cnt = 0;
		for (int i = 0; i < N - H + 1; i++)
			for (int j = 0; j < M - W + 1; j++)
				if (teacherHash[i][j] == myHash)
					cnt++;
		cout << "#" << test_case << " " << cnt << '\n';
	}
	
	return 0;
} 
