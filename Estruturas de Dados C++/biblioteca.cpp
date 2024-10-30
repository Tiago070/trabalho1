#include <iostream>
#include <cstdio>
#include <limits>
#include <cstring>

using namespace std;

//definição das estruturas
struct emprestimos {
    char dt_emp[10], dt_dev[10], usuario[255];
};

struct livros {
    int codigo, paginas;
    char area[30], titulo[255], autores[255], editora[50];
    struct emprestimos emp;
} livro;

//definição das variáveis
int opcMenu, codLivro, posicao;
char opc;

//definição dos arquivos
FILE *arquivo, *arquivoAux;

int main(){
    do {
        cout << "|||||||||||SISTEMA DE GERENCIAMENTO DE BIBLIOTECA|||||||||||||" << endl;
        cout << "1 - Cadastro" << endl;
        cout << "2 - Alteração" << endl;
        cout << "3 - Exclusão" << endl;
        cout << "4 - Empréstimo" << endl;
        cout << "5 - Devolução" << endl;
        cout << "6 - Consulta de livro" << endl;
        cout << "7 - Livros disponíveis" << endl;
        cout << "8 - Listagem geral de livros" << endl;
        cout << "9 - Sair" << endl << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcMenu;

        switch (opcMenu){
            case 1:
                cout << "CADASTRO DE LIVROS" << endl;
                cout << "Deseja cadastrar um livro? [S/N]: ";
                cin >> opc;
                while (opc == 'S' || opc == 's'){
                    //coleta de dados
                    cout << "Código: ";
                    cin >> livro.codigo;
                    //limpar último caractere
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Área: ";
                    //coleta de string com espaços
                    cin.get(livro.area, 30);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Título: ";
                    cin.get(livro.titulo, 255);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Autor(es): ";
                    cin.get(livro.autores, 255);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Editora: ";
                    cin.get(livro.editora, 50);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Número de páginas: ";
                    cin >> livro.paginas;

                    //abrir arquivo adicionando dados
                    arquivo = fopen("dados.dat", "ab");

                    // para primeira execução, cria o arquivo e adiciona o primeiro registro
                    if (arquivo == NULL) {
                        arquivo = fopen("dados.dat", "wb");
                    }

                    //salvar dados    
                    if (fwrite(&livro, sizeof(struct livros), 1, arquivo) == 1){
                        cout << "Livro cadastrado com sucesso!";
                    } else {
                        cout << "Erro ao cadastrar o livro!";
                    }
                    //fechar arquivo
                    fclose(arquivo);

                    //pausa
                    cin.ignore();
                    cin.get();

                    cout << "Deseja cadastrar outro livro? [S/N]: ";
                    cin >> opc;
                }
                break;
            case 2:
                cout << "ALTERAÇÃO DE LIVRO" << endl;
                cout << "Deseja alterar um livro? [S/N]: ";
                cin >> opc;
                while (opc == 'S' || opc == 's'){
                    arquivo = fopen("dados.dat", "rb+");
                    if (arquivo != NULL){
                        cout << "Digite o código do livro que deseja alterar: ";
                        cin >> codLivro;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        
                        //definindo posição inicial do registro
                        posicao = -1;

                        //enquanto não chegar ao final do arquivo
                        while(!feof(arquivo)){
                            //leitura do registro
                            fread(&livro, sizeof(struct livros), 1, arquivo);
                            //incremento da posição
                            posicao++;

                            //alteração do registro
                            if (codLivro == livro.codigo){
                                cout << "Área: ";
                                cin.get(livro.area, 30);
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Título: ";
                                cin.get(livro.titulo, 255);
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Autor(es): ";
                                cin.get(livro.autores, 255);
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Editora: ";
                                cin.get(livro.editora, 50);
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Número de páginas: ";
                                cin >> livro.paginas;

                                //movendo o ponteiro para a posição inicial do registro
                                fseek(arquivo, sizeof(struct livros) * posicao, SEEK_SET);

                                //teste de gravação do registro
                                if (fwrite(&livro, sizeof(struct livros), 1, arquivo) == 1){
                                    cout << "Livro alterado com sucesso!";
                                } else {
                                    cout << "Erro ao alterar o livro!";
                                } 
                                cin.ignore();
                                cin.get();
                                break;
                            }
                        }
                        fclose(arquivo);

                    } else {
                        cout << "Erro ao abrir o banco de dados!";
                        cin.ignore();
                        cin.get();
                    }

                    cout << "Deseja alterar outro livro? [S/N]: ";
                    cin >> opc;
                }
                break;
            case 3:
                cout << "EXCLUSÃO DE LIVRO" << endl;
                cout << "Digite o código do livro que deseja excluir: ";
                cin >> codLivro;

                //abrir arquivo principal e arquivo auxiliar
                arquivo = fopen("dados.dat", "rb");
                arquivoAux = fopen("dados.aux", "wb");

                //leitura do arquivo principal
                fread(&livro, sizeof(struct livros), 1, arquivo);

                //enquanto não chegar ao final do arquivo
                while(!feof(arquivo)){
                    //se o código do livro for diferente do código informado, salva no arquivo auxiliar
                    if (codLivro != livro.codigo){
                        fwrite(&livro, sizeof(struct livros), 1, arquivoAux);
                    }
                    //leitura do próximo registro
                    fread(&livro, sizeof(struct livros), 1, arquivo);
                }

                //fechamento dos arquivos
                fclose(arquivo);
                fclose(arquivoAux);

                //exclusão física do arquivo principal e renomeação do arquivo auxiliar
                remove("dados.dat");
                rename("dados.aux", "dados.dat");
                break;
            case 4:
                arquivo = fopen("dados.dat", "rb+");
                if (arquivo != NULL){
                    cout << "EMPRÉSTIMO DE LIVRO" << endl;
                    cout << "Digite o código do livro que deseja emprestar: ";
                    cin >> codLivro;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    posicao = -1;
                    while(!feof(arquivo)){
                        fread(&livro, sizeof(struct livros), 1, arquivo);
                        posicao++;
                        if (codLivro == livro.codigo){
                            //movendo o ponteiro para a posição inicial do registro
                            fseek(arquivo, sizeof(struct livros) * posicao, SEEK_SET);
                            cout << "Data de empréstimo: ";
                            cin.get(livro.emp.dt_emp, 10);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Data de devolução: ";
                            cin.get(livro.emp.dt_dev, 10);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Usuário: ";
                            cin.get(livro.emp.usuario, 255);
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            //gravação do registro
                            fwrite(&livro, sizeof(struct livros), 1, arquivo);
                            break;
                        }
                    }
                    fclose(arquivo);

                } else {
                    cout << "Erro ao abrir o banco de dados!";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 5:
                arquivo = fopen("dados.dat", "rb+");
                if (arquivo != NULL){
                    cout << "DEVOLUÇÃO DE LIVRO" << endl;
                    cout << "Digite o código do livro que deseja devolver: ";
                    cin >> codLivro;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    posicao = -1;
                    while(!feof(arquivo)){
                        fread(&livro, sizeof(struct livros), 1, arquivo);
                        posicao++;
                        if (codLivro == livro.codigo){
                            //movendo o ponteiro para a posição inicial do registro
                            fseek(arquivo, sizeof(struct livros) * posicao, SEEK_SET);
                            //limpando campos de empréstimo
                            strcpy(livro.emp.dt_emp, "");
                            strcpy(livro.emp.dt_dev, "");
                            strcpy(livro.emp.usuario, "");
                            //gravação do registro
                            fwrite(&livro, sizeof(struct livros), 1, arquivo);
                            break;
                        }
                    }
                    fclose(arquivo);

                } else {
                    cout << "Erro ao abrir o banco de dados!";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 6:
                arquivo = fopen("dados.dat", "rb");
                if (arquivo != NULL){
                    cout << "CONSULTAR LIVRO" << endl;
                    cout << "Digite o código do livro que deseja pesquisar: ";
                    cin >> codLivro;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    while(!feof(arquivo)){
                        fread(&livro, sizeof(struct livros), 1, arquivo);
                        if (codLivro == livro.codigo){
                            //lista um livro específico
                            cout << "Código: " << livro.codigo << endl;
                            cout << "Área: " << livro.area << endl;
                            cout << "Título: " << livro.titulo << endl;
                            cout << "Autor(es): " << livro.autores << endl;
                            cout << "Editora: " << livro.editora << endl;
                            cout << "Número de páginas: " << livro.paginas << endl;
                            cin.get();
                            break;
                        }
                    }
                    fclose(arquivo);

                } else {
                    cout << "Erro ao abrir o banco de dados!";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 7:
                arquivo = fopen("dados.dat", "rb");
                if (arquivo != NULL){

                    //leitura do primeiro registro
                    fread(&livro, sizeof(struct livros), 1, arquivo);

                    cout << "LIVROS DISPONÍVEIS" << endl;
                    while(!feof(arquivo)){
                        //lista livros disponíveis, ou seja, sem data de empréstimo
                        if (strcmp(livro.emp.dt_emp, "") == 0){
                            cout << "Código: " << livro.codigo << endl;
                            cout << "Área: " << livro.area << endl;
                            cout << "Título: " << livro.titulo << endl;
                            cout << "Autor(es): " << livro.autores << endl;
                            cout << "Editora: " << livro.editora << endl;
                            cout << "Número de páginas: " << livro.paginas << endl;
                            cout << "---------------------------------------" << endl;
                        }
                        //leitura do próximo registro
                        fread(&livro, sizeof(struct livros), 1, arquivo);
                    }
                    fclose(arquivo);
                    cin.ignore();
                    cin.get();
                } else {
                    cout << "Erro ao abrir o banco de dados!";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 8:
                arquivo = fopen("dados.dat", "rb");
                if (arquivo != NULL){
                    fread(&livro, sizeof(struct livros), 1, arquivo);

                    cout << "LISTAGEM GERAL DE LIVROS" << endl;

                    //leitura de todos os registros do arquivo
                    while(!feof(arquivo)){
                        cout << "Código: " << livro.codigo << endl;
                        cout << "Área: " << livro.area << endl;
                        cout << "Título: " << livro.titulo << endl;
                        cout << "Autor(es): " << livro.autores << endl;
                        cout << "Editora: " << livro.editora << endl;
                        cout << "Número de páginas: " << livro.paginas << endl;
                        cout << "---------------------------------------" << endl;
                        fread(&livro, sizeof(struct livros), 1, arquivo);
                    }
                    fclose(arquivo);
                    cin.ignore();
                    cin.get();
                } else {
                    cout << "Erro ao abrir o banco de dados!";
                    cin.ignore();
                    cin.get();
                }
                break;
            case 9:
                cout << "Obrigado por usar nossa solução!";
                break;
            default:
                cout << "Informe uma opção válida!";
                break;
        }
        system("clear");
    } while (opcMenu != 9);

}