//
// Created by User on 25/11/2019.
//

#include "Free.h"
#include <string>
#include <iostream>
#include <vector>
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