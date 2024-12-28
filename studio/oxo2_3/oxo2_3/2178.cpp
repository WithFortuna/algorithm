#include <iostream>
#include <queue>
#include <string>
using namespace std;
//칸 개수 세기=전체 경로 길이-1
int N, M;
int arr[102][102];
bool visited[102][102];
struct triple {
	int x, y, length;
};
int bfs();
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int n = N;

	while (n--)
	{
		string row;
		cin >> row;
		for (int i = 0; i < row.size(); i++)	//string -> intArr
		{
			arr[N - n][i+1] = row[i]-'0';
		}
	}

	//when
	int minPath = bfs();
	cout << minPath+1;
	return 0;
}

int bfs()
{
	//initialization
	queue<triple> q;
	triple start = { 1,1,0 };
	visited[1][1] = true;
	q.push(start);
	
	while (!q.empty())
	{
		//q.pop
		triple node = q.front(); q.pop();
		if (node.x == M && node.y == N)
			return node.length;
		//탐색
		int dx[] = { 0,0,1,-1 };
		int dy[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++)
		{
			int newX = node.x + dx[i];
			int newY = node.y + dy[i];
			if (newX<1 || newX>M || newY<1 || newY>N)	//경계 밖으로 나감
				continue;
		//q.push
			else if (!visited[newY][newX] && arr[newY][newX] == 1)	//발견
			{
				visited[newY][newX] = true;
				q.push({ newX, newY, node.length + 1 });
			}

		}

		

	}
}