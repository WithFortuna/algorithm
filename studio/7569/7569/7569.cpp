//output: 모두 익는데 필요한 최소일수 or -1(익지못한 토마토가 존재)

#include <iostream>
#include <queue>

using namespace std;
int M, N, H;
int arr[101][101][101];
int day;
struct triple {
	int h, x, y;
	int day;
};
queue<triple> q;

void bfs();
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;
	int col = M;
	int row = N;
	for (int i = 1;i <= H;i++)
		for (int j = 1;j <= row;j++)
			for (int k = 1;k <= col;k++)
			{
				//initialize
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)
					q.push({ i,j,k,0 });

			}

	//when
	//bfs with 다중 시작점
	bfs();

	//then
	for (int i = 1;i <= H;i++)
		for (int j = 1;j <= row;j++)
			for (int k = 1;k <= col;k++)
			{
				if (arr[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}
			}

	cout << day;

	return 0;
}


void bfs()
{
	while (!q.empty())
	{
	//q.pop
	triple node = q.front(); q.pop();
		
	//탐색
	int dx[] = { 1,-1,0,0,0,0};
	int dy[] = { 0,0,-1,1,0,0 };
	int dz[] = { 0,0,0,0,1,-1 };
	for (int i = 0;i < 6;i++)
	{
		int nx = node.x + dx[i];
		int ny = node.y + dy[i];
		int nz = node.h + dz[i];

		if (nx<1 || ny<1 || nz<1 || nx>N || ny>M || nz>H)
			continue;
		else if (arr[nz][nx][ny] == 0)	//arr[][][]==0 => nonvisited;
		{
			//q.push
			arr[nz][nx][ny] = 1;
			q.push({ nz,nx,ny,node.day + 1 });
			day = node.day + 1;
		}
	}

	}


}