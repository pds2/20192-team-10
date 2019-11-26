//
// Created by User on 24/11/2019.
//

#ifndef INC_20192_TEAM_10_USUARIO_H
#define INC_20192_TEAM_10_USUARIO_H


#include <string>

class Usuario {
    protected:
        std::string username;
        std::string name;
    //lista de livros alugados

    public:
        Usuario();
        Usuario(int id, std::string username, std::string name);
        ~Usuario()= default;
        std::string get_username();
        void set_username(std::string username);
        std::string get_name();
        void set_name(std::string name);
        virtual void fazerLogin(std::string username)=0;
        void fazerLogin(std::string username, std::string filepath);
};


#endif //INC_20192_TEAM_10_USUARIO_H
