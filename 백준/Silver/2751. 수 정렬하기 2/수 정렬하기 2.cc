/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2751                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2751                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 22:35:41 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> vec(n);

    for (auto i = 0; i < n; i++)
    {
        std::cin >> vec.at(i);
    }
    std::sort(vec.begin(), vec.end());
    for (auto i = 0; i < n; i++)
    {
        std::cout << vec.at(i) << '\n';
    }

    return 0;
}