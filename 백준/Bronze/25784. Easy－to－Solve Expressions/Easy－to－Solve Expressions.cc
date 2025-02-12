/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25784                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25784                          #+#        #+#      #+#    */
/*   Solved: 2025/02/12 19:14:05 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const short SIZE = 3;
    std::vector<int> list(SIZE);

    std::cin >> list.at(0) >> list.at(1) >> list.at(2);
    for (auto i = 0; i < SIZE; i++)
    {
        if (list.at(i % SIZE) + list.at((i + 1) % SIZE) == list.at((i + 2) % SIZE))
        {
            std::cout << 1;
            break;
        }
        else if (list.at(i % SIZE) * list.at((i + 1) % SIZE) == list.at((i + 2) % SIZE))
        {
            std::cout << 2;
            break;
        }
        else if (i == SIZE - 1)
        {
            std::cout << 3;
            break;
        }
    }

    return 0;
}