#include <iostream>
#include <string>
#include <queue>
using namespace std;
//pop: 수를 빼고 출력하기로 한다. 없다면 -1을 출력해야함
//empty: 비어있으면 1, 아니면 0
//front, back모두 없다면 -1을 출력
//push, size
int N;
queue<int> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	while (N--)
	{
		string inst;
		cin >> inst;
		if (inst == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if(inst=="pop")
		{
			if (q.empty())
				cout << -1<<'\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (inst == "front")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
			}
		}
		else if (inst == "back")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
			{
				cout << q.back() << '\n';
			}
		}
		else if (inst == "empty")
		{

			if (q.empty())
				cout << 1 << '\n';
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (inst == "size")
		{
			cout << q.size() << "\n";
		}
	}

	return 0;
}

