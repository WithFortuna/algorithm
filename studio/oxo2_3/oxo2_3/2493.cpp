// A -> B ��ȣ ����. ��ȣ�� �ޱ����� ����: h(A)<=h(B)

#include <iostream>
#include <list>
#include <stack>
using namespace std;
int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> output;
	list<int> list;

	cin >> N;
	int n = N;
	while(n--)	//o(n)
	{
		int num;
		cin >> num;
		list.push_back(num);
	}
	n = N;
	//1 2 3
	while (n--) //o(n)
	{
		if (n == 0)
			output.push(0);
		else //list���� 2 �̻�
		{
			auto iter = list.rbegin();
			auto first = list.rend();
			first--;
			int sender = *iter;
			int count = n;
			for (iter++ ;iter != list.rend(); iter++)			//o(length)
			{
				if (*iter >= sender) //������ �߰�
				{
					output.push(count);
					break;
				}
				else if(iter==first) //�����ڰ� �����ϴ�
				{
					output.push(0);
									}
				count--;
			}
			list.pop_back();
		}
	}

	while (!output.empty())
	{
		cout << output.top() << ' ';
		output.pop();
	}

	return 0;
}

//time complexity
// n + n-1 + n-2 + ... + 1 = o(n^2)