/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1629                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1629                           #+#        #+#      #+#    */
/*   Solved: 2025/03/06 16:10:45 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    long long a, b, c;
    std::cin >> a >> b >> c;

    // 분할정복 거듭제곱
    long long result = 1;
    while (b)
    {
        if (b & 1)
        {
            result = (result * a) % c;
        }
        a = (a * a) % c;
        b = b >> 1;
    }
    std::cout << result % c << '\n';

    return 0;
}