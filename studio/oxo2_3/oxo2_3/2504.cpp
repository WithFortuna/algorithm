#include <iostream>
#include <stack>
#include <string>
//idea: 쌍을 이루면 pop
//open side: (2,3) 결정
//close side: 제대로 닫혔는지 체크
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<char> stk;
	string exp;
	cin >> exp;
	int sum = 0;
	int factor = 1;
	char prev='o';
	for (char c : exp)
	{
		if (c == '(')
		{
			stk.push(c);
			factor *= 2;
			prev = c;
		}
		else if (c == ')')
		{
			if (stk.empty() || stk.top()!='(')
			{
				sum = 0;
				break;
			}
			else if (stk.top() == '(')
			{
				if (prev == '(')
				{
					sum += factor;
					factor /= 2;
					stk.pop();
				}
				else
				{
					stk.pop();
					factor /= 2;
				}
				
			}

			prev = c;


		}
		else if (c == '[')
		{
			stk.push(c);
			factor *= 3;
			prev = c;

		}
		else if (c == ']')
		{
			if (stk.empty() || stk.top() != '[')
			{
				sum = 0;
				break;
			}
			if (stk.top() == '[')
			{
				if (prev == '[')
				{
					stk.pop();
					sum += factor;
					factor /= 3;
				}
				else
				{
					stk.pop();
					factor /= 3;
				}
				
			}
			
			prev = c;

			
		}
	}
	if (stk.empty()) cout << sum;
	else cout << 0;
	return 0;
}

// 2*(2+ 3*3)+3*2

// (2+3*3)*2

