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

int tamTabelaHash(int numChave){
  for(int i=(numChave/4);i>0;i--){
    if(ehPrimo(i)){
      return i;
    }
  }
  return 0;
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
  Tabela_hash(int tamHash, string nome){
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
  Kinojo(){}

  TabelaHash* funcaoUnion(tabHash p, tabHash q){

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
      tabHash* aux = new tabHash(q->getTamHash(), R);
      while(!q->checkTabHashVazia()){
        aux->insereAVL(q->removeNo());
      }
      delete aux;
    }*/
    //criar nova tabela
    return r;
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
    return r;
  }

  TabelaHash* funcaoMinus(tabHash p, tabHash q){
    //percorrer a tabeça Q para cada item da tabela P
    //nova tabela devera conter todos os itens que estao em P e nao estao em Q
    //tamanho da nova tabela devera ser maior primo menor ou igual que |P|-|Q|
    //caso |p|-|q|<2 : excecao
    //caso P e Q nao possuam chaves em comum : return P
    //caso P MINUS P : return vazio
    //caso Vazio MINUS Q : return Vazio
    //caso P MINUS Vazio : return P

    return r;
  }

  void funcaoPrint(tabHash t, int k){
    //imprimir todos os itens que estao na avl na posicao tabHash[k]
    //percorre a avl
    //ordem crescente
    //se estiver vazia: excecao
    //se a chave nao existir: excecao
  }

};

int main(){
  do{//inicio da Leitura

    cin>>comando;

    if(comando == "TH"){ //comanda que cria uma Tabela Hash
      cin>>nome>>igual>>numDeChaves;
      while(numDeChaves--){
        cin>>chave; //introduz as chaves na Tabela Hash
      }
    }

    cin>>ponto;

    if(comando == "UNION"){ //comando de Uniao de Tabelas Hash
      cin>>uni>>igual>>tabelaHash1>>tabelaHash2>>ponto;
    }

    if(comando == "INTER"){//comando de Intersecao das Tabelas Hash
      cin>>intersec>>igual>>tabelaHash1>>tabelaHash2>>ponto;
    }

    if(comando == "MINUS"){//comando de Subtracao de Tabelas Hash
      cin>>minus>>igual>>tabelaHash1>>tabelaHash2>>ponto;
    }

    if(comando == "PRINT"){//comando que imprime as chaves que colidiram na Tabela Hash
      cout<<chavesColididas<<endl; //Tambem é a saida do codigo
    }

  }while(comando != "FIM")//fim da Leitura

  return 0;
}
