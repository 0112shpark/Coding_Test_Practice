#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
string res;
string chn;
string chn1;

char ret(char i) {
	if (i == '0') {
		return '1';
	}
	else {
		return '0';
	}
}
void alter(int i) {

	chn[i - 1] = ret(chn[i - 1]);
	chn[i] = ret(chn[i]);
	if (i + 1 < n) {
		chn[i + 1] = ret(chn[i + 1]);
	}
}
void alter1(int i) {

	chn1[i - 1] = ret(chn1[i - 1]);
	chn1[i] = ret(chn1[i]);
	if (i + 1 < n) {
		chn1[i + 1] = ret(chn1[i + 1]);
	}
}
int main() {

	cin >> n;
	int cnt = 0;
	int str;
	cin >> chn;
	chn1 = chn;
	cin >> res;
	for (int i = 1; i < n; i++) {
		if (chn[i - 1] != res[i - 1]) {
			
			alter(i);
			
			cnt++;
		}
	}
	

	int fail = 0;
	for (int i = 0; i < n; i++) {
		if (chn[i] != res[i]) {
			fail = 1;
			break;
		}
	}
	if (fail) {
		cnt = 1;
	}
	else {
		cout << cnt;
		return 0;
	}


	chn1[0] = ret(chn1[0]);
	chn1[1] = ret(chn1[1]);
	
	for (int i = 1; i < n; i++) {
		if (chn1[i - 1] != res[i - 1]) {
			alter1(i);
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (chn1[i] != res[i]) {
			
			cout << -1;
			return 0;
		}
	}
	
		cout << cnt;
		return 0;
}