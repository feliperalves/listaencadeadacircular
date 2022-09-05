#include "Lista.h"

Lista** Lista::Inserir(Lista **R, std::string N, std::string T)
{
    Lista * novo = new Lista ();
    novo -> Nome = N;
    novo -> Telefone = T;
    if(R[0] == NULL)
    {
        R[0] = novo;
        R[1] = novo;
        R[1] -> elo = novo;
    }
    else
    {
        Lista * anterior = NULL, * atual = R [0];
        while (( atual != R [1]) && ( novo -> Nome > atual -> Nome ))
        {
            anterior = atual ;
            atual = atual -> elo ;
        }
        if(( atual == R [0]) && ( novo -> Nome < atual -> Nome ))
        {
            novo -> elo = R [0];
            R [1] -> elo = novo ;
            R [0] = novo ;
        }
        else if(( atual == R [1]) && ( novo -> Nome > atual -> Nome ))
        {
            atual -> elo = novo ;
            R [1] = novo ;
            R [1] -> elo = R [0];
        }
        else
        {
            anterior -> elo = novo;
            novo -> elo = atual;
        }
    }
    return R;
};

Lista ** Lista :: Excluir( Lista **R, std :: string N, bool * achei )
{
    Lista * aux = R[0], *anterior = NULL ;
    while (( aux != R [1]) && ( aux -> Nome != N))
    {
        anterior = aux;
        aux = aux -> elo;
    }
    if(( aux == R [1]) && ( aux -> Nome != N))
    {
        *achei = false ;
    }
    else
    {
        *achei = true ;
        if(( aux == R[0]) && (R[0] == R[1]) )
        {
            R[0] = NULL;
            R[1] = NULL ;
        }
        else if( aux == R [0])
        {
            R[0] = R[0] -> elo ;
            R[1] -> elo = R[0];
        }
        else if( aux == R [1])
        {
            R[1] = anterior;
            R [1] -> elo = R[0];
        }
        else
        {
            anterior -> elo = aux -> elo;
        }
        delete(aux);
    }
    return R;
};

void Lista :: Percorrer( Lista *I )
{
    Lista * aux = I;
    while( aux -> elo != I )
    {
        std::cout << " Nome : " << aux -> Nome << " | Telefone: " << aux -> Telefone << " \n";
        aux = aux -> elo;
    }
    std :: cout << " Nome : " << aux -> Nome << " | Telefone: " << aux -> Telefone
                << "\n";
};

void Lista::Sortear(Lista**R)
{
    Lista *Atual = R[0], *Prox;
    int N, i;
    bool Achei;
    while (R[0] != R[1])
    {
        N = rand()%30 + 1;
        for(i=0; i<N; i++)
        {
            Atual = Atual->elo;
        }
        Prox = Atual->elo;
        std::cout<<"\n\ndeletando\n\n"<< Atual->Nome;
        R = Excluir(R, Atual->Nome, &Achei);
        Atual = Prox;
    }
    std::cout<<"\n\nvencedor\n\n"<<Atual->Nome;
    R = Excluir(R, Atual->Nome, &Achei);
};
