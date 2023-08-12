#include <string>
#include <list>

#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
class Passageiro {
    public:
        Passageiro(std::string nome, int idade, std::string planeta);
        int getId();
        std::string getNome();
        int getIdade();
        std::string getPlaneta();
        void setNome(std::string);
        void setIdade(int);
        void setPlaneta(std::string planeta);
    private:
        int id;
        std::string nome;
        int idade;
        std::string planeta;
};
#endif