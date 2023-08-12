#include "espacoNave.h"

class Heap {
    public:
        Heap(int tamanho);
        int getTamanho();
        int getTamanhoAtual();
        void setTamanhoAtual(int tamanhoAtual);
        EspacoNave* getEspacoNave(int posicao);
        void addEspacoNave(EspacoNave* espacoNave);
        EspacoNave* removeEspacoNave();
        void buildHeap();
        void heapSort();
        void printHeap();
    private:
        int tamanho;
        int tamanhoAtual;
        EspacoNave** espacoNaves;
        void swap(int posicao1, int posicao2);
        void subir(int posicao);
        void descer(int posicao);
};