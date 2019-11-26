#include <iostream>
#include <fstream>
#include <vector>
#include "Usuario.h"
#include "Organizador.h"
#include "Free.h"
#include "Premium.h"
#include "Csv.h"

int main() {
    std::string user_name;
    std::vector<std::vector<std::string>> resposta;
    std::cin >> user_name;
    Premium user = Premium();
    user.fazerLogin(user_name);
    std::cout << user.get_name() << std::endl;
    std::cout << user.get_username() << std::endl;
    return 0;
}