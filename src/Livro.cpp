//
// Created by User on 27/11/2019.
//

#include "Livro.h"
Livro::Livro(){
    this->titulo = "";
    this->autor = "";
    this->alugado_por = "";
    this->localizacao = "";
}
Livro::Livro(std::string titulo, std::string autor, std::string alugado_por, std::string localizacao){
    this->titulo = titulo;
    this->autor=autor;
    this->alugado_por = alugado_por;
    this->localizacao = localizacao;
}
std::string Livro::get_titulo(){
    return this->titulo;
}
void Livro::set_titulo(std::string titulo){
    this->titulo=titulo;
}
std::string Livro::get_autor(){
    return this->autor;
}
void Livro::set_autor(std::string autor){
    this->autor = autor;
}
std::string Livro::get_alugado_por(){
    return this->alugado_por;
}
void Livro::set_alugado_por(std::string alugado_por){
    this->alugado_por = alugado_por;
}
std::string Livro::get_localizacao(){
    return this->localizacao;
}
void Livro::set_localizacao(std::string localizacao){
    this->localizacao = localizacao;
}