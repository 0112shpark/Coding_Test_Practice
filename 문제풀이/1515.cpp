#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	
	string str;
	string temp;
	string num;
	int idx = 0;
	int ans = 0;
	cin >> str;

	//cout << str.size();
	for (int i = 0; i < 30000; i++) {
		temp = to_string(i);
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == str[idx]) {
				idx++;
				if (idx == str.size()) {
					cout << i;
					return 0;
				}
			}
		}
	}
}