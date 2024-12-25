#include <iostream>
#include <string>
#include <stack>
using namespace std;
//good word == �������� �ʴ� ��찡 ������
//case1: ������ �Ȱ�ħ
//AABB
//case2: ���ξȱ�
//ABBBBA
//error case
//ABA�� goodword���� ABAABA
int N;
//�ذ���: �������ڰ� �������� ������ stack.pop()��. stack�� 
//	���� �����ִٸ� bad word 
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
				if (stk.top() == c)	//�׻� ���� case
					stk.pop();
				else if (stk.top() != c) //�ΰ�����ϴ� case
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