#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans[1000002];

int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int value;

        scanf("%d %d", &m, &value);

        int values[m];

        for(int j = 0; j<m; ++j)
            scanf("%d", &values[j]);

        memset(ans, 999999, sizeof(ans));

        ans[0] = 0;

        for(int j = 0; j<m; ++j)

            for(int k = values[j]; k<=value; k++)

                ans[k] = min(ans[k], ans[k-values[j]]+1);

        printf("%d\n", ans[value]);
    }
    return 0;
}