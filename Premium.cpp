//
// Created by User on 25/11/2019.
//

#include "Premium.h"
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