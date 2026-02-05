    #include <iostream>
    #include <fstream>
    #include <string>
    #include <sstream>
    #include <vector>
    #include <unordered_map> 
    #include "braille_dictionary.cpp"

    int readFile(const std::string& fileInput);
    std::string file = "braille_input.txt";
    int cells = 6;


    std::vector<std::vector<std::vector<int>>> getLine(int line);

    int main(){
        std::ifstream inputFile(file);
        
        if(!inputFile.is_open())
        {
            std::cerr << "Error: Could not open file" << std::endl;
            return 0;
        }
        else { return 1; }
    }

    // int readFile(const std::string& fileInput){
    //     std::ifstream inputFile(fileInput);
        
    //     if(!inputFile.is_open())
    //     {
    //         std::cerr << "Error: Could not open file" << std::endl;
    //         return 0;
    //     }
    //     else { return 1; }
    // }

    std::vector<std::vector<std::vector<int>>> getLine(int line) {
        int byte = line * cells;
        std::ifstream inputFile(file);
        std::vector<std::vector<std::vector<int>>> wordLine;
        int end = (byte + 1) * cells;
        if (inputFile.is_open()) {
            inputFile.seekg(byte);
            for (int i = byte; i <= end; i++) {
                char c = inputFile.get();
                wordLine.push_back(getBraillePattern(c));
            } 
            return wordLine;
        }
        else return {{}};
    }

