#include <iostream>
#include <queue>
using namespace std;
// problem:
//state: 1, 0, -1
//  �Ϸ� => ���� �丶�� ����

//solution:
// queue���� tprible{x,y,z}�� ����
//1�� ��帶�� bfs�� ����. => z���� ũ�� queue�� push�� ����

int arr[1005][1005];	//1 indexed
int day[1005][1005];	//(0 or 1) -> 2000, -1 -> 0
bool visited[1005][1005] = { 0 };

int M, N;
void bfs();
struct triple {
	int x;
	int y;
	int day;
};
queue<triple> q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				day[i][j] = 0;
			else if (arr[i][j] == 1)
			{
				::q.push({ i,j,0 });
				visited[i][j] = true;

			}
			else
			{
				day[i][j] = 2000;

			}
		}
	}

	//when
	bfs();
	int tomatoTime = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (day[i][j] == 2000)	//���� ����
			{
				cout << -1;
				return 0;
			}
			else if (day[i][j] > tomatoTime)	//���� ���
				tomatoTime = day[i][j];
		}
	}

	cout << tomatoTime;

	return 0;
}
//���� case: ��� 1 => 0 , ���� ���� -> -1
void bfs()
{

	//initialize
	//������ ó����
	
	//q.pop
	while (!q.empty())
	{
		triple node = q.front();
		q.pop();

		//Ž��
		int dy[] = { 0,0,-1,1 };
		int dx[] = { 1,-1,0,0 };
		for (int k = 0; k < 4; k++)
		{
			int newX = node.x + dx[k];
			int newY = node.y + dy[k];
			if (newX<1 || newY<1 || newX>N || newY>M)
				continue;
			else if (!visited[newX][newY] && (arr[newX][newY] == 0 || arr[newX][newY] == 1))
			{
				//visited=true & q.push
				visited[newX][newY] = true;
				q.push({ newX,newY,node.day + 1 });
				if (day[newX][newY] > node.day + 1)
					day[newX][newY] = node.day + 1;
			}
			else if (!visited[newX][newY] && arr[newX][newY] == -1)
			{
				visited[newX][newY] = true;
			}

		}
	}
}