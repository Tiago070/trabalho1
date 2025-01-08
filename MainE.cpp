#include <iostream> // Biblioteca padrão para entrada e saída
#include <cstdlib>  // Biblioteca padrão para funções de utilidade geral
#include "ListaEncadeada.hpp" // Inclusão do cabeçalho da lista sequencial

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

    cout << "Nome: "; // Imprime uma mensagem
    cin >> al.nome; // Lê o nome do aluno
    cout << "Matrícula: "; // Imprime uma mensagem
    cin >> al.matricula; // Lê a matrícula do aluno
    cout << "Notas: "; // Imprime uma mensagem
    cin >> al.n1 >> al.n2; // Lê as notas do aluno

    bool insInicio = insereListaInicio(li, al); // Insere um aluno no início da lista
    if (insInicio){
        cout << "Inserção no início realizada com sucesso" << endl; // Imprime se a inserção no início foi realizada com sucesso
    }else{
        cout << "Inserção no início não realizada" << endl; // Imprime se a inserção no início não foi realizada
    }

    bool insFinal = insereListaFinal(li, al); // Insere um aluno no final da lista
    if (insFinal){
        cout << "Inserção no final realizada com sucesso" << endl; // Imprime se a inserção no final foi realizada com sucesso
    }else{
        cout << "Inserção no final não realizada" << endl; // Imprime se a inserção no final não foi realizada
    }

    bool insMeio = insereListaMeio(li, al); // Insere um aluno no meio da lista
    if (insMeio){
        cout << "Inserção no meio realizada com sucesso" << endl; // Imprime se a inserção no meio foi realizada com sucesso
    }else{
        cout << "Inserção no meio não realizada" << endl; // Imprime se a inserção no meio não foi realizada
    }

    bool remInicio = removeListaInicio(li); // Remove um aluno do início da lista   
    if (remInicio){
        cout << "Remoção no início realizada com sucesso" << endl; // Imprime se a remoção no início foi realizada com sucesso
    }else{
        cout << "Remoção no início não realizada" << endl; // Imprime se a remoção no início não foi realizada
    }

    bool remFinal = removeListaFinal(li); // Remove um aluno do final da lista
    if (remFinal){
        cout << "Remoção no final realizada com sucesso" << endl; // Imprime se a remoção no final foi realizada com sucesso
    }else{
        cout << "Remoção no final não realizada" << endl; // Imprime se a remoção no final não foi realizada
    }

    bool remMeio = removeListaMeio(li); // Remove um aluno do meio da lista
    if (remMeio){
        cout << "Remoção no meio realizada com sucesso" << endl; // Imprime se a remoção no meio foi realizada com sucesso
    }else{
        cout << "Remoção no meio não realizada" << endl; // Imprime se a remoção no meio não foi realizada
    }

    
    

}