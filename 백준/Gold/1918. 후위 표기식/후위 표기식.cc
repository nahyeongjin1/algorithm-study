/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1918                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1918                           #+#        #+#      #+#    */
/*   Solved: 2025/03/23 14:04:51 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <stack>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string infix;
    std::cin >> infix;

    std::queue<char> postfix;
    std::stack<char> op;

    for (const char &c : infix)
    {
        if (c >= 'A' && c <= 'Z')
        {
            postfix.push(c);
        }
        else
        {
            // 연산자와 괄호 처리
            switch (c)
            {
            case '+':
            case '-':
                // +와 -의 우선순위는 낮으므로 스택의 top에 있는 연산자가
                // '('가 아니고, 우선순위가 같거나 높은 경우 모두 후위 표기식에 추가
                while (!op.empty() && op.top() != '(' &&
                       (op.top() == '+' || op.top() == '-' || op.top() == '*' || op.top() == '/'))
                {
                    postfix.push(op.top());
                    op.pop();
                }
                op.push(c);
                break;
            case '*':
            case '/':
                // *와 /의 우선순위는 +와 -보다 높지만 같은 그룹 내에서는 좌측 결합성이므로,
                // 스택의 top이 '*' 또는 '/'인 경우에만 pop
                while (!op.empty() && op.top() != '(' &&
                       (op.top() == '*' || op.top() == '/'))
                {
                    postfix.push(op.top());
                    op.pop();
                }
                op.push(c);
                break;
            case '(':
                // 여는 괄호는 그대로 스택에 push
                op.push(c);
                break;
            case ')':
                // 닫는 괄호를 만나면 여는 괄호 '('가 나올 때까지 pop하여 후위 표기식에 추가
                while (!op.empty() && op.top() != '(')
                {
                    postfix.push(op.top());
                    op.pop();
                }
                // '('는 결과에 포함하지 않고 제거
                if (!op.empty())
                {
                    op.pop();
                }
                break;
            }
        }
    }

    while (!op.empty())
    {
        postfix.push(op.top());
        op.pop();
    }

    while (!postfix.empty())
    {
        std::cout << postfix.front();
        postfix.pop();
    }
    std::cout << '\n';

    return 0;
}