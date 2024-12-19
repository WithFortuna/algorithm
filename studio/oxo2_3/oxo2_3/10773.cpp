#include <iostream>
#include <list>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<int> numbers;

	int N;
	cin >> N;

	while (N--)
	{
		int num;
		cin >> num;
		if (num == 0)
			numbers.pop_back();
		else
			numbers.push_back(num);
	}

	int sum = 0;
	for(auto iter = numbers.begin();iter!=numbers.end();iter++)
		{
		sum += *iter;
		}

	cout << sum;
}