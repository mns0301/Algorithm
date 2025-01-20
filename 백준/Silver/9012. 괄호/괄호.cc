#include <stdio.h>

int main(void) {
	int t;
	char vps[51];
	int len;
	int gab;
	scanf("%d", &t);

	for (int k = 0; k < t; k++) {

		scanf("%s", vps);
		len = 0;
		gab = 1;
		while (vps[len]) len++;
		if (len % 2 == 0 && vps[len - 1] != '(') {
			for (int i = 0; i < len; i++) {
				if (vps[i] == '(') {
					gab = 1;
					while (vps[i + gab] != '(') {
						if (vps[i + gab] == 0) { 
							gab++;
							if (i + gab > len-1) break;
							continue;
						}
						vps[i] = 0;
						vps[i + gab] = 0;
						i = -1;
						break;
					}
				}
			}
		}
		gab = 0;
		for (int i = 0; i < len; i++) {
			if (vps[i] != 0) gab = 1;
		}
		if (gab) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}
/*
6
(())())
(((()())()
(()())((()))
((()()(()))(((())))()
()()()()(()()())()
(()((())()(
*/