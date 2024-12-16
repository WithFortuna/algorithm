// '-' : 지우기
// '<'. '>' : 커서이동\

#include <iostream>
#include <string>
#include <list>	//삽입,삭제: O(1)
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
				if (iter != sentence.begin())	//지울 대상이 존재함
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