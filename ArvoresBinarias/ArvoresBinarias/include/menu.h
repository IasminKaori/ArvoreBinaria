#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include<iostream>
#include<windows.h>

using namespace std;

void imprimeMenu()
{
    system("cls");
    cout << "                      Arvore Binaria Generica de Busca" << endl<<endl;
    cout << "#### [Selecione a operacao] #########" << endl;
    cout << "#     1 - Inserir nó                #" << endl;
    cout << "#     2 - Pesquisa de largura       #" << endl;
    cout << "#     3 - Verifique o item          #" << endl;
    cout << "#     4  - Get Min/Max              #" << endl;
    cout << "#     5  - Apagar Arvore            #" << endl;
    cout << "#     6  - PREFIXO RECURSIVO        #" << endl;
    cout << "#     7  - POSFIXO RECURSIVO        #" << endl;
    cout << "#     8  - INFIXO  RECURSIVO        #" << endl;
    cout << "#     9  - PREFIXO INTERATIVO       #" << endl;
    cout << "#     10 - POSFIXO INTERATIVO       #" << endl;
    cout << "#     11 - INFIXO  INTERATIVO       #" << endl;
    cout << "#     12 - Remove nó (por fusao)    #" << endl;
    cout << "#     13 - Remove nó (por copia)    #" << endl;
    cout << "#     14 - Sair                     #" << endl;
    cout << "#####################################" << endl;
    cout <<endl;
    cout << "Digite a opcao:";
}

#endif // MENU_H_INCLUDED
