#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

int main() {
    FILE *dadosLivros;

    struct emprestimos{
        char dataEmprestimo[10], dataDevolucao[10], usuario[150];
    };
    
    struct livros{
        int codigo, paginas;
        char titulo[150], autor[255], editora[50];
        struct emprestimos emp;
        char area, status;
    } livro;

    int i, opcaoMenu, codLivro;
    char opc;

    do {
        cout << "---------SISTEMA DE GERENCIAMENTO DE BIBLIOTECA--------" << endl;
        cout << "1 - Cadastro" << endl;
        cout << "2 - Alteração" << endl;
        cout << "3 - Exclusão" << endl;
        cout << "4 - Empréstimo" << endl;
        cout << "5 - Devolução" << endl;
        cout << "6 - Consulta de Livro" << endl;
        cout << "7 - Livros disponíveis" << endl;
        cout << "8 - Listagem geral de livros" << endl;
        cout << "9 - Sair" << endl << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcaoMenu;
        cout << endl << endl << endl;

        switch (opcaoMenu){
        case 1:
            i = 0;
            cout << "CADASTRO DE LIVROS" << endl << endl;
            cout << "Deseja cadastrar um livro? [S/N]: ";
            cin >> opc;

            while (opc == 'S'){

                dadosLivros = fopen("dadosLivros.dat", "ab+");

                if (dadosLivros == NULL){
                    cout << "Erro ao abrir o arquivo" << endl;
                    cin.ignore();
                    cin.get();
                } else{
                    i++;
                    cout << "Informe os dados do " << i+1 << "º livro" << endl;
                    cout << "Código: ";
                    cin >> livro.codigo;
                    cout << "Área de conhecimento [E - Exatas, H - Humanas, B - Biológicas]: ";
                    cin >> livro.area;
                    cout << "Título: ";
                    cin.get(livro.titulo, 149);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Autor(es): ";
                    cin.get(livro.autor, 254);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Editora: ";
                    cin.get(livro.editora, 49);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Número de páginas: ";
                    cin >> livro.paginas;
                    livro.status = 'S';
                    fwrite(&livro, sizeof(struct livros), 1, dadosLivros);
                    fclose(dadosLivros);
                }
                cout << "Deseja cadastrar outro livro? [S/N]: ";
                cin >> opc;
            }
            break;
        case 2:
            cout << "ALTERAÇÃO DE LIVRO" << endl;
            cout << "Deseja alterar um livro? [S/N]: " << endl;
            cin >> opc;
            cout << "Informe o código do livro: " << endl;
            cin >> codLivro;

            dadosLivros = fopen("dadosLivros.dat", "ab+");
            fread(&livro, sizeof(struct livros), 1, dadosLivros);

            while (!feof(dadosLivros) && opc == 'S'){
                if (codLivro == livro.codigo){
                    if (dadosLivros == NULL){
                        cout << "Erro ao abrir o arquivo" << endl;
                        cin.ignore();
                        cin.get();
                    } else{
                        cout << "Informe os novos dados do livro: " << endl;
                        cout << "Código: ";
                        cin >> livro.codigo;
                        cout << "Área de conhecimento [E - Exatas, H - Humanas, B - Biológicas]: ";
                        cin >> livro.area;
                        cout << "Título: ";
                        cin.get(livro.titulo, 149);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Autor(es): ";
                        cin.get(livro.autor, 254);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Editora: ";
                        cin.get(livro.editora, 49);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Número de páginas: ";
                        cin >> livro.paginas;
                        livro.status = 'S';
                        fwrite(&livro, sizeof(struct livros), 1, dadosLivros);
                        fclose(dadosLivros);
                    } 
                }
                cout << "Deseja alterar outro livro? [S/N]: ";
                cin >> opc;
            }
            break;
        case 3:
            cout << "EXCLUSÃO DE LIVRO" << endl;
            cout << "Em contrução..." << endl;

            break;
        case 4:
            cout << "EMPRÉSTIMO DE LIVRO" << endl;
            cout << "Informe o código do livro: ";
            cin >> codLivro;

            dadosLivros = fopen("dadosLivros.dat", "ab+");

            if (dadosLivros == NULL){
                cout << "Erro ao abrir o arquivo" << endl;
                cin.ignore();
                cin.get();
            } else{
                if (codLivro == livro.codigo){
                    cout << "Informe a data do empréstimo: ";
                    cin.get(livro.emp.dataEmprestimo, 9);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Informe a data de devolução: ";
                    cin.get(livro.emp.dataDevolucao, 9);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Informe o nome do usuário: ";
                    cin.get(livro.emp.usuario, 149);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Livro emprestado com sucesso!" << endl;
                }
            }
            break;
        case 5:
            cout << "Devolver Livro" << endl;
            cout << "Informe o código do livro: ";
            cin >> codLivro;
            for (i=0; i<3; i++){
                if (codLivro == livro.codigo){
                    livro.emp.dataEmprestimo = "";
                    livro.emp.dataDevolucao = "";
                    livro.emp.usuario = "";
                    cout << "Livro devolvido com sucesso!" << endl;
                }
            }
            break;
        case 6:
            cout << "Consultar livro" << endl;
            cout << "Informe o código do livro: ";
            cin >> codLivro;
            for (i=0; i<3; i++){
                if (codLivro == livro.codigo){
                    cout << "Código: " << livro.codigo << endl;
                    cout << "Área de conhecimento: " << livro.area << endl;
                    cout << "Título: " << livro.titulo << endl;
                    cout << "Autor(es): " << livro.autor << endl;
                    cout << "Editora: " << livro.editora << endl;
                    cout << "Número de páginas: " << livro.paginas << endl;
                    if (livro.emp.dataEmprestimo != ""){
                        cout << "Data do empréstimo: " << livro.emp.dataEmprestimo << endl;
                        cout << "Data de devolução: " << livro.emp.dataDevolucao << endl;
                        cout << "Usuário: " << livro.emp.usuario << endl;
                    }
                    cin.ignore();
                    cin.get();
                }
            }
            break;
        case 7:
            cout << "Livros disponíveis" << endl;
            for (i=0; i<3; i++){
                if (livro.emp.dataEmprestimo == ""){
                    cout << "Código: " << livro.codigo << endl;
                    cout << "Área de conhecimento: " << livro.area << endl;
                    cout << "Título: " << livro.titulo << endl;
                    cout << "Autor(es): " << livro.autor << endl;
                    cout << "Editora: " << livro.editora << endl;
                    cout << "Número de páginas: " << livro.paginas << endl;
                    cout << endl;
                }
            }
            cin.ignore();
            cin.get();
            break;
        case 8:
            cout << "Listagem geral de livros" << endl;
            dadosLivros = fopen("dadosLivros.dat", "rb");
            fread(&livro, sizeof(struct livros), 1, dadosLivros);
            while (!feof(dadosLivros)){
                cout << "Código: " << livro.codigo << endl;
                cout << "Área de conhecimento: " << livro.area << endl;
                cout << "Título: " << livro.titulo << endl;
                cout << "Autor(es): " << livro.autor << endl;
                cout << "Editora: " << livro.editora << endl;
                cout << "Número de páginas: " << livro.paginas << endl;
                cout << "Status: " << livro.status << endl;
                cout << endl;
                fread(&livro, sizeof(struct livros), 1, dadosLivros);
            }
            fclose(dadosLivros);
            cin.ignore();
            cin.get();
            break;
        }
        system("cls");
    } while (opcaoMenu != 9);
    
}