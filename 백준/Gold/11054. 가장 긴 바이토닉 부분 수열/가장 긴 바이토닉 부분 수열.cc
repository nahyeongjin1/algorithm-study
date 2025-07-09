/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11054                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11054                          #+#        #+#      #+#    */
/*   Solved: 2025/07/09 12:16:20 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm> // max_element

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n;
    std::cin >> n;

    vector<uint16_t> a(n);
    for (uint16_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    vector<uint16_t> ldp(n, 1);
    vector<uint16_t> rdp(n, 1);

    for (uint16_t i = 0; i < n; i++)
    {
        for (uint16_t j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                ldp[i] = std::max(uint16_t(ldp[j] + 1), ldp[i]);
            }
            if (a[n - 1 - i] > a[n - 1 - j])
            {
                rdp[n - 1 - i] = std::max(uint16_t(rdp[n - 1 - j] + 1), rdp[n - 1 - i]);
            }
        }
    }

    vector<uint16_t> result(n);
    for (uint16_t i = 0; i < n; i++)
    {
        result[i] = ldp[i] + rdp[i] - 1;
    }

    std::cout << *std::max_element(result.begin(), result.end()) << '\n';

    return 0;
}