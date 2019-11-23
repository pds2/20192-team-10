#include <iostream>
#include <fstream>

int main() {
    std::ifstream f("../Database/Usuarios/usuarios.csv",std::ios::in);
    char c[200];
    if(f.fail()){
        std::cout <<"no file"<<std::endl;
    }
    else {
        while (!f.eof()) {
            f.getline(c, 200);
            std::cout << c << std::endl;
        }
    }
    f.close();
    return 0;
}