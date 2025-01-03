#include <iostream>
#include <queue>
using namespace std;
int T;
int visited[300][300];//(0,0)~(n-1,n-1) 0 indexed
struct triple {
	int x, y, length;
};

triple start, target;

int bfs(int);
int main() {
	cin >> T;
	int t = T;

	while (t--)
	{
		int n;
		int x, y;
		cin >> n;
		cin >> x >> y;
		start.x = x;
		start.y = y;
		start.length = 0;
		cin >> x >> y;
		target.x = x;
		target.y = y;
		target.length = 0;

		//when
		int move = bfs(n);
		cout << move << '\n';
		//visited 초기화 필요
		fill(&visited[0][0], &visited[0][0] + 300 * 300, false);
	}

	return 0;
}


int bfs(int size)
{
	queue<triple> q;
	//initialize
	q.push({ start.x,start.y,start.length });
	visited[start.x][start.y] = true;
	while (!q.empty())
	{
		//q.pop
		triple node = q.front(); q.pop();
		if (node.x == target.x && node.y == target.y)
			return node.length;
		//탐색
		int dx[] = { 2,2,-2,-2,1,1,-1,-1 };
		int dy[] = { -1,1,-1,1,-2,2,-2,2 };
		for (int i = 0; i < 8; i++)
		{
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= size || ny >= size)
				continue;
		//visited = true, q.push
			else if (!visited[nx][ny])
			{
				visited[nx][ny] = true;
				q.push({ nx,ny,node.length + 1 });
			}
		}
	}

}