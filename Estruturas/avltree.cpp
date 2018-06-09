#include <iostream>

#define NULLPTR 0;

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
}

template <typename N>
class No{
private:

  No<N>* esq;
  No<N>* dir;
  No<N>* pai;

  Item item;

  int altura;
  int balance;

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

  void setAltura(int altura){
    this->altura = altura;
  }

  int getAltura(){
    return altura;
  }

  void setBalance(int balance){
    this->balance = balance;
  }

  int getBalance(){
    return balance;
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

  void insercaoAVL(T item, int pos, No<T>* aux){

    int cresceu; //VARIAVEL PARA SABER SE PRECISA BALANCEAR
    //USA NO LUGAR DO BOOLEANO

    //SE A ARVORE VAZIA
    if (aux == NULL){
      aux->getItem()->setChave(pos);
      aux->setItem(item);
      aux->setDir(NULL);
      aux->setEsq(NULL);
      aux->setBalance(0);


      cresceu = 1;
    }
    else if(aux->getChave() > pos){
      //TENTA INSERIR NA ARVORE ESQUERDA E VE SE CRESCEU
      cresceu = insereAVL(item, pos, &aux->getEsq());
      if(cresceu){
        switch(aux->getBalance()){

        //CASO A ARV DIR SEJA MAIOR, N HA CRESCIMENTO
        case 1:
          aux->setBalance(0);
          cresceu = 0;
          break;
        //CASO A ARV DIREITA TAMANHO IGUAL HOUVE CRESCIMENTO
        case 0:
          aux->setBalance(-1);
          cresceu = 1;
          break;
        //CASO A ESQ SEJA MAIOR REBALANCEAR
        case -1:
          if(aux->getEsq()->getBalance() == -1){
            rotacaoDireita(aux);
            aux->setBalance(0);
            aux->getDir()->setBalance(0);
          }
          else{
            //ROTACAO DUPLA
            rotacaoEsquerda(&aux->getEsq());

            rotacaoDireita(aux);
            if(aux->getBalance() == -1){
              aux->getEsq()->setBalance(0);
              aux->getDir()->setBalance(1);
            }
            else{
              aux->getDir()->setBalance(0);
              aux->getEsq()->setBalance(-aux->getBalance());
            }
            aux->setBalance(0);
          }
          cresceu = 0;
        }
      }
    }
    else if(aux->getChave() < x){
      cresceu = insereAVL(item, pos, &aux->getDir());
      if (cresceu){
        switch(aux->getBalance()){
        case -1:
          aux->setBalance(0);
          cresceu = 0;
          break;
        case 0:
          aux->setBalance(1);
          cresceu = 1;
          break;
        case 1:
          if(aux->getDir()->getBalance() == 1){
            rotacaoEsquerda(aux);

            aux->setBalance(0);
            aux->getEsq()->setBalance(0);
          }
          else{
            rotacaoDireita(&aux->getDir());
            rotacaoEsquerda(aux);
            if(aux->getBalance() == -1){
              aux->getEsq()->setBalance(0);
              aux->getDir()->setBalance(1);
            }
            else{
              aux->getDir()->setBalance(0);
              aux->getEsq()->setBalance(- aux->getBalance());
            }
            aux->setBalance(0);
          }
          cresceu = 0;
        }
      }
    }
    else cresceu = 0;

    return cresceu;
  }

  No<T>* removeNo(No<T>* p){
    if(p->getEsq() != NULL){
      removeNo(p->getEsq());
    }
    else if(p->getDir() != NULL){
      removeNo(p->getDir());
    }
    else{
      No<T>* aux = new No<T>();
      aux = p;
      delete p;
      return aux;
    }
  }


  void rotacaoDireita(No<T>* p){
    No<T>* aux;
    aux = p->getEsq();
    p->setEsq(aux->getEsq());
    aux->setDir(p);
    p = aux;
  }

  void rotacaoEsquerda(No<T>* p){
    No<T>* aux;
    aux = p->getDir();
    p->setDir(aux->getEsq());
    aux->setEsq(p);
    p = aux;
  }

  bool checkVazia(){
    return if (raiz == NULL);
  }

};

template <typename H>
class TabelaHash{
private:
  AVLtree<H>* tabHash[];
  int tamHash;
  string nome;
public:
  Tabela_hash(int tamHash, string nome){
    for (int i = 1; i<=Tam_hash; i++){
      AVLtree<H>* aux = new AVLtree<H>();
      tabHash[i] = aux;
    }
    this->tamHash = tamHash;
    this->nome = nome;
  }

  int funcaoHash(string palavra){
    long int hashNumber = 0;
    for (int i=0; i<contarCaracteres(palavra); i++){
      hashNumber = hash_number + (((palavra[i]))*(potencia(10,9)+7));
    }
    return hash_number % tamHash;
  }

  void addHash(H* elemento){
    tabHash[funcaoHash(elemento->getNome())]->insereAVL(palavra);
  }

  void addHash(string elemnto){
    tabHash[funcaoHash(elemento)]->insereAVL(palavra);
  }

  bool checkTabHashVazia(){
    return checkVazia();
  }

  int getTamHash(){
    return tamHash;
  }


};

class Kinojo{
private:
  TabelaHash* kinojo = new TabelaHash();
public:
  Kinojo(){
  }

  void funcaoUnion(tabHash p, tabHash q){
    if (p->checkTabHashVazia()){
      tabHash* aux = new tabHash(p->getTamHash(), R);
      while(!q->checkTabHashVazia()){
        aux->insereAVL(p->removeNo());
      }
      delete aux;
    }
    else if (q->checkTabHashVazia()){
      tabHash* aux = new tabHash(q->getTamHash(), R);
      while(!q->checkTabHashVazia()){
        aux->insereAVL(q->removeNo());
      }
      delete aux;
    }
    
  }
  void funcaoInter(){

  }

  void funcaoMinus(){

  }

  void funcaoPrint(){

  }
};


int main(){}
