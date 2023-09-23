#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void) {
	char str[1000000];
	scanf("%s", str);

	int alphabet[26];
	
	int len = strlen(str);
	for (int i = 0; i < 26; i++) {
		alphabet[i] = 0;
	}
	for (int i = 0; i < len; i++) {
		char temp = tolower(str[i]);
		alphabet[temp - 'a']++;
	}

	int max = 0;
	int ans = 0;
	bool flag = true;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == max) {
			flag = false;
		}
		else if (alphabet[i] > max) {
			max = alphabet[i];
			ans = i;
			flag = true;
		}
		
	}
	if (flag == false) {
		printf("?");
	}
	else {
		printf("%c", ans + 'A');
	}
}