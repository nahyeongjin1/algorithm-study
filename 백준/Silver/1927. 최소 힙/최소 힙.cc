/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1927                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1927                           #+#        #+#      #+#    */
/*   Solved: 2025/02/23 18:37:59 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

bool Compare(unsigned int u1, unsigned int u2)
{
    return u1 > u2;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    unsigned int t, input;
    std::vector<unsigned int> heap;
    std::cin >> t;

    for (auto i = 0; i < t; i++)
    {
        std::cin >> input;
        if (input == 0)
        {
            if (heap.empty())
            {
                std::cout << 0 << '\n';
            }
            else
            {
                std::pop_heap(heap.begin(), heap.end(), Compare);
                std::cout << heap.back() << '\n';
                heap.pop_back();
            }
        }
        else
        {
            heap.push_back(input);
            std::push_heap(heap.begin(), heap.end(), Compare);
        }
    }

    return 0;
}