#include <iostream>
#include <string>
#include <stack>
using namespace std;
//good word == 교차하지 않는 경우가 존재함
//case1: 범위가 안겹침
//AABB
//case2: 감싸안김
//ABBBBA
//error case
//ABA도 goodword가능 ABAABA
int N;
//해결방법: 같은문자가 연속으로 나오면 stack.pop()함. stack에 
//	값이 남아있다면 bad word 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int n = N;
	int count = 0;
	while (n--)
	{
		string voca;
		stack<char> stk;
		cin >> voca;
		for (char c : voca)
		{
			if (stk.empty())
				stk.push(c);
			else
			{
				if (stk.top() == c)	//항상 참인 case
					stk.pop();
				else if (stk.top() != c) //두고봐야하는 case
				{
					stk.push(c);
				}
			}
		}
		if (stk.empty())
			count++;
	}

	cout << count;
	return 0;
}