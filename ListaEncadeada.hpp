// Define a estrutura 'aluno' que contém informações sobre um aluno
struct aluno {
    int matricula; // Número de matrícula do aluno
    char nome[30]; // Nome do aluno
    float n1, n2;  // Notas do aluno
};

// Define a estrutura 'elemento' que representa um nó na lista encadeada
struct elemento {
    struct aluno dados; // Dados do aluno armazenados no nó
    struct elemento *prox; // Ponteiro para o próximo nó na lista
};

// Define um ponteiro para um 'elemento', que será usado como a lista de alunos
typedef struct elemento* listaAlunos;

// Define um alias para a estrutura 'elemento'
typedef struct elemento elemLista;

// Função para criar uma nova lista encadeada
listaAlunos* criaLista(void) {
    // Aloca memória para a lista
    listaAlunos* cl = (listaAlunos*) malloc(sizeof(listaAlunos));
    if(cl != NULL) {
        *cl = NULL; // Inicializa a lista como vazia
    }
    return cl; // Retorna o ponteiro para a lista criada
}

// Função para liberar a memória ocupada pela lista
void liberaLista(listaAlunos* cl) {
    if(cl != NULL) {
        elemLista* cAux;
        // Percorre a lista e libera cada nó
        while((*cl) != NULL) {
            cAux = *cl;
            *cl = (*cl)->prox;
            free(cAux);
        }
        free(cl); // Libera o ponteiro da lista
    }
}

// Função para obter o tamanho da lista
int tamanhoLista(listaAlunos* cl) {
    if(cl == NULL) {
        return 0; // Se a lista for nula, retorna 0
    }
    int cont = 0;
    elemLista* cAux = *cl;
    // Percorre a lista contando os nós
    while(cAux != NULL) {
        cont++;
        cAux = cAux->prox;
    }
    return cont; // Retorna o número de nós na lista
}

// Função que verifica se a lista está cheia (sempre retorna falso, pois lista encadeada não fica cheia)
bool listaCheia(listaAlunos* cl) {
    return 0;
}

// Função que verifica se a lista está vazia
bool listaVazia(listaAlunos* cl) {
    if(cl == NULL) {
        return true; // Se a lista for nula, está vazia
    }
    if(*cl == NULL) {
        return true; // Se o primeiro nó for nulo, está vazia
    }
    return false; // Caso contrário, não está vazia
}

// Função para inserir um aluno no início da lista
bool insereListaInicio(listaAlunos* cl, struct aluno da) {
    if(cl == NULL) {
        return false; // Se a lista for nula, falha na inserção
    }
    // Aloca memória para o novo nó
    elemLista* novoElem = (elemLista*) malloc(sizeof(elemento));
    if(novoElem == NULL) {
        return false; // Se falhar na alocação, falha na inserção
    }
    novoElem->dados = da; // Atribui os dados do aluno ao novo nó
    novoElem->prox = (*cl); // Faz o novo nó apontar para o primeiro nó atual
    *cl = novoElem; // Atualiza o ponteiro da lista para o novo nó
    return true; // Sucesso na inserção
}

// Função para inserir um aluno no final da lista
bool insereListaFinal(listaAlunos* cl, struct aluno da) {
    if(cl == NULL) {
        return false; // Se a lista for nula, falha na inserção
    }
    // Aloca memória para o novo nó
    elemLista* novoElem = (elemLista*) malloc(sizeof(elemento));
    if(novoElem == NULL) {
        return false; // Se falhar na alocação, falha na inserção
    }
    novoElem->dados = da; // Atribui os dados do aluno ao novo nó
    novoElem->prox = NULL; // O novo nó será o último, então aponta para NULL
    if(listaVazia(cl)) {
        *cl = novoElem; // Se a lista estiver vazia, o novo nó é o primeiro
    } else {
        elemLista* cAux = *cl;
        // Percorre a lista até o último nó
        while(cAux->prox != NULL) {
            cAux = cAux->prox;
        }
        cAux->prox = novoElem; // Faz o último nó atual apontar para o novo nó
    }
    return true; // Sucesso na inserção
}

// Função para inserir um aluno no meio da lista, mantendo a ordem pela matrícula
bool insereListaMeio(listaAlunos* cl, struct aluno da) {
    if(cl == NULL) {
        return false; // Se a lista for nula, falha na inserção
    }
    // Aloca memória para o novo nó
    elemLista* novoElem = (elemLista*) malloc(sizeof(elemento));
    if(novoElem == NULL) {
        return false; // Se falhar na alocação, falha na inserção
    }
    novoElem->dados = da; // Atribui os dados do aluno ao novo nó
    if(listaVazia(cl)) {
        novoElem->prox = NULL; // Se a lista estiver vazia, o novo nó é o primeiro
        *cl = novoElem;
        return true; // Sucesso na inserção
    } else {
        elemLista* cAnt = NULL;
        elemLista* cAux = *cl;
        // Percorre a lista até encontrar a posição correta
        while(cAux != NULL && cAux->dados.matricula < da.matricula) {
            cAnt = cAux;
            cAux = cAux->prox;
        }
        if(cAnt == NULL) {
            novoElem->prox = (*cl); // Insere no início se for a menor matrícula
            *cl = novoElem;
        } else {
            novoElem->prox = cAnt->prox; // Insere no meio ou no final
            cAnt->prox = novoElem;
        }
        return true; // Sucesso na inserção
    }
}

// Função para remover o primeiro aluno da lista
bool removeListaInicio(listaAlunos* cl) {
    if(cl == NULL) {
        return false; // Se a lista for nula, falha na remoção
    }
    if(listaVazia(cl)) {
        return false; // Se a lista estiver vazia, falha na remoção
    }
    elemLista* elemRem = *cl; // Aponta para o primeiro nó
    *cl = elemRem->prox; // Atualiza o ponteiro da lista para o próximo nó
    free(elemRem); // Libera a memória do nó removido
    return true; // Sucesso na remoção
}

// Função para remover o último aluno da lista
bool removeListaFinal(listaAlunos* cl) {
    if(cl == NULL) {
        return false; // Se a lista for nula, falha na remoção
    }
    if(listaVazia(cl)) {
        return false; // Se a lista estiver vazia, falha na remoção
    }
    elemLista *anterior = NULL, *elemRem = *cl;
    // Percorre a lista até o último nó
    while(elemRem->prox != NULL) {
        anterior = elemRem;
        elemRem = elemRem->prox;
    }
    if(anterior == NULL) {
        *cl = elemRem->prox; // Se houver apenas um nó, a lista fica vazia
    } else {
        anterior->prox = elemRem->prox; // Remove o último nó
    }
    free(elemRem); // Libera a memória do nó removido
    return true; // Sucesso na remoção
}

// Função para remover um aluno específico da lista, baseado na matrícula
bool removeListaMeio(listaAlunos* cl) {
    if(cl == NULL) {
        return false; // Se a lista for nula, falha na remoção
    }
    if(listaVazia(cl)) {
        return false; // Se a lista estiver vazia, falha na remoção
    }
    int matricula;
    cout << "Digite a matrícula do aluno que deseja remover: ";
    cin >> matricula; // Solicita a matrícula do aluno a ser removido
    elemLista* cAnt = NULL;
    elemLista* cAux = *cl;
    // Percorre a lista até encontrar o nó com a matrícula correspondente
    while(cAux != NULL && cAux->dados.matricula != matricula) {
        cAnt = cAux;
        cAux = cAux->prox;
    }
    if(cAux == NULL) {
        return false; // Se não encontrar a matrícula, falha na remoção
    }
    if(cAnt == NULL) {
        *cl = cAux->prox; // Se for o primeiro nó, atualiza o ponteiro da lista
    } else {
        cAnt->prox = cAux->prox; // Remove o nó do meio ou do final
    }
    free(cAux); // Libera a memória do nó removido
    return true; // Sucesso na remoção
}