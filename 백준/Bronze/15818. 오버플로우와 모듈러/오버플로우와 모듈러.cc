/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15818                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15818                          #+#        #+#      #+#    */
/*   Solved: 2025/03/10 21:41:57 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 1 <= n <= 100
    uint32_t m; // 1 <= m <= 2,147,483,647

    std::cin >> n >> m;

    unsigned long long output = 1;
    std::queue<unsigned long long> q;

    while (n--)
    {
        unsigned long long temp;
        std::cin >> temp;
        q.push(temp);
    }
    while (!q.empty())
    {
        unsigned long long cur = q.front();
        q.pop();
        output = (output * (cur % m)) % m;
    }

    std::cout << output << '\n';

    return 0;
}