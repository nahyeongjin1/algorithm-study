/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1620                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1620                           #+#        #+#      #+#    */
/*   Solved: 2025/02/18 19:28:31 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector, std::pair, std::string;

string to_lowercase(string str)
{
    if (str.front() >= 'A' and str.front() <= 'Z')
    {
        str.front() += 'a' - 'A';
    }
    if (str.back() >= 'A' and str.back() <= 'Z')
    {
        str.back() += 'a' - 'A';
    }
    return str;
}

int binary_search_name(vector<pair<string, int>> &dogam, string name)
{
    int min = 0;
    int max = dogam.size() - 1;
    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (dogam.at(mid).first > name)
        {
            max = mid - 1;
        }
        if (dogam.at(mid).first < name)
        {
            min = mid + 1;
        }
        if (dogam.at(mid).first == name)
        {
            return dogam.at(mid).second;
        }
    }
    return -1;
}

bool Compare(pair<string, int> p1, pair<string, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;
    vector<pair<string, int>> dogam(n);
    vector<string> only_num(n);
    string input;

    for (auto i = 0; i < n; i++)
    {
        string lowercase;

        std::cin >> input;
        lowercase = to_lowercase(input);

        dogam.at(i) = {lowercase, i + 1};
        only_num.at(i) = input;
    }
    std::sort(dogam.begin(), dogam.end(), Compare);
    for (auto i = 0; i < m; i++)
    {
        std::cin >> input;
        if (input.front() >= '0' and input.front() <= '9')
        {
            std::cout << only_num.at(std::stoi(input) - 1) << '\n';
        }
        else
        {
            input = to_lowercase(input);
            std::cout << binary_search_name(dogam, input) << '\n';
        }
    }
    return 0;
}