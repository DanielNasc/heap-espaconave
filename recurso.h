#include <string>

#ifndef RECURSO_H
#define RECURSO_H

class Recurso {
    public:
        Recurso(std::string nome, int quantidade);
        int getId();
        std::string getNome();
        void setNome(std::string);
        int getQuantidade();
        void setQuantidade(int quantidade);
    private:
        int id;
        std::string nome;
        int quantidade;
};

#endif