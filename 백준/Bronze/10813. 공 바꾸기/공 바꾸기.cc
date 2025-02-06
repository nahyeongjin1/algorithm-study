/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10813                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10813                          #+#        #+#      #+#    */
/*   Solved: 2025/02/06 21:12:02 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short n, m, i, j, temp;
    std::vector<short> bagooni;

    std::cin >> n >> m;
    for (short t = 0; t < n; t++)
    {
        bagooni.push_back(t + 1);
    }
    for (short t = 0; t < m; t++)
    {
        std::cin >> i >> j;
        temp = bagooni.at(i - 1);
        bagooni.at(i - 1) = bagooni.at(j - 1);
        bagooni.at(j - 1) = temp;
    }
    for (short t = 0; t < n; t++)
    {
        std::cout << bagooni.at(t) << ' ';
    }
    return 0;
}