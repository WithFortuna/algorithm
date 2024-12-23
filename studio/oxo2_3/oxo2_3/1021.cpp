#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int N, M;
deque<int> dq;
queue<int> deleteList;
int count;
int main() {

	//given
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
		dq.push_back(i);
	int m=M;
	while (m--)
	{
		int num;
		cin >> num;
		deleteList.push(num);
	}
	//when
	m = M;
	while (m--)
	{
		
		int target = deleteList.front(); //.front()항상 가능
		deleteList.pop();

		//deque 순회
		int pos;
		for (int i = 0; i < dq.size(); i++)
		{
			if (target == dq[i])
			{
				pos = i;
				break;
			}
		}
		int numFrontElement = pos;
		int numBackElement = dq.size() - (pos + 1);

		if (numFrontElement <= numBackElement) //왼쪽 회전
		{
			::count += numFrontElement;
			while (numFrontElement--)
			{
				int temp = dq.front();	//항상 가능
				dq.pop_front();
				dq.push_back(temp);

			}
			dq.pop_front();	//항상가능
		}
		else if(numFrontElement > numBackElement) //오른쪽 회전
		{
			::count += (numBackElement+1);
			while (numBackElement--)
			{
				int temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
			}
			dq.pop_back();
		}

	}

	cout << ::count;

	//앞, 뒤 원소의 개수 == 필요한 명령어 개수
	// 1 2 3 4 5 6  7

	return 0;
}