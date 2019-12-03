//
// Created by User on 24/11/2019.
//

#include "Usuario.h"
#include "Csv.h"
#include <string>
#include <iostream>
#include <vector>

Usuario::Usuario() {
    this->username = "";
    this->name = "";
    this->livros_alugados ={} ;
}

Usuario::Usuario(std::string username, std::string name, std::vector<std::string> livros_alugados) {
    this->name = name;
    this ->username = username;
    this->livros_alugados =livros_alugados;
}

void Usuario::fazerLogin(std::string username, std::string filepath) {
    std::vector<std::string> encontrou;
    std::vector<std::string>livros_alugados;
    try{
        encontrou = encontrarUsuario(username, filepath);
    }
    catch(std::runtime_error){
        std::cout << "não foi encontrado nenhum usuario com esse username"<< std::endl;
        throw std::runtime_error("nenhum usuario encontrado");
    }
    this->username = encontrou.at(0);
    this->name = encontrou.at(1);
    std::string delimiter = "/";
    size_t pos = 0;
    std::string token;
    std::string s = encontrou.at(2);
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        livros_alugados.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    token = s.substr(0, pos);
    livros_alugados.push_back(token);
    this->livros_alugados = livros_alugados;

}

std::string Usuario::get_name() {
    return this->name;
}

void Usuario::set_name(std::string name) {
    this->name = name;
}

std::string Usuario::get_username() {
    return this->username;
}

void Usuario::set_username(std::string username) {
    this->username = username;
}

std::vector<std::string> Usuario::get_livros_alugados(){
    return this->livros_alugados;
}

void Usuario::set_livros_alugados(std::vector<std::string> livros_alugados){
    this->livros_alugados = livros_alugados;
}