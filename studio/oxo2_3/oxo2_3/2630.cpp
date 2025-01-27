#include <iostream>
#define x first
#define y second

using namespace std;

int arr[200][200]; //0 indexed
int result[2]; //0은 하얀색 1은 파란색
int N;

bool isOneColor(pair<int, int> pointA, int len)
{
	pair<int, int> pointB = { pointA.x + len - 1,pointA.y + len - 1 };

	int color = arr[pointA.x][pointA.y];
	for (int i = pointA.x; i <= pointB.x; i++)
	{
		for (int j = pointA.y; j <= pointB.y; j++)
		{
			if (color != arr[i][j])
				return false;
		}
	}

	return true;
}

void recFunc(pair<int,int> pointA, int len)
{
	//탈출조건
	if (isOneColor(pointA, len))
	{
		result[arr[pointA.x][pointA.y]]++;
	}
	else
	{
		for(int i=0;i<2;i++)
			for (int j = 0; j < 2; j++)
			{
				int newLen = len / 2;
				recFunc({ pointA.x + newLen * i, pointA.y + newLen * j }, len / 2);
			}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	recFunc({ 0,0 }, N);
	cout << result[0] << endl << result[1];
	return 0;
}