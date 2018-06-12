#include <iostream>
#define NULLPTR 0

using namespace std;

int contarCaracteres(string linha)
{
  int contador = 0;
  for(int i = 0; i < 80 ; ++i){
    if (linha[i] != '\0' && linha[i] != ' '){
        contador++;
    }
    else{
      (linha[i]=='\0');
      break;
    }
  }
  return contador;
}

bool ehPrimo(int numero){
  int cont=0;
  for(int i=2; i<=numero/2;i++){
    if(numero%i==0){
      cont++;
    }
  }
  if(cont==0){
    return true;
  }
  return false;
}

int tamTabelaHash(int numChave){
  for(int i=(numChave/4);i>0;i--){
    if(ehPrimo(i)){
      return i;
    }
  }
  return 0;
}


unsigned long int potencia(unsigned long int numero, int expoente)
{
  int aux = numero;
  if (expoente == 1){
    return numero;
  }
  else if(expoente == 0){
    return numero = 1;
  }
  else{
    for(int i = 1; i <expoente; i++){
      numero = numero * aux;
    }
    return numero;
  }
}

template <typename I>
class Item{
private:

  string chave;

  I conteudo;

public:

  Item(I conteudo, string chave){
    this->conteudo = conteudo;
    this->chave = chave;
  }

  Item(){}

  void setItem(I conteudo, string chave){
    this->conteudo = conteudo;
    this->chave = chave;
  }

  string getChave(){
    return chave;
  }

  I getConteudo(){
    return conteudo;
  }

  void setChave(string chave){
    this->chave = chave;
  }

  void setConteudo(I conteudo){
    this->conteudo = conteudo;
  }

};

template <typename N>
class No{
private:

  No<N>* esq;
  No<N>* dir;
  No<N>* prox;
  No<N>* ant;

  Item<N> item;

  int count;
  int balance;

public:

  No(){
    esq = NULL;
    dir = NULL;
    prox = NULL;
    balance = 0;
    count = 0;

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

  Item<N> getItemNo(){
    return item;
  }

  void setChaveNo(N novaChave){
    item.setChave(novaChave);
  }

  void setConteudoItem(N conteudo){
    item.setConteudo(conteudo);
  }

  N getChaveItem(){
    return item.getChave();
  }

  void setBalance(int balance){
    balance = balance;
  }

  int getBalance(){
    return balance;
  }

  void setCount(int count){
    count = count;
  }

  int getCount(){
    return count;
  }

  void setProx(No<N>* prox){
    this->prox = prox;
  }

  No<N>* getProx(){
    return prox;
  }

  void setAnt(No<N>* ant){
    this->ant = ant;
  }

  No<N>* getAnt(){
    return ant;
  }

  void setItemNo(Item<N> item){
    this->item = item;
  }

  void criaItem(N item){
    item.setChave(item);
    item.setConteudo(item);
  }

};

template <typename L>
class Lista{
private:
  No<L>* prim;
  No<L>* ult;

  int tamanho;

public:
  Lista(){
    this->prim = new No<L>();
    this->prim->setProx(NULLPTR);
    this->ult = this->prim;
    this->tamanho = 0;
  }

  void setPrim(No<L>* prim){
    this->prim = prim;
  }

  No<L>* getPrim(){
    return this->prim;
  }

  void setUlt(No<L>* ult){
    this->ult = ult;
  }

  No<L>* getUlt(){
    return this->ult;
  }

  int getTamanho(){
    return this->tamanho;
  }

  void insere(L item){
    No<L>* n = new No<L>();
    this->ult->setProx(n);
    n->setAnt(ult);
    this->ult = n;
    this->ult->setProx(NULL);
    this->ult->criaItem(item);
    this->tamanho+=1;
  }

  bool vazia(){
    return prim == ult;
  }

  No<L>* busca(L* buscado){
    No<L>* p = new No<L>();
    p = prim->getProx();
    while( p != NULL && p->getChaveItem() != buscado){
      p = p->getProx();
    }
    return p;
  }

  No<L> busca(L buscado){
    No<L>* p = new No<L>();
    p = prim->getProx();
    while( p != NULL && p->getChaveItem() != buscado){
      p = p->getProx();
    }
    return p;
  }
};

template <typename T>
class AVLtree{
private:

  No<T>* raiz;


public:

  AVLtree(){
    raiz = NULL;
  }

  void insereAVL(Item<T> item){
    insereAVL(item, raiz, false);
  }

  void insereAVL(Item<T> item, No<T>* p, bool h){
    No<T>* p1;
    No<T>* p2;
    string x = item.getChave();
    if(p == NULL){
      p = new No<T>();
      h = true;
      p->setChaveNo(x);
      p->setItemNo(item);
      p->setEsq(NULL);
      p->setDir(NULL);
      p->setBalance(0);
      p->setCount(1);
    }
    else if(p->getChaveItem() > x){
      insereAVL(item, p->getEsq(), h);
      if(h){
        if(p->getBalance() == 1){
          p->setBalance(0);
          h = false;
        }
        else if(p->getBalance() == 0){
          p->setBalance(-1);
        }
        else{
          p1 = p->getEsq();
          if(p1->getBalance() == -1){
            p->setEsq(p1->getDir());
            p1->setDir(p);
            p->setBalance(0);
            p = p1;
          }
          else{
            p2 = p1->getDir();
            p1->setDir(p2->getEsq());
            p2->setDir(p1);
            p->setEsq(p2->getDir());
            p2->setDir(p);
            if(p2->getBalance() == -1){
              p->setBalance(1);
            }
            else{
              p->setBalance(0);
            }
            if(p2->getBalance() == 1){
              p1->setBalance(-1);
            }
            else{
              p1->setBalance(0);
            }
            p = p2;
          }
          p->setBalance(0);
          h = false;
        }
      }
    }
    else if(p->getChaveItem() < x){
      insereAVL(item, p->getDir(), h);
      if(h){
        if(p->getBalance() == -1){
          p->setBalance(0);
          h=false;
        }
        else if(p->getBalance() == 0){
          p->setBalance(1);
        }
        else{
          p1 = p->getDir();
          if(p1->getBalance() == 1){
            p->setDir(p->getEsq());
            p1->setEsq(p);
            p->setBalance(0);
            p = p1;
          }
          else{
            p2 = p1->getEsq();
            p1->setEsq(p2->getDir());
            p2->setDir(p1);
            p->setDir(p2->getEsq());
            p2->setEsq(p);
            if(p2->getBalance() == 1){
              p->setBalance(-1);
            }
            else{
              p->setBalance(0);
            }
            if(p2->getBalance() == -1){
              p1->setBalance(1);
            }
            else{
              p1->setBalance(0);
            }
          }
          p->setBalance(0);
          h = false;
        }
      }
    else{
      p->setCount(p->getCount() + 1);
    }
    }
  }

  No<T>* busca(string buscado){
    return busca(buscado, raiz);
  }

  No<T>* busca(string buscado, No<T> *& aux){
    if(aux == NULL || aux->getChaveItem() == buscado){
      return aux;
    }
    if(aux->getChaveItem() < buscado){
       return busca(aux->getDir(), buscado);
    }
    return busca(aux->getEsq(), buscado);
  }

  void retornaEmOrdem(No<T> *p, Lista<T>* lista){
    if(p != NULL){
      retornaEmOrdem(p->getEsq(), lista);
      lista->insere(p->getItemNo().getChave());
      retornaEmOrdem(p->getDir(), lista);
    }
  }

  void retornaEmOrdem(Lista<T>* lista){
    retornaEmOrdem(raiz, lista);
  }


  void percorreEmOrdem(){
    percorreEmOrdem(raiz);
  }

  void percorreEmOrdem(No<T> *& p){
    if(p != NULL){
      percorreEmOrdem(p->getEsq());
      cout << p->getChave() << " " << endl;
      percorreEmOrdem(p->getDir());
    }
  }

  bool checkVazia(){
    return raiz == NULL;
  }

  void setRaiz(No<T>* raiz){
    this->raiz = raiz;
  }

  No<T>* getRaiz(){
    return raiz;
  }

};

template <typename H>
class TabelaHash{
private:
  int tamHash;
  string nome;

  AVLtree<H>* tabelaHash;

public:
  TabelaHash(){
    tamHash = 0;
    nome = "";
  }

  TabelaHash(int tamHash, string nome){
    this->tamHash = tamHash;
    this->nome = nome;
    tabelaHash = new AVLtree<H>[tamHash];

  }

  int funcaoHash(string palavra){
    long int hashNumber = 0;
    for (int i=0; i<contarCaracteres(palavra); i++){
      hashNumber = hashNumber + (((palavra[i]))*(potencia(10,9)+7));
    }
    return hashNumber % tamHash;
  }

  void insereHash(Item<H> item){
    tabelaHash[funcaoHash(item.getChave())].insereAVL(item);
  }

  bool checkTabelaHashVazia(){
    for(int i = 0; i <tamHash; i++){
      if(!tabelaHash[i]->checkVazia()){
        return false;
      }
    }
    return true;
  }

  int getTamHash(){
    return tamHash;
  }

  void setTamHash(int tamHash){
    this->tamHash = tamHash;
  }

  AVLtree<H> getTree(int pos){
    return tabelaHash[pos];
  }

  void retornaItemAVL(Lista<H>* lista, int pos){
    tabelaHash[pos].retornaEmOrdem(lista);
  }

};

class Kinojo{
private:
  AVLtree<TabelaHash<string>>* kinojo;

public:
  Kinojo(){
    kinojo = new AVLtree<TabelaHash<string>>();
  }

  AVLtree<TabelaHash<string>>* getTreeKinojo(){
    return kinojo;
  }

  TabelaHash<string> funcaoUnion(TabelaHash<string> p, TabelaHash<string> q, string nome){
    Lista<string>* lista1 = new Lista<string>();
    Lista<string>* lista2 = new Lista<string>();
    int tam = 0;
    for(int i=0; i<p.getTamHash();i++){
      p.retornaItemAVL(lista1, i);
    }
    for(int i=0; i<q.getTamHash();i++){
      q.retornaItemAVL(lista2, i);
    }
    tam = lista1->getTamanho() + lista2->getTamanho();
    tam = tamTabelaHash(tam);
    TabelaHash<string> tabelaHash(tam, nome);
    int cont = 0;
    for(No<string>* nav = lista1->getPrim()->getProx(); nav!=NULLPTR; nav = nav->getProx()){
      tabelaHash.insereHash(nav->getItemNo());
    }
    for(No<string>* nav2 = lista2->getPrim()->getProx(); nav2!=NULLPTR; nav2 = nav2->getProx()){
      for(No<string>* nav = lista1->getPrim()->getProx(); nav!=NULLPTR; nav = nav->getProx()){
        if(nav->getChaveItem() == nav2->getChaveItem()){
          cont++;
        }
      }
      if(cont==0){
        tabelaHash.insereHash(nav2->getItemNo());
      }
      cont=0;
    }
    return tabelaHash;
  }

  TabelaHash<string> funcaoInter(TabelaHash<string> p, TabelaHash<string> q, string nome){

    Lista<string>* lista1 = new Lista<string>();
    Lista<string>* lista2 = new Lista<string>();
    int tam = 0;
    for(int i=0; i<p.getTamHash();i++){
      p.retornaItemAVL(lista1, i);
    }
    for(int i=0; i<q.getTamHash();i++){
      q.retornaItemAVL(lista2, i);
    }
    if(lista1->getTamanho() > lista2->getTamanho()){
      tam = lista2->getTamanho();
    }
    else{
      tam = lista1->getTamanho();
    }
    TabelaHash<string> tabelaHash(tam, nome);
    int cont = 0;
    for(No<string>* nav2 = lista2->getPrim()->getProx(); nav2!=NULLPTR; nav2 = nav2->getProx()){
      for(No<string>* nav = lista1->getPrim()->getProx(); nav!=NULLPTR; nav = nav->getProx()){
        if(nav->getChaveItem() != nav2->getChaveItem()){
          cont++;
        }
      }
      if(cont>=1){
        tabelaHash.insereHash(nav2->getItemNo());
      }
      cont=0;
    }
    return tabelaHash;
  }

  TabelaHash<string> funcaoMinus(TabelaHash<string> p, TabelaHash<string> q, string nome){

    Lista<string>* lista1 = new Lista<string>();
    Lista<string>* lista2 = new Lista<string>();
    int tam1 = 0,tam2 = 0, tam = 0;

    for(int i=0; i<p.getTamHash();i++){
      p.retornaItemAVL(lista1, i);
    }
    tam1 = lista1->getTamanho();
    tam2 = lista2->getTamanho();
    if(tam1-tam2<2){
      cout<<"Operação inválida"<<endl;
    }
    else{
      tam = tamTabelaHash(tam1-tam2);
    }
    TabelaHash<string> tabelaHash(tam, nome);
    int cont = 0;
    for(No<string>* nav = lista1->getPrim()->getProx(); nav!=NULLPTR; nav = nav->getProx()){
      for(No<string>* nav2 = lista2->getPrim()->getProx(); nav2!=NULLPTR; nav2 = nav2->getProx()){
        if(nav2->getChaveItem() == nav->getChaveItem()){
          cont++;
        }
      }
      if(cont==0){
        tabelaHash.insereHash(nav->getItemNo());
      }
      cont=0;
    }
    return tabelaHash;
  }


};

int main(){
  return 0;
}
