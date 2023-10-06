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
			//a 문자열에서 j까지와 b문자열에서 i까지의 가장 긴 문자열 = dp[i][j]
			//만약 b[i]와 a[j]가 다를경우, max(dp[i-1][j],dp[i][j-1])->어차피 다르니깐 b문자열 전 혹을 a문자열 전까지 비교
			if (b[i] != a[j]) {
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
			else {
				//같다면 [i-1][j-1]에 1 더한 값과 현재값의 max
				dp[i+1][j+1] = max(dp[i ][j ]+1, dp[i+1][j+1]);
			}
			ans = max(ans, dp[i+1][j+1]);
		}
	}
	
	cout << ans;
}