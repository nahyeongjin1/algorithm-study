/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11283                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11283                          #+#        #+#      #+#    */
/*   Solved: 2025/02/19 21:20:25 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string input;
    std::cin >> input;

    /*
    본래 한글은 유니코드(2byte)로 다루는 것이 정석이지만
    utf-8로 인코딩된 경우 3byte가 되고 각 요소들이 음수로 나오게 되어
    직접 디코딩하여 한글에 대한 유니코드를 뽑아내야 한다.
    한글이 인코딩 되는 방식은 간단하다
    2byte에서 3byte로 변환될 때 순서대로
    4bit + 6bit + 6bit로 쪼개지고,
    이는 각 byte 속의 4 + 4,2 + 2,4가 된다. 쉽게 풀어쓰면
    aaaa bbbb cccc dddd ->
    1110aaaa, 10bbbbcc, 10ccdddd 이런 모양이 됨. 앞의 숫자는 약속된 값
    이를 유니코드로 변환하게 되면
    가~힣 순서대로 유니코드상 값이 1씩 증가하게 되므로
    우리가 원하는 문제의 답을 얻어낼 수 있게 된다.
    44031은 그냥 비트 연산 후 찍어보니 '가' = 44032 길래 뺐더니 딱 맞아떨어졌다.
     */

    std::cout
        << (((unsigned short)((input.at(0) & 15) << 12) | (unsigned short)((input.at(1) & 63) << 6)) | (unsigned short)(input.at(2) & 63)) - 44031 << '\n';

    return 0;
}