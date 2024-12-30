#include <iostream>
#include <queue>
using namespace std;
//idea: queue에 불부터 push, 지훈은 나중에 push
char arr[1001][1001];
bool visited[1001][1001];
int R, C;
struct triple {
	int x;
	int y;
	char c;	//J, F
	int count = 0;

};
queue<triple> q;
int bfs();
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	int a, b;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'F')
				q.push({ i,j,'F' });
			else if (arr[i][j] == 'J')
			{
				a = i;
				b = j;
			}
		}
	}
	visited[a][b] = true;
	q.push({ a,b,'J' });

	//when
	int time = bfs();
	if (time == -1)
		cout << "IMPOSSIBLE";
	else
		cout << time+1;



	return 0;
}

int bfs()
{
	//initialize
	//..
	
	while (!q.empty())
	{
		//q.pop
		triple node = q.front();
		q.pop();
	
		//탐색
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		for (int i = 0; i < 4; i++)
		{
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];
			if (nx<1 || ny<1 || nx>R || ny>C)
			{
				if (node.c == 'F')	//Fire
					continue;
				else if (node.c == 'J')	//Jihoon
					return node.count;
			}
		//q.push
			else if (node.c == 'F')	//Fire
			{
				if (arr[nx][ny] == '.' || arr[nx][ny] == 'J')
				{
					arr[nx][ny] = 'F';
					q.push({ nx,ny,'F',node.count+1 });
				}
			}
			else if (node.c == 'J')	//Jihoon
			{
				if (arr[nx][ny] == '.' && !visited[nx][ny])
				{
					arr[nx][ny] = 'J';
					visited[nx][ny] = true;
					q.push({ nx,ny,'J',node.count+1 });
					if (nx == 1 || ny == 1 || nx == R || ny == C)
					{
						return node.count+1;
					}
				}
				
			}
		}
	}
	return -1;

}