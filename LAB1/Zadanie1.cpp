/* аналоги функций:
C        -- C++

strlen() -- string::size()
strcpy() -- string a = "foo"; string b; a = b;
strcmp() -- string.compare() ИЛИ strcmp(), но тогда строки должны быть в С стиле (массив символов)
strcat() -- strcat(), обычная конкатенация строк
getting the character at index -- string a = "boo"; a[index] ИЛИ a.at(index)
char str[5] = "Foo"; arr[3] = new_value; -- push_back()
char str[3] = "Foo"; str[strlen(str) - 1] = "\0"; -- pop_back()

Главное различие между строками: в С это массив char'ов с элементом NULL в конце. Контроль памяти - обязанность програмиста.
В C++ библиотека <string> позволяет создавать сущности с автоматизированным контролем памяти. К ним можно применять методы для манипуляции как в Python.
--*/

#include <iostream>
#include <string>


int main() {
    std::string str;
    std::cout << "Type a string: " << "\n"; 
    std::getline(std::cin, str);
    for (int i = 0, len = str.size(); i < len; i++)
        if (ispunct(str[i]) || isspace(str[i])) {
            str.erase(i--, 1);
            len = str.size();
            }

    int len = str.length();
    for (int i = 1; i < len; i++) {
        char temp = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > temp) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = temp;
    }

    std::cout << str << '\n';
    return 0;
}
