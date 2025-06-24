/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9251                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9251                           #+#        #+#      #+#    */
/*   Solved: 2025/04/06 19:39:52 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    string a, b;
    std::cin >> a >> b;

    int a_len = a.length(), b_len = b.length();
    vector<vector<uint16_t>> dp(a_len + 1, vector<uint16_t>(b_len + 1, 0));

    // dp[i][j]는 a의 처음 i글자와 b의 처음 j글자의 LCS 길이를 저장
    // dp[0][j]와 dp[i][0]은 0으로 초기화
    // dp[i][j]는 a[i-1]와 b[j-1]이 같으면
    // dp[i][j] = dp[i-1][j-1] + 1
    // 그렇지 않으면 dp[i][j] = max(dp[i-1][j], dp[i][j-1])로 계산
    // 최종적으로 dp[a_len][b_len]이 LCS의 길이가 됨

    for (int i = 1; i <= a_len; ++i)
    {
        for (int j = 1; j <= b_len; ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // LCS의 길이를 출력
    std::cout << dp[a_len][b_len] << '\n';

    return 0;
}