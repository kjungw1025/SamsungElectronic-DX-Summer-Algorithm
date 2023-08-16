#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
struct node {
    string data;
    int leftNode, rightNode;
};
 
int N, answer;
node arr[1001];
 
bool isOper(string s) 
{
    if (s == "+" || s == "-" || s == "*" || s == "/") return true;
    return false;
}
 
double calculate(double a, string oper, double b) 
{
    double output = 0;
    if (oper == "+") output = a + b;
    else if (oper == "-") output = a - b;
    else if (oper == "*") output = a * b;
    else output = a / b;
    return output;
}
 
double postOrder(int idx) 
{
    if (!isOper(arr[idx].data)) return stoi(arr[idx].data);
 
    double ret = 0;
    ret = calculate(postOrder(arr[idx].leftNode), arr[idx].data, postOrder(arr[idx].rightNode));
    return ret;
}
 
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    for (int test_case = 1; test_case <= 10; test_case++) 
    {
        for (int i = 0; i < 1001; i++) arr[i] = { "",0,0 };
        answer = 0;

        cin >> N;
        for (int i = 0; i < N; i++) 
        {
            int idx;
            string data;
            cin >> idx >> data;
            arr[idx].data = data;
            if (isOper(data)) 
            {
                int leftNode, rightNode;
                cin >> leftNode >> rightNode;
                arr[idx].leftNode = leftNode, arr[idx].rightNode = rightNode;
            }
        }
 
        answer = postOrder(1);
 
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
} 
