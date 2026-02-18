#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

#ifndef BRAILLE_DICTIONARY_H
#define BRAILLE_DICTIONARY_H

class BrailleCell{
    private:
    std::unordered_map<char, std::vector<std::vector<int>>> braille_dictionary;


    public:
    BrailleCell();

    std::vector<std::vector<int>> getBraillePattern(char letter);

    int printBrailleLetter(char letter);
    int printBrailleWord(std::string word);

    std::pair<std::vector<std::vector<std::vector<int>>>, int> getBrailleWord(std::string word, int max);

};

#endif

