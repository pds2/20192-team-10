//
// Created by User on 24/11/2019.
//

#include "Usuario.h"
#include <string>
#include <iostream>
#include <fstream>

Usuario::Usuario() {
    this->id = 0;
    this->username = "nenhum";
    this->name = "NINGUEM";
}

Usuario::Usuario(int id, std::string username, std::string name) {
    this->id = id;
    this->name = name;
    this ->username = username;
}

int Usuario::get_id() {
    return this->id;
}

void Usuario::set_id(int id) {
    this->id = id;
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