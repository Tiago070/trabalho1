#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;

int main(){
    FILE *dadosUsuario;

    struct usuario{
        int codigo;
        char nome[100], login[20], senha[10];
    } usu;

    char opc;
    int busca;

    cout << "Deseja cadastrar usuário? [S/N] ";
    cin >> opc;

    while (opc == 'S'){
        dadosUsuario = fopen("dados_usuarios.dat", "ab+");
        if (dadosUsuario == NULL){
            cout << "Erro ao abrir o arquivo";
            cin.ignore();
            cin.get();
        } else {
            cout << "Por favor, informe os dados do usuário: " << endl;
            cout << "Código";
            cin >> usu.codigo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nome: ";
            cin >> usu.nome;
        }
    }
}