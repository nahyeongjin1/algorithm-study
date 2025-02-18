/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1764                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1764                           #+#        #+#      #+#    */
/*   Solved: 2025/02/18 19:28:42 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

bool Compare(std::string s1, std::string s2)
{
    return s1 < s2;
}

bool binary_search(std::vector<std::string> &vec, std::string str)
{
    int min = 0;
    int max = vec.size() - 1;
    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (vec.at(mid) < str)
        {
            min = mid + 1;
        }
        if (vec.at(mid) > str)
        {
            max = mid - 1;
        }
        if (vec.at(mid) == str)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> never_heard(n);
    std::vector<std::string> deud_bo_job;

    for (auto i = 0; i < n; i++)
    {
        std::cin >> never_heard.at(i);
    }
    std::sort(never_heard.begin(), never_heard.end(), Compare);

    for (auto i = 0; i < m; i++)
    {
        std::string never_seen;
        std::cin >> never_seen;

        if (binary_search(never_heard, never_seen))
        {
            deud_bo_job.push_back(never_seen);
        }
    }
    std::sort(deud_bo_job.begin(), deud_bo_job.end(), Compare);
    std::cout << deud_bo_job.size() << '\n';
    for (auto i = deud_bo_job.begin(); i != deud_bo_job.end(); i++)
    {
        std::cout << *i << '\n';
    }

    return 0;
}