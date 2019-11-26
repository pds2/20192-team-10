#include <iostream>
#include <fstream>
#include <vector>
#include "Usuario.h"
#include "Organizador.h"
#include "Free.h"
#include "Csv.h"

int main() {
    std::string user_name;
    std::vector<std::vector<std::string>> resposta;
    std::cin >> user_name;
    Free user = Free();
    user.fazerLogin(user_name);
    std::cout << user.get_name() << std::endl;
    std::cout << user.get_username() << std::endl;
    return 0;
}