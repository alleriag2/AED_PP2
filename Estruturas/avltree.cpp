#include <iostream>
#define NULLPTR 0;


using namespace std;

int contarCaracteres(string linha){
  int contador=0;
  for(int i=0; i<80; ++i){
    if (linha[i]!='\0' && linha[i]!=' '){
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
  else return false;
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
};


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

  bool busca(string chave, No<T>* p){
    if(p->getChave() == NULL){
      return false;
    }
    else if(chave < p->getChave()){
      return busca(chave, p->getEsq());
    }
    else if(p->getChave() < chave){
      return busca(chave, p->getDir());
    }
    return true;
  }

  bool busca(string chave){
    if(busca(chave, raiz)){
      return true;
    }
    return false;
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
  Kinojo(){}

  TabelaHash<K>* funcaoUnion(TabelaHash<K> p, TabelaHash<K> q){

    //copiar primeira tabela hash para a nova percorrendo e copiando item a item
    //para cada item na nova tabela, percorrer a segunda tabela para ver
    //se ele ja existe. Se existir, não insere.
    //FAVOR NAO REMOVER OS ITENS DA TABELA HASH INICIAL
    //POIS A TABELA HASH SERÁ USADA NOVAMENTE EM OUTRAS OPERAÇÕES
    //retorna nova tabela hash com os termos nao repetidos de cada uma das duas



    /*if (p->checkTabHashVazia()){
      tabHash* aux = new tabHash(p->getTamHash(), R);
      while(!p->checkTabHashVazia()){
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
  TabelaHash* funcaoInter(tabHash p, tabHash q){
    //percorre a segunda tabela para cada item da primeira
    //se achar um item igual, adiciona na nova tabela
    //NAO REMOVER ITENS
    //retorna nova tabela com a interseçao


    /*if(p->checkTabHashVazia() || ){
      tabHash* aux = new tabHash(p)
      while(!p->checkTabHashVazia()){
        if(){
          aux->insereAVL(p->removeNo());
        }
      }
    }*/
    //return r;
  }

  TabelaHash<K>* funcaoMinus(TabelaHash<K> p, TabelaHash<K> q){
    //percorrer a tabeça Q para cada item da tabela P
    //nova tabela devera conter todos os itens que estao em P e nao estao em Q
    //tamanho da nova tabela devera ser maior primo menor ou igual que |P|-|Q|
    //caso |p|-|q|<2 : excecao
    //caso P e Q nao possuam chaves em comum : return P
    //caso P MINUS P : return vazio
    //caso Vazio MINUS Q : return Vazio
    //caso P MINUS Vazio : return P

    //return r;
  }

  void funcaoPrint(TabelaHash<K> t, int k){
    //imprimir todos os itens que estao na avl na posicao tabHash[k]
    //percorre a avl
    //ordem crescente
    //se estiver vazia: excecao
    //se a chave nao existir: excecao
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
