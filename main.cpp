#include "heap.h"
#include "espacoNave.h"
#include "recurso.h"
#include "passageiro.h"

#include <iostream>
#include <random>
#include <string>
#include <time.h>

using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::string;


#define HEAP_SIZE 10

int main() {
    cout << "Iniciando heap..." << endl;
    Heap heap(HEAP_SIZE);

    // criar passageiros, recursos e colocá-los em espacoNaves e adicionar ao heap
    for (int i = 0; i < HEAP_SIZE; i++) {
        cout << "Criando espacoNave " << i << "..." << endl;
        int qtdPassageiros = rand() % 50 + 1;
        int qtdRecursos = rand() % 50 + 1;
        int prioridade = rand() % 100 + 1;
        cout << "Prioridade da espacoNave " << i << ": " << prioridade << endl;
        EspacoNave* espacoNave = new EspacoNave(prioridade);

        for (int j = 0; j < qtdPassageiros; j++) {
            string nome = "Passageiro " + std::to_string(j);
            int idade = rand() % 80 + 1;
            string planetaOrigem = "Planeta " + std::to_string(rand() % 100 + 1);
            Passageiro* passageiro = new Passageiro(nome, idade, planetaOrigem);
            espacoNave->addPassageiro(passageiro);
        }

        for (int j = 0; j < qtdRecursos; j++) {
            string nome = "Recurso " + std::to_string(j);
            int quantidade = rand() % 100 + 1;
            Recurso* recurso = new Recurso(nome, quantidade);
            espacoNave->addRecurso(recurso);
        }

        heap.addEspacoNave(espacoNave);
        cout << "EspacoNave " << i << " criada com sucesso!" << endl << endl;
    }

    // imprimir heap
    cout << "Heap inicial:" << endl << endl;
    heap.printHeap();

    // remover espacoNave com maior prioridade
    cout << "Removendo espacoNave com maior prioridade..." << endl << endl;
    EspacoNave* espacoNave = heap.removeEspacoNave();

    // imprimir heap
    cout << "Heap apos remocao:" << endl;
    heap.printHeap();

    // imprimir espacoNave removida
    cout << endl << "EspacoNave removida:" << endl;
    espacoNave->printInfo();

    return 0;
}