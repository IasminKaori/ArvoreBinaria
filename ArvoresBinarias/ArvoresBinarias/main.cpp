#include <iostream>
#include "menu.h"
#include "Globals.h"
#include "Tree.h"

int main()
{
    Tree arvore;
    int item, minimo, maximo;
    int opcao = NOOP;
    string op;
    while (true)
    {
        imprimeMenu();
        getline(cin, op);
        try
        {
            opcao = atoi(op.c_str());
            if (opcao > 0 && opcao <= MENU)
            {
                switch (opcao)
                {
                    case 1:
                  cout << "Digite um inteiro:";
                  cin >> item;
                  if (arvore.searchItemTree(item)==NULL)
                     arvore.insertItem(item);
                  else
                  {
                      cout << "Item ja esta na arvore." << endl;
                      cout << "Tecle algo para continuar..." << endl;
                      cin.ignore();
                  }
                  cin.ignore();
                break;
                    case 2:
                        arvore.breadthSearch();
                        cout << endl;
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();
                        break;

                    case 3:
                        int i;
                        cout<<"Digite o inteiro a ser buscado:"<<endl;
                        cin >>i;
                        if(arvore.searchItemTree(i)!= i)
                            {
                                cout<< "O valor "<<i<<" Não existe";
                        }
                        else
                            {
                                cout<<"O valor "<<i<<" existe";
                        }
                        cout << endl;
                        cout << endl;
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();cin.ignore();
                        break;

                    case 4:
                        arvore.getMinMax(minimo, maximo);
                        cout << endl;
                        cout << "minimo: " << minimo << endl;
                        cout << "maximo: " << maximo << endl;
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();

                        break;

                   case 5:
                        arvore.clearTree();
                        cout<<"Arvore apagada com sucesso!"<<endl;
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();
                        break;

                    case 6:
                        arvore.Prefixo(arvore.root);
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();
                        break;

                    case 7:
                        arvore.Posfixo(arvore.root);
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();
                        break;

                    case 8:
                        arvore.Inffixo(arvore.root);
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();
                        break;

                    case 9:

                        arvore.visitPreFixada();
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();
                        break;

                    case 10:
                         arvore.iterativePosOrdem();
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();
                        break;
                    case 11:
                         arvore.iterativeInorder();
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();
                        break;

                   case 12:
                        int ix;
                        cout<<"Digite o no que deseja remover: "<<endl;
                        cin>>ix;
                        arvore.removeNodeByMerge(arvore.root, ix);
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();
                        cin.ignore();
                        break;

                      case 13:
                        int is;
                        cout<<"Digite o no que deseja remover: "<<endl;
                        cin>>is;
                        arvore.removeNodeByCopy(arvore.root, is);
                        cout << "Tecle algo para continuar..." << endl;
                        cin.ignore();
                        cin.ignore();
                        break;


                    case 14:
                        cout <<"Exiting..." << endl;
                        return 0;

                    default:
                        break;

                }
            }
            else
            {
                throw "opcao invalida";
            }
        }
        catch (string op)
        {
            cout << endl << "Opcao invalida: " << op << endl;
            cout << endl << "Tecle algo para continuar..." << endl;
            cin.ignore();
        }
    }

    return 0;
}
