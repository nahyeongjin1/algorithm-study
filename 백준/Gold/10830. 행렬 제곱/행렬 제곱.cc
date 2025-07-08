/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10830                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10830                          #+#        #+#      #+#    */
/*   Solved: 2025/07/08 15:00:31 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n;
    uint64_t b;

    std::cin >> n >> b;

    vector<vector<uint32_t>> matrix(n, vector<uint32_t>(n, 0));
    for (uint16_t i = 0; i < n; i++)
    {
        for (uint16_t j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    // 어떤 matrix에 identity matrix를 곱하면 그 matrix가 그대로 나옴
    vector<vector<uint32_t>> result(n, vector<uint32_t>(n, 0));
    for (uint16_t i = 0; i < n; i++)
    {
        result[i][i] = 1;
    }

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            vector<vector<uint32_t>> temp(n, vector<uint32_t>(n, 0));
            for (uint16_t i = 0; i < n; i++)
            {
                for (uint16_t j = 0; j < n; j++)
                {
                    for (uint16_t k = 0; k < n; k++)
                    {
                        temp[i][j] += result[i][k] * matrix[k][j] % 1000;
                    }
                }
            }
            result = temp;
        }

        vector<vector<uint32_t>> temp(n, vector<uint32_t>(n, 0));
        for (uint16_t i = 0; i < n; i++)
        {
            for (uint16_t j = 0; j < n; j++)
            {
                for (uint16_t k = 0; k < n; k++)
                {
                    temp[i][j] += matrix[i][k] * matrix[k][j] % 1000;
                }
            }
        }
        matrix = temp;

        b /= 2;
    }

    for (uint16_t i = 0; i < n; i++)
    {
        for (uint16_t j = 0; j < n; j++)
        {
            std::cout << (j == 0 ? "" : " ") << result[i][j] % 1000;
        }
        std::cout << '\n';
    }

    return 0;
}