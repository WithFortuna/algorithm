#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[1001][1001];
bool visited[1001][1001];
bool visited_crasher[1001][1001];

struct triple {
	int x;
	int y; 
	int dist;
	bool isCrashUsed;
};
int bfs(int n, int m);
int main()
{
	cin >> N >> M;
	for (int row = 1; row <= N; row++)
	{
		string str;
		cin >> str;
		int col = 1;
		for (char c : str)
		{
			arr[row][col++] = c - '0';
		}
	}

	//then
	int result = bfs(N, M);

	cout << result;
}

void checkVisited(int x, int y, bool isCrashedUsed)
{
	if (isCrashedUsed)
		visited_crasher[x][y] = true;
	else
		visited[x][y] = true;
}

int bfs(int n, int m)
{
	//initialize
	queue<triple> q;
	q.push({ 1,1,1, false });
	visited[1][1] = true;
	visited_crasher[1][1] = true;
	while (!q.empty())
	{
		//q.pop
		triple node = q.front(); q.pop();
		if (node.x == N && node.y == M)
			return node.dist;
	//탐색
		int dx[] = { 1, -1, 0, 0 };
		int dy[] = { 0, 0, 1, -1 };
		for (int i = 0; i < 4; i++)
		{
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];

			if (nx<1 || ny<1 || nx>N || ny>M)
				continue;
			else if (node.isCrashUsed&&!visited_crasher[nx][ny] || !node.isCrashUsed && !visited[nx][ny])
			{
				//q.push, visited=true
				if (arr[nx][ny] == 0)
				{
					checkVisited(nx, ny, node.isCrashUsed);
					q.push({ nx,ny,node.dist + 1,node.isCrashUsed });
				}
				else if (arr[nx][ny] == 1 && !node.isCrashUsed)
				{
					checkVisited(nx, ny, node.isCrashUsed);
					q.push({ nx,ny, node.dist + 1, true});

				}
			}
		}

	}
	return -1;
}