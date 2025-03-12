/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17826                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17826                          #+#        #+#      #+#    */
/*   Solved: 2025/03/12 16:01:43 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

constexpr uint16_t STUDENTS = 50;

std::string place_to_rank(const uint16_t &place)
{
    std::string result = "";
    if (place >= 1 && place <= 5)
    {
        result = "A+";
    }
    else if (place >= 6 && place <= 15)
    {
        result = "A0";
    }
    else if (place >= 16 && place <= 30)
    {
        result = "B+";
    }
    else if (place >= 31 && place <= 35)
    {
        result = "B0";
    }
    else if (place >= 36 && place <= 45)
    {
        result = "C+";
    }
    else if (place >= 46 && place <= 48)
    {
        result = "C0";
    }
    else if (place >= 49 && place <= 50)
    {
        result = "F";
    }
    return result;
}

uint16_t binary_search(const vector<uint16_t> &scores, const uint16_t &target)
{
    uint16_t min = 0;
    uint16_t max = STUDENTS - 1;
    uint16_t mid = 0;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (scores[mid] == target)
        {
            break;
        }
        if (scores[mid] > target)
        {
            min = mid + 1;
        }
        if (scores[mid] < target)
        {
            max = mid - 1;
        }
    }
    return mid + 1;
}

bool Compare(const uint16_t &s1, const uint16_t &s2)
{
    return s1 > s2;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    vector<uint16_t> scores(STUDENTS, 0);
    uint16_t target;
    for (uint16_t i = 0; i < STUDENTS; i++)
    {
        std::cin >> scores[i];
    }
    std::cin >> target;
    std::sort(scores.begin(), scores.end(), Compare);
    uint16_t place = binary_search(scores, target);
    std::cout << place_to_rank(place) << '\n';

    return 0;
}