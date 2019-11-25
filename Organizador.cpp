//
// Created by User on 24/11/2019.
//

#include "Organizador.h"
#include "Usuario.h"
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
    std::ifstream f("../Database/Usuarios/organizadores.csv",std::ios::in);
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
                    categoria[k]='\0';
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