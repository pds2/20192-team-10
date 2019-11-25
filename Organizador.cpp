//
// Created by User on 24/11/2019.
//

#include "Organizador.h"
#include "Usuario.h"
#include "Csv.h"
#include <string>
#include <iostream>
#include <fstream>

Organizador::Organizador(int id, std::string name, std::string username) {
    this->id = id;
    this->username = username;
    this->name = name;
}
Organizador::Organizador() {
    this->id = 0;
    this->username = "nenhum";
    this->name = "NINGUEM";
}
void Organizador::fazerLogin(std::string username) {
    int i;
    std::string file_path = "../Database/Usuarios/organizadores.csv";
    std::vector<std::vector<std::string>> registros = parse_csv(file_path);
    if (registros.empty()){
        return;
    }
    for (i =0;i<registros.size();i++){
        if (registros.at(i).at(1)==username){
            this->id = stoi(registros.at(i).at(0));
            this->username = registros.at(i).at(1);
            this->name = registros.at(i).at(2);
            std::cout << "Olá "<< this->name << std::endl;
            return;
        }
    }
    std::cout << "não foi encontrado nenhum usuario com esse username"<< std::endl;
}