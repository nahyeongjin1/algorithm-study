/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 31403                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/31403                          #+#        #+#      #+#    */
/*   Solved: 2025/02/05 19:47:24 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using std::stoi;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string a, b, c;

    std::cin >> a >> b >> c;

    std::cout << stoi(a) + stoi(b) - stoi(c) << '\n'
              << stoi(a + b) - stoi(c) << '\n';

    return 0;
}