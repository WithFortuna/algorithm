#include <iostream>
using namespace std;
#define value first
#define pos second
//recursion
int hanoi(int k)
{
	//탈출조건
	if (k == 1)
		return 1;
	return hanoi(k - 1) * 2 + 1;
}

void printTrace(pair<int,int> block, int target)	//block을 target으로 이동
{
	//탈출조건
	if (block.value == 1)
		cout << block.pos << ' ' << target << '\n';
	else
	{
			int num = 6 - (block.pos + target); //pos,target을 제외한 남은 위치
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

