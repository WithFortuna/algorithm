#include <iostream>
#include <queue>
using namespace std;
bool visited[51][51] = { 0 };
int arr[51][51] = { 0 };	//1 indexed
int T;
void bfs(int, int,int,int);
int main()
{
	cin >> T;
	int t = T;
	while (t--)
	{
		fill(&arr[0][0], &arr[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, false);
		int count = 0;
		//given
		int col, row, num;
		cin >> col >> row >> num;
		int temp = num;
		while (temp--)
		{
			int y, x;
			cin >> y >> x;
			arr[x+1][y+1] = 1;	//¹èÃß
		}

		//when
		for(int i=1;i<=row;i++)
			for (int j = 1; j <= col; j++)
			{
				if (arr[i][j] == 1 && !visited[i][j])
				{
					bfs(i, j,row,col);
					count++;
				}
			}

		cout << count << '\n';

	}


	return 0;
}

void bfs(int x, int y, int row, int col)
{
	queue<pair<int, int>> q;
	//initialize
	visited[x][y] = true;
	q.push({ x,y });

	while (!q.empty())
	{
		//q.pop
		pair<int, int> node = q.front(); q.pop();
		//Å½»ö
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,-1,1 };
		for (int i = 0; i < 4; i++)
		{
			int nx = node.first + dx[i];
			int ny = node.second + dy[i];
			if (nx<1 || ny<1 || nx>row || ny>col)
				continue;
			//visited=true, q.
			else if (arr[nx][ny] == 1 && !visited[nx][ny])
			{
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}

		}

	}


}