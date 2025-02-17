/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2164                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2164                           #+#        #+#      #+#    */
/*   Solved: 2025/02/17 18:21:36 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;

    if (n == 1)
    {
        std::cout << 1;
        return 0;
    }

    std::list<int> list;
    for (auto i = 0; i < n; i++)
    {
        list.push_back(i + 1);
    }

    while (true)
    {
        list.pop_front();
        if (list.size() == 1)
        {
            std::cout << list.front();
            break;
        }
        list.push_back(list.front());
        list.pop_front();
    }

    return 0;
}