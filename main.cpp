#include <iostream>
#include <fstream>
#include <vector>
#include "Usuario.h"
#include "Organizador.h"
#include "Free.h"
#include "Premium.h"
#include "Csv.h"

int main() {
    std::string user_name;
    std::vector<std::vector<std::string>> resposta;
    std::getline(std::cin,user_name);;
    std::string nome;
    std::string i = "1";
    Organizador user = Organizador();
    user.fazerLogin("daniel");
//    std::cout<<"Nome do novo usuario: "<<std::endl;
//    std::getline(std::cin,nome);
//    std::cout<<"tipo de usuario:"<<std::endl;
//    std::getline(std::cin,i);
//    std::cout<<"username: "<<std::endl;
//    std::getline(std::cin,user_name);
    user.cadastrarNovoUsuario("jeanine","JEANINE VASCONCELOS",stoi(i));
    user.cadastrarNovoUsuario("paulo", "PAULO MIRANDA", 2);
    user.cadastrarNovoUsuario("rachel", "RACHEL MARINHO", 3);
    return 0;
}