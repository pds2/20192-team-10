//
// Created by User on 27/11/2019.
//

#ifndef INC_20192_TEAM_10_LIVRO_H
#define INC_20192_TEAM_10_LIVRO_H


#include <string>

class Livro {
private:
    std::string titulo;
    std::string autor;
    std::string localizacao;
    std::string alugado_por;
public:
    Livro();
    Livro(std::string titulo, std::string autor, std::string alugado_por, std::string localizacao);
    ~Livro()=default;
    std::string get_titulo();
    void set_titulo(std::string titulo);
    std::string get_autor();
    void set_autor(std::string autor);
    std::string get_alugado_por();
    void set_alugado_por(std::string alugado_por);
    std::string get_localizacao();
    void set_localizacao(std::string localizacao);
};


#endif //INC_20192_TEAM_10_LIVRO_H
