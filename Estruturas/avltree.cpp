#include <iostream>



using namespace std;

int contarCaracteres(string linha)
{
  int contador = 0;
  for(int i = 0; i < 15 ; ++i){
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


template <typename T>
class No{
private:

  No<T>* esq;
  No<T>* dir;

  T chave;

  int count;
  int balance;

public:
  // No(No<T>* pai){
  //   this-> esq = NULL;
  //   this-> dir = NULL;
  // }

  No(){
    this-> esq = NULL;
    this-> dir = NULL;
    chave = 0;
    balance = 0;
    count = 0;
  }

  void setEsq(No<T>* esq){
    this->esq = esq;
  }

  No<T>*& getEsq(){
    return esq;
  }

  void setDir(No<T>* dir){
    this->dir = dir;
  }

  No<T>*& getDir(){
    return dir;
  }

  void setChave(T novaChave){
    chave = novaChave;
  }

  T getChave(){
    return chave;
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


};

template <typename T>
class AVLtree{
private:

  No<T>* raiz = new No<T>();

public:

  AVLtree(){
  }

  void insereAVLmain(T x){
    cout<<"DDADD"<<endl;
    insereAVL(x, raiz, false);
  }

  void insereAVL(T x, No<T>* &p, bool h){
    No<T>* p1 = new No<T>();
    No<T>* p2 = new No<T>();
    if(p == NULL){
      cout<<"1"<<endl;
      p = new No<T>();
      h = true;
      p->setEsq(NULL);
      p->setChave(x);
      p->setDir(NULL);
      p->setBalance(0);
      p->setCount(1);
    }
    else if(p->getChave() > x){
      cout<<"AEDSD"<<endl;
      insereAVL(x, p->getEsq(), h);
      if(h){
        cout<<"d2"<<endl;
        if(p->getBalance() == 1){
          cout<<"d3"<<endl;
          p->setBalance(0);
          h = false;
        }
        else if(p->getBalance() == 0){
          cout<<"d4"<<endl;
          p->setBalance(-1);
        }
        else{
          p1 = p->getEsq();
          if(p1->getBalance() == -1){
            cout<<"d5"<<endl;
            p->setEsq(p1->getDir());
            p1->setDir(p);
            p->setBalance(0);
            p = p1;
          }
          else{
            p2 = p1->getDir();
            cout<<"d6"<<endl;
            p1->setDir(p2->getEsq());
            p2->setDir(p1);
            p->setEsq(p2->getDir());
            p2->setDir(p);
            cout<<"d7"<<endl;
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
    else if(p->getChave() < x){
      insereAVL(x, p->getDir(), h);
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

  void print(No<T>* p){
    while(p!= NULL){
      if(p->getEsq() != NULL){
        removeNo(p->getEsq());
      }
      else if(p->getDir() != NULL){
        removeNo(p->getDir());
      }
      else{
        cout<<"A chave eh: "<<p->getChave()<<endl;
      }
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
  AVLtree<H>* tabHash[];
  int tamHash;
  string nome;
public:
  TabelaHash(int tamHash, string nome){
    for (int i = 1; i<=tamHash; i++){
      AVLtree<H>* aux = new AVLtree<H>();
      tabHash[i] = aux;
    }
    this->tamHash = tamHash;
    this->nome = nome;
  }

  int funcaoHash(string palavra){
    long int hashNumber = 0;
    for (int i=0; i<contarCaracteres(palavra); i++){
      hashNumber = hashNumber + (((palavra[i]))*(potencia(10,9)+7));
    }
    return hashNumber % tamHash;
  }

  void addHash(H* elemento){
    tabHash[funcaoHash(elemento->getNome())]->insereAVL(elemento);
  }

  void addHash(string elemento){
    tabHash[funcaoHash(elemento)]->insereAVL(elemento);
  }

  bool checkTabHashVazia(){
    return tabHash->checkVazia();
  }

  int getTamHash(){
    return tamHash;
  }


};

template <typename K>
class Kinojo{
private:
  TabelaHash<TabelaHash<K>>* kinojo = new TabelaHash<TabelaHash<K>>();
public:
  Kinojo(){
  }

  void funcaoUnion(TabelaHash<K> p, TabelaHash<K> q){
    if (p->checkTabHashVazia()){
      TabelaHash<K>* aux = new TabelaHash<K>(p->getTamHash(), "R");
      while(!q->checkTabHashVazia()){
        aux->insereAVL(p->removeNo());
      }
      delete aux;
    }
    else if (q->checkTabHashVazia()){
      TabelaHash<K>* aux = new TabelaHash<K>(q->getTamHash(), "R");
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


int main(){

  AVLtree<int>* arv = new AVLtree<int>();

  arv->insereAVLmain(2);
  arv->print(arv->getRaiz());
  arv->insereAVLmain(3);
  arv->insereAVLmain(5);
  //arv->insereAVLmain(4);
  //arv->insereAVLmain(6);
  //arv->insereAVLmain(8);
  //arv->insereAVLmain(10);
  //arv->insereAVLmain(7);
  //arv->insereAVLmain(11);
  //arv->insereAVLmain(20);

  //arv->print(arv->getRaiz());

}
