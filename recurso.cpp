#include "recurso.h"

using std::string;

Recurso::Recurso(string nome, int quantidade) {
    id = rand();
    this->nome = nome;
    this->quantidade = quantidade;
}

int Recurso::getId() {
    return id;
}

string Recurso::getNome() {
    return nome;
}

void Recurso::setNome(string nome) {
    this->nome = nome;
}

int Recurso::getQuantidade() {
    return quantidade;
}

void Recurso::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}