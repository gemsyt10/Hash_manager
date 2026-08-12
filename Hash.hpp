#ifndef HASH_HPP
#define HASH_HPP
//#define DEBUG


#include <iostream>
// #include <fstream>
#include <utility>

class HashMachine {
public:
    /*========================================
      == КОДИРОВКА СИМВОЛІВ ФУНКЦИЯ CODED ==
    ========================================*/
    std::string Coded(std::string word, std::string alphabet[][2], int rows) {
        std::string wordArr;
        int i = 0, j = 0;

        for(i = 0; i < word.length(); i++) {
            bool isSearched = false;
            for(j = 0; j < rows; j++) {
                if(word[i] == alphabet[j][0][0]) {
                    wordArr += alphabet[j][1];
                    break;
                } else if(j+1 == rows && !isSearched) wordArr += '#';
            }
        }

        return wordArr;
    } //ГОТОВА
    std::string Coded(char sym, std::string alphabet[][2], int rows) {
        std::string wordArr;

        bool isSearched = false;
        for(int j = 0; j < rows; j++) {
            if(sym == alphabet[j][0][0]) {
                wordArr += alphabet[j][1];
                break;
            } else if(j+1 == rows && !isSearched) wordArr += '#';
        }

        return wordArr;
    } //ГОТОВА

    /*==================================
     == ДЕКОДИРОВКА СИМВОЛІВ DECODED ==
    ==================================*/
    std::string Decoded(std::string hash, std::string alphabet[][2], int rows, int hashSymbolByteSize = 1) {
        std::string word;
        std::string hashSym;
        for(int i = 0; i < hash.length(); i++) {
            if(hash[i] == '#') continue;
            hashSym += hash[i];
            if(hashSym.length() == hashSymbolByteSize) {

                for(int j = 0; j < rows; j++) {
                    if(hashSym == alphabet[j][1]) {
                        word += alphabet[j][0];
                        hashSym = "";
                        break;
                    }
                }
            }
        }
        return word;
    }

    /*==============================
     === ДЕБАГ ФУНКЦІЯ PRINTALP ===
    ==============================*/
    void printAlp(std::string alphabet[][2], int rows) {
        int c = 0;
        for(int i = 0; i < rows; i++) {
            std::cout << alphabet[i][0] << ":  " << alphabet[i][1] << std::endl;
            c++;
        }
        std::cout << "size: " << c << std::endl;
    }
};
#endif // HASH_HPP
