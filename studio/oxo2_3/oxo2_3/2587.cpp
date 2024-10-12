#include <iostream>
using namespace std;
const int N = 5;
void sort(int* arr)
{
	for (int i = N - 1;i >= 0;i--) {
		for (int j = 0;j <= i-1;j++) {
			int temp;
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}

		}
	}
}

int main() {
	int arr[N];
	int avg = 0, mid;
	for (int i = 0;i < 5;i++)
		cin >> arr[i];

	//sorting
	sort(arr);
	//avg,median
	for (int i = 0;i < N;i++) {
		avg += arr[i];
	}
	avg /= N;
	cout << avg << '\n' << arr[2];
	//system("pause");
}

