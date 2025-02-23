/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1074                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1074                           #+#        #+#      #+#    */
/*   Solved: 2025/02/23 19:33:58 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

unsigned int z(unsigned int n, int r, int c)
{
    if (n == 0)
        return 0;
    unsigned int half = 1u << (n - 1);
    unsigned int area = half * half;
    if (r < half && c < half)
        return z(n - 1, r, c);
    else if (r < half && c >= half)
        return area + z(n - 1, r, c - half);
    else if (r >= half && c < half)
        return 2 * area + z(n - 1, r - half, c);
    else if (r >= half && c >= half)
        return 3 * area + z(n - 1, r - half, c - half);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned int n;
    int r, c;
    std::cin >> n >> r >> c;

    std::cout << z(n, r, c) << '\n';

    return 0;
}