#include <iostream>
#include <stack>
#include <string>
using namespace std;

//idea
// 잘린 막대기 개수 = 레이저 개수 + 1
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//given
	stack<char> stk;
	string sticks;
	int count = 0;
	char prev;

	cin >> sticks;

	//when
	for (char c : sticks)
	{
		if (c == '(')
		{
			stk.push('(');
			prev = '(';
		}
		else if (c == ')')
		{
			//stk always not empty
			//case1: laser
			if (prev == '(')
			{
				stk.pop();
				int cutStick = stk.size();
				count += cutStick;
			}
			//case2: stick
			else if (prev == ')')
			{
				stk.pop();
				count += 1;
			}
			prev = ')';

		}
	}

	cout << count;

	return 0;
}
