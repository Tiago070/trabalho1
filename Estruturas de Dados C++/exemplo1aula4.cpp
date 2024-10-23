#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    FILE *arquivoDados;

    arquivoDados = fopen("dados.dat", "wb");
    if (arquivoDados == NULL){
        cout << "Erro ao abrir o arquivo" << endl;
    } else {
        cout << "Arquivo aberto com sucesso" << endl;
        fclose(arquivoDados);
    }
}