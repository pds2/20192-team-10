//
// Created by User on 24/11/2019.
//

#include "Organizador.h"
#include "Usuario.h"
#include "Csv.h"
#include "Livro.h"
#include <string>
#include <iostream>
#include <fstream>

Organizador::Organizador(std::string name, std::string username) {
    this->username = username;
    this->name = name;
    this->livros_alugados ={} ;
}
Organizador::Organizador() {
    this->username = "nenhum";
    this->name = "NINGUEM";
    this->livros_alugados ={} ;
}
void Organizador::fazerLogin(std::string username) {
    std::string file_path = "../Database/Usuarios/organizadores.csv";
    Usuario::fazerLogin(username,file_path);
}

void Organizador::cadastrarNovoUsuario(std::string username, std::string nome, int tipo)  {
    std::string arquivo_usuarios = "../Database/Usuarios/usuarios.csv";
    std::vector<std::string> encontrou;
    try{
        encontrou = encontrarUsuario(username, arquivo_usuarios);
    }
    catch(std::runtime_error){
        switch (tipo){
            case 1:
                cadastrarNovoOrganizador(username,nome);
                break;
            case 2:
                cadastrarNovoPremium(username, nome);
                break;
            case 3:
                cadastrarNovoFree(username,nome);
                break;
            default:
                std::cout<< "tipo de conta invalida"<<std::endl;
                return;
        }
        std::cout<<"cadastro realizado com sucesso"<<std::endl;
        return;
    }
    std::cout<< "este username ja esta sendo usado por outra pessoa"<<std::endl;
}

void Organizador::cadastrarNovoOrganizador(std::string username, std::string nome) {
    std::string filepath = "../Database/Usuarios/organizadores.csv";
    insereUsuario(username, nome, filepath);
    filepath = "../Database/Usuarios/usuarios.csv";
    insereUsuario(username, filepath,1);
}

void Organizador::cadastrarNovoPremium(std::string username, std::string nome) {
    std::string filepath = "../Database/Usuarios/premium.csv";
    insereUsuario(username, nome, filepath);
    filepath = "../Database/Usuarios/usuarios.csv";
    insereUsuario(username, filepath,2);
}

void Organizador::cadastrarNovoFree(std::string username, std::string nome) {
    std::string filepath = "../Database/Usuarios/free.csv";
    insereUsuario(username, nome, filepath);
    filepath = "../Database/Usuarios/usuarios.csv";
    insereUsuario(username, filepath, 3);
}

void Organizador::alugarLivro(Livro livro) {
    std::string filepath = "../Database/Usuarios/organizadores.csv";
    alugaLivro(this->username,livro.get_titulo(),filepath);
    std::vector<std::string> novoLivrosAlugados;
    novoLivrosAlugados = get_livros_alugados();
    novoLivrosAlugados.push_back(livro.get_titulo());
    set_livros_alugados(novoLivrosAlugados);
}

void Organizador::devolverLivro(Livro livro){
    std::string filepath = "../Database/Usuarios/organizadores.csv";
    devolveLivro(this->username,livro.get_titulo(),filepath);
}