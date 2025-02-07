/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10811                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10811                          #+#        #+#      #+#    */
/*   Solved: 2025/02/07 19:25:01 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    short n, m, i, j;
    std::vector<short> bagooni, temp;

    std::cin >> n >> m;
    for (short t = 0; t < n; t++)
    {
        bagooni.push_back(t + 1);
    }
    for (short t = 0; t < m; t++)
    {
        std::cin >> i >> j;
        for (short u = i - 1; u <= j - 1; u++)
        {
            temp.push_back(bagooni.at(u));
        }
        for (short u = i - 1; u <= j - 1; u++)
        {
            bagooni.at(u) = temp.at(temp.size() - 1);
            temp.pop_back();
        }
        temp.clear();
    }
    for (short t = 0; t < n; t++)
    {
        std::cout << bagooni.at(t) << ' ';
    }
    return 0;
}