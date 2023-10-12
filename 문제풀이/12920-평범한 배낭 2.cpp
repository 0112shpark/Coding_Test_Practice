#include <iostream>
#include <vector>
#include <algorithm>


//���԰� v�� ������ K�� �ִٸ�, 1,2..k���� ����� n�� �� ���̰� n�� �� ��ġ�ִ� �������� ����
// ��� ���ϸ� o(NMK)�Ƿ� �ð��ʰ�. 
//�ִ� ���� 10000. �־��� k���� ���� �ŵ������� ������ �����ش�. 
//�׸��� ���� ������ �� �������� ���� k=>log2(K)+1=> o(NMlog(k))
// log2(10000) = 14.xx*100 =>1400 �̻��� dp�迭

using namespace std;

int dp[1500][10010];
//weight, cost
vector<pair<int, int>> arr;
int n, m;


int main() {

	cin >> n >> m;

	//dummy data�־��ֱ�
	//arr.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		int w, v, k;
		cin >> w >> v >> k;
		
		int factor = 1;
		while (factor * 2 -1 <= k) {
			//2^0 ~ 2^(n-1) �� ���ڷ� 2^n -1 ������ ���� ���� �� ����.
			// 1,2,4,8,16,32 6���� ���ڷ� 1~63���� ���� �� ����. 2^6-1�� 2^(6-1)������ ���� �� ����.
			// �׷��Ƿ� �־��� k�� �����ϱ� ���ؼ� k-1���� ���� �� �ִ� n�� ã�ƾ���.
			arr.push_back({ factor * w,factor * v });
			factor *=2;
		}
		if (factor - 1 != k) {
			// ���� ���� �� �������� �־��ֱ�.
			arr.push_back({ ((k - (factor - 1)) * w),((k - (factor - 1)) * v) });
		}
	}
	
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i].first > j) {
				
				dp[i+1][j] = dp[i][j];
			}
			else {
				dp[i+1][j] = max(dp[i][j - arr[i].first] + arr[i].second, dp[i][j]);
			}
		}
	}
	
	cout << dp[arr.size()][m];
}