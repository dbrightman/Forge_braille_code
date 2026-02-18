#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

class BrailleCell{
    private:
    std::unordered_map<char, std::vector<std::vector<int>>> braille_dictionary = {
        {'a', {{0},{1,0},{0,0},{0,0}}},
        {'b', {{0},{1,0},{1,0},{0,0}}},
        {'c', {{0},{1,1},{0,0},{0,0}}},
        {'d', {{0},{1,1},{0,1},{0,0}}},
        {'e', {{0},{1,0},{0,1},{0,0}}},
        {'f', {{0},{1,1},{1,0},{0,0}}},
        {'g', {{0},{1,1},{1,1},{0,0}}},
        {'h', {{0},{1,0},{1,1},{0,0}}},
        {'i', {{0},{0,1},{1,0},{0,0}}},
        {'j', {{0},{0,1},{1,1},{0,0}}},
        {'k', {{0},{1,0},{0,0},{1,0}}},
        {'l', {{0},{1,0},{1,0},{1,0}}},
        {'m', {{0},{1,1},{0,0},{1,0}}},
        {'n', {{0},{1,1},{0,1},{1,0}}},
        {'o', {{0},{1,0},{0,1},{1,0}}},
        {'p', {{0},{1,1},{1,0},{1,0}}},
        {'q', {{0},{1,1},{1,1},{1,0}}},
        {'r', {{0},{1,0},{1,1},{1,0}}},
        {'s', {{0},{0,1},{1,0},{1,0}}},
        {'t', {{0},{0,1},{1,1},{1,0}}},
        {'u', {{0},{1,0},{0,0},{1,1}}},
        {'v', {{0},{1,0},{1,0},{1,1}}},
        {'w', {{0},{0,1},{1,1},{0,1}}},
        {'x', {{0},{1,1},{0,0},{1,1}}},
        {'y', {{0},{1,1},{0,1},{1,1}}},
        {'z', {{0},{1,0},{0,1},{1,1}}},
        {',', {{0},{0,0},{1,0},{0,0}}},
        {'.', {{0},{0,0},{1,1},{0,1}}},
        {'\'', {{0},{0,0},{0,0},{1,0}}},
        {':', {{0},{0,0},{1,1},{0,0}}},
        {'!', {{0},{0,0},{1,1},{0,0}}},
        {'?', {{0},{0,0},{1,0},{1,1}}},
        {';', {{0},{0,0},{1,0},{1,0}}},
        {'"', {{0},{0,0},{1,0},{1,1}}},
        {'A', {{1},{1,0},{0,0},{0,0}}},
        {'B', {{1},{1,0},{1,0},{0,0}}},
        {'C', {{1},{1,1},{0,0},{0,0}}},
        {'D', {{1},{1,1},{0,1},{0,0}}},
        {'E', {{1},{1,0},{0,1},{0,0}}},
        {'F', {{1},{1,1},{1,0},{0,0}}},
        {'G', {{1},{1,1},{1,1},{0,0}}},
        {'H', {{1},{1,0},{1,1},{0,0}}},
        {'I', {{1},{0,1},{1,0},{0,0}}},
        {'J', {{1},{0,1},{1,1},{0,0}}},
        {'K', {{1},{1,0},{0,0},{1,0}}},
        {'L', {{1},{1,0},{1,0},{1,0}}},
        {'M', {{1},{1,1},{0,0},{1,0}}},
        {'N', {{1},{1,1},{0,1},{1,0}}},
        {'O', {{1},{1,0},{0,1},{1,0}}},
        {'P', {{1},{1,1},{1,0},{1,0}}},
        {'Q', {{1},{1,1},{1,1},{1,0}}},
        {'R', {{1},{1,0},{1,1},{1,0}}},
        {'S', {{1},{0,1},{1,0},{1,0}}},
        {'T', {{1},{0,1},{1,1},{1,0}}},
        {'U', {{1},{1,0},{0,0},{1,1}}},
        {'V', {{1},{1,0},{1,0},{1,1}}},
        {'W', {{1},{0,1},{1,1},{0,1}}},
        {'X', {{1},{1,1},{0,0},{1,1}}},
        {'Y', {{1},{1,1},{0,1},{1,1}}},
        {'Z', {{1},{1,0},{0,1},{1,1}}},
        }; 


    public:
    BrailleCell() {}

    std::vector<std::vector<int>> const getBraillePattern(char letter){
        if (braille_dictionary.find(letter) != braille_dictionary.end()){
            std::vector<std::vector<int>> pattern = braille_dictionary[letter];
            if (pattern[0][0] == 1){
                pattern.erase(pattern.begin());
                std::vector<std::vector<int>> capital_list = {{1},{0,0}, {0,0}, {0,1}};
                capital_list.insert(capital_list.end(), pattern.begin(), pattern.end());
                return capital_list;
            }
            else {
                return pattern;
            }
        }
        else {
            return {{0},{0,0},{0,0},{0,0}};
        }
    }

    int const printBrailleLetter(char letter)  {
        if (braille_dictionary.find(letter) != braille_dictionary.end()){
            std::vector<std::vector<int>> pattern = braille_dictionary[letter];
            if (pattern[0][0] == 1){
                std::cout << "o " << "o" << std::endl;
                std::cout << "o " << "o" << std::endl;
                std::cout << "o " << "x" << std::endl;
                for (int row = 1; row < 4; row++){
                    for (int column = 0; column < 2; column++){
                        if (pattern[row][column] == 1){
                            std::cout << "x ";
                        }
                        else{
                            std::cout << "o ";
                        }
                    }
                    std::cout << std::endl;
                }
                std::cout << letter << std::endl;
                return 1;
            }
            else {
                for (int row = 1; row < 4; row++){
                    for (int column = 0; column < 2; column++){
                        if (pattern[row][column] == 1){
                            std::cout << "x ";
                        }
                        else{
                            std::cout << "o ";
                        }
                    }
                    std::cout << std::endl;
                }
                std::cout << letter << std::endl;
                return 1;
            }
        }
        else {
            std::cout << "o " << "o" << std::endl;
            std::cout << "o " << "o" << std::endl;
            std::cout << "o " << "o" << std::endl;
            return 0;
        }
    }


    int const printBrailleWord(std::string& word) {
        for (char c : word){
            printBrailleLetter(c);
        }
        return 0;
    }

    std::pair<std::vector<std::vector<std::vector<int>>>, int> const getBrailleWord(std::string& word, int max) {
        std::vector<std::vector<std::vector<int>>> braille_word;
        int count = 0;
        int index = 0;
        while (count < max && index < word.length()) {
            char letter = word[index];
            int cost = isupper(letter) ? 2 : 1;
            if (cost + count > max){
                int remainder = word.length() - index;
                return std::make_pair(braille_word, remainder);
            }
            count += cost;
            braille_word.push_back(getBraillePattern(letter));
            index++;
        }
        int remainder = word.length() - index;
        return std::make_pair(braille_word, remainder);
    }

};