#include <iostream>
#include <cmath>
#define x first
#define y second
using namespace std;
int N;
int arr[2200][2200];//0 indexed
int result[3]; //-1,0,1의 종이개수

void recFunc(pair<int,int> pointA, pair<int,int> pointB)
{
	//탈출조건: 모두 같은 수
	bool flag = true;
	int num = arr[pointA.x][pointA.y];
	for(int i=pointA.x;i<=pointB.x;i++)
		for (int j = pointA.y; j <= pointB.y; j++)
		{
			if (num != arr[i][j])
				flag = false;
		}
	if (flag) {
		result[num + 1]++;
		return;
	}
	else
	{
		int lenX = pointB.x - pointA.x + 1;
		int lenY = pointB.y - pointA.y + 1;
		lenX /= 3; //길이
		lenY /= 3;
		recFunc({ pointA.x,pointA.y }, { pointA.x + lenX - 1,pointA.y + lenY - 1 });
		recFunc({ pointA.x,pointA.y + lenX }, { pointA.x + lenX - 1, pointA.y + 2 * lenY - 1 });
		recFunc({ pointA.x,pointA.y + 2 * lenX }, { pointA.x + lenX - 1, pointA.y + 3 * lenY - 1 });
		
		recFunc({ pointA.x + lenX, pointA.y }, { pointA.x + 2 * lenX - 1,pointA.y + lenY - 1 });
		recFunc({ pointA.x + lenX ,pointA.y + lenY }, { pointA.x + 2 * lenX - 1 , pointA.y + 2 * lenY - 1 });
		recFunc({ pointA.x + lenX , pointA.y + 2 * lenY }, { pointA.x + 2 * lenX - 1 , pointA.y + 3 * lenY - 1 });

		recFunc({ pointA.x + 2 * lenX,  pointA.y }, { pointA.x + 3 * lenX - 1, pointA.y + lenY - 1 });
		recFunc({ pointA.x + 2 * lenX,pointA.y + lenY }, { pointA.x + 3 * lenX - 1,  pointA.y + 2 * lenY - 1 });
		recFunc({ pointA.x + 2 * lenX,pointA.y + 2 * lenY }, { pointA.x + 3 * lenX - 1,pointA.y + 3 * lenY - 1 });

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	recFunc({ 0,0 }, { N - 1,N - 1 });

	for (int i = 0; i < 3; i++)
		cout << result[i] << '\n';

}