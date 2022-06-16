#include <iostream>
#include <set>
#include <memory.h>
#include <stdio.h>

#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;
int dp[50][50];

int main(){
    // freopen("input.txt", "r", stdin);
    int d;
    cin >> d;
    while (d--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        memset(dp, 0, sizeof(dp));
        set<int> s;
        REP(i, k)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == 1)
                {
                    if (j == 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }
                else
                {
                    if (s.find(i) != s.end())
                    {
                        dp[i][j] = ((j == 0) ? 0 : dp[i - 1][j - 1]);
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j + 1] + ((j == 0) ? 0 : dp[i - 1][j - 1]);
                    }
                }
            }
        }
        cout << dp[2 * n][0] << endl;
    }
}
