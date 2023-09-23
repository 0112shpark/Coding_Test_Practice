#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#define _CTR_SECURE_NO_WARNING

using namespace std;


int main() {

	//ios_base::sync_with_stdio(false);

	

	char arr[500010];

	int n;
	scanf("%d", &n);

	scanf("%s", arr);
	

	int red = 0;
	int red1 = 0;
	int blue = 0;
	int blue1 = 0;
	int flag = 0;
	//red
	for (int i = n - 1; i >= 0; i--) {
		if (!flag && arr[i] == 'B') {
			flag = 1;
			continue;
		}
		if (flag && arr[i] == 'R') {
			red++;
		}
	}
	flag = 0;
	for (int i = 0; i < n; i++) {
		if (!flag && arr[i] == 'B') {
			flag = 1;
			continue;
		}
		if (flag && arr[i] == 'R') {
			red1++;
		}
	}
	red = min(red, red1);
	flag = 0;
	//blue
	for (int i = n - 1; i >= 0; i--) {
		if (!flag && arr[i] == 'R') {
			flag = 1;
			continue;
		}
		if (flag && arr[i] == 'B') {
			blue++;
		}
	}
	flag = 0;
	for (int i = 0; i <n; i++) {
		if (!flag && arr[i] == 'R') {
			flag = 1;
			continue;
		}
		if (flag && arr[i] == 'B') {
			blue1++;
		}
	}
	blue = min(blue, blue1);
	printf("%d", min(red, blue));
}