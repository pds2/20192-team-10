//
// Created by User on 24/11/2019.
//

#ifndef INC_20192_TEAM_10_USUARIO_H
#define INC_20192_TEAM_10_USUARIO_H


#include <string>
#include <vector>
#include "Livro.h"

class Usuario {
    protected:
        std::string username;
        std::string name;
        std::vector<std::string> livros_alugados;

    public:
        Usuario();
        Usuario(std::string username, std::string name, std::vector<std::string> livros_alugados);
        ~Usuario()= default;
        std::string get_username();
        void set_username(std::string username);
        std::string get_name();
        void set_name(std::string name);
        std::vector<std::string> get_livros_alugados();
        void set_livros_alugados(std::vector<std::string> livros_alugados);
        virtual void fazerLogin(std::string username)=0;
        void fazerLogin(std::string username, std::string filepath);
        virtual void alugarLivro(Livro livro)=0;
        virtual void devolverLivro(Livro livro)=0;
};


#endif //INC_20192_TEAM_10_USUARIO_H
