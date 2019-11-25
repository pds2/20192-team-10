#include <iostream>
#include <fstream>
#include "Usuario.h"
#include "Organizador.h"

int main() {
    std::string user_name;
    std::cin >> user_name;
    Organizador user = Organizador();
    user.fazerLogin(user_name);
    std::cout << user.get_id() << std::endl;
    std::cout << user.get_name() << std::endl;
    std::cout << user.get_username() << std::endl;
    return 0;
}