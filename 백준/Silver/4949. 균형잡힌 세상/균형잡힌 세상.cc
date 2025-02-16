/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4949                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4949                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 17:47:33 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    while (true)
    {
        std::string line, temp, output;
        std::getline(std::cin, line);
        if (line == ".")
        {
            break;
        }
        for (auto i = line.begin(); i != line.end(); i++)
        {
            if (*i == '(' or *i == ')' or *i == '[' or *i == ']')
            {
                temp += *i;
            }
        }
        while (true)
        {
            auto parentheses = temp.find("()");
            if (parentheses != std::string::npos)
            {
                temp.erase(temp.begin() + parentheses);
                temp.erase(temp.begin() + parentheses);
                continue;
            }
            auto brackets = temp.find("[]");
            if (brackets != std::string::npos)
            {
                temp.erase(temp.begin() + brackets);
                temp.erase(temp.begin() + brackets);
                continue;
            }
            break;
        }
        output = temp.empty() ? "yes" : "no";
        std::cout << output << '\n';
    }

    return 0;
}