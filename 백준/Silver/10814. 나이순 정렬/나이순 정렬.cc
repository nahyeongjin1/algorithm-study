/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10814                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10814                          #+#        #+#      #+#    */
/*   Solved: 2025/02/16 16:56:30 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using std::pair, std::string, std::vector, std::make_pair;

bool Compare(pair<pair<short, string>, int> p1, pair<pair<short, string>, int> p2)
{
    if (p1.first.first == p2.first.first)
    {
        return p1.second < p2.second;
    }
    return p1.first.first < p2.first.first;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;
    vector<pair<pair<short, string>, int>> vec(n);

    for (auto i = 0; i < n; i++)
    {
        short age;
        std::string name;
        std::cin >> age >> name;
        vec.at(i) = make_pair(make_pair(age, name), i);
    }
    std::sort(vec.begin(), vec.end(), Compare);
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        std::cout << i->first.first << ' ' << i->first.second << '\n';
    }

    return 0;
}