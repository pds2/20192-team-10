#include "Csv.h"
#include "Usuario.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

std::vector<std::vector<std::string>> parse_csv(std::string path_arquivo){
    std::vector<std::vector<std::string>> resposta;
    std::string s;
    char l[200];
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    std::ifstream f(path_arquivo,std::ios::in);
    int i=0;
    if(f.fail()){
        std::cout <<"no file"<<std::endl;
        return resposta;
    }
    f.getline(l,200);
    while (!f.eof()) {
        std::vector<std::string> linha;
        f.getline(l,200);
        s=l;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            linha.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        token = s.substr(0, pos);
        linha.push_back(token);
        resposta.push_back(linha);
        i++;
    }
    f.close();
    return resposta;
  }

std::vector<std::string> encontrarUsuario(std::string username, std::string filepath) {
    unsigned int i;
    transform(username.begin(), username.end(), username.begin(), ::tolower);
    std::vector<std::vector<std::string>> registros = parse_csv(filepath);
    std::vector<std::string> nenhum = {" "};
    if (registros.empty()){
        throw std::runtime_error("Nenhum usuario cadastrado");
    }
    for (i =0;i<registros.size()-1;i++){
        if (registros.at(i).at(0)==username) {
            return registros.at(i);
        }
    }
    throw std::runtime_error("usuario não encontrado");
}

void insereUsuario(std::string username, std::string nome, std::string filepath){
    transform(nome.begin(), nome.end(), nome.begin(), ::toupper);
    std::string linha = username+","+nome+",0\n";
    std::ofstream f(filepath,std::ios::app);
    if(f.fail()){
        std::cout <<"no file"<<std::endl;
        return;
    }
    f<<linha;
}

void insereUsuario(std::string username,  std::string filepath, int tipo){
    std::ofstream f(filepath,std::ios::app);
    if(f.fail()){
        std::cout <<"no file"<<std::endl;
        return;
    }
    switch(tipo){
        case 1:
            f<<username<<",organizador\n";
            break;
        case 2:
            f<<username<<",premium\n";
            break;
        case 3:
            f<<username<<",free\n";
            break;
        default:
            return;
    }
}

std::vector<std::string> encontraLivroPorTitulo(std::string titulo){
    std::string filepath = "../Database/Livros/livros.csv";
    unsigned int i=0;
    size_t pos = 0;
    transform(titulo.begin(), titulo.end(), titulo.begin(), ::toupper);
    std::vector<std::vector<std::string>> registros = parse_csv(filepath);
    std::vector<std::string> nenhum = {" "};
    if (registros.empty()){
        return nenhum;
    }
    for (i =0;i<registros.size()-1;i++){
        pos = registros.at(i).at(0).find(titulo);//acha substring
        if (pos < registros.at(i).at(0).size()) {
            return registros.at(i);
        }
    }
    return  nenhum;
}

void atualiza_csv(std::vector<std::vector<std::string>> dados,std::string path_arquivo){
    unsigned int i =0, j=0, fim =0;
    std::vector<std::vector<std::string>> resposta = parse_csv(path_arquivo);
    for(i=0;i<(resposta.size()-1);i++){
        if(resposta.at(i).at(0)==dados.at(1).at(0)){
            resposta.at(i)=dados.at(1);
            break;
        }
    }
    std::ofstream f(path_arquivo,std::ios::out);
    if(f.fail()){
        std::cout <<"no file"<<std::endl;
        return;
    }
    fim = dados.at(0).size()-1;
    std::string linha;
    for(j=0;j<(dados.at(0).size()-1);j++){
        linha.append(dados.at(0).at(j));
        linha.append(",");
    }
    linha.append(dados.at(0).at(j));
    linha.append("\n");
    f<<linha;
    for(i=0;i<(resposta.size()-1);i++){
        linha="";
        for(j=0;j<(resposta.at(i).size()-1);j++){
            linha.append(resposta.at(i).at(j));
            linha.append(",");
        }
        linha.append(resposta.at(i).at(j));
        linha.append("\n");
        f<<linha;
    }
    f.close();
}

void alugaLivro(std::string username, std::string titulo, std::string filepath){
    std::string livros_path = "../Database/Livros/livros.csv";
    std::vector<std::vector<std::string>> dadosLivro= {{"titulo","autor","localizacao","alugado por"}};
    dadosLivro.push_back(encontraLivroPorTitulo(titulo));
    std::vector<std::vector<std::string>>dadosUsuario = {{"user_name", "nome", "livros_alugados"}};
    dadosUsuario.push_back(encontrarUsuario(username,filepath));
    unsigned int ultima_coluna =dadosLivro.at(1).size()-1;
    if(dadosLivro.at(1).at(ultima_coluna).at(0)=='0'){
        dadosLivro.at(1).at(ultima_coluna)=username;
    }
    else{
        std::cout<<"livro já está alugado\n";
        return;
    }
    atualiza_csv(dadosLivro,livros_path);
    ultima_coluna =dadosUsuario.at(1).size()-1;
    if(dadosUsuario.at(1).at(ultima_coluna).at(0)=='0'){
        dadosUsuario.at(1).at(ultima_coluna)=titulo;
    }
    else{
        dadosUsuario.at(1).at(ultima_coluna).push_back('/');
        dadosUsuario.at(1).at(ultima_coluna).append(titulo);
    }
    atualiza_csv(dadosUsuario,filepath);
    std::cout<<"aluguel realizado com sucesso\n";
}

void devolveLivro(std::string username, std::string titulo, std::string filepath){
    std::string livros_path = "../Database/Livros/livros.csv";
    std::vector<std::vector<std::string>> dadosLivro= {{"titulo","autor","localizacao","alugado por"}};
    dadosLivro.push_back(encontraLivroPorTitulo(titulo));
    std::vector<std::vector<std::string>>dadosUsuario = {{"user_name", "nome", "livros_alugados"}};
    dadosUsuario.push_back(encontrarUsuario(username,filepath));
    unsigned int ultima_coluna =dadosLivro.at(1).size()-1;
    dadosLivro.at(1).at(ultima_coluna)="0";
    std::string separador = "/";
    atualiza_csv(dadosLivro,livros_path);
    ultima_coluna =dadosUsuario.at(1).size()-1;
    size_t pos = dadosUsuario.at(1).at(ultima_coluna).find(titulo);
    if (pos != std::string::npos){
        dadosUsuario.at(1).at(ultima_coluna).erase(pos, titulo.length());
    }
    pos = dadosUsuario.at(1).at(ultima_coluna).find(separador);
    if (pos != std::string::npos){
        dadosUsuario.at(1).at(ultima_coluna).erase(pos, separador.length());
    }
    else{
        dadosUsuario.at(1).at(ultima_coluna).push_back('0');
    }
    atualiza_csv(dadosUsuario,filepath);
}