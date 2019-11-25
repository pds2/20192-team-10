#include "Csv.h"
#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> Csv::parse_csv(std::string path_arquivo){
    std::vector<std::string> resposta;
    std::string s = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        resposta.push_back(token);
        std::cout << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    std::cout << s << std::endl;
    return resposta;
  }
