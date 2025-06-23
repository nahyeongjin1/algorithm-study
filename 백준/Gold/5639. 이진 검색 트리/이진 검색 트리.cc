/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5639                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5639                           #+#        #+#      #+#    */
/*   Solved: 2025/04/06 19:40:14 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

void post_order(vector<uint32_t> &pre_order, uint32_t start, uint32_t end)
{
    if (start > end)
        return;

    uint32_t root = pre_order[start];
    uint32_t right_start = start + 1;

    while (right_start <= end && pre_order[right_start] < root)
        right_start++;

    // left subtree
    post_order(pre_order, start + 1, right_start - 1);

    // right subtree
    post_order(pre_order, right_start, end);

    // root
    std::cout << root << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    vector<uint32_t> pre_order;
    while (true)
    {
        uint32_t input;
        std::cin >> input;
        if (std::cin.eof())
            break;
        pre_order.push_back(input);
    }

    post_order(pre_order, 0, pre_order.size() - 1);

    return 0;
}