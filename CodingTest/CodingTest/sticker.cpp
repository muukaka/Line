// ���չ���(Combination), ���װ��(Binomial Coefficient)

#include <iostream>
#include <vector>
#include <algorithm>//min()
using namespace std;

/*
Time Complexity : O(nk)
Space Complexity : O(nk)
*/

#define MOD 1003001

int T;// testcase ����
int N;// ����, 1 <= N <= 1000*1000
int K, M;// 1 <= M <= K <= N

int main()
{
	cin >> T;

	// algor
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K >> M;
		vector< vector<int> > item(N + 1, vector<int>(K + 1));

		for (int i = 0; i <= N; i++)
		{
			for (int j = 0; j <= min(i,K); j++)
			{
				if (j == 0 || j == i)
					item[i][j] = 1;
				else
					item[i][j] = (item[i - 1][j - 1] + item[i - 1][j]) % MOD;
			}
		}

		// output
		int ret=0;// ����Ǽ�, �� : (n)C(m) * (n)C(k-m)
		ret = (item[N][M] * item[N][(K - M)]) % MOD;
		cout << ret << endl;
	}

	return 0;
}

/* �������
�׽�Ʈ���̽����� �� �ٿ� ����� ���� ���
����� % 1003001 ���
*/
/* �׽�Ʈ���̽�
// �Է�
2
5 4 2
1 1 1
// ���
100
1
*/
/* ���װ�� ���� ����
//�ʱ�ȭ
for (int i = 0; i <= N; i++) {
	dp[i][0] = 1;
	dp[i][i] = 1;
}

//DP
for (int i = 1; i < N; i++) {
	for (int j = 0; j < i; j++) {
		dp[i + 1][j + 1] = (dp[i][j] + dp[i][j + 1]) % mod;
	}
}
*/