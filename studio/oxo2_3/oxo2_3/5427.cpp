#include <iostream>
#include <queue>
using namespace std;
int T;
char arr[1001][1001];
bool visited[1001][1001];

int bfs(int, int, int, int);
void clear();
struct triple {
	int x, y, length;
};
queue<triple> q;

int main()
{
	cin >> T;
	int t = T;
	while (t--)
	{
		//TestCase초기화
		clear();

		int col, row;
		int x, y;
		cin >> col >> row;
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@')	//사람은 나중에 움직임
				{
					x = i;
					y = j;
				}
				else if (arr[i][j] == '*')	//불을 먼저 움직임
					q.push({ i,j,-1 });
			}
		}

		int minTime = bfs(x, y,row,col);

		if (minTime == -1)
			cout << "IMPOSSIBLE"<<'\n';
		else
			cout << minTime<<'\n';

	}


	return 0;
}

int bfs(int x, int y,int row, int col)
{
	//initialize
	q.push({ x,y,0 });
	visited[x][y] = true;

	while (!q.empty())
	{
		//q.front
		triple node = q.front();
		q.pop();
		//탐색
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		if (node.length == -1)//불
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];

				if (nx<1 || ny<1 || nx>row || ny>col)
				{
					continue;
				}
				else if (arr[nx][ny] == '.' || arr[nx][ny] == '@')
				{
		//q.push
					q.push({ nx,ny,-1 });
					arr[nx][ny] = '*';
				}
			}

		}
		else if (node.length != -1)//사람
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];

				if (nx<1 || ny<1 || nx>row || ny>col)
				{
					return node.length + 1;
				}
		//q.push
				else if (!visited[nx][ny]&& arr[nx][ny] == '.')
				{
					visited[nx][ny] = true;
					q.push({ nx,ny,node.length + 1 });
				}

			}
		}
	
	}

	return -1;
}

void clear()
{
	while (!q.empty())
	{
		q.pop();
	}
	fill(&visited[0][0], &visited[0][0] + 1001 * 1001, false);
}