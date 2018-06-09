#include<iostream>

using namespace std;

/*
1. TH alfa = 6 asda3s1das qw0eq1 srt12qf tyutyuty 2f45gdf8gdfg rt4rut5565i .
2. TH beta = 7 vcbaqqq posd pavn6a qweqweqe tyutyuty uiouiuo cv12cv1bcvb.
3. TH gama = 5 poduvnahs8 oqpfhaixxzzi aiurqlm330 k31238jkkmasoo o992o3iiap .
4. UNION uni = alfa beta .
5. PRINT uni KEY asda3s1das .
6. INTER intersec = beta gama .
7. MINUS m = intersec uni .
8. PRINT m KEY pavn6a .
9. FIM
*/

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
