
#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j, k, len, cost;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    int dp[n + 1][n + 1];

    printf("Enter dimensions: ");
    for(i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    for(i = 1; i <= n; i++)
        dp[i][i] = 0;

    for(len = 2; len <= n; len++)
    {
        for(i = 1; i <= n - len + 1; i++)
        {
            j = i + len - 1;
            dp[i][j] = INT_MAX;

            for(k = i; k < j; k++)
            {
                cost = dp[i][k] + dp[k+1][j]
                     + p[i-1] * p[k] * p[j];

                if(cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum multiplications: %d\n", dp[1][n]);

    return 0;
}

