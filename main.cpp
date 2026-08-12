#include <iostream>
#include <vector>
#define DEBUG
#include "Hash.hpp"
using namespace std;

int main() {
    const int letterCount = 26;
    std::string alphabet[letterCount][2] = {
        {"a", "00010"}, {"b", "10010"}, {"c", "10000"},
        {"d", "00100"}, {"e", "01010"}, {"f", "10111"},
        {"g", "01100"}, {"h", "11010"}, {"i", "10011"},
        {"j", "01001"}, {"k", "11111"}, {"l", "10110"},
        {"m", "10101"}, {"n", "10100"}, {"o", "00000"},
        {"p", "10001"}, {"q", "00011"}, {"r", "11000"},
        {"s", "00101"}, {"t", "01111"}, {"u", "01000"},
        {"v", "11110"}, {"w", "11011"}, {"x", "01101"},
        {"y", "00110"}, {"z", "11100"}
    };
    cout << "Hash Manager\nВведіть 1 щоб шифрувати \nВведіть 2 щоб розшифрувати\nВведіть 0 щоб вийти" << endl << endl;
    for(int i = 0; i < 1; ) {
    int num;
    cin >> num;

    HashMachine m;
    string text;

    if(num == 1) {
        cout << "Введіть текст на англійській який потрібно зашифрувати (використовуйте тільки букви без пробілів): " <<endl;
        cin >> text;

        if(text != "" || text != " ") {
            string hash = m.Coded(text, alphabet, letterCount);
            cout << hash << endl;
        } else cout << "Ви не ввели текст" << endl;
    } else if(num == 2) {
        cout << "Введіть зашифроване повідомлення: " << endl;
        cin >> text;

        if(text != "" || text != " ") {
            string msg = m.Decoded(text, alphabet, letterCount, 5);
            cout << msg << endl;
        }
    }else if(num == 0) {
        cout << "програму завершено" << endl;
        break;
    }
    }
    return 0;
}
