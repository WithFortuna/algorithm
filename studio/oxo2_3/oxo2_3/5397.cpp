// '-' : �����
// '<'. '>' : Ŀ���̵�\

#include <iostream>
#include <string>
#include <list>	//����,����: O(1)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		string input;
		cin >> input;

		list<char> sentence;
		auto iter = sentence.begin();
		for (char ch : input)
		{
			if (ch == '<')
			{
				if (iter != sentence.begin())
					iter--;
			}
			else if (ch == '>')
			{
				if (iter != sentence.end())
					iter++;
			}

			else if (ch == '-')
			{
				if (iter != sentence.begin())	//���� ����� ������
				{
					iter = sentence.erase(--iter);
				}
			}

			else
			{
				sentence.insert(iter, ch); //acb
			}
		}
		for (char pw : sentence)
			cout << pw;
		cout << '\n';
	}

	
}