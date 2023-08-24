#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		priority_queue <int> pq;
		cout << "#" << test_case;
		for (int i = 0; i < N; i++) {
			int com;
			cin >> com;
			switch (com) {
			case 1 :
				int elem;
				cin >> elem;
				pq.push(elem);
				break;
			case 2 :
				if (!pq.empty()) {
					cout << " " << pq.top();
					pq.pop();
				}
				else cout << " -1";
				break;
			}
		}
		cout << "\n";
	}
	return 0;
}

