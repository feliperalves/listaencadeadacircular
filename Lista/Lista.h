#include <iostream>
class Lista
{
    private:
        std::string Nome;
        Lista *elo;
    public:
        Lista** Inserir(Lista**, std::string);
        void Percorrer(Lista*);
        Lista** Excluir(Lista**, std::string, bool*);
};
