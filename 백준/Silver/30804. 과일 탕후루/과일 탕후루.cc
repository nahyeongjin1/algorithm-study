/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 30804                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/30804                          #+#        #+#      #+#    */
/*   Solved: 2025/03/03 17:16:39 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint32_t n;
    std::cin >> n;

    uint32_t max_fruits = 0;
    uint32_t window_start = 0;

    uint16_t first = 10, second = 10, last_fruit = 10;
    uint32_t last_count = 0;
    for (uint32_t i = 0; i < n; i++)
    {
        uint16_t input;
        std::cin >> input;

        if (input == first || input == second)
        {
            if (input == last_fruit)
            {
                last_count++;
            }
            else
            {
                last_count = 1;
            }
        }
        else
        {
            window_start = i - last_count;
            first = last_fruit;
            second = input;
            last_count = 1;
        }
        last_fruit = input;
        uint32_t current_window = i - window_start + 1;
        max_fruits = std::max(max_fruits, current_window);
    }
    std::cout << max_fruits << '\n';
    return 0;
}