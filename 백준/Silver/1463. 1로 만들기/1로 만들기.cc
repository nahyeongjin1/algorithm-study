/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1463                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1463                           #+#        #+#      #+#    */
/*   Solved: 2025/02/18 22:02:52 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;
    if (n == 1)
    {
        std::cout << 0;
        return 0;
    }

    std::vector<int> vec1;
    std::vector<int> vec2;
    int count = 0;
    vec1.push_back(n);

    while (true)
    {
        std::vector<int>::iterator i;
        count++;
        if (count % 2 == 1)
        {
            for (i = vec1.begin(); i != vec1.end(); i++)
            {
                if (*i - 1 == 1)
                {
                    break;
                }
                vec2.push_back(*i - 1);
                if (*i % 2 == 0)
                {
                    if (*i / 2 == 1)
                    {
                        break;
                    }
                    vec2.push_back(*i / 2);
                }
                if (*i % 3 == 0)
                {
                    if (*i / 3 == 1)
                    {
                        break;
                    }
                    vec2.push_back(*i / 3);
                }
            }
            if (i != vec1.end())
            {
                break;
            }
            vec1.clear();
        }
        else
        {
            for (i = vec2.begin(); i != vec2.end(); i++)
            {
                if (*i - 1 == 1)
                {
                    break;
                }
                vec1.push_back(*i - 1);
                if (*i % 2 == 0)
                {
                    if (*i / 2 == 1)
                    {
                        break;
                    }
                    vec1.push_back(*i / 2);
                }
                if (*i % 3 == 0)
                {
                    if (*i / 3 == 1)
                    {
                        break;
                    }
                    vec1.push_back(*i / 3);
                }
            }
            if (i != vec2.end())
            {
                break;
            }
            vec2.clear();
        }
    }
    std::cout << count;
    return 0;
}