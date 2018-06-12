#include<iostream>

using namespace std;


int main(){
  string comando, nome, key, uni, intersec, minus, tabelaHash1, tabelaHash2, nomeTabelaHash, chave;
  char igual, ponto;
  int numDeChaves;
  //Kinojo* kinojo = new Kinojo();
  //TabelaHash<string>* th;

  do{//inicio da Leitura

    cin>>comando;

    if(comando == "TH"){ //comanda que cria uma Tabela Hash
      cin>>nome>>igual>>numDeChaves;
      //th = new TabelaHash<string>(numDeChaves, nome);
      while(numDeChaves--){
        cin>>chave; //introduz as chaves na Tabela Hash
        //th->addHash(chave);
      }
      //kinojo->getTreeKinojo()->insereAVLHash(th);
      cin>>ponto;
    }



    if(comando == "UNION"){ //comando de Uniao de Tabelas Hash
      cin>>uni>>igual>>tabelaHash1>>tabelaHash2>>ponto;

    }

    if(comando == "INTER"){//comando de Intersecao das s Hash
      cin>>intersec>>igual>>tabelaHash1>>tabelaHash2>>ponto;
    }

    if(comando == "MINUS"){//comando de Subtracao de Tabelas Hash
      cin>>minus>>igual>>tabelaHash1>>tabelaHash2>>ponto;
    }

    if(comando == "PRINT"){
      //cout<<comando<<endl;
      cin>>nomeTabelaHash>>key>>chave>>ponto;
      cout<<"KEY    "<<key<<endl;
      cout<<nomeTabelaHash<<endl;
      cout<<"Chave: "<<chave<<endl;
      //kinojo->funcaoPrint("kages", chave);
    }

  }while(comando != "FIM");//fim da Leitura

  return 0;
}
