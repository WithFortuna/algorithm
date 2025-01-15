#include <iostream>
#include <queue>
#include <list>
using namespace std;
int M, N, K;
int arr[101][101];	//0 indexed, 축 리버스
bool visited[101][101];
int count;
list<int> ls;

int bfs(int, int);

int main()
{
	cin >> M >> N >> K;
	int k = K;
	while (k--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		/*
		* col: x1부터 (x2-x1)개
		* row: y1부터 (y2-y1)개
		*/

		for (int i = y1; i < y2; i++)
			for (int j = x1; j < x2; j++)
				arr[i][j] = 1;
	}

	for(int i=0;i<M;i++)
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0 && !visited[i][j])
			{
				::count++;
				int area = bfs(i, j);
				ls.push_back(area);
			}
		}

	ls.sort();

	//then
	cout << ::count<<'\n';
	for (auto iter = ls.begin(); iter != ls.end(); iter++)
	{
		cout << *iter<<' ';
	}

	return 0;
}

int bfs(int row, int col) {
	//initialize
	int area = 1;
	queue<pair<int, int>> q;

	visited[row][col] = true;
	q.push({ row,col });

	while (!q.empty())
	{
		//q.pop
		pair<int, int> node = q.front(); q.pop();

		//탐색
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };

		for (int i = 0; i < 4; i++)
		{
			int nr = node.first + dx[i];
			int nc = node.second + dy[i];
			if (nr<0 || nc<0 || nr>=M || nc>=N)
				continue;
			else if (arr[nr][nc] == 0 && !visited[nr][nc])
			{
		//visited=true, q.push
				visited[nr][nc] = true;
				q.push({ nr,nc });
				area++;
			}
		}
	}

	return area;

}
