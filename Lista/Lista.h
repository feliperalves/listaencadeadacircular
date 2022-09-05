#include <iostream>
class Lista{

private:
    std::string Nome, Telefone;
    Lista *elo;
public:
    Lista** Inserir(Lista**, std::string, std::string);
    void Percorrer(Lista*);
    Lista** Excluir(Lista**, std::string, bool*);
    void Sortear(Lista **R);
};
