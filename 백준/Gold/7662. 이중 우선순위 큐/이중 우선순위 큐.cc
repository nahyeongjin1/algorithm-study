/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7662                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7662                           #+#        #+#      #+#    */
/*   Solved: 2025/02/26 16:31:56 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned short t;
    std::cin >> t;

    for (auto i = 0; i < t; i++)
    {
        int k;
        std::cin >> k; // (진행할 연산 횟수)k <= 1,000,000
        std::multiset<int> ms;
        for (auto j = 0; j < k; j++)
        {
            char op;
            int n;
            std::cin >> op >> n;
            if (op == 'I')
            {
                ms.insert(n);
            }
            else if (ms.empty())
            {
                continue;
            }
            else
            {
                if (n == -1)
                {
                    ms.erase(ms.begin());
                }
                else if (n == 1)
                {
                    ms.erase(--ms.end());
                }
            }
        }
        if (ms.empty())
        {
            std::cout << "EMPTY" << '\n';
        }
        else
        {
            std::cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}
