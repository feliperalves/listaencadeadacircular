#include "Lista.h"

Lista** Lista::Inserir(Lista **R, std::string N){
    Lista *novo = new Lista();
    novo->Nome = N;
    if (R[0] == NULL){
        R[0] = novo;
        R[1] = novo;
        R[1]->elo = novo;
    }else{
        Lista *anterior = NULL, *atual = R[0];
        while((atual != R[1]) && (novo->Nome > atual->Nome)){
            anterior = atual;
            atual = atual->elo;
        }
        if((atual == R[0]) && (novo->Nome < atual->Nome)){
            novo->elo = R[0];
            R[1]->elo = novo;
            R[0] = novo;
        }else if ((atual == R[1]) && (novo->Nome > atual->Nome)){
            atual->elo = novo;
            R[1] = novo;
            R[1]-> elo = R[0];
        }else{
            anterior->elo = novo;
            novo->elo = atual;
        }
    }
    return R;
};
Lista** Lista::Excluir(Lista **R, std::string N, bool *achei){
    Lista *aux = R[0], *anterior = NULL;
    while((aux != R[1]) && (aux->Nome != N)){
        anterior = aux;
        aux = aux->elo;
    }
    if((aux != R[1]) && (aux->Nome != N)){
            *achei = false;
    }else{
        *achei = true;
        if ((aux == R[0]) && (R[0] == R[1])){
            R[0] == NULL;
            R[1] == NULL;
        }else if(aux == R[0]){
            R[0] = R[0]->elo;
            R[1] ->elo = R[0];
        }else if(aux == R[1]){
            R[1] = anterior;
            R[1]->elo = R[0];
        }else{
            anterior-> elo = aux->elo;
        }
        delete(aux);
    }
    return R;
};
void Lista::Percorrer(Lista *I){
    Lista *aux = I;
    while(aux->elo != I){
        std::cout << "Nome: " << aux->Nome;
        aux = aux->elo;
    }
    std::cout << "Nome: " << aux->Nome << "\n";
};
