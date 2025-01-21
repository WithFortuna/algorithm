#include <iostream>
using namespace std;
#define value first
#define pos second
//recursion
int hanoi(int k)
{
	//Ż������
	if (k == 1)
		return 1;
	return hanoi(k - 1) * 2 + 1;
}

void printTrace(pair<int,int> block, int target)	//block�� target���� �̵�
{
	//Ż������
	if (block.value == 1)
		cout << block.pos << ' ' << target << '\n';
	else
	{
			int num = 6 - (block.pos + target); //pos,target�� ������ ���� ��ġ
			printTrace({ block.value - 1, block.pos }, num);
			cout << block.pos << ' ' << target << '\n';
			printTrace({ block.value - 1, num }, target);
	

	}
	
}

int N;

int main()
{
	cin >> N;
	cout << hanoi(N) << '\n';
	printTrace({ N,1 }, 3);

}

