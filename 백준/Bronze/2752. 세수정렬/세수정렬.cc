/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2752                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2752                           #+#        #+#      #+#    */
/*   Solved: 2025/03/10 09:31:36 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::vector<uint32_t> vec(3);
    std::cin >> vec[0] >> vec[1] >> vec[2];
    std::sort(vec.begin(), vec.end());
    std::cout << vec[0] << ' ' << vec[1] << ' ' << vec[2] << '\n';

    return 0;
}