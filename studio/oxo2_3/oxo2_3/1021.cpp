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
		
		int target = deleteList.front(); //.front()�׻� ����
		deleteList.pop();

		//deque ��ȸ
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

		if (numFrontElement <= numBackElement) //���� ȸ��
		{
			::count += numFrontElement;
			while (numFrontElement--)
			{
				int temp = dq.front();	//�׻� ����
				dq.pop_front();
				dq.push_back(temp);

			}
			dq.pop_front();	//�׻󰡴�
		}
		else if(numFrontElement > numBackElement) //������ ȸ��
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

	//��, �� ������ ���� == �ʿ��� ��ɾ� ����
	// 1 2 3 4 5 6  7

	return 0;
}