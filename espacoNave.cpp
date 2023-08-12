#include <string>
#include <list>
#include <iostream>

#include "espacoNave.h"

using std::string;
using std::list;
using std::cout;
using std::endl;

// prioridade maxima = 100
// prioridade minima = 0
EspacoNave::EspacoNave(int prioridade) {
    if (prioridade > 100) {
        prioridade = 100;
    }
    if (prioridade < 0) {
        prioridade = 0;
    }

    id = rand();
    this->prioridade = prioridade;
}

int EspacoNave::getId() {
    return id;
}

int EspacoNave::getPrioridade() {
    return prioridade;
}

list<Passageiro*> EspacoNave::getPassageiros() {
    return passageiros;
}

list<Recurso*> EspacoNave::getRecursos() {
    return recursos;
}

void EspacoNave::addRecurso(Recurso* recurso) {
    recursos.push_back(recurso);
}

void EspacoNave::removeRecurso(int id) {
    for (list<Recurso*>::iterator it = recursos.begin(); it != recursos.end(); it++) {
        if ((*it)->getId() == id) {
            recursos.erase(it);
            break;
        }
    }
}

void EspacoNave::addPassageiro(Passageiro *passageiro) {
    passageiros.push_back(passageiro);
}

void EspacoNave::removePassageiro(int id) {
    for (list<Passageiro*>::iterator it = passageiros.begin(); it != passageiros.end(); it++) {
        if ((*it)->getId() == id) {
            passageiros.erase(it);
            break;
        }
    }
}

void EspacoNave::mudarPrioridade(int prioridade) {
    if (prioridade > 100) {
        prioridade = 100;
    }
    if (prioridade < 0) {
        prioridade = 0;
    }

    cout << "! EspacoNave " << id << " teve sua prioridade alterada de " << this->prioridade << " para " << prioridade << endl;
    this->prioridade = prioridade;
}

void EspacoNave::printInfo() {
    cout << "EspacoNave " << id << "\tPrioridade: " << prioridade << "\tPassageiros: " << passageiros.size() << "\tRecursos: " << recursos.size() << endl;
}