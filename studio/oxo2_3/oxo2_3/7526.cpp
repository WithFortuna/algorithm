#include <iostream>
#include <queue>
using namespace std;
// problem:
//state: 1, 0, -1
//  하루 => 인접 토마토 변함

//solution:
// queue에는 tprible{x,y,z}를 저장
//1인 노드마다 bfs를 실행. => z값이 크면 queue에 push를 멈춤

int arr[1001][1001];	//1 indexed
int day[1001][1001];	//(0 or 1) -> 1000, -1 -> 0
int M, N;

void bfs(int, int);
struct triple {
	int x;
	int y;
	int day;
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[j][i];
			if (arr[j][i] == -1)
				day[j][i] = 0;
			else
				day[j][i] = 2000;
		}
	}

	//when
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}
	int tomatoTime = 0;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (day[i][j] == 2000)	//익지 못함
			{
				cout << -1;
				return 0;
			}
			else if (day[i][j] > tomatoTime)	//익은 경우
				tomatoTime = day[i][j];
		}
	}
	
	cout << tomatoTime;

	return 0;
}
//예외 case: 모두 1 => 0 , 익지 못함 -> -1
void bfs(int x, int y)
{

	//initialize
	bool visited[1001][1001] = {0};
	visited[x][y] = true;
	queue<triple> q;

	q.push({ x,y,0 });
	if (day[x][y] > 0)
		day[x][y] = 0;
	//q.pop
	while (!q.empty())
	{
		triple node = q.front();
		q.pop();

		//탐색
		int dx[] = { 0,0,-1,1 };
		int dy[] = { 1,-1,0,0 };
		for (int k = 0; k < 4; k++)
		{
			int newX = node.x + dx[k];
			int newY = node.y + dy[k];
			if (newX<1 || newY<1 || newX>M || newY>N)
				continue;
			else if (!visited[newX][newY] && (arr[newX][newY] == 0 || arr[newX][newY]==1))
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