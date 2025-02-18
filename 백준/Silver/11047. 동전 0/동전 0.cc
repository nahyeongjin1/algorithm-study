/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11047                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11047                          #+#        #+#      #+#    */
/*   Solved: 2025/02/18 21:13:22 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n;
    int k, output = 0;
    std::cin >> n >> k;
    std::vector<int> value(n);
    for (auto i = 0; i < n; i++)
    {
        std::cin >> value.at(i);
    }
    while (k != 0)
    {
        if (k - value.back() < 0)
        {
            value.pop_back();
        }
        else
        {
            k -= value.back();
            output++;
        }
    }
    std::cout << output;

    return 0;
}