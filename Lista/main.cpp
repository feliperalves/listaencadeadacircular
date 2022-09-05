#include "Lista.h"

using namespace std;

void Menu(){
    system("clear");
    cout << "########## MENU #########\n\n";
    cout << "1 - Inserir\n";
    cout << "2 - Listagem\n";
    cout << "3 - Remover\n";
    cout << "4 - Sair\n";
    cout << "EScolha a opção: ";
};
 int main()
 {
     Lista **P, obj;
     P = new Lista*[2];
     string nome, telefone;
     int op;
     bool achei;
     do{
        Menu();
        cin >> op;
        switch(op){
            case 1:
                cout << "Informe  Nome: ";
                cin.ignore();
                getline(cin, nome);
                P = obj.Inserir(P, nome);
                cout << "\nInserido com sucesso!!!\n";
                break;
            case 2:
                if(P[0] == NULL){
                    cout << "\nSem contatos para listar!\n";
                }else{
                    cout << "\nAGENDA\n";
                    obj.Percorrer(P[0]);
                }
               break;
            case 3:
                if(P[0] == NULL){
                    cout << "\nSem contatos para listar!\n";
                }else{
                    cout << "Informe o Nome: ";
                    cin.ignore();
                    getline(cin, nome);
                    P = obj.Excluir(P, nome, &achei);
                    if(achei){
                        cout << "\nExcluido com sucesso!\n";
                    }else{
                        cout << "\nContato não localizado!\n";
                    }
                }
                break;
            case 4:
                cout << "\nTchau!!\n";
                break;
            default:
                cout << "\nOpção inválida!\n";
           }
           cout << "Tecle ENTER para continuar! ";
           cin.ignore().get();
     }while(op != 4);

     return 0;
 }
