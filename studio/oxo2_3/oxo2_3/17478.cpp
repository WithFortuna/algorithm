#include <iostream>
using namespace std;

int N;
void displayDash(int n)	//n����ŭ dash���
{
	while (n--)
	{
		cout << '_';
	}
}
void recFunc(int k, int dash)
{
	//Ż������
	if (k == 0)
	{
		//��
		displayDash(dash);
		cout << "\"����Լ��� ������?\""<<'\n';
		//��2
		displayDash(dash);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
		//��
		displayDash(dash);
		cout << "��� �亯�Ͽ���." << '\n';

	}
	else
	{
		//��
		displayDash(dash);
		cout << "\"����Լ��� ������?\"" << '\n';
		//��
		displayDash(dash);
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
		displayDash(dash);
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
		displayDash(dash);
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\""<<'\n';

		recFunc(k-1, dash + 4);
		//��
		displayDash(dash);
		cout << "��� �亯�Ͽ���." << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������."<<'\n';
	recFunc(N, 0);

	return 0;
}