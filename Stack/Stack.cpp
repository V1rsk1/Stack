#include <iostream>
#include <stack>
#include<Windows.h>
using namespace std;

bool checkBrack(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}
void checkStr(string str) {
    stack<char> stack;
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (!stack.empty() && checkBrack(stack.top(), ch)) {
                stack.pop();
            }
            else {
                cout << "Помилка: дужка на позиції " << i + 1 << " неправильна" << endl;
                return;
            }
        }
        result += ch;
    }

    cout << result << endl;
    if (stack.empty()) {
        cout << "Усі дужки правильні!" << endl;
    }
    else {
        cout << "Помилка: не закриті дужки" << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    checkStr("({x-y-z} * [x + 2y] - (z + 4x))");
    checkStr("({x-y-z] * [x + 2y) - (z + 4x})");
    return 0;
}
