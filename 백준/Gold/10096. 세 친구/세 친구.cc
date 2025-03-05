/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10096                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10096                          #+#        #+#      #+#    */
/*   Solved: 2025/03/04 21:15:32 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint64_t n;
    std::string u, last = "";
    std::cin >> n >> u;
    if (n % 2 == 0)
    {
        std::cout << "NOT POSSIBLE" << '\n';
    }
    else
    {
        uint64_t length = n / 2;
        uint64_t count = 0;
        uint64_t i;
        bool duplicate = false;
        for (i = 0; i < u.length(); i++)
        {
            bool valid = true;
            uint64_t j;
            for (j = 0; j < length; j++)
            {
                uint64_t idx1 = (j < i ? j : j + 1);
                uint64_t idx2 = (j + length < i ? j + length : j + length + 1);
                if (u[idx1] != u[idx2])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                count++;
                if (last == "")
                {
                    for (uint64_t j = 0; j < length; j++)
                    {
                        uint64_t idx2 = ((j + length) < i ? (j + length) : (j + length + 1));
                        last.push_back(u[idx2]);
                    }
                }
                else
                {
                    std::string cur = "";
                    for (uint64_t j = 0; j < length; j++)
                    {
                        uint64_t idx2 = ((j + length) < i ? (j + length) : (j + length + 1));
                        cur.push_back(u[idx2]);
                    }
                    if (cur != last)
                    {
                        duplicate = true;
                        break;
                    }
                }
            }
        }

        if (duplicate)
        {
            std::cout << "NOT UNIQUE" << '\n';
        }
        else if (count == 0)
        {
            std::cout << "NOT POSSIBLE" << '\n';
        }
        else
        {
            std::cout << last << '\n';
        }
    }

    return 0;
}
