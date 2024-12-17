#include <iostream>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k >> n;

	list<int> lines;
	int j = n;
	for (int i = 1; i <= k; i++)
	{
		lines.push_back(i);
	}
	auto iter = lines.begin();

	cout << "<";
	while (!lines.empty())
	{
		for (int i = 0; i < n-1; i++)	//erase에서 한칸 뒤로 이동하기에 n-1 만큼만 이동
		{
			if (iter == --lines.end())	//iter: 끝 원소
				iter = lines.begin();
			else
				iter++;

		}
		cout << *iter;
		iter = lines.erase(iter);
		if (iter == lines.end())
			iter = lines.begin();

		if (!lines.empty())
			cout << ", ";
		else
			cout << ">";
	}
}

//124567