//
// Created by User on 24/11/2019.
//

#ifndef INC_20192_TEAM_10_ORGANIZADOR_H
#define INC_20192_TEAM_10_ORGANIZADOR_H


#include "Usuario.h"

class Organizador : public Usuario{
    public:
        Organizador(std::string name, std::string username);
        Organizador();
        ~Organizador() = default;
        void fazerLogin(std::string username) override;
        void cadastrarNovoUsuario(std::string username, std::string nome, int tipo);
private:
    void cadastrarNovoOrganizador(std::string username, std::string nome);
    void cadastrarNovoPremium(std::string username, std::string nome);
    void cadastrarNovoFree(std::string username, std::string nome);

};


#endif //INC_20192_TEAM_10_ORGANIZADOR_H
