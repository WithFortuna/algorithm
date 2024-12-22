#include <iostream>
#include <queue>
using namespace std;
int N;
queue<int> q;
int main()
{
	cin >> N;
	for (int i = 1;i <= N;i++)
	{
		q.push(i);
	}
	while (q.size() >= 2 )
	{
		q.pop();
		int move = q.front();
		q.pop();
		q.push(move);
	}

	cout << q.front();

	return 0;
}