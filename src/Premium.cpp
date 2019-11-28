//
// Created by User on 25/11/2019.
//

#include "Premium.h"
#include "Csv.h"
#include <algorithm>
#include <vector>
Premium::Premium() {
    this->name = "NENHUM";
    this->username = "ninguem";
}

Premium::Premium(std::string name, std::string username) {
    this->name = name;
    this->username = username;
}

void Premium::fazerLogin(std::string username) {
    std::string file_path = "../Database/Usuarios/premium.csv";
    Usuario::fazerLogin(username,file_path);
}
void Premium::alugarLivro(Livro livro) {
    std::string filepath = "../Database/Usuarios/premium.csv";
    alugaLivro(this->username,livro.get_titulo(),filepath);
    this->livros_alugados.push_back(livro.get_titulo());
}
void Premium::devolverLivro(Livro livro) {
    std::string filepath = "../Database/Usuarios/premium.csv";
    devolveLivro(this->username,livro.get_titulo(),filepath);
}