#include <iostream>
using namespace std;
int odd[7];

int main() {
	int arr[7];
	int sum=0;
	int t = 7;
	while (t--) {
		//cout << '\n' << t << "번째 시도" << '\n';
		cin >> arr[7-t-1];
		if (arr[7 - t-1] % 2 != 0) { //odd number
			odd[7 - t-1] = arr[7 - t-1];
		
		}
		else
		{
			odd[7 - t-1] = 0;
		}
		sum += odd[7 - t-1];
			
	}

	if (sum == 0)
		cout << "-1";
	else
	{
		cout << sum << '\n';
		int min = 200;
		for (int i = 0;i < 7;i++) {
			if (min > odd[i] && odd[i]!=0)
				min = odd[i];
		}
		cout << min;
	}
	
	//system("pause");

}