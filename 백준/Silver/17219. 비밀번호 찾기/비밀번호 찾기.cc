/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17219                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17219                          #+#        #+#      #+#    */
/*   Solved: 2025/02/18 21:13:07 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector, std::pair, std::string;

bool Compare(pair<string, string> p1, pair<string, string> p2)
{
    return p1.first < p2.first;
}

string manipulate_url(string url)
{
    for (auto i = url.begin(); i != url.end(); i++)
    {
        if (*i == '-' or *i == '.')
        {
            url.erase(i);
        }
        else if (*i >= 'A' and *i <= 'Z')
        {
            *i += ('a' - 'A');
        }
    }
    return url;
}

string find_password(vector<pair<string, string>> &vec, string input)
{
    input = manipulate_url(input);
    int min = 0;
    int max = vec.size() - 1;

    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (vec.at(mid).first < input)
        {
            min = mid + 1;
        }
        if (vec.at(mid).first > input)
        {
            max = mid - 1;
        }
        if (vec.at(mid).first == input)
        {
            return vec.at(mid).second;
        }
    }

    return "";
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;
    vector<pair<string, string>> vec(n);
    for (auto i = 0; i < n; i++)
    {
        string url, password;
        std::cin >> url >> password;
        vec.at(i) = {manipulate_url(url), password};
    }
    std::sort(vec.begin(), vec.end(), Compare);
    for (auto i = 0; i < m; i++)
    {
        string input;
        std::cin >> input;
        std::cout << find_password(vec, input) << '\n';
    }

    return 0;
}