#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	if (n == 1) {
		printf("1");
	}
	else {
		int range = 5;
		int curNum = 7;
		int ans = 2;
		while (1) {
			if (n <= curNum) {
				printf("%d", ans);
				break;
			}
			else {
				
				range += 6;
				curNum = curNum + range + 1;
				ans++;
			}
		}
	}
}