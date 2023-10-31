#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int l, c;
char arr[20];
int selected[20];
vector<string> pass;
char moeum[5] = { 'a','e','i','o','u' };
int cnt = 0;

int check_moeum(string a) {
	int mo_cnt = 0;
	int ja_cnt = 0;
	for (int i = 0; i < a.length(); i++) {
		int flag = 0;
		for (int j = 0; j < 5; j++) {
			if (a[i] == moeum[j]) {
				mo_cnt++;
				flag = 1;
			}
		}
		if (!flag) {
			ja_cnt++;
		}
	}
	if (mo_cnt >= 1 && ja_cnt >= 2) {
		return 1;
	}
	return 0;
}
void dfs(int cnt, int idx, string a) {

	if (cnt == l) {
		if (check_moeum(a)) {
			pass.push_back(a);
		}
		return;
	}
	for (int i = idx; i < c; i++) {
		if (selected[i] == 1) {
			continue;
		}
		a += arr[i];
		selected[i] = 1;
		dfs(cnt + 1, i + 1, a);
		a.pop_back();
		selected[i] = 0;
	}

}

int main() {

	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + c);
	
	string a = "";

	dfs(0,0,a);
	for (int i = 0; i < pass.size(); i++) {
		cout << pass[i] << endl;
	}
}