#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
int N, M;
int arr[501][501]; //1 indexed
bool visited[501][501];
int numOfPicture, maxSize;

int bfs(int x, int y);
int main()
{
	cin >> N >> M; //N:세로 M:가로
	cin.ignore();
	int n = N;
	while (n--)
	{
		string row, token;
		getline(cin, row);
		stringstream ss(row);
		int i = 1;
		while (getline(ss, token, ' '))
		{
			arr[i++][N-n] = stoi(token);
		}
	}


	//when
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visited[i][j] || arr[i][j]==0)
				continue;
			else
			{
				numOfPicture++;
				int temp = bfs(i, j);
				if (temp > maxSize)
					maxSize = temp;
			}
		}
	}

	//then
	cout << numOfPicture << '\n' << maxSize;
	return 0;
}

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	int size = 1;
	visited[x][y] = true;
	q.push({ x,y });

	while (!q.empty())
	{
		//q.pop()
		pair<int, int> node = q.front(); q.pop();
		//해당 노드 탐색
		int dx[4] = { 0, 0, -1, 1 };
		int dy[4] = { 1, -1, 0, 0 };
		for (int i = 0; i < 4; i++)
		{
			//발견
			//visited=true, q.push()
			int newX, newY;
			newX = node.first + dx[i];
			newY = node.second + dy[i];
			if (visited[newX][newY] == false && arr[newX][newY] == 1)
			{
				visited[newX][newY] = true;
				q.push({ newX,newY });
				size++;
			}
		}
	}

	return size;
}
