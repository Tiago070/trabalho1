#include <iostream>

using namespace std;

int main() {
    struct banco{
        int agencia;
        int conta;
        float saldo;
    };

    struct cliente{
        string nome;
        struct banco ban;
    } cli[10];

    int i, age_dep, cont_dep;
    float valor_dep;

    for (i = 0; i < 10; i++) {
        cout << "INFORME OS DADOS DO CLIENTE " << i+1 << endl;
        cout << "Informe o nome: ";
        getline(cin, cli[i].nome);
        cout << "Informe a agencia: ";
        cin >> cli[i].ban.agencia;
        cout << "Informe a conta: ";
        cin >> cli[i].ban.conta;
        cout << "Informe o saldo: ";
        cin >> cli[i].ban.saldo;
        cout << endl;
        cin.get();
    }

    system("cls");

    for (i = 0; i < 10; i++) {
        cout << "DADOS DO CLIENTE " << i+1 << endl;
        cout << "Nome: " << cli[i].nome << endl;
        cout << "Agencia: " << cli[i].ban.agencia << endl;
        cout << "Conta: " << cli[i].ban.conta << endl;
        cout << "Saldo: " << cli[i].ban.saldo << endl << endl;
    }

    cout << "DADOS DO DEPOSITO" << endl;
    cout << "Informe a agencia: ";
    cin >> age_dep;
    cout << "Informe a conta: ";
    cin >> cont_dep;
    cout << "Informe o valor do deposito: ";
    cin >> valor_dep;

    for (i = 0; i < 10; i++) {
        if (cli[i].ban.agencia == age_dep && cli[i].ban.conta == cont_dep) {
            cli[i].ban.saldo += valor_dep;
            cout << "Deposito efetuado com sucesso!" << endl;
            cout << "Nome: " << cli[i].nome << endl;
            cout << "Novo saldo: " << cli[i].ban.saldo << endl;
        }
    }
}
