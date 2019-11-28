#include <string>
#include <vector>
#include "Usuario.h"

std::vector<std::vector<std::string>> parse_csv(std::string path_arquivo);
std::vector<std::string> encontrarUsuario (std::string username, std::string filepath);
void insereUsuario(std::string username, std::string nome, std::string filepath);
void insereUsuario(std::string username, std::string filepath, int tipo);
std::vector<std::string> encontraLivroPorTitulo(std::string titulo);
std::vector<std::vector<std::string>> encontraLivroPorAutor(std::string autor);
void atualiza_csv(std::vector<std::vector<std::string>> dados ,std::string path_arquivo);
void alugaLivro(std::string username, std::string titulo, std::string filepath);
void devolveLivro(std::string username, std::string titulo, std::string filepath);