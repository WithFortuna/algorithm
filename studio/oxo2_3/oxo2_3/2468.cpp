#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[101][101];
int map[101][101];
bool visited[101][101];
int result[101];

int N;
void drawNewMap(int);
int bfsRepeated();
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];	//1~100
		}
	int maxHeight = *max_element(&arr[0][0], &arr[0][0] + 101 * 101);

	for (int h = 0; h <= maxHeight; h++)
	{
		drawNewMap(h);
		result[h] = bfsRepeated();

		//리소스 정리
		//1. map초기화
		fill(&map[0][0], &map[0][0] + 101 * 101, 0);
		//2. visited초기화
		fill(&visited[0][0], &visited[0][0] + 101 * 101, false);

	}

	int maxResult = *max_element(&result[0], &result[0] + 101);

	cout << maxResult;


	return 0;
}

void drawNewMap(int h)
{
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] <= h)
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}
}

int bfsRepeated()
{
	int count = 0;
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= N; j++)
		{
			if (!visited[i][j] && map[i][j] == 1)
			{
				count++;
				/*bfs*/

				//initialize
				queue<pair<int, int>> q;
				q.push({ i,j });
				//q.pop
				while (!q.empty())
				{
					pair<int, int> node = q.front();
					q.pop();
					//탐색
					int dx[] = { 1,-1,0,0 };
					int dy[] = { 0,0,1,-1 };
					for (int k = 0; k < 4; k++)
					{
						int nx = node.first + dx[k];
						int ny = node.second + dy[k];

						if (nx<1 || ny<1 || nx>N || ny>N)
							continue;
						else if (!visited[nx][ny] && map[nx][ny] == 1)
						{
							//q.push
							visited[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}

	return count;
}