#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> score(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> score.at(i);
    }

    std::vector<int> dp(n, 0);
    dp[0] = score[0];
    if (n >= 2)
    {
        dp[1] = score[0] + score[1];
    }
    if (n >= 3)
    {
        dp[2] = std::max(score[0] + score[2], score[1] + score[2]);
    }

    for (int i = 3; i < n; i++)
    {
        dp[i] = std::max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
    }

    std::cout << dp[n - 1] << "\n";
    return 0;
}
