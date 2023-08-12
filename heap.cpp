#include <iostream>
#include <random>

#include "heap.h"

using std::cout;
using std::endl;

/**
 * Heap constructor
 * @param tamanho
 */
Heap::Heap(int tamanho) {
    this->tamanho = tamanho;
    this->tamanhoAtual = 0;
    this->espacoNaves = new EspacoNave*[tamanho];
}

/**
 * Get heap size
 * @return heap size
 */
int Heap::getTamanho() {
    return this->tamanho;
}

/**
 * Get current heap size
 * @return current heap size
 */
int Heap::getTamanhoAtual() {
    return this->tamanhoAtual;
}

/**
 * Set current heap size
 * @param tamanhoAtual
 */
void Heap::setTamanhoAtual(int tamanhoAtual) {
    this->tamanhoAtual = tamanhoAtual;
}

/**
 * Get EspacoNave from heap
 * @param posicao
 * @return EspacoNave
 */

EspacoNave* Heap::getEspacoNave(int posicao) {
    return this->espacoNaves[posicao];
}


/**
 * Add EspacoNave in heap
 *  Para simplificar o sistema, para cada espaçonave que entra na fila, deve-se atribuir
uma nova prioridade com probabilidade de 10%.
 * @param espacoNave
 */
void Heap::addEspacoNave(EspacoNave *espacoNave) {
    if (tamanhoAtual == tamanho) {
        cout << "Heap cheio" << endl;
    }

    int probabilidade = rand() % 10 + 1;
    if (probabilidade == 1) {
        espacoNave->mudarPrioridade(rand() % 100 + 1);
    }

    espacoNaves[tamanhoAtual] = espacoNave;
    tamanhoAtual++;
    subir(tamanhoAtual - 1);
}

/**
 * Remove EspacoNave from heap (the one with the highest priority)
 * @return EspacoNave
 */
EspacoNave* Heap::removeEspacoNave() {
    if (tamanhoAtual == 0) {
        cout << "Heap vazio" << endl;
    }

    EspacoNave* espacoNave = espacoNaves[0];
    espacoNaves[0] = espacoNaves[tamanhoAtual - 1];
    tamanhoAtual--;
    descer(0);

    return espacoNave;
}

/**
 * Build heap
 */
void Heap::buildHeap() {
    for (int i = tamanhoAtual / 2 - 1; i >= 0; i--) {
        descer(i);
    }
}

/**
 * Heap sort
 */
void Heap::heapSort() {
    buildHeap();

    for (int i = tamanhoAtual - 1; i >= 1; i--) {
        swap(0, i);
        tamanhoAtual--;
        descer(0);
    }
}

/**
 * Print heap
 */
void Heap::printHeap() {
    for (int i = 0; i < tamanhoAtual; i++) {
        espacoNaves[i]->printInfo();
    }
}

/**
 * Swap EspacoNave positions
 * @param posicao1
 * @param posicao2
 */
void Heap::swap(int posicao1, int posicao2) {
    EspacoNave* temp = espacoNaves[posicao1];
    espacoNaves[posicao1] = espacoNaves[posicao2];
    espacoNaves[posicao2] = temp;
}

/**
 * Up EspacoNave
 * @param posicao
 */
void Heap::subir(int posicao) {
    int pai = (posicao - 1) / 2;

    if (posicao > 0 && espacoNaves[posicao]->getPrioridade() > espacoNaves[pai]->getPrioridade()) {
        swap(posicao, pai);
        subir(pai);
    }
}

/**
 * Down EspacoNave
 * @param posicao
 */
void Heap::descer(int posicao) {
    int filhoEsquerda = 2 * posicao + 1;
    int filhoDireita = 2 * posicao + 2;

    int maior = posicao;

    if (filhoEsquerda < tamanhoAtual && espacoNaves[filhoEsquerda]->getPrioridade() > espacoNaves[maior]->getPrioridade()) {
        maior = filhoEsquerda;
    }

    if (filhoDireita < tamanhoAtual && espacoNaves[filhoDireita]->getPrioridade() > espacoNaves[maior]->getPrioridade()) {
        maior = filhoDireita;
    }

    if (maior != posicao) {
        swap(posicao, maior);
        descer(maior);
    }
}

