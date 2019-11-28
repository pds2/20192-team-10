#include <iostream>
#include <string>
#include "Organizador.h"
#include "Free.h"
#include "Premium.h"
#include "Csv.h"
#include "interface-usuario.h"
#include "Livro.h"

void mostraMenu(Organizador user){
	std::string input;
	int opcao;
	
	while(1){

		std::cout << "\tMENU\n";
		std::cout<<"(1) Meus Livros\n";
		std::cout<<"(2) Alugar Livro\n";
		//std::cout<<"(3) Cadastrar Novo Usuário\n";
		std::cout<<"(3) Devolver Livro\n";
		std::cout<<"escreva o número da opção que deseja acessar\n";
		std::cout<<"para sair escreva: \tsair\n";
		std::getline(std::cin, input);

		if(input == "sair"){
			break;
		}
		try{
			if(stoi(input)>0&&stoi(input)<5){
				opcao=stoi(input);
				switch(opcao){
					case 1:{
						mostraMeusLivros(user);
						break;
					}
					case 2:{
						mostraAlugarLivro(user);
						break;
					}
					case 3:{
						mostraDevolverLivro(user);
						break;
					}
				}
			}
			else{
				std::cout<<"entrada invalida\n";
			}
		}
		catch(std::invalid_argument){
            std::cout<<"entrada invalida\n";
        }
	}
}

void mostraMeusLivros(Organizador user){
	std::vector<std::string> meusLivros;
	meusLivros = user.get_livros_alugados();
	unsigned int i;
	std::cout<<"\tMEUS LIVROS\n";
	for(i=0;i<meusLivros.size();i++){
		std::cout<<meusLivros.at(i)<<"\n";
	}
}

void mostraAlugarLivro(Organizador user){
	Livro livro = Livro();
	std::string input;
	std::vector<std::string> dados;
	int opcao;
	std::cout<<"\tALUGAR LIVRO\n";
	std::cout<<"Você deseja encontrar o livro por:\n";
	std::cout<<"(1) Titulo\n";
	//std::cout<<"(2) Autor\n";
	std::cout<<"escreva o número da opção que deseja acessar\n";
	std::cout<<"para sair escreva: \tsair\n";
	while(1){
		std::getline(std::cin, input);
		if(input == "sair"){
			break;
		}
		try{
			if(stoi(input)>0&&stoi(input)<2){
				opcao=stoi(input);
				switch(opcao){
					case 1:{
						std::cout<<"digite titulo:\n";
						std::getline(std::cin, input);
						dados = encontraLivroPorTitulo(input);
						std::cout<<dados.at(0);
						if(dados.at(0) != " "){
							std::cout<<"Você está solicitando:\n";
							std::cout<<"Titulo: "<<dados.at(0)<<"\n";
							std::cout<<"Autor: "<<dados.at(1)<<"\n";
							std::cout<<"Que esta localizado em: "<<dados.at(2)<<"\n";
							livro.set_titulo(dados.at(0));
							user.alugarLivro(livro);
						}
						break;
					}
					case 2:{
						//autor
						break;
					}
				}
				break;
			}
			else{
				std::cout<<"entrada invalida\n";
			}
		}
		catch(std::invalid_argument){
            std::cout<<"entrada invalida\n";
        }
	}
}

void mostraDevolverLivro(Organizador user){
	Livro livro = Livro();
	std::string input;
	int opcao;
	std::vector<std::string> dados;
	std::cout<<"\tDEVOLVER LIVRO\n";
	std::cout<<"Você deseja devolver qual livro:\n";
	std::vector<std::string> meusLivros;
	meusLivros = user.get_livros_alugados();
	unsigned int i;
	for(i=0;i<meusLivros.size();i++){
		std::cout<<"("<<i<<")"<<meusLivros.at(i)<<"\n";
	}
	while(1){
		std::cout<<"escreva o número do opção que deseja acessar\n";
		std::cout<<"para sair escreva: \tsair\n";
		std::getline(std::cin, input);
			if(input == "sair"){
				break;
			}
		try{
			if(stoi(input)>-1&&stoi(input)<meusLivros.size()){
				opcao=stoi(input);
				livro.set_titulo(meusLivros.at(opcao));
				user.devolverLivro(livro);
				std::cout<< livro.get_titulo()<<" devolvido\n";
				}
			else{
				std::cout<<"entrada invalida\n";
			}
		}
		catch(std::invalid_argument){
            std::cout<<"entrada invalida\n";
        }
	}
}


void mostraMenu(Free user){
	std::string input;
	int opcao;
	
	while(1){

		std::cout << "\tMENU\n";
		std::cout<<"(1) Meus Livros\n";
		std::cout<<"(2) Alugar Livro\n";
		//std::cout<<"(3) Cadastrar Novo Usuário\n";
		std::cout<<"(3) Devolver Livro\n";
		std::cout<<"escreva o número da opção que deseja acessar\n";
		std::cout<<"para sair escreva: \tsair\n";
		std::getline(std::cin, input);

		if(input == "sair"){
			break;
		}
		try{
			if(stoi(input)>0&&stoi(input)<5){
				opcao=stoi(input);
				switch(opcao){
					case 1:{
						mostraMeusLivros(user);
						break;
					}
					case 2:{
						mostraAlugarLivro(user);
						break;
					}
					case 3:{
						mostraDevolverLivro(user);
						break;
					}
				}
			}
			else{
				std::cout<<"entrada invalida\n";
			}
		}
		catch(std::invalid_argument){
            std::cout<<"entrada invalida\n";
        }
	}
}

void mostraMeusLivros(Free user){
	std::vector<std::string> meusLivros;
	meusLivros = user.get_livros_alugados();
	unsigned int i;
	std::cout<<"\tMEUS LIVROS\n";
	for(i=0;i<meusLivros.size();i++){
		std::cout<<meusLivros.at(i)<<"\n";
	}
}

void mostraAlugarLivro(Free user){
	Livro livro = Livro();
	std::string input;
	std::vector<std::string> dados;
	int opcao;
	std::cout<<"\tALUGAR LIVRO\n";
	std::cout<<"Você deseja encontrar o livro por:\n";
	std::cout<<"(1) Titulo\n";
	//std::cout<<"(2) Autor\n";
	std::cout<<"escreva o número da opção que deseja acessar\n";
	std::cout<<"para sair escreva: \tsair\n";
	while(1){
		std::getline(std::cin, input);
		if(input == "sair"){
			break;
		}
		try{
			if(stoi(input)>0&&stoi(input)<2){
				opcao=stoi(input);
				switch(opcao){
					case 1:{
						std::cout<<"digite titulo:\n";
						std::getline(std::cin, input);
						dados = encontraLivroPorTitulo(input);
						std::cout<<dados.at(0);
						if(dados.at(0) != " "){
							std::cout<<"Você está solicitando:\n";
							std::cout<<"Titulo: "<<dados.at(0)<<"\n";
							std::cout<<"Autor: "<<dados.at(1)<<"\n";
							std::cout<<"Que esta localizado em: "<<dados.at(2)<<"\n";
							livro.set_titulo(dados.at(0));
							user.alugarLivro(livro);
						}
						break;
					}
					case 2:{
						//autor
						break;
					}
				}
				break;
			}
			else{
				std::cout<<"entrada invalida\n";
			}
		}
		catch(std::invalid_argument){
            std::cout<<"entrada invalida\n";
        }
	}
}

void mostraDevolverLivro(Free user){
	Livro livro = Livro();
	std::string input;
	int opcao;
	std::vector<std::string> dados;
	std::cout<<"\tDEVOLVER LIVRO\n";
	std::cout<<"Você deseja devolver qual livro:\n";
	std::vector<std::string> meusLivros;
	meusLivros = user.get_livros_alugados();
	unsigned int i;
	for(i=0;i<meusLivros.size();i++){
		std::cout<<"("<<i<<")"<<meusLivros.at(i)<<"\n";
	}
	while(1){
		std::cout<<"escreva o número do opção que deseja acessar\n";
		std::cout<<"para sair escreva: \tsair\n";
		std::getline(std::cin, input);
			if(input == "sair"){
				break;
			}
		try{
			if(stoi(input)>-1&&stoi(input)<meusLivros.size()){
				opcao=stoi(input);
				livro.set_titulo(meusLivros.at(opcao));
				user.devolverLivro(livro);
				std::cout<< livro.get_titulo()<<" devolvido\n";
				}
			else{
				std::cout<<"entrada invalida\n";
			}
		}
		catch(std::invalid_argument){
            std::cout<<"entrada invalida\n";
        }
	}
}


void mostraMenu(Premium user){
	std::string input;
	int opcao;
	
	while(1){

		std::cout << "\tMENU\n";
		std::cout<<"(1) Meus Livros\n";
		std::cout<<"(2) Alugar Livro\n";
		//std::cout<<"(3) Cadastrar Novo Usuário\n";
		std::cout<<"(3) Devolver Livro\n";
		std::cout<<"escreva o número da opção que deseja acessar\n";
		std::cout<<"para sair escreva: \tsair\n";
		std::getline(std::cin, input);

		if(input == "sair"){
			break;
		}
		try{
			if(stoi(input)>0&&stoi(input)<5){
				opcao=stoi(input);
				switch(opcao){
					case 1:{
						mostraMeusLivros(user);
						break;
					}
					case 2:{
						mostraAlugarLivro(user);
						break;
					}
					case 3:{
						mostraDevolverLivro(user);
						break;
					}
				}
			}
			else{
				std::cout<<"entrada invalida\n";
			}
		}
		catch(std::invalid_argument){
            std::cout<<"entrada invalida\n";
        }
	}
}

void mostraMeusLivros(Premium user){
	std::vector<std::string> meusLivros;
	meusLivros = user.get_livros_alugados();
	unsigned int i;
	std::cout<<"\tMEUS LIVROS\n";
	for(i=0;i<meusLivros.size();i++){
		std::cout<<meusLivros.at(i)<<"\n";
	}
}

void mostraAlugarLivro(Premium user){
	Livro livro = Livro();
	std::string input;
	std::vector<std::string> dados;
	int opcao;
	std::cout<<"\tALUGAR LIVRO\n";
	std::cout<<"Você deseja encontrar o livro por:\n";
	std::cout<<"(1) Titulo\n";
	//std::cout<<"(2) Autor\n";
	std::cout<<"escreva o número da opção que deseja acessar\n";
	std::cout<<"para sair escreva: \tsair\n";
	while(1){
		std::getline(std::cin, input);
		if(input == "sair"){
			break;
		}
		try{
			if(stoi(input)>0&&stoi(input)<2){
				opcao=stoi(input);
				switch(opcao){
					case 1:{
						std::cout<<"digite titulo:\n";
						std::getline(std::cin, input);
						dados = encontraLivroPorTitulo(input);
						std::cout<<dados.at(0);
						if(dados.at(0) != " "){
							std::cout<<"Você está solicitando:\n";
							std::cout<<"Titulo: "<<dados.at(0)<<"\n";
							std::cout<<"Autor: "<<dados.at(1)<<"\n";
							std::cout<<"Que esta localizado em: "<<dados.at(2)<<"\n";
							livro.set_titulo(dados.at(0));
							user.alugarLivro(livro);
						}
						break;
					}
					case 2:{
						//autor
						break;
					}
				}
				break;
			}
			else{
				std::cout<<"entrada invalida\n";
			}
		}
		catch(std::invalid_argument){
            std::cout<<"entrada invalida\n";
        }
	}
}

void mostraDevolverLivro(Premium user){
	Livro livro = Livro();
	std::string input;
	int opcao;
	std::vector<std::string> dados;
	std::cout<<"\tDEVOLVER LIVRO\n";
	std::cout<<"Você deseja devolver qual livro:\n";
	std::vector<std::string> meusLivros;
	meusLivros = user.get_livros_alugados();
	unsigned int i;
	for(i=0;i<meusLivros.size();i++){
		std::cout<<"("<<i<<")"<<meusLivros.at(i)<<"\n";
	}
	while(1){
		std::cout<<"escreva o número do opção que deseja acessar\n";
		std::cout<<"para sair escreva: \tsair\n";
		std::getline(std::cin, input);
			if(input == "sair"){
				break;
			}
		try{
			if(stoi(input)>-1&&stoi(input)<meusLivros.size()){
				opcao=stoi(input);
				livro.set_titulo(meusLivros.at(opcao));
				user.devolverLivro(livro);
				std::cout<< livro.get_titulo()<<" devolvido\n";
				}
			else{
				std::cout<<"entrada invalida\n";
			}
		}
		catch(std::invalid_argument){
            std::cout<<"entrada invalida\n";
        }
	}
}