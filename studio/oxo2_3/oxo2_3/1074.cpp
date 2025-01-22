#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int N, r, c;
int table[2][2] = {
	{1,2},
	{3,4}
};
//f(N): 2^N x 2^N�� �湮���� �� �鸥 Ƚ��

//recursion: ~~ func(k) = 4 * func(k-1)
int func(int k,int row, int col)
{
	int num = 0;

	//Ż������
	if (k == 1)
	{
		return table[row-1][col-1];
	}
	else
	{
		//����Ȯ��
		if (row > (int)pow(2, k-1))
		{
			if (col <= (int)pow(2, k - 1))
			{
				num += 2 * func(k - 1, (int)pow(2, k - 1), (int)pow(2, k - 1));
				//��ǥ��ȯ
				int nr = row - (int)pow(2, k - 1);
				num += func(k - 1, nr, col);
			}
			else
			{
				num += 3 * func(k - 1, (int)pow(2, k - 1), (int)pow(2, k - 1));
				//��ǥ��ȯ
				int nr = row - (int)pow(2, k - 1);
				int nc = col- (int)pow(2, k - 1);
				num += func(k - 1, nr, nc);
			}
			return num;
		}

		else
		{
			if (col <= (int)pow(2, k - 1))
			{
				num += func(k - 1, row, col);
			}
			else
			{
				num += func(k - 1, (int)pow(2, k - 1), (int)pow(2, k - 1));
				//��ǥ��ȯ
				int nc = col - (int)pow(2, k - 1);
				num += func(k - 1, row, nc);
			}

			return num;
		}
	}
}

int main()
{
	cin >> N >> r >> c;

	cout << func(N, r+1, c+1)-1;

	return 0;
}