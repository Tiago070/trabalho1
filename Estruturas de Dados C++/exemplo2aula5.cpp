#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

int main(){
    FILE *dadosUsuario;
    struct usuario{
        char nome[100], login[20], senha[10];
    } usu;

    char opcao;

    dadosUsuario = fopen("usuarios.dat", "ab+");

    if (dadosUsuario == NULL){
        cout << "Erro ao abrir o arquivo!" << endl;
    } else {
        cout << "Deseja cadastrar um usuário? [S/N]: ";
        cin >> opcao;
        while (opcao == 'S'){
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
            cout << "Deseja cadastrar outro usuário? [S/N]: ";
            cin >> opcao;
        }
    }
    fclose(dadosUsuario);
    cin.get();

    cout << endl << endl << "USUÁRIOS CADASTRADOS" << endl << endl;

    dadosUsuario = fopen("usuarios.dat", "rb");
    fread(&usu, sizeof(struct usuario), 1, dadosUsuario);
    while (!feof(dadosUsuario)){
        cout << "Nome: " << usu.nome << endl;
        cout << "Login: " << usu.login << endl;
        cout << "Senha: " << usu.senha << endl;
        cout << "---------------------------------------------"<< endl;
        fread(&usu, sizeof(struct usuario), 1, dadosUsuario);
    }
    fclose(dadosUsuario);
    cin.get();
}
