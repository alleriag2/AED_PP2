#include <iostream>

#define NULLPTR 0

using namespace std;

template <typename I>
class Item{
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
};

template <typename N>
class No{
private:

  No<N>* esq;
  No<N>* dir;
  No<N>* pai;

  N item;

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

  No<N>* getPai(){
    return pai;
  }

  void setEsq(No<N>* esq){
    this->esq = esq;
  }

  No<N>* getEsq(){
    return esq;
  }

  void setDir(No<N>* dir){
    this->dir = dir;
  }

  No<N>* getDir(){
    return dir;
  }

  N getItem(){
    return this->item;
  }

  void setItem(N item){
    this->item = item;
  }

  void setAltura(int altura){
    this->altura = altura;
  }

  int getAltura(){
    return this->altura;
  }


};

template <typename T>
class AVLtree{
private:
  No<T>* raizArvore;
public:
/*
  void busca(T item){
    No<T>* aux = new No<T>();
    aux = raiz;
    if (aux == NULLPTR){
      cout<<"Item não encontrado"<<endl;
    }
    else if(aux->getItem().getChave() > )
  }*/

  int fatorBalanceamento(No<T>* raiz){
    int balanceamento = 0;
    if(raiz) {
      balanceamento = raiz->getEsq()/*.getChave()*/ - raiz->getDir()/*.getChave()*/;
    }
    return balanceamento;
  }

  void insere(T item){
    No<T>* novoNo = new No<T>();
    novoNo->setItem(item);
    if(!raizArvore)
      raizArvore = novoNo;
    else
      insercaoAVL(raizArvore, novoNo);

  }

  void insercaoAVL(No<T>* raiz, No<T>* ins){
    if( ins->getItem()/*.getChave()*/ <= raiz->getItem()/*.getChave() */) {
      if(raiz->getEsq())
        insercaoAVL(raiz->getEsq(), ins);
      else {
        raiz->setEsq(ins);
        ins->setPai(raiz);
      }
    }
    else {
      if( raiz->getDir() )
        insercaoAVL(raiz->getDir(), ins);
      else {
        raiz->setDir(ins);
        ins->setPai(raiz);
      }
    }
    int balanceamento = fatorBalanceamento(raiz);
    if(balanceamento > 1) {
      if( fatorBalanceamento(raiz->getEsq()) < 0 )
        rotacaoEsquerda(raiz->getEsq());
      rotacaoDireita(raiz);
    }
    else if( balanceamento < -1 ) {
      if( fatorBalanceamento(raiz->getDir() ) > 0)
        rotacaoDireita(raiz->getDir());
      rotacaoEsquerda(raiz);
    }
  }


  void rotacaoDireita(No<T>* raiz){
   No<T>* novaRaiz = new No<T>();
   novaRaiz = raiz->getEsq();
   raiz->setEsq(novaRaiz->getDir());
   novaRaiz->setDir(raiz);

   if( raiz->getPai() == NULLPTR ) {
     raizArvore = novaRaiz;
     novaRaiz->setPai(NULLPTR);
   }
   else {
     if( raiz->getPai()->getEsq() == raiz ) {
       raiz->getPai()->setEsq(novaRaiz);
     }
     else {
       raiz->getPai()->setDir(novaRaiz);
     }
     novaRaiz->setPai(raiz->getPai());
   }

   raiz->setPai(novaRaiz);
  }

  void rotacaoEsquerda(No<T>* raiz){
    No<T>* novaRaiz = raiz->getDir();
    raiz->setDir(novaRaiz->getEsq());
    novaRaiz->setEsq(raiz);

    if( raiz->getPai() == NULLPTR ) {
      raizArvore = novaRaiz;
      novaRaiz->setPai(NULLPTR);
    }
    else {
      if( raiz->getPai()->getEsq() == raiz ) {
        raiz->getPai()->setEsq(novaRaiz);
      }
      else {
        raiz->getPai()->setDir(novaRaiz);
      }
      novaRaiz->setPai(raiz->getPai());
    }
    raiz->setPai(novaRaiz);
  }
};



int main(){
  AVLtree<int> *avl = new AVLtree<int>();
  avl->insere(14);
  avl->insere(15);
  avl->insere(4);
  avl->insere(9);
  avl->insere(7);
  avl->insere(18);
  avl->insere(3);
  avl->insere(5);
  avl->insere(16);
  avl->insere(20);
  avl->insere(17);

}
