#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int cheese[301], potato[301];
int dp[301][301];
int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) 
		cin >> cheese[i] >> potato[i];
	for (int i = 1; i <= N; i++) { 
		for (int j = M; j >= cheese[i]; j--) { // ġ�����
			for (int k = K; k >= potato[i]; k--) {  // ����Ƣ��
				dp[j][k] = max(dp[j][k], dp[j - cheese[i]][k - potato[i]] + 1); 
			}
		}
	}
	cout << dp[M][K];
	return 0;
}