/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5430                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5430                           #+#        #+#      #+#    */
/*   Solved: 2025/02/25 19:35:56 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <deque>

typedef unsigned int ui;
typedef unsigned short us;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    // 1 <= t <= 100
    unsigned short t;
    std::cin >> t;
    for (auto i = 0; i < t; i++)
    {
        // 1 <= p.length() <= 100,000
        std::string p;
        // 0 <= n <= 100,000
        ui n;
        // 입력 시에 저장하지 않을 문자들
        char trash;
        std::cin >> p >> n >> trash;
        // 1 <= x_i <= 100
        std::deque<us> dq(n, 0);
        for (auto j = 0; j < n; j++)
        {
            std::cin >> dq.at(j) >> trash;
        }
        if (n == 0)
        {
            std::cin >> trash;
        }
        bool error = false;
        bool reverse = false;
        for (auto j = 0; j < p.length(); j++)
        {
            if (p.at(j) == 'R')
            {
                reverse = !reverse;
            }
            else if (dq.empty())
            {
                error = true;
                break;
            }
            else if (!reverse)
            {
                dq.pop_front();
            }
            else if (reverse)
            {
                dq.pop_back();
            }
        }
        if (error)
        {
            std::cout << "error" << '\n';
        }
        else if (dq.empty())
        {
            std::cout << "[]" << '\n';
        }
        else
        {
            std::cout << '[';
            if (reverse)
            {
                std::cout << dq.back();
                for (auto j = dq.rbegin(); j != dq.rend(); j++)
                {
                    if (j == dq.rbegin())
                    {
                        continue;
                    }
                    std::cout << ',' << *j;
                }
            }
            else
            {
                std::cout << dq.front();
                for (auto j = dq.begin(); j != dq.end(); j++)
                {
                    if (j == dq.begin())
                    {
                        continue;
                    }
                    std::cout << ',' << *j;
                }
            }
            std::cout << ']' << '\n';
        }
    }

    return 0;
}