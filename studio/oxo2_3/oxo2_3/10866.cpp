#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> dq;
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--)
	{
		string inst;
		cin >> inst;

		if (inst == "push_front")
		{
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (inst == "push_back")
		{
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (inst == "pop_front")
		{
			if (dq.empty())
				cout << -1 << '\n';
			else
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (inst == "pop_back")
		{
			if (dq.empty())
				cout << -1 << '\n';
			else
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (inst == "size")
			cout << dq.size() << '\n';
		else if (inst == "empty")
			cout << dq.empty() << '\n';
		else if (inst == "front")
		{
			if (dq.empty())
				cout << -1 << '\n';
			else
			{
				cout << dq.front() << '\n';

			}
		}
		else if (inst == "back")
		{
			if (dq.empty())
				cout << -1 << '\n';
			else
			{
				cout << dq.back() << '\n';

			}
		}
	}

	return 0;
}