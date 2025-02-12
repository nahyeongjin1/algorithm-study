/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1181                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1181                           #+#        #+#      #+#    */
/*   Solved: 2025/02/06 19:41:25 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::set<std::string> set;
    std::vector<std::string> vector;
    short n, target = 0;

    std::cin >> n;
    for (auto i = 0; i < n; i++)
    {
        std::string temp;
        std::cin >> temp;
        set.insert(temp);
    }

    for (auto i = set.begin(); i != set.end(); i++)
    {
        vector.push_back(*i);
    }

    for (auto i = 0; i < vector.size() - 1; i++)
    {
        short min_length = vector.at(i).length();
        target = i;
        for (auto j = i + 1; j < vector.size(); j++)
        {
            if (vector.at(j).length() < min_length)
            {
                min_length = vector.at(j).length();
                target = j;
            }
        }
        if (target != i)
        {
            std::swap(vector.at(target), vector.at(i));
        }
    }

    for (auto i = 0; i < vector.size() - 1; i++)
    {
        target = i;
        for (auto j = i + 1; j < vector.size(); j++)
        {
            if (vector.at(i).length() != vector.at(j).length())
            {
                break;
            }
            if (vector.at(target) > vector.at(j))
            {
                target = j;
            }
        }
        if (target != i)
        {
            std::swap(vector.at(target), vector.at(i));
        }
    }

    for (auto i = vector.begin(); i != vector.end(); i++)
    {
        std::cout << *i << '\n';
    }

    return 0;
}