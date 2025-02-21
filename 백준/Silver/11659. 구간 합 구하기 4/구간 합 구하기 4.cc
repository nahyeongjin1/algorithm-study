/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11659                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11659                          #+#        #+#      #+#    */
/*   Solved: 2025/02/20 23:20:46 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;
    std::vector<unsigned int> prefix_sum(n);
    std::cin >> prefix_sum.at(0);
    for (int i = 1; i < n; i++)
    {
        std::cin >> prefix_sum.at(i);
        prefix_sum.at(i) += prefix_sum.at(i - 1);
    }
    for (int i = 0; i < m; i++)
    {
        int start, end;
        std::cin >> start >> end;
        unsigned int output = 0;
        output += prefix_sum.at(end - 1);
        if (start != 1)
        {
            output -= prefix_sum.at(start - 2);
        }
        std::cout << output << '\n';
    }

    return 0;
}