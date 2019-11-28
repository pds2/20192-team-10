//
// Created by User on 25/11/2019.
//

#include "Free.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Csv.h"
Free::Free() {
    this->name = "NINGUEM";
    this->username = "nenhum";
}

Free::Free(std::string name, std::string username) {
    this->name = name;
    this->username =username;
}

void Free::fazerLogin(std::string username) {
    std::string file_path = "../Database/Usuarios/free.csv";
    Usuario::fazerLogin(username,file_path);
}

int Free::permitirAluguel(){
    std::string file_path = "../Database/Usuarios/free.csv";
    std::vector<std::vector<std::string>>dadosUsuario = {{"user_name", "nome", "livros_alugados"}};
    dadosUsuario.push_back(encontrarUsuario(this->username,file_path));
    unsigned int ultima_coluna =dadosUsuario.at(1).size()-1;
    unsigned int i=0;
    std::string alugados =dadosUsuario.at(1).at(ultima_coluna);
    size_t pos = 0;
    size_t n = std::count(alugados.begin(), alugados.end(), '/');
    if(n<2){
        return 1;
    }
    return 0;

}
void Free::alugarLivro(Livro livro) {
    std::string filepath = "../Database/Usuarios/free.csv";
    if(permitirAluguel()){
        alugaLivro(this->username,livro.get_titulo(),filepath);
        return;
    }
    std::cout<<"Você já alugou o máximo de livros permitidos para um membro Free"<<std::endl;
}
void Free::devolverLivro(Livro livro){
    std::string filepath = "../Database/Usuarios/free.csv";
    devolveLivro(this->username,livro.get_titulo(),filepath);
}