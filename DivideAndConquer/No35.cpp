// STL set 활용한게 더 성능이 좋음

// mergeSort로 구현 (최적화 안됨) : 17376kb, 1503ms, 1312B
// STL set, 구조체로 비교 연산자로 구현 : 15792kb, 1391ms, 655B

#include <iostream>
#define MAX 20005
using namespace std;

int N;
string s;
string arr[MAX];

void mergeSort(string arr[], int size)
{
	if (size == 1) return;

	int mid = size / 2;
	// mid를 기준으로 나눈 좌, 우 배열 2개를 분할
	mergeSort(arr, mid);
	mergeSort(arr + mid, size - mid);

	string* buf = new string[size];
	int i = 0, j = mid, k = 0;
	
	// 좌, 우측 배열 비교하면서 임시 buf 배열에 정렬하여 저장
	while (i < mid && j < size)
	{
		if (arr[i].size() == arr[j].size())
		{
			buf[k++] = (arr[i] < arr[j]) == true ? arr[i++] : arr[j++];
		}
		else
		{
			buf[k++] = arr[i].size() < arr[j].size() ? arr[i++] : arr[j++];
		}
	}
	// 좌측 배열만 남은 경우
	while (i < mid)
	{
		buf[k++] = arr[i++];
	}
	
	// 우측 배열만 남은 경우
	while (j < size)
	{
		buf[k++] = arr[j++];
	}
	
	// 정렬을 마친 후 arr에 저장
	for (i = 0; i < size; i++)
	{
		arr[i] = buf[i];
	}
	
	delete[] buf;
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
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> s;
			arr[i] = s;
		}
		
		mergeSort(arr, N);
		
		cout << "#" << test_case << '\n';
		for (int i = 0; i < N; i++)
		{
			if (arr[i] != arr[i + 1])
			{
				cout << arr[i] << '\n';
			}
		}
	}
	return 0;
}


// STL set, 구조체로 비교 연산자 코드

// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <set>
// using namespace std;

// int N;
// string str;

// struct cmp
// {
// 	bool operator() (const string& s1, const string& s2)
// 	{
// 		if (s1.size() == s2.size())
// 			return s1 < s2;
// 		return s1.size() < s2.size();
// 	}
// };

// int main() 
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
	
// 	int test_case;
// 	int T;
	
// 	cin >> T;
	
// 	for (test_case = 1; test_case <= T; test_case++)
// 	{
// 		cin >> N;
		
// 		set<string, cmp> s;
// 		while (N--)
// 		{
// 			cin >> str;
// 			s.insert(str);
// 		}
		
// 		cout << "#" << test_case << '\n';
// 		for (const string& result: s)
// 		{
// 			cout << result << '\n';
// 		}
// 	}
	
// 	return 0;
// } 
