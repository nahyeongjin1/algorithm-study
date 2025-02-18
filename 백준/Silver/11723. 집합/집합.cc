/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11723                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11723                          #+#        #+#      #+#    */
/*   Solved: 2025/02/18 19:28:16 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    const short MAX = 20;
    std::set<short> s;
    int m;
    std::cin >> m;
    for (auto i = 0; i < m; i++)
    {
        std::string input;
        std::cin >> input;
        if (input == "all")
        {
            for (auto j = 0; j < MAX; j++)
            {
                s.insert(j + 1);
            }
        }
        else if (input == "empty")
        {
            s.clear();
        }
        else
        {
            short x;
            std::cin >> x;
            if (input == "add")
            {
                s.insert(x);
            }
            else if (input == "remove")
            {
                s.erase(x);
            }
            else if (input == "check")
            {
                if (s.find(x) != s.end())
                {
                    std::cout << 1 << '\n';
                }
                else
                {
                    std::cout << 0 << '\n';
                }
            }
            else if (input == "toggle")
            {
                if (s.find(x) != s.end())
                {
                    s.erase(x);
                }
                else
                {
                    s.insert(x);
                }
            }
        }
    }

    return 0;
}