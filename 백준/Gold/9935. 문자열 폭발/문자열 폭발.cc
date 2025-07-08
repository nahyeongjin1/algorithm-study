/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9935                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9935                           #+#        #+#      #+#    */
/*   Solved: 2025/06/24 09:47:03 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using std::string;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    string input, bomb;

    std::cin >> input >> bomb;

    string result;
    for (char c : input)
    {
        result += c;
        if (result.size() >= bomb.size() && result.substr(result.size() - bomb.size(), bomb.size()) == bomb)
        {
            result.erase(result.size() - bomb.size());
        }
    }

    std::cout << (result.empty() ? "FRULA" : result) << '\n';

    return 0;
}