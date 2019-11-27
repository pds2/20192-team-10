#include <string>
#include <vector>
#include "Usuario.h"

std::vector<std::vector<std::string>> parse_csv(std::string path_arquivo);
std::vector<std::string> encontrarUsuario (std::string username, std::string filepath);
void insereUsuario(std::string username, std::string nome, std::string filepath);
void insereUsuario(std::string username, std::string filepath, int tipo);