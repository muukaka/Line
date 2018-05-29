// Dynamic Programming(?), path ����?
// �ﰢ�� ���� �ִ���(���̵�:��)
// �迭 ���� ���� Ȯ��!

#include <iostream>
#include <vector>
#include <algorithm>// max()
#include <stack>

using namespace std;

/*
Time Complexity : O()
Space Complexity : O()
*/

int N;// �˹� ����, 3 <= N <= 500
int M;// �˹� ���۳�, 0 <= M <= 200
int D;// �˹� �Ⱓ, 0 <= D <= 100
int I;// ����, 0 <= I <= 100
int s[501][3];//�˹� ������, M D I
//int chck[501] = { 0, };// ������ �˹ٴ� 1�� ǥ��, ����� ���� ���
int day[301] = { 0, };// �˹��ϴ� ��¥, 0 ~ 300
int ret;
vector<int> alist;


// ��ȭ�� : alba(n) = max{ alba(n + 1), alba(n + 1) + s[n][2] }
// ���⵵ O(2^n) <- 10�����������ۿ� ������
int alba(int n)
{
	if (n > N)
		return 0;
	int sum = 0;
	int check = 0;
	for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
	{
		if (day[i] == 1)
			check = 1;
	}
	if (check == 1)
		sum = alba(n + 1);
	else
	{
		sum = alba(n + 1);

		for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
			day[i] = 1;
		sum = max(sum, alba(n + 1) + s[n][2]);

		for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
			day[i] = 0;
	}
	return sum;
}

// ó������ �˹��� ���� �ִ밪�� ���� �� �� ���� �˹� ����Ʈ�� ���
// n : ���� �˹� ��ȣ, sum : ������� ������ ��, m : ������ �ִ���
void albaList(int n, int sum, int m)
{
	if (n > N)
		return;
	if (sum == m)
	{
		for (int i = 0; i < alist.size(); i++)
			cout << s[alist[i]][0] << " " << s[alist[i]][1] << endl;
		return;
	}

	int check = 0;
	for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
		if (day[i] == 1)
			check = 1;

	if (check == 1)
		albaList(n + 1, sum, m);
	else
	{
		for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
			day[i] = 1;
		alist.push_back(n);
		albaList(n + 1, sum + s[n][2], m);

		for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
			day[i] = 0;
		alist.pop_back();
		albaList(n + 1, sum, m);
	}
	return;
}

int main()
{
	// input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i][0] >> s[i][1] >> s[i][2];// M D I

	// algor
	// alba(n) = ���� �˹� ��ȣ�� n�̰�, ����κ��� ���� �� �ִ� ������ �ִ����� ��ȯ
	// �˹� ����Ʈ�� �ǵڱ��� ����Ͽ� ���� �� �ִ� ������ �ִ����� ��ȯ
	ret = alba(0);

	// output
	cout << endl;
	cout << ret << endl;
	//cout << "�˹� ���" << endl;
	albaList(0, 0, ret);
	return 0;
}