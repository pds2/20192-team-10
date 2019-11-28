#include<iostream>
#include<string>
#include "Organizador.h"
void mostraMenu(Organizador user){
	std::string input;
	int opcao;
	std::cout << "\tMENU\n";
	std::cout<<"(1) Meus Livros\n";
	std::cout<<"(2) Alugar Livro\n";
	std::cout<<"(3) Cadastrar Novo Usuário\n";
	std::cout<<"(4) Devolver Livro\n";
	std::cout<<"escreva o número da opção que deseja acessar\n";
	std::cout<<"para sair escreva: \tsair\n";
	while(1){
		std::getline(std::cin, input);
		if(input == "sair"){
			break;
		}
		try{
			if(stoi(input)>0&&stoi(input)<5){
				opcao=stoi(input);
				switch(opcao){
					case 1:{
						//mostra livros
						break;
					}
					case 2:{
						//alugar livros
						break;
					}
					case 3:{
						//cadastra novo usuario
						break;
					}
					case 4:{
						//devolve livro
						break;
					}
				}
			}
		}
		catch(std::invalid_argument){
            std::cout<<"entrada invalida\n";
        }
	}
}