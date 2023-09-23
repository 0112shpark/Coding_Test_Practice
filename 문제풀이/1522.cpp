#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int numa = 0;
	cin >> str;
	int ans = str.size();

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a') {
			numa++;
		}
	}
	for (int i = 0; i < str.size(); i++) {
		int cntb = 0;
		for (int j = i; j < i + numa; j++) {
			if (str[j % str.size()] == 'b') {
				cntb++;
			}
		}
		ans = min(ans, cntb);
	}
	cout << ans;
}