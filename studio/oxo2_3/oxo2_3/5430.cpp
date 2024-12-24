//R: 순서 뒤집기
//D: 첫번째 수 버리기, if empty -> error

#include <iostream>
#include <sstream>
#include <string>
#include <list>
using namespace std;

int N;
list<int> ls;
bool isRightSide=true;
bool isError = false;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int n = N;
	while (n--)
	{
		isRightSide = true;
		isError = false;
		ls.clear();
		string inst;
		int len, l;
		char a;
		string arr,token;

		cin >> inst;	//input instruction
		cin >> len;		//length
		l = len;
		
		cin >> a;
		cin >> arr;
		stringstream ss(arr);
		
		if (len != 0)
		{
			while (getline(ss, token, ',')) //','제거
			{
				// ']'제거
				token.erase(remove(token.begin(), token.end(), ']'), token.end());
				ls.push_back(stoi(token));
			}
		}
			
		
		//instruction 실행
			for (char c : inst)
			{
				if (c == 'R')
				{
					if (isRightSide)
						isRightSide = false;
					else
						isRightSide = true;
				}
				else if (c == 'D')
				{
					if (ls.empty())
					{
						cout << "error" << '\n';
						isError = true;
						break;
					}
					else
					{
						if (isRightSide)	//정방향
							ls.pop_front();
						else                //역방향
							ls.pop_back();
					}
			

				}
			}

		//instruction 결과 출력
			if (isError)
				continue;
			else if (ls.empty())
			{
				cout << "[]"<<'\n';
				continue;
			}
			if (isRightSide)//정방향
			{
				int n, size;
				n = 1;
				size = ls.size();
				
				cout << '[';
				for (auto first = ls.begin(); first != ls.end(); first++)
				{
					if (n++ == size)
						cout << *first;	
					else
						cout << *first << ',';
				}
				cout << ']';
			}
			else //역방향
			{
				int n, size;
				n = 1;
				size = ls.size();
				cout << '[';
				for (auto first = ls.rbegin(); first != ls.rend(); first++)
				{
					if (n++ == size)
						cout << *first;
					else
						cout << *first << ',';

				}
				cout << ']';
			}
			cout << '\n';
	
	}

	return 0;
}