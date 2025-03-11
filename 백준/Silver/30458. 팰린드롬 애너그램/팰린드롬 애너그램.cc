/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 30458                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/30458                          #+#        #+#      #+#    */
/*   Solved: 2025/03/10 22:34:35 by skgudwls      ###          ###   ##.kr    */
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

    uint32_t n; // 3 <= n <= 200,000
    std::cin >> n;
    string s;
    std::cin >> s;

    vector<uint32_t> cnt('z' - 'a' + 1, 0);
    for (const char &c : s)
    {
        cnt[c - 'a']++;
    }

    int odd_count = 0;
    for (const uint32_t &v : cnt)
    {
        if ((v & 1) == 1)
        {
            odd_count++;
        }
    }

    bool can = false;
    if ((n & 1) == 1 && odd_count == 1 && (cnt[s[n / 2] - 'a'] & 1) == 1)
    {
        can = true;
    }
    else if ((n & 1) == 0 && odd_count == 0)
    {
        can = true;
    }

    std::cout << (can ? "Yes" : "No") << "\n";

    return 0;
}
