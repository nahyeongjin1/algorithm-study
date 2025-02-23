/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1541                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1541                           #+#        #+#      #+#    */
/*   Solved: 2025/02/23 18:38:05 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

void delete_prefix_zero(std::string &s)
{
    std::string::iterator i = s.begin();
    while (*i == 0)
    {
        s.erase(i);
    }
    return;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string exp;
    std::cin >> exp;
    std::queue<int> plus;
    std::queue<int> minus;
    std::string operand = "";
    std::string::iterator iter = exp.begin();
    bool toggle = false;

    while (true)
    {
        if (*iter >= '0' && *iter <= '9')
        {
            operand += *iter;
        }
        else
        {
            delete_prefix_zero(operand);
            if (!toggle)
            {
                plus.push(std::stoi(operand));
            }
            else
            {
                minus.push(std::stoi(operand));
            }
            operand = "";
        }
        if (*iter == '-')
        {
            toggle = true;
        }
        if (iter == exp.end())
        {
            break;
        }
        iter++;
    }
    int output = 0;
    while (!plus.empty())
    {
        output += plus.front();
        plus.pop();
    }
    while (!minus.empty())
    {
        output -= minus.front();
        minus.pop();
    }
    std::cout << output;

    return 0;
}