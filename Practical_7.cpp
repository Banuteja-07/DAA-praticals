#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minCoins(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount];
}

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    int result = minCoins(coins, amount);

    if (result == INT_MAX)
        cout << "Change cannot be made" << endl;
    else
        cout << "Minimum number of coins = " << result << endl;

    return 0;
}
