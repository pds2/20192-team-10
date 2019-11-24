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

void Usuario::buscarUsuario(std::string username) {
    std::ifstream f("../Database/Usuarios/usuarios.csv",std::ios::in);
    char linha[200], categoria[50];
    std::string category;
    int i =0, j=0, k=0, u_id =0;
    if(f.fail()){
        std::cout <<"no file"<<std::endl;
    }
    else {
        f.getline(linha, 200);//tira o cabeçalho
        while (!f.eof()) {
            f.getline(linha, 200);
            for(j=0;j<200;j++){
                if(linha[j] != ','){
                    if((linha[j] == ' ' && i!=2) || linha[j] == '"'){
                        continue;
                    }
                    categoria[k]=linha[j];
                    k++;
                    continue;
                }
                else if (i==0){
                    u_id = atoi(categoria);
                    for (k=0;k<j;k++){ //zera string
                        categoria[k] ='\0';
                    }
                    i++;
                    k=0;
                }
                else if(i==1){
                    categoria[k]='\0';
                    category = categoria;
                    if (category == username){
                        this->username = username;
                        for(i=0;i<k;i++){
                            categoria[i]='\0';
                        }
                        i=2;
                        k=0;
                        f.close();

                    }
                    else {
                        for (i = 0; i < k; i++) {
                            categoria[i] = '\0';
                        }
                        i = 0;
                        k = 0;
                        break;
                    }
                }
                else{
                    categoria[k+1]='\0';
                    category = categoria;
                    this->name = category;
                    this->id = u_id;
                    std::cout << "Login feito com sucesso!"<< std::endl;
                    f.close();
                    return;
                }
            }
        }
    }
    f.close();
    std::cout << "não foi encontrado nenhum usuario com esse username"<< std::endl;
}