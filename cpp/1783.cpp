#include <bits/stdc++.h>
using namespace std;

int N, M;
int main() {
	cin >> N >> M;
	// ������
	if (N == 1)
		cout << 1;
	// ���� 2ĭ
	else if (N == 2) {
		if (M >= 7)
			cout << 4;
		else
			cout << (M - 1) / 2 + 1;
	}
	else {
		// �湮�� ĭ 4�� ����
		if (M < 7)
			cout << min(4, M);
		// �̵���� ��� 1����
		else
			cout << M - 5 + 3;
	}
	return 0;
}