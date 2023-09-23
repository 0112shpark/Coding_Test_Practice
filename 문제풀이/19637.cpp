#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>


using namespace std;

int main() {

	vector<int>arr;
	vector<string> str;
	vector<string> ans;
	int m, n;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp;
		int val;
		cin >> temp >> val;
		arr.push_back(val);
		str.push_back(temp);
	}

	int value;
	int index;
	for (int i = 0; i < m; i++) {
		cin >> value;
		index = lower_bound(arr.begin(), arr.end(), value) - arr.begin();
		ans.push_back(str[index]);
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << '\n';
	}
}
