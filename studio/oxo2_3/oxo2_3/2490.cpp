#include <iostream>
using namespace std;
//µµ(1x3)A °³(1x2)B °É(1x1)C À·(1x0)D ¸ð(1x4)E

int main()
{
//{
//	//given
//	int arr[3][4];
//	char result[6] = { 'D', 'C','B','A','E'};
//
//	for (int i = 0;i < 3;i++)
//	{
//		for (int j = 0;j < 4;j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	
//	//then
//	for (int i = 0;i < 3;i++)
//	{
//		int count = 0;
//
//		for (int j = 0;j < 4;j++)
//		{
//			if (arr[i][j] == 1)
//				count++;
//		}
//
//		for (int k = 0;k<= 4;k++)
//		{
//			if (count == k)
//				cout << result[k] << "\n";
//
//		}
//	}
//	system("pause");

	int t = 3, a, b, c, d;
	while (t--)
	{
		cin >> a >> b >> c >> d;
		cout << "DCBAE"[a + b + c + d];
	}
	system("pause");
}