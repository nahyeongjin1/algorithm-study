/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 27889                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/27889                          #+#        #+#      #+#    */
/*   Solved: 2025/02/07 21:30:07 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, std::string> map;
    std::string input;

    map.insert({"NLCS", "North London Collegiate School"});
    map.insert({"BHA", "Branksome Hall Asia"});
    map.insert({"KIS", "Korea International School"});
    map.insert({"SJA", "St. Johnsbury Academy"});

    std::cin >> input;
    std::cout << map[input];

    return 0;
}