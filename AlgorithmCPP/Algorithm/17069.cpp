#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, dp[33][33][3], arr[33][33];
// 0 ���� 1 ���� 2 �밢��
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> arr[i][j];
	dp[1][1][0] = 1;
	for (int i = 1; i <= 32; i++) {
		for (int j = 1; j <= 32; j++) {
			// ���� -> ����
			if (j + 2 <= 32 && !arr[i][j+2])
				dp[i][j + 1][0] += dp[i][j][0];
			// �밢�� -> ����
			if (i + 1 <= 32 && j + 2 <= 32 && !arr[i+1][j+2])
				dp[i + 1][j + 1][0] += dp[i][j][2];
			// ���� -> ����
			if (i + 2 <= 32 && !arr[i+2][j])
				dp[i + 1][j][1] += dp[i][j][1];
			// �밢�� -> ����
			if (i + 2 <= 32 && j + 1 <= 32 && !arr[i+2][j+1])
				dp[i + 1][j + 1][1] += dp[i][j][2];
			// ���� -> �밢��
			if (i + 1 <= 32 && j + 2 <= 32 && !arr[i+1][j+1] && !arr[i+1][j+2] && !arr[i][j+2])
				dp[i][j + 1][2] += dp[i][j][0];
			// ���� -> �밢��
			if (i + 2 <= 32 && j + 1 <= 32 && !arr[i+1][j+1] && !arr[i+2][j] && !arr[i+2][j+1])
				dp[i + 1][j][2] += dp[i][j][1];
			// �밢�� -> �밢��
			if (i + 2 <= 32 && j + 2 <= 32 && !arr[i + 1][j + 2] && !arr[i + 2][j + 1] && !arr[i + 2][j + 2])
				dp[i + 1][j + 1][2] += dp[i][j][2];
		}
	}
	cout << dp[n][n - 1][0] + dp[n - 1][n - 1][2] + dp[n - 1][n][1];
	return 0;
}