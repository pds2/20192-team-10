//
// Created by User on 24/11/2019.
//

#include "Organizador.h"
#include "Usuario.h"
#include "Csv.h"
#include <string>
#include <iostream>
#include <fstream>

Organizador::Organizador(std::string name, std::string username) {
    this->username = username;
    this->name = name;
}
Organizador::Organizador() {
    this->username = "nenhum";
    this->name = "NINGUEM";
}
void Organizador::fazerLogin(std::string username) {
    std::string file_path = "../Database/Usuarios/organizadores.csv";
    Usuario::fazerLogin(username,file_path);
}