#include <bits/stdc++.h>
#define DIV 1'000'000'007
using namespace std;
int n, dp[1000001][2];
// dp[n][0] = ���簢���� ������
// dp[n][1] = ���簢���� �������� ���ϰ� ��ĭ Ƣ���
int main() {
	cin >> n;
	dp[1][0] = 2, dp[1][1] = 2;
	dp[2][0] = 7, dp[2][1] = 2 * dp[1][0] + dp[1][1];
	for (int i = 3; i <= n; i++) {
		dp[i][0] = ((2 * dp[i - 1][0]) % DIV + (dp[i - 1][1] + dp[i - 2][0]) % DIV) % DIV;
		dp[i][1] = ((2 * dp[i - 1][0]) % DIV + dp[i - 1][1] % DIV) % DIV;
	}
	cout << dp[n][0];
	return 0;
}