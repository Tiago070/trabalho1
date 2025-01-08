#include <iostream> // Biblioteca padrão para entrada e saída
#include <cstdlib>  // Biblioteca padrão para funções de utilidade geral
#include "ListaSequencial.hpp" // Inclusão do cabeçalho da lista sequencial

using namespace std; // Uso do namespace padrão para evitar escrever std:: antes de cout, cin, etc.

int main(){
    listaAlunos * li; // Declaração de um ponteiro para a lista de alunos
    li = criaLista(); // Criação da lista de alunos
    liberaLista(li); // Liberação da lista de alunos (possivelmente um erro, pois a lista acabou de ser criada)

    int tam = tamanhoLista(li); // Obtém o tamanho da lista

    bool cheia = listaCheia(li); // Verifica se a lista está cheia
    if (cheia){
        cout << "Lista cheia" << endl; // Imprime se a lista está cheia
    }else{
        cout << "Lista não está cheia" << endl; // Imprime se a lista não está cheia
    }

    bool vazia = listaVazia(li); // Verifica se a lista está vazia
    if (vazia){
        cout << "Lista vazia" << endl; // Imprime se a lista está vazia
    }else{
        cout << "Lista não está vazia" << endl; // Imprime se a lista não está vazia
    }

    struct aluno al; // Declaração de uma variável do tipo aluno

    // Entrada de dados do aluno
    cout << "Nome: ";
    cin >> al.nome;
    cout << "Matrícula: ";
    cin >> al.matricula;
    cout << "Notas: ";
    cin >> al.n1 >> al.n2;

    // Inserção do aluno no início da lista
    bool insereInicio = insereListaInicio(li, al);
    if (insereInicio){
        cout << "Inserção no início realizada com sucesso" << endl; // Sucesso na inserção
    }else{
        cout << "Inserção no início não realizada" << endl; // Falha na inserção
    }

    // Entrada de dados do aluno
    cout << "Nome: ";
    cin >> al.nome;
    cout << "Matrícula: ";
    cin >> al.matricula;
    cout << "Notas: ";
    cin >> al.n1 >> al.n2;

    // Inserção do aluno no final da lista
    bool insereFinal = insereListaFinal(li, al);
    if (insereFinal){
        cout << "Inserção no final realizada com sucesso" << endl; // Sucesso na inserção
    }else{
        cout << "Inserção no final não realizada" << endl; // Falha na inserção
    }

    // Entrada de dados do aluno
    cout << "Nome: ";
    cin >> al.nome;
    cout << "Matrícula: ";
    cin >> al.matricula;
    cout << "Notas: ";
    cin >> al.n1 >> al.n2;

    // Inserção do aluno no meio da lista
    bool insereMeio = insereListaMeio(li, al);
    if (insereMeio){
        cout << "Inserção no meio realizada com sucesso" << endl; // Sucesso na inserção
    }else{
        cout << "Inserção no meio não realizada" << endl; // Falha na inserção
    }

    // Remoção do aluno no início da lista
    bool removeInicio = removeListaInicio(li);
    if (removeInicio){
        cout << "Remoção no início realizada com sucesso" << endl; // Sucesso na remoção
    }else{
        cout << "Remoção no início não realizada" << endl; // Falha na remoção
    }

    // Remoção do aluno no final da lista
    bool removeFinal = removeListaFinal(li);
    if (removeFinal){
        cout << "Remoção no final realizada com sucesso" << endl; // Sucesso na remoção
    }else{
        cout << "Remoção no final não realizada" << endl; // Falha na remoção
    }

    // Remoção do aluno no meio da lista (posição 1)
    bool removeMeio = removeListaMeio(li, 1);
    if (removeMeio){
        cout << "Remoção no meio realizada com sucesso" << endl; // Sucesso na remoção
    }else{
        cout << "Remoção no meio não realizada" << endl; // Falha na remoção
    }
}