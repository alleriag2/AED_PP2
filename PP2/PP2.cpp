#include <iostream>

using namespace std;

int contarCaracteres(string linha){
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

unsigned long int potencia(unsigned long int numero, int expoente){
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

template <typename N>
class No{
private:
  No<N>* esq;
  No<N>* dir;
  N chave;
  int count;
  int balance;

public:
  No(){
    esq = NULL;
    dir = NULL;
    balance = 0;
    count = 0;
  }

  void setEsq(No<N>* esq){
    this->esq = esq;
  }

  No<N>*& getEsq(){
    return esq;
  }

  void setDir(No<N>* dir){
    this->dir = dir;
  }

  No<N>*& getDir(){
    return dir;
  }

  void setChave(N novaChave){
    chave = novaChave;
  }

  N getChave(){
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
  No<T>* raiz;

public:
  AVLtree(){
    raiz = NULL;
  }

  void percorreEmOrdem(){
    percorreEmOrdem(raiz);
  }

  void insereAVL(string x){
    insereAVL(x, raiz, false);
  }

  void insereAVLHash(T x){
    insereAVLHash(x, raiz, false);
  }

  void insereAVLHash(T tabH, No<T>* &p, bool h){
    No<T>* p1;
    No<T>* p2;
    string x = tabH->getNome();
    if(p == NULL){
      p = new No<T>();
      h = true;
      p->setChave(tabH);
      p->setEsq(NULL);
      p->setDir(NULL);
      p->setBalance(0);
      p->setCount(1);
    }
    else if(p->getChave()->getNome() > x){
      insereAVLHash(tabH, p->getEsq(), h);
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
    else if(p->getChave()->getNome() < x){
      insereAVLHash(tabH, p->getDir(), h);
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

  void insereAVL(string x, No<T>* &p, bool h){
    No<T>* p1;
    No<T>* p2;
    if(p == NULL){
      p = new No<T>();
      h = true;
      p->setChave(x);
      p->setEsq(NULL);
      p->setDir(NULL);
      p->setBalance(0);
      p->setCount(1);
    }
    else if(p->getChave() > x){
      insereAVL(x, p->getEsq(), h);
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

  No<T>* busca(string buscado){
    return busca(buscado, raiz);
  }

  No<T>* busca(string buscado, No<T> *& aux){
    if(aux != NULL){
      if(aux->getChave() == buscado){
        return aux;
      }
      else if(aux->getEsq() != NULL){
        if(aux->getChave() == buscado){
          return aux;
        }
        else busca(buscado, aux->getEsq());
      }
      else if(aux->getDir() != NULL){
        if(aux->getChave() == buscado){
          return aux;
        }
        else busca(buscado, aux->getDir());
      }
    }
    return aux;
  }

  No<T>* buscaHash(string buscado){
    return buscaHash(buscado, raiz);
  }

  No<T>* buscaHash(string buscado, No<T> *&aux){
    if(aux != NULL){
      if(aux->getChave().getNome() == buscado){
        return aux;
      }
      else if(aux->getEsq() != NULL){
        if(aux->getChave().getNome() == buscado){
          return aux;
        }
        else buscaHash(buscado, aux->getEsq());
      }
      else if(aux->getDir() != NULL){
        if(aux->getChave().getNome() == buscado){
          return aux;
        }
        else buscaHash(buscado, aux->getDir());
      }
    }
    return aux;
  }

  void percorreEmOrdem(No<T> *& p){
    if(p != NULL){
      percorreEmOrdem(p->getEsq());
      cout << p->getChave() << " " << endl;
      percorreEmOrdem(p->getDir());
    }
  }

  void ordemCentral(No<T>* p){
    if(raiz){
      cout<<ordemCentral(p->getEsq())<<endl;
      cout<<p<<endl;
      cout<<ordemCentral(p->getDir())<<endl;
    }
  }

  void ordemCentral(){
    ordemCentral(raiz);
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
  AVLtree<H>* tabHash;

public:
  TabelaHash(){
    tamHash = 0;
    nome = "";
  }

  TabelaHash(int tamHash, string nome){
    this->tamHash = tamHash;
    this->nome = nome;
    tabHash = new AVLtree<H>[tamHash];
  }

  int funcaoHash(string palavra){
    long int hashNumber = 0;
    for (int i=0; i<contarCaracteres(palavra); i++){
      hashNumber = hashNumber + (((palavra[i]))*(potencia(10,9)+7));
    }
    return hashNumber % tamHash;
  }

  void addHash(string elemento){
    tabHash[funcaoHash(elemento)].insereAVL(elemento);
  }

  bool checkTabHashVazia(){
    return tabHash->checkVazia();
  }

  int getTamHash(){
    return tamHash;
  }

  void setTamHash(int tamHash){
    this->tamHash = tamHash;
  }

  void setNome(string nome){
      this->nome = nome;
  }

  string getNome(){
    return nome;
  }

  AVLtree<H> getTree(int pos){
    return tabHash[pos];
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

  void funcaoUnion(TabelaHash<string> p, TabelaHash<string> q){
  }

  void funcaoInter(){

  }

  void funcaoMinus(){

  }

  void funcaoPrint(string nomeTabHash, string key){
    No<TabelaHash<string>>* aux = new No<TabelaHash<string>>();
    No<string>* auxiliar = new No<string>();
    AVLtree<string> arvoreAux;
    int numHash;
    aux = kinojo->buscaHash(nomeTabHash);
    if(aux != NULL){
      numHash = aux->getChave().funcaoHash(key);
      arvoreAux = aux->getChave().getTree(numHash);
      if(arvoreAux.checkVazia()){
        auxiliar = arvoreAux.busca(key);
        if(auxiliar){
          arvoreAux.percorreEmOrdem();
        }
        else cout<<"Chave "<<key<<" nao encontrada em Tabela "<<nomeTabHash<<endl;
      }
      else cout<<"Tabela "<<nomeTabHash<<" vazia"<<endl;
    }
  }
};

int main(){
  string comando, nome, key, uni, intersec, minus, tabelaHash1, tabelaHash2, nomeTabelaHash, chave;
  char igual, ponto;
  int numDeChaves;
  Kinojo* kinojo = new Kinojo();
  TabelaHash<string>* th;

  do{

    cin>>comando;

    if(comando == "TH"){
      cin>>nome>>igual>>numDeChaves;
      th = new TabelaHash<string>(numDeChaves, nome);
      while(numDeChaves--){
        cin>>chave;
        th->addHash(chave);
      }
    }

    cin>>ponto;

    if(comando == "UNION"){
      cin>>uni>>igual>>tabelaHash1>>tabelaHash2>>ponto;
    }

    if(comando == "INTER"){
      cin>>intersec>>igual>>tabelaHash1>>tabelaHash2>>ponto;
    }

    if(comando == "MINUS"){
      cin>>minus>>igual>>tabelaHash1>>tabelaHash2>>ponto;
    }

    if(comando == "PRINT"){
      cout<<comando<<endl;
      cin>>nomeTabelaHash>>key>>chave>>ponto;
      cout<<"KEY    "<<key<<endl;
      cout<<"Nome da Tabela:   "<<nomeTabelaHash<<endl;
      cout<<"Chave: "<<chave<<endl;
      kinojo->funcaoPrint(nomeTabelaHash, chave);
    }

  }while(comando != "FIM");

  return 0;
}
