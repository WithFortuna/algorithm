#include <iostream>
#define x first
#define y second
using namespace std;

int arr[70][70];
int N;
bool isOneNumber(pair<int, int> point, int len);

void recFunc(pair<int,int> point, int len)
{
	//≈ª√‚¡∂∞«
	if (isOneNumber(point, len))
	{
		cout << arr[point.x][point.y];
	}
	else
	{
		cout << '(';
		for(int i=0;i<2;i++)
			for (int j = 0; j < 2; j++)
			{
				int delta = len / 2;
				recFunc({ point.x + delta * i,point.y + delta * j }, len / 2);
			}
		cout << ')';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//given
	cin >> N;
	for(int i=0;i<N;i++)
	{
		string str;
		cin >> str;
		
		int j = 0;
		for (char c : str)
		{
			arr[i][j++] = c-'0';
		}
	}

	//when
	recFunc({ 0,0 }, N);

	return 0;
}

bool isOneNumber(pair<int, int> point, int len)
{
	int x = point.x;
	int y = point.y;
	int num = arr[x][y];

	for (int i = x; i < x + len; i++)
		for (int j = y; j < y + len; j++)
			if (num != arr[i][j])
				return false;
	return true;
}