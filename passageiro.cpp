#include "passageiro.h"

#include <random>

using std::string;

Passageiro::Passageiro(std::string nome, int idade, std::string planeta) {
    this->id = rand();
    this->nome = nome;
    this->planeta = planeta;
    this->idade = idade;
};

int Passageiro::getId() {
    return id;
}

string Passageiro::getNome() {
    return nome;
}

int Passageiro::getIdade() {
    return idade;
}

string Passageiro::getPlaneta() {
    return planeta;
}

void Passageiro::setNome(string nome) {
    this->nome = nome;
}

void Passageiro::setIdade(int idade) {
    this->idade = idade;
}

void Passageiro::setPlaneta(string planeta) {
    this->planeta = planeta;
}