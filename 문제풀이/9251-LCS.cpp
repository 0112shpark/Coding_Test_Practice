#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	string a;
	string b;
	int ans = 0;
	

	cin >> a >> b;
	
	//b*a
	int** dp = new int* [b.length() + 1];
	for (int i = 0; i <= b.length(); i++) {
		dp[i] = new int[a.length() + 1];
	}
	for (int i = 0; i <= b.length(); i++) {
		for (int j = 0; j <= a.length(); j++) {
			dp[i][j] = 0;
		} 
	}


	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			//a ���ڿ����� j������ b���ڿ����� i������ ���� �� ���ڿ� = dp[i][j]
			//���� b[i]�� a[j]�� �ٸ����, max(dp[i-1][j],dp[i][j-1])->������ �ٸ��ϱ� b���ڿ� �� Ȥ�� a���ڿ� ������ ��
			if (b[i] != a[j]) {
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
			else {
				//���ٸ� [i-1][j-1]�� 1 ���� ���� ���簪�� max
				dp[i+1][j+1] = max(dp[i ][j ]+1, dp[i+1][j+1]);
			}
			ans = max(ans, dp[i+1][j+1]);
		}
	}
	
	cout << ans;
}