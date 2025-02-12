/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 29699                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/29699                          #+#        #+#      #+#    */
/*   Solved: 2025/02/12 18:47:30 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string welcome = "WelcomeToSMUPC";
    int n;

    std::cin >> n;
    n = (n - 1) % welcome.length();
    std::cout << welcome.at(n);

    return 0;
}