#include <iostream>

#define NULLPTR 0;

using namespace std;

template <typename I>
class Item(){
private:
  I item;
  int chave;

public:
  void setItem(I item){
    this->item = item;
  }

  I getItem(){
    return item;
  }

  void setChave(){
    this->chave = chave;
  }

  int getChave(){
    return chave;
  }
}

template <typename N>
class No{
private:

  No<N>* esq;
  No<N>* dir;
  No<N>* pai;

  Item item;

  int altura;

public:
  No(No<N>* pai){
    this->pai = pai;
    this-> esq = NULLPTR;
    this-> dir = NULLPTR;
  }

  No(){
    this->pai = NULLPTR;
    this-> esq = NULLPTR;
    this-> dir = NULLPTR;
  }

  void setPai(No<N>* pai){
    this->pai = pai;
  }

  No*<N> getPai(){
    return pai;
  }

  void setEsq(No<N>* esq){
    this->esq = esq;
  }

  No*<N> getEsq(){
    return esq;
  }

  void setDir(No<N>* dir){
    this->dir = dir;
  }

  No*<N> getDir(){
    return dir;
  }

  Item getItemNo(){
    return this->item;
  }


};

template <typename T>
class AVLtree{
private:

  No<T>* raiz;

public:

  AVLtree(){
    this->raiz->setPai(NULLPTR);
  }

  void busca(T item){
    No<T>* aux = new No<T>();
    aux = raiz;
    if (aux == NULL){
      cout<<"Item não encontrado"<<endl;
    }
    else if(aux->getItemNo().getChave() > )
  }

  void insercao(T item){

  }


  void rotacaoDireita(){}

  void rotacaoEsquerda(){}



}



int main(){}
