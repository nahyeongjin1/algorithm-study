/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2630                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2630                           #+#        #+#      #+#    */
/*   Solved: 2025/02/23 18:37:53 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using std::pair;
using std::vector;

typedef unsigned short us;

pair<us, us> operator+(const pair<us, us> &p1, const pair<us, us> &p2)
{
    return {p1.first + p2.first, p1.second + p2.second};
}

pair<us, us> split(vector<vector<bool>> &paper, us length, pair<us, us> coord)
{
    pair<us, us> result = {0, 0};
    us i;
    bool compared = paper.at(coord.second).at(coord.first);
    for (i = coord.second; i < coord.second + length; i++)
    {
        us j;
        for (j = coord.first; j < coord.first + length; j++)
        {
            if (compared != paper.at(i).at(j))
            {
                break;
            }
        }
        if (j != coord.first + length)
        {
            break;
        }
    }
    if (i != coord.second + length)
    {
        result = result + split(paper, length / 2, {coord.first, coord.second});
        result = result + split(paper, length / 2, {coord.first + (length / 2), coord.second});
        result = result + split(paper, length / 2, {coord.first, coord.second + (length / 2)});
        result = result + split(paper, length / 2, {coord.first + (length / 2), coord.second + (length / 2)});
    }
    else
    {
        if (!compared)
        {
            result.first += 1;
        }
        else
        {
            result.second += 1;
        }
    }

    return result;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned short n;
    std::cin >> n;

    // true = blue, false = white
    vector<vector<bool>> paper(n, vector<bool>(n, false));
    unsigned short input;
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            std::cin >> input;
            paper.at(i).at(j) = (input == 1) ? true : false;
        }
    }
    pair<us, us> result = split(paper, n, {0, 0});
    std::cout << result.first << '\n'
              << result.second << '\n';

    return 0;
}
