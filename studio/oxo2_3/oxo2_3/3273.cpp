#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	bool flag = false;
	int count=0;
	int n, target;
	int arr[100001];
	cin >> n;

	for (int i = 0; i < n; i++){		//n
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> target;

	for (int i = 0;i < n-1;i++) {
		if (arr[i] > target)
			break;
		for (int j = i + 1;j < n;j++) {
			if (arr[i] + arr[j] == target)
				count++;
			else if (arr[i] + arr[j] > target)
				break;
		}
	}
	//for (int i = 0;i < n - 1;i++) {	//n+n-1+n-2+...+1 = N(N+1)/2
	//	for (int j = i + 1;j < n;j++)
	//	{
	//		if (arr[i] + arr[j] == target)
	//			count++;
	//	}
	//}


	cout << count;
}