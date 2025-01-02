#include <iostream>
#include <queue>
using namespace std;
int N;
char arr[101][101];
bool visited[101][101];

void bfs(int, int);
void bfs_RGEqual(int x, int y);

int main()
{
	cin >> N;
	int n = N;
	while (n--)
	{
		string row;
		cin >> row;

		//string -> arrº¯È¯
		int i = 1;
		for (char c : row)
		{
			arr[N - n][i++] = c;
		}
	}
//when
	int count = 0;
	//normal person
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= N; j++)
		{
			if (!visited[i][j])
			{
				bfs(i, j);
				count++;
			}
		}
	cout << count<<' ';
	
	//Àû·Ï»ö¸Í person
	count = 0;
	fill(&visited[0][0], &visited[0][0] + 101*101, false);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (!visited[i][j])
			{
				bfs_RGEqual(i, j);
				count++;
			}
		}
	cout << count;

	return 0;
}

void bfs(int x, int y) {
	//initialize
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x,y });
	char color = arr[x][y];

	while (!q.empty())
	{
		//q.pop
		pair<int, int> node = q.front();
		q.pop();

		//Å½»ö
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		for (int i = 0; i < 4; i++)
		{
			int nx = node.first + dx[i];
			int ny = node.second + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N)
				continue;

			else if (arr[nx][ny] == color && !visited[nx][ny])
			{
				//q.push
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

}


void bfs_RGEqual(int x, int y) {
	//initialize
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x,y });
	char color = arr[x][y];

	while (!q.empty())
	{
		//q.pop
		pair<int, int> node = q.front();
		q.pop();

		//Å½»ö
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		for (int i = 0; i < 4; i++)
		{
			int nx = node.first + dx[i];
			int ny = node.second + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>N)
				continue;

			if ((arr[nx][ny] == 'R' || arr[nx][ny] == 'G')&&(color == 'R' || color=='G')&&!visited[nx][ny])
			{
				//q.push
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
			else if (arr[nx][ny] == color && !visited[nx][ny])
			{
				//q.push
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

}
