# include "Lista.h"

using namespace std;

void Menu ()
{
    system (" clear ") ;
    cout << " ############ MENU ##############\n\n";
    cout << "1 - Inserir Dados\n";
    cout << "2 - Listagem\n";
    cout << "3 - Realizar sorteio\n";
    cout << "4 - Sair \n";
    cout << " Escolha a opção : ";
};

int main ()
{
    Lista **P, obj;
    P = new Lista *[2];
    P[0] = P[1] = NULL ;
    string nome, telefone;
    int op;
    bool achei;
    do
    {
        Menu ();
        cin >> op ;
        switch (op)
        {
        case 1:
            cout << " Informe o Nome : ";
            cin.ignore() ;
            getline( cin,nome);
            cout << " Informe o telefone: ";
            getline( cin,telefone) ;
            P = obj. Inserir(P,nome,telefone);
            cout << " \ nInserido com sucesso !!!\ n";
            break;
        case 2:
            if(P [0] == NULL )
            {
                cout << " \ nSem contatos para listar !\ n";
            }
            else
            {
                cout << " \ nAGENDA\n ";
                obj. Percorrer( P[0]) ;
            }
            break;

        case 3:
            if(P [0] == NULL )
            {
                cout << " \ nSem contatos para sortear !\ n";
            }
            else
            {
                obj.Sortear(P);
                break;
            case 4:
                cout << " \nTchau !!\n ";
                break;
            default:
                cout << " \nOpção inválida !!\n";
            }
            cout << "Tecle ENTER para continuar! ";

        }
        cin.ignore().get();
    }

    while( op != 4) ;

    return 0;
}
