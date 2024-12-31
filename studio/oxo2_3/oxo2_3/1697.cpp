//熱綴: 務晦(+-1), 牖除檜翕(2*pos)
//營寞僥 x

#include <iostream>
#include <queue>
#define length second

using namespace std;
int N, K;
int arr[100001];
bool visited[100001];
queue<pair<int, int>> q;
int main()
{
	cin >> N >> K;	//N -> K move

	//bfs
	//initialize
	q.push({ N,0 });
	visited[N] = true;
	while (!q.empty())
	{
		//q.pop
		pair<int, int> node = q.front(); q.pop();
		//target
		if (node.first == K)
		{
			cout << node.length;
			return 0;
		}
		//visited=true, q.push
		if (!visited[node.first + 1])
		{
			visited[node.first + 1] = true;
			q.push({ node.first + 1,node.length + 1 });
		}
		if (!visited[node.first - 1])
		{
			visited[node.first - 1] = true;
			q.push({ node.first - 1,node.length + 1 });
		}
		if (!visited[node.first * 2])
		{
			visited[node.first * 2] = true;
			q.push({ node.first * 2,node.length + 1 });
		}
	}



	return 0;
}
