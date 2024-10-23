#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

int main(){
    FILE *dadosUsuario;
    struct usuario{
        char nome[100], login[20], senha[10];
    } usu;

    dadosUsuario = fopen("usuarios.dat", "wb");

    if (dadosUsuario == NULL){
        cout << "Erro ao abrir o arquivo!" << endl;
    } else {
        cout << "Por favor, informe os dados do usuário" << endl;
        cout << "Nome: ";
        cin.get(usu.nome, 99);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Login: ";
        cin >> usu.login;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Senha: ";
        cin >> usu.senha;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (fwrite(&usu, sizeof(struct usuario), 1, dadosUsuario) == 1){
            cout << "Registro gravado com sucesso!" << endl;
            cin.get();
        } else {
            cout << "Erro ao gravar o registro!" << endl;
            cin.get();
        }
    }
    
}