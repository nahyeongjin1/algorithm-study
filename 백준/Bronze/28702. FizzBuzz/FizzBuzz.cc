/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 28702                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/28702                          #+#        #+#      #+#    */
/*   Solved: 2025/02/14 22:24:09 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
15의 배수면 FizzBuzz
5의 배수는 아니고 3의 배수면 Fizz
3의 배수는 아니고 5의 배수면 Buzz
다 아니면 숫자 그대로 출력
근데 어차피 연속된 세 수면 무조건 숫자로만 이뤄진게 나올텐데
그냥 셋 다 아닌거 찾아버리면 되는거 아님?
*/

#include <iostream>

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::string input, output;
    long long temp;

    for (auto i = 0; i < 3; i++)
    {
        std::cin >> input;
        if (input != "Fizz" && input != "Buzz" && input != "FizzBuzz")
        {
            temp = std::stoi(input) + 3 - i;
            break;
        }
    }
    if (temp % 3 == 0 && temp % 5 == 0)
    {
        output = "FizzBuzz";
    }
    else if (temp % 3 == 0)
    {
        output = "Fizz";
    }
    else if (temp % 5 == 0)
    {
        output = "Buzz";
    }
    else
    {
        output = std::to_string(temp);
    }

    std::cout << output;
    return 0;
}