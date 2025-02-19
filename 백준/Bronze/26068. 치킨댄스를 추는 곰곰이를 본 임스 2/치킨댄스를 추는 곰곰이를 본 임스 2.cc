/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 26068                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/26068                          #+#        #+#      #+#    */
/*   Solved: 2025/02/19 22:18:08 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n, count = 0;
    std::cin >> n;
    for (auto i = 0; i < n; i++)
    {
        std::string input;
        std::cin >> input;
        input.erase(0, 2);
        if (std::stoi(input) <= 90)
        {
            count++;
        }
    }

    std::cout << count;

    return 0;
}