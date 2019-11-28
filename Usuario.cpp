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
    encontrou = encontrarUsuario(username, filepath);
    if (encontrou.at(0) == " "){
        std::cout << "não foi encontrado nenhum usuario com esse username"<< std::endl;
        return;
    }
    this->username = encontrou.at(0);
    this->name = encontrou.at(1);
    std::cout << "Olá "<< this->name << std::endl;
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