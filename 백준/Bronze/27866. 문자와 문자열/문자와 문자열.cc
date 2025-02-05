/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 27866                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/27866                          #+#        #+#      #+#    */
/*   Solved: 2025/02/05 11:22:22 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string s;
    short i;
    std::cin >> s >> i;
    std::cout << s.at(i - 1) << '\n';
    return 0;
}