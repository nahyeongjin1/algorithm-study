/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14696                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14696                          #+#        #+#      #+#    */
/*   Solved: 2025/03/24 22:42:09 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 1 <= n <= 1,000
    std::cin >> n;

    while (n--)
    {
        uint16_t a;
        std::cin >> a;
        vector<uint16_t> paper_a(4, 0);
        for (uint16_t i = 0; i < a; i++)
        {
            uint16_t input;
            std::cin >> input;
            paper_a[input - 1]++;
        }
        uint16_t b;
        std::cin >> b;
        vector<uint16_t> paper_b(4, 0);
        for (uint16_t i = 0; i < b; i++)
        {
            uint16_t input;
            std::cin >> input;
            paper_b[input - 1]++;
        }
        bool draw = true;
        for (int16_t i = 3; i >= 0; i--)
        {
            if (paper_a[i] > paper_b[i])
            {
                std::cout << 'A' << '\n';
                draw = false;
                break;
            }
            else if (paper_a[i] < paper_b[i])
            {
                std::cout << 'B' << '\n';
                draw = false;
                break;
            }
        }
        if (draw)
        {
            std::cout << 'D' << '\n';
        }
    }

    return 0;
}