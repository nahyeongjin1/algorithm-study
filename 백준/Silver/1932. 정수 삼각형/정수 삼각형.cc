/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1932                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1932                           #+#        #+#      #+#    */
/*   Solved: 2025/03/23 14:04:46 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint32_t n;
    std::cin >> n;

    vector<vector<uint32_t>> tree(n);
    uint16_t floor = 0;

    // 입력
    while (floor != n)
    {
        tree[floor].resize(floor + 1);
        for (uint16_t i = 0; i <= floor; i++)
        {
            uint32_t input;
            std::cin >> input;
            tree[floor][i] = input;
        }
        floor++;
    }

    // from bottom to top
    for (uint16_t i = 0; i < n - 1; i++)
    {
        const vector<uint32_t> &cur = tree[n - i - 1];
        for (uint16_t j = 0; j < cur.size() - 1; j++)
        {
            uint32_t max = std::max(cur[j], cur[j + 1]);
            tree[n - i - 2][j] += max;
        }
    }

    std::cout << tree[0][0] << '\n';

    return 0;
}