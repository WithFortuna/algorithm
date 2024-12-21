#include <iostream>
#include <stack>
using namespace std;

int N;
stack<pair<int, int>> stk;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	stk.push({ 300000000,0 });

	for (int i = 1; i <= N; i++)
	{
		int height;
		cin >> height;
		while (stk.top().first < height)
		{
			stk.pop();	//앞의 높이 중 작은 수는 필요없다(중복탐색x)
		}
		cout << stk.top().second<<" ";
		stk.push({ height,i });
	}

	return 0;
}