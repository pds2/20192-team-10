#include <iostream>
#include <fstream>
#include <vector>
#include "Usuario.h"
#include "Organizador.h"
#include "Free.h"
#include "Premium.h"
#include "interface-usuario.h"
#include "Csv.h"

int main() {
    std::string tipo_conta;
    int conta;
    std::string username;



    while(1){
        std::cout<<"\n\tSISTEMA DE BIBLIOTECA\n\nselecione seu tipo de conta cadastrado:\n";
        std::cout<<"(1)Organizador\n(2)Premium\n(3)Free\n";
        std::cout<<"para selecionar digite o numero da opcao\n";
        std::cout<<"para sair digite:\tsair\n";
        std::getline(std::cin,tipo_conta);
        if(tipo_conta == "sair"){
            break;
        }
        try{
            if(stoi(tipo_conta)>0&&stoi(tipo_conta)<4){
                conta =stoi(tipo_conta);
                std::cout<<"OK\n";
                std::cout<<"digite seu usuario no campo a baixo\n";
                std::cout<<"login:\n";
                std::getline(std::cin,username);
                switch(conta){
                    case 1:{
                        Organizador user = Organizador();
                        try{
                            user.fazerLogin(username);
                        }
                        catch(std::runtime_error &e){
                            break;
                        }
                        mostraMenu(user);
                        return 0;
                    }

                    case 2:{
                        Premium user = Premium();
                        try{
                            user.fazerLogin(username);
                        }
                        catch(std::runtime_error &e){
                            break;
                        }
                        mostraMenu(user);
                        return 0;
                    }

                    case 3:{
                        Free user = Free();
                        try{
                            user.fazerLogin(username);
                        }
                        catch(std::runtime_error &e){
                            break;
                        }
                        mostraMenu(user);
                        return 0;
                    }

                }
            }
            else{
                std::cout<<"entrada invalida\n";
            }
        }
        catch(std::invalid_argument &e){
            std::cout<<"entrada invalida\n";
        }
        }


    return 0;
}