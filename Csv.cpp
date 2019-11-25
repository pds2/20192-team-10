#include "Csv.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<std::vector<std::string>> parse_csv(std::string path_arquivo){
    std::vector<std::string> linha;
    std::vector<std::vector<std::string>> resposta;
    std::string s;
    char l[200];
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    std::ifstream f(path_arquivo,std::ios::in);
    if(f.fail()){
        std::cout <<"no file"<<std::endl;
        return resposta;
    }
    f.getline(l,200);
    while (!f.eof()) {
        f.getline(l,200);
        s=l;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            linha.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        resposta.push_back(linha);
    }
    f.close();
    return resposta;
  }
