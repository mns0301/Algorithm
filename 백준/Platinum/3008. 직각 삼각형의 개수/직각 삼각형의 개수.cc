#include <stdio.h>
int main()
{

    int n, ans = 0;
    scanf("%d", &n);
    
    long long v[1500][2];
    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &v[i][0], &v[i][1]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                long long x1 = v[k][0] - v[j][0];
                long long y1 = v[k][1] - v[j][1];
                long long x2 = v[i][0] - v[j][0];
                long long y2 = v[i][1] - v[j][1];
                long long x3 = v[i][0] - v[k][0];
                long long y3 = v[i][1] - v[k][1];

                if (x1 * x2 + y1 * y2 == 0 || x1 * x3 + y1 * y3 == 0 || x3 * x2 + y3 * y2 == 0)
                    ans++;
            }
        }
    }

    printf("%d", ans);

    return 0;
}