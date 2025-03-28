/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1991                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1991                           #+#        #+#      #+#    */
/*   Solved: 2025/03/25 14:48:43 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::string;
using std::vector;

string preorder(const vector<vector<char>> &tree)
{
    string result = "";
    stack<char> st;
    vector<bool> visited(tree.size(), false);

    st.push('A');
    visited['A' - 'A'] = true;

    while (!st.empty())
    {
        char cur = st.top();
        st.pop();
        result += cur;
        for (uint16_t i = 0; i < 2; i++)
        {
            char child = tree[cur - 'A'][1 - i];
            if (child != '.' && !visited[child - 'A'])
            {
                st.push(child);
                visited[child - 'A'] = true;
            }
        }
    }

    return result;
}

string inorder(const vector<vector<char>> &tree)
{
    string result = "";
    stack<char> st;
    vector<bool> visited(tree.size(), false);

    st.push('A');
    visited['A' - 'A'] = true;

    while (!st.empty())
    {
        char cur = st.top();
        char left_child = tree[cur - 'A'][0];
        if (left_child != '.' && !visited[left_child - 'A'])
        {
            st.push(left_child);
            visited[left_child - 'A'] = true;
            continue;
        }
        st.pop();
        result += cur;
        char right_child = tree[cur - 'A'][1];
        if (right_child != '.' && !visited[right_child - 'A'])
        {
            st.push(right_child);
            visited[right_child - 'A'] = true;
        }
    }

    return result;
}

string postorder(const vector<vector<char>> &tree)
{
    string result = "";
    stack<char> st;
    vector<bool> visited(tree.size(), false);

    st.push('A');
    visited['A' - 'A'] = true;

    while (!st.empty())
    {
        char cur = st.top();
        char left_child = tree[cur - 'A'][0];
        if (left_child != '.' && !visited[left_child - 'A'])
        {
            st.push(left_child);
            visited[left_child - 'A'] = true;
            continue;
        }
        char right_child = tree[cur - 'A'][1];
        if (right_child != '.' && !visited[right_child - 'A'])
        {
            st.push(right_child);
            visited[right_child - 'A'] = true;
            continue;
        }
        st.pop();
        result += cur;
    }

    return result;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 1 <= n <= 26
    std::cin >> n;

    vector<vector<char>> tree(n, vector<char>(2, 0));
    for (uint16_t i = 0; i < n; i++)
    {
        char parent, left, right;
        std::cin >> parent >> left >> right;
        tree[parent - 'A'][0] = left;
        tree[parent - 'A'][1] = right;
    }

    std::cout << preorder(tree) << '\n'
              << inorder(tree) << '\n'
              << postorder(tree) << '\n';

    return 0;
}