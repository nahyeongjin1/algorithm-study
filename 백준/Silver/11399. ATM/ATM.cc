/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11399                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11399                          #+#        #+#      #+#    */
/*   Solved: 2025/02/18 21:13:15 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    long long int sum = 0;
    short n;
    std::cin >> n;
    std::vector<short> vec(n);
    for (auto i = 0; i < n; i++)
    {
        std::cin >> vec.at(i);
    }
    std::sort(vec.begin(), vec.end());
    for (auto i = 0; i < n; i++)
    {
        sum += vec.at(i) * (n - i);
    }
    std::cout << sum;

    return 0;
}