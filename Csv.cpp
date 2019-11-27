#include "Csv.h"
#include "Usuario.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<std::vector<std::string>> parse_csv(std::string path_arquivo){
    std::vector<std::vector<std::string>> resposta;
    std::string s;
    char l[200];
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    std::ifstream f(path_arquivo,std::ios::in);
    int i=0;
    if(f.fail()){
        std::cout <<"no file"<<std::endl;
        return resposta;
    }
    f.getline(l,200);
    while (!f.eof()) {
        std::vector<std::string> linha;
        f.getline(l,200);
        s=l;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            linha.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        resposta.push_back(linha);
        i++;
    }
    f.close();
    return resposta;
  }

std::vector<std::string> encontrarUsuario(std::string username, std::string filepath) {
    unsigned int i;
    std::vector<std::vector<std::string>> registros = parse_csv(filepath);
    std::vector<std::string> nenhum = {" "};
    if (registros.empty()){
        return nenhum;
    }
    for (i =0;i<registros.size()-1;i++){
        if (registros.at(i).at(0)==username) {
            return registros.at(i);
        }
    }
    return  nenhum;
}

void insereUsuario(std::string username, std::string nome, std::string filepath){
    std::string linha = username+","+nome+",0\n";
    std::ofstream f(filepath,std::ios::app);
    if(f.fail()){
        std::cout <<"no file"<<std::endl;
        return;
    }
    f<<linha;
}

void insereUsuario(std::string username,  std::string filepath, int tipo){
    std::ofstream f(filepath,std::ios::app);
    if(f.fail()){
        std::cout <<"no file"<<std::endl;
        return;
    }
    switch(tipo){
        case 1:
            f<<username<<",organizador\n";
            break;
        case 2:
            f<<username<<",premium\n";
            break;
        case 3:
            f<<username<<",free\n";
            break;
        default:
            return;
    }

}