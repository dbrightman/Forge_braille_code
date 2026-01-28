    #include <iostream>
    #include <fstream>
    #include <string>
    #include <sstream>
    #include <vector>
    #include <unordered_map>
    


    int readFile(const std::string& fileInput);

    int main(){


    }

    int readFile(const std::string& fileInput){
        std::ifstream inputFile(fileInput);
        
        if(!inputFile.is_open())
        {
            std::cerr << "Error: Could not open file" << std::endl;
            return 0;
        }
        else { return 1; }
    }

    std::vector<int> getBraille(const std::string& line){
        
        
    }

