#define MAX 100 // Define o tamanho máximo da lista

// Estrutura que representa um aluno
struct aluno {
    int matricula; // Número de matrícula do aluno
    char nome[30]; // Nome do aluno
    float n1, n2; // Notas do aluno
};

// Estrutura que representa a lista de alunos
struct lista {
    int qtd; // Quantidade de elementos na lista
    struct aluno dados[MAX]; // Array de alunos
};

typedef struct lista listaAlunos; // Define um novo nome para a estrutura lista

// Função para criar uma nova lista
listaAlunos* criaLista(void) {
    listaAlunos *pl;
    pl = (listaAlunos*) malloc(sizeof(listaAlunos)); // Aloca memória para a lista
    if(pl != NULL) {
        pl->qtd = 0; // Inicializa a quantidade de elementos como 0
    }
    return pl; // Retorna o ponteiro para a lista criada
}

// Função para liberar a memória da lista
void liberaLista(listaAlunos* pl) {
    free(pl); // Libera a memória alocada para a lista
}

// Função para obter o tamanho da lista
int tamanhoLista(listaAlunos* pl) {
    if(pl == NULL) {
        return -1; // Retorna -1 se a lista for nula
    } else {
        return pl->qtd; // Retorna a quantidade de elementos na lista
    }
}

// Função para verificar se a lista está cheia
int listaCheia(listaAlunos* pl) {
    if(pl == NULL) {
        return -1; // Retorna -1 se a lista for nula
    } else {
        return (pl->qtd == MAX); // Retorna 1 se a lista estiver cheia, caso contrário 0
    }
}

// Função para verificar se a lista está vazia
int listaVazia(listaAlunos* pl) {
    if(pl == NULL) {
        return -1; // Retorna -1 se a lista for nula
    } else {
        return (pl->qtd == 0); // Retorna 1 se a lista estiver vazia, caso contrário 0
    }
}

// Função para inserir um aluno no início da lista
bool insereListaInicio(listaAlunos* pl, struct aluno da) {
    if(pl == NULL) {
        return false; // Retorna false se a lista for nula
    }
    if(pl->qtd == MAX) {
        return false; // Retorna false se a lista estiver cheia
    }
    for(int i = pl->qtd-1; i >= 0; i--) {
        pl->dados[i+1] = pl->dados[i]; // Desloca os elementos para a direita
    }
    pl->dados[0] = da; // Insere o novo aluno no início
    pl->qtd++; // Incrementa a quantidade de elementos
    return true; // Retorna true indicando sucesso
}

// Função para inserir um aluno no final da lista
bool insereListaFinal(listaAlunos* pl, struct aluno da) {
    if(pl == NULL) {
        return false; // Retorna false se a lista for nula
    }
    if(pl->qtd == MAX) {
        return false; // Retorna false se a lista estiver cheia
    }
    pl->dados[pl->qtd] = da; // Insere o novo aluno no final
    pl->qtd++; // Incrementa a quantidade de elementos
    return true; // Retorna true indicando sucesso
}

// Função para inserir um aluno no meio da lista de forma ordenada
bool insereListaMeio(listaAlunos* pl, struct aluno da) {
    if(pl == NULL) {
        return false; // Retorna false se a lista for nula
    }
    if(pl->qtd == MAX) {
        return false; // Retorna false se a lista estiver cheia
    }
    int k, i = 0;
    while(i < pl->qtd && pl->dados[i].matricula < da.matricula) {
        i++; // Encontra a posição correta para inserir o novo aluno
    }
    for(k = pl->qtd-1; k >= i; k--) {
        pl->dados[k+1] = pl->dados[k]; // Desloca os elementos para a direita
    }
    pl->dados[i] = da; // Insere o novo aluno na posição correta
    pl->qtd++; // Incrementa a quantidade de elementos
    return true; // Retorna true indicando sucesso
}

// Função para remover o primeiro aluno da lista
bool removeListaInicio(listaAlunos* pl) {
    if(pl == NULL) {
        return false; // Retorna false se a lista for nula
    }
    if(pl->qtd == 0) {
        return false; // Retorna false se a lista estiver vazia
    }
    for(int i = 0; i < pl->qtd-1; i++) {
        pl->dados[i] = pl->dados[i+1]; // Desloca os elementos para a esquerda
    }
    pl->qtd--; // Decrementa a quantidade de elementos
    return true; // Retorna true indicando sucesso
}

// Função para remover o último aluno da lista
bool removeListaFinal(listaAlunos* pl) {
    if(pl == NULL) {
        return false; // Retorna false se a lista for nula
    }
    if(pl->qtd == 0) {
        return false; // Retorna false se a lista estiver vazia
    }
    pl->qtd--; // Decrementa a quantidade de elementos
    return true; // Retorna true indicando sucesso
}

// Função para remover um aluno específico da lista
bool removeListaMeio(listaAlunos* pl, int mat) {
    if(pl == NULL) {
        return false; // Retorna false se a lista for nula
    }
    if(pl->qtd == 0) {
        return false; // Retorna false se a lista estiver vazia
    }
    int k, i = 0;
    while(i < pl->qtd && pl->dados[i].matricula != mat) {
        i++; // Encontra a posição do aluno a ser removido
    }
    if(i == pl->qtd) {
        return false; // Retorna false se o aluno não for encontrado
    }
    for(k = i; k < pl->qtd-1; k++) {
        pl->dados[k] = pl->dados[k+1]; // Desloca os elementos para a esquerda
    }
    pl->qtd--; // Decrementa a quantidade de elementos
    return true; // Retorna true indicando sucesso
}