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
