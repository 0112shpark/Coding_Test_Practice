#include <iostream>
#include <vector>
#include <algorithm>


//무게가 v인 물건이 K개 있다면, 1,2..k등을 사용해 n배 더 무겁고 n배 더 가치있는 물건으로 생각
// 모두 더하면 o(NMK)므로 시간초과. 
//최대 갯수 10000. 주어진 k보다 작은 거듭제곱수 까지만 나눠준다. 
//그리고 남은 갯수를 한 묶음으로 생각 k=>log2(K)+1=> o(NMlog(k))
// log2(10000) = 14.xx*100 =>1400 이상의 dp배열

using namespace std;

int dp[1500][10010];
//weight, cost
vector<pair<int, int>> arr;
int n, m;


int main() {

	cin >> n >> m;

	//dummy data넣어주기
	//arr.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		int w, v, k;
		cin >> w >> v >> k;
		
		int factor = 1;
		while (factor * 2 -1 <= k) {
			//2^0 ~ 2^(n-1) 의 숫자로 2^n -1 까지의 수를 만들 수 있음.
			// 1,2,4,8,16,32 6개의 숫자로 1~63까지 만들 수 있음. 2^6-1은 2^(6-1)까지로 만들 수 있음.
			// 그러므로 주어진 k를 분할하기 위해선 k-1까지 만들 수 있는 n을 찾아야함.
			arr.push_back({ factor * w,factor * v });
			factor *=2;
		}
		if (factor - 1 != k) {
			// 남은 갯수 한 묶음으로 넣어주기.
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