#include <list>

#include "recurso.h"
#include "passageiro.h"

#ifndef ESPACONAVE_H
#define ESPACONAVE_H
class EspacoNave {
    public:
        EspacoNave(int prioridade);
        int getId();
        int getPrioridade();
        std::list<Passageiro*> getPassageiros();
        std::list<Recurso*> getRecursos();
        void addRecurso(Recurso* recurso);
        void removeRecurso(int id);
        void addPassageiro(Passageiro *passageiro);
        void removePassageiro(int id);
        void mudarPrioridade(int prioridade);
        void printInfo();
    private:
        int id;
        int prioridade;
        std::list<Passageiro*> passageiros;
        std::list<Recurso*> recursos;
};
#endif