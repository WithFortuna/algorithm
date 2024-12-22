#include <iostream>
#include <string>
#include <queue>
using namespace std;
//pop: ���� ���� ����ϱ�� �Ѵ�. ���ٸ� -1�� ����ؾ���
//empty: ��������� 1, �ƴϸ� 0
//front, back��� ���ٸ� -1�� ���
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

