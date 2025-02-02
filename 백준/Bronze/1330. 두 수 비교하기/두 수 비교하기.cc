/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1330                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1330                           #+#        #+#      #+#    */
/*   Solved: 2025/02/02 14:35:44 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    int a, b;
    std::string output;
    std::cin >> a >> b;
    if (a > b)
        output = ">";
    else if (a < b)
        output = "<";
    else
        output = "==";
    std::cout << output << std::endl;
    return 0;
}