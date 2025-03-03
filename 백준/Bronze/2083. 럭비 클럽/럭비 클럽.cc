/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2083                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2083                           #+#        #+#      #+#    */
/*   Solved: 2025/03/03 21:23:24 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    while (true)
    {
        std::string name;
        uint16_t age, weight;
        std::cin >> name >> age >> weight;
        if (name == "#")
        {
            break;
        }
        std::cout << name << ' ';
        if (age > 17 || weight >= 80)
        {
            std::cout << "Senior";
        }
        else
        {
            std::cout << "Junior";
        }
        std::cout << '\n';
    }

    return 0;
}