#ifndef TREE_H
#define TREE_H
#include <queue>
#include <Node.h>
#include <stack>

using namespace std;

class Tree
{
    public:
        Node *root;
        Tree();
        void insertItem(int);
        int searchItemTree(int);
        void getMinMax(int &, int &);
        bool isEmpty();
        void clearTree();
        void breadthSearch();
        virtual ~Tree();
        int Prefixo(Node*);
        int Posfixo(Node *);
        int Inffixo(Node*);
        Node* minNode(Node* node);
        void visitPreFixada();
        void visitPosFixada();
        void iterativePreorder();
        void iterativePosOrdem();
        void iterativeInorder();
        int removeNodeByCopy(Node*&, int valor);
        int removeNodeByMerge(Node*&, int data);


    private:
        int nodes;
        void clearNodes(Node*);
        int searchItem(int,Node*);
        void visit(Node*);
};

Tree::Tree()
{
   root=NULL;
   nodes=0;
}

Tree::~Tree()
{
   clearTree();
}

void Tree::clearTree() // define uma fun��o chamada clearTree na classe Tree
{
    clearNodes(root); // chama a fun��o recursiva clearNodes, passando o n� raiz como par�metro
    root=NULL; // define que a raiz da �rvore � NULL
    nodes=0; // zera a contagem de n�s da �rvore
}

bool Tree::isEmpty() // define uma fun��o booleana chamada isEmpty na classe Tree
{
    return root==NULL; // retorna true se a raiz da �rvore for NULL, caso contr�rio retorna false
}



void Tree::visitPreFixada() // define uma fun��o chamada visitPreFixada na classe Tree
{
    stack<Node*> pilha; // cria uma pilha de ponteiros para n�
    Node* p = root; // cria um ponteiro para n� chamado p e o inicializa com o n� raiz da �rvore

    while (p != NULL || !pilha.empty()) // enquanto p n�o for nulo OU a pilha n�o estiver vazia
    {
        if (p != NULL) { // se p n�o for nulo
            visit(p); // chama a fun��o visit, passando o n� p como par�metro
            pilha.push(p); // empilha o n� p na pilha
            p = p->left; // define p como o n� filho esquerdo de p
        }
        else { // se p for nulo
            p = pilha.top(); // define p como o n� que est� no topo da pilha
            pilha.pop(); // remove o n� do topo da pilha
            p = p->right; // define p como o n� filho direito do n� anterior
        }
    }
}


void Tree::visit(Node* p) // define uma fun��o chamada visit que recebe um ponteiro para n� como par�metro
{
    cout << p->getKey() << ' '; // imprime a chave do n� na tela, seguido de um espa�o em branco
}

void Tree::insertItem(int dado) // define uma fun��o chamada insertItem na classe Tree, que recebe um inteiro como par�metro
{
    Node *p=root; // cria um ponteiro para n� chamado p e o inicializa com o n� raiz da �rvore
    Node *prev=NULL; // cria um ponteiro para n� chamado prev e o inicializa como nulo

    if(isEmpty()) // se a �rvore estiver vazia
        root=new Node(dado); // cria um novo n� com o dado passado como par�metro e o define como raiz da �rvore
    else // se a �rvore n�o estiver vazia
    {
        while(p!=NULL) // enquanto p n�o for nulo
        {
            prev=p; // define prev como p
            if(prev->getKey()<dado) // se a chave do n� prev for menor que o dado passado como par�metro
                p=p->right; // define p como o n� filho direito de p
            else // caso contr�rio
                p=p->left; // define p como o n� filho esquerdo de p
        }
        if (prev->getKey()<dado) // se a chave do n� prev for menor que o dado passado como par�metro
            prev->right = new Node(dado); // cria um novo n� com o dado passado como par�metro e o define como filho direito do n� prev
        else // caso contr�rio
            prev->left = new Node(dado); // cria um novo n� com o dado passado como par�metro e o define como filho esquerdo do n� prev
    }

    nodes++; // incrementa o contador de n�s da �rvore
}



int Tree::Prefixo(Node *p) // define uma fun��o chamada Prefixo que recebe um ponteiro para n� como par�metro
{
     if(p != NULL) // se o ponteiro para n� p n�o for nulo
    {
        visit(p); // chama a fun��o visit, passando o n� p como par�metro
        Prefixo(p->left); // chama a fun��o Prefixo recursivamente, passando o n� filho esquerdo de p como par�metro
        Prefixo(p->right); // chama a fun��o Prefixo recursivamente, passando o n� filho direito de p como par�metro
    }
}



int Tree::Posfixo(Node *p) // define uma fun��o chamada Posfixo que recebe um ponteiro para n� como par�metro
{
    if(p != NULL) // se o ponteiro para n� p n�o for nulo
    {
        Posfixo(p->left); // chama a fun��o Posfixo recursivamente, passando o n� filho esquerdo de p como par�metro
        Posfixo(p->right); // chama a fun��o Posfixo recursivamente, passando o n� filho direito de p como par�metro
        visit(p); // chama a fun��o visit, passando o n� p como par�metro
    }
}



int Tree::Inffixo(Node *p) // define uma fun��o chamada Inffixo que recebe um ponteiro para n� como par�metro
{
    if(p != NULL) // se o ponteiro para n� p n�o for nulo
    {
        Inffixo(p->left); // chama a fun��o Inffixo recursivamente, passando o n� filho esquerdo de p como par�metro
        visit(p); // chama a fun��o visit, passando o n� p como par�metro
        Inffixo(p->right); // chama a fun��o Inffixo recursivamente, passando o n� filho direito de p como par�metro
    }
}


int Tree::searchItem(int dado,Node* p) // define uma fun��o chamada searchItem que recebe um valor inteiro e um ponteiro para n� como par�metros
{
    if(p==NULL) // se o ponteiro para n� p for nulo
        return NULL; // retorna nulo
    if (dado==p->getKey()) // se o valor inteiro dado for igual � chave do n� p
        return p->getKey(); // retorna a chave do n� p
    else
        if (dado<p->getKey()) // se o valor inteiro dado for menor que a chave do n� p
            searchItem(dado,p->left); // chama a fun��o searchItem recursivamente, passando o n� filho esquerdo de p como par�metro
        else
            searchItem(dado,p->right); // chama a fun��o searchItem recursivamente, passando o n� filho direito de p como par�metro
}


int Tree::searchItemTree(int dado) // define uma fun��o chamada searchItemTree que recebe um valor inteiro como par�metro
{
    if (!isEmpty()) // se a �rvore n�o estiver vazia
      return searchItem(dado,root); // chama a fun��o searchItem com o valor inteiro dado e o ponteiro para o n� raiz como par�metros e retorna o resultado

    else
      return NULL; // se a �rvore estiver vazia, retorna nulo
}


void Tree::getMinMax(int &minimo, int &maximo) // define uma fun��o chamada getMinMax que recebe duas vari�veis inteiras por refer�ncia
{
    Node *p=root; // define um ponteiro para n� chamado p que aponta para o n� raiz
    while (p->left != NULL) // enquanto houver um n� � esquerda de p
       p=p->left; // avan�a para a esquerda at� encontrar o n� mais � esquerda da �rvore, que ser� o menor valor
    minimo=p->getKey(); // atribui o valor chave do n� mais � esquerda � vari�vel minimo
    p=root; // redefine o ponteiro p para apontar para o n� raiz
    while(p->right!=NULL) // enquanto houver um n� � direita de p
       p=p->right; // avan�a para a direita at� encontrar o n� mais � direita da �rvore, que ser� o maior valor
    maximo=p->getKey(); // atribui o valor chave do n� mais � direita � vari�vel maximo
}



void Tree::breadthSearch()
{
    queue<Node*> fila; // Cria uma fila vazia de ponteiros para n�s.
    Node *p=root; // Define o ponteiro p como a raiz da �rvore.

    if (p!=NULL) // Se a �rvore n�o estiver vazia
    {
       fila.push(p); // Insere o ponteiro p na fila.
       while(!fila.empty()) // Enquanto a fila n�o estiver vazia
       {
           p=fila.front(); // Define p como o primeiro elemento da fila.
           fila.pop(); // Remove o primeiro elemento da fila.
           visit(p); // Chama a fun��o visit() para o n� p.
           if(p->left!=NULL) // Se o n� p tiver um filho esquerdo
              fila.push(p->left); // Insere o filho esquerdo na fila.
           if(p->right!=NULL) // Se o n� p tiver um filho direito
              fila.push(p->right); // Insere o filho direito na fila.
       }
    }
    else
        cout << "Arvore vazia." << endl; // Caso a �rvore esteja vazia, exibe essa mensagem.
}


void Tree::clearNodes(Node* p)
{
queue<Node*> fila; // Declara��o de uma fila para armazenar os n�s a serem deletados.

   cout << "Deletando �rvore..." << endl; // Imprime uma mensagem de aviso que a �rvore est� sendo deletada.

if (!isEmpty()) // Verifica se a �rvore n�o est� vazia.
{
    fila.push(p); // Adiciona o n� raiz na fila.
    while(!fila.empty()) // Enquanto a fila n�o estiver vazia, repita.
    {
        p=fila.front(); // Armazena o primeiro n� da fila na vari�vel p.
        fila.pop(); // Remove o primeiro n� da fila.
        if(p->left!=NULL) // Se o n� tem um filho � esquerda.
            fila.push(p->left); // Adiciona o filho � esquerda na fila.
        if(p->right!=NULL) // Se o n� tem um filho � direita.
            fila.push(p->right); // Adiciona o filho � direita na fila.
        delete p; // Deleta o n� armazenado em p.
        nodes--; // Diminui o contador de n�s da �rvore.
    }
}
else // Se a �rvore estiver vazia.
    cout << "Arvore vazia." << endl; // Imprime uma mensagem de aviso que a �rvore est� vazia.

}

void Tree::iterativePreorder()
{
    stack <Node*> pilha; //cria uma pilha de ponteiros para n�s
    Node *p=root; //inicializa o ponteiro "p" com o n� raiz
    if (p!=NULL) //se a �rvore n�o estiver vazia
    {
        pilha.push(p); //empilha o n� raiz
    }
    while(!pilha.empty()) //enquanto a pilha n�o estiver vazia
    {
        p=pilha.top(); //atribui a "p" o n� que est� no topo da pilha
        pilha.pop(); //remove o n� do topo da pilha
        visit(p); //visita o n� atual
        if  (p->right != NULL) //se o n� atual tiver um filho � direita
            pilha.push(p->right); //empilha o filho � direita do n� atual
        if (p->left != NULL) //se o n� atual tiver um filho � esquerda
            pilha.push(p->left); //empilha o filho � esquerda do n� atual
    }
}


void Tree::iterativePosOrdem()
{
    stack<Node*> pilha;
    Node* p = root;
    Node* last = NULL;
/*
Cria-se uma pilha de ponteiros de n�s, um ponteiro p que ser� usado para
percorrer a �rvore e um ponteiro last que armazenar� o �ltimo n� visitado.
 */
    while (p != NULL || !pilha.empty())
    {
/*
Enquanto p n�o for nulo ou a pilha n�o estiver vazia:
 */
        if (p != NULL)
        {
            pilha.push(p);
            p = p->left;
        }
/*
Se p n�o for nulo, o n� atual � empilhado e p avan�a para seu filho � esquerda.
*/
        else
        {
            Node* aux = pilha.top();
            if (aux->right != NULL && last != aux->right)
            {
                p = aux->right;
            }
            else
            {
                visit(aux);
                last = aux;
                pilha.pop();
            }
        }
/*
Caso contr�rio, o n� no topo da pilha � desempilhado e armazenado em aux.
Se o filho direito de aux n�o for nulo e n�o tiver sido visitado, p avan�a
para o filho direito. Caso contr�rio, aux � visitado e last � atualizado, e p
permanece nulo. O n� aux � removido da pilha.
*/
    }
}
//O loop termina quando a pilha estiver vazia e todos os n�s tiverem sido visitados.

void Tree::iterativeInorder()
{
    stack<Node*> pilha;     // cria uma pilha vazia
    Node* p = root;         // define o n� atual como a raiz da �rvore
    while (p != NULL || !pilha.empty())   // executa enquanto o n� atual n�o for nulo ou a pilha n�o estiver vazia
    {
        while (p != NULL)   // executa enquanto o n� atual n�o for nulo
        {
            pilha.push(p);  // adiciona o n� atual na pilha
            p = p->left;    // define o n� atual como o filho esquerdo do n� atual
        }
        p = pilha.top();    // define o n� atual como o elemento do topo da pilha
        pilha.pop();        // remove o elemento do topo da pilha
        visit(p);           // visita o n� atual
        p = p->right;       // define o n� atual como o filho direito do n� atual
    }
}

// Fun��o que encontra o n� com a menor chave a partir de um n� dado
Node* Tree::minNode(Node* node) {
  Node* current = node;
    while (current->left != NULL) { // Enquanto o n� atual tiver um filho � esquerda
    current = current->left; // Avan�a para o filho � esquerda
        }
    return current; // Retorna o n� com a menor chave
}

// Fun��o para remover um n� por meio da t�cnica de merge
// Recebe a raiz da �rvore e o valor do n� a ser removido
// Usa ponteiro para ponteiro para conseguir modificar a raiz da �rvore
int Tree::removeNodeByMerge(Node*& root, int valor)
{
// Inicializa ponteiros para percorrer a �rvore
Node* p = root;
Node* pai = NULL;

  // Verifica se a �rvore est� vazia
if (root == NULL) {
    cout << "Arvore Vazia" << endl;
}
// Busca pelo n� a ser removido
while (p != NULL && p->getKey() != valor) {
    pai = p;
    if (valor < p->getKey()) {
        p = p->left;
    }
    else {
        p = p->right;
    }
}

// Caso o n� tenha sido encontrado
if (p != NULL) {
    // Caso o n� tenha somente um filho ou nenhum filho
    if (p->left == NULL) {
        Node* temp = p->right;
        if (pai == NULL) {
            root = temp; // Atualiza a raiz da �rvore
        }
        else if (p == pai->left) {
            pai->left = temp; // Atualiza o filho � esquerda do pai
        }
        else {
            pai->right = temp; // Atualiza o filho � direita do pai
        }
        delete p; // Libera a mem�ria alocada para o n�
    }
    else if (p->right == NULL) {
        Node* temp = p->left;
        if (pai == NULL) {
            root = temp; // Atualiza a raiz da �rvore
        }
        else if (p == pai->left) {
            pai->left = temp; // Atualiza o filho � esquerda do pai
        }
        else {
            pai->right = temp; // Atualiza o filho � direita do pai
        }
        delete p; // Libera a mem�ria alocada para o n�
    }
    // Caso o n� tenha dois filhos, utiliza-se a t�cnica de remo��o por merge
    else {
        Node* temp = minNode (p->right); // Encontra o menor n� da sub�rvore direita
        p->setKey(temp->getKey()); // Substitui o valor do n� a ser removido pelo menor valor da sub�rvore direita

        // Percorre a sub�rvore direita a partir do menor n� para encontrar o pai do menor n�
        Node* tempPai = p;
        Node* tempCurrent = p->right;
        while (tempCurrent != temp) {
            tempPai = tempCurrent;
            tempCurrent = tempCurrent->left;
        }

        // Atualiza o filho do pai do menor n� para o filho direito do menor n� (ou NULL)
        if (temp == tempPai->left) {
            tempPai->left = (temp->right != NULL) ? temp->right : NULL;
        } else {
            tempPai->right = (temp->right != NULL) ? temp->right : NULL;
        }

        delete temp; // Libera a mem�ria alocada para o menor n�
    }
  }
}
int Tree::removeNodeByCopy(Node*& root, int valor) {
    Node* p = root; // Cria ponteiro p para a raiz da �rvore
    Node* pai = NULL; // Cria ponteiro pai inicializado como nulo
    while (p != NULL && p->getKey() != valor) { // Percorre a �rvore at� encontrar o n� ou o final da �rvore
        pai = p; // Atualiza o ponteiro pai com o n� anterior
        if (valor < p->getKey()) { // Se o valor a ser removido � menor do que o valor do n� atual
            p = p->left; // Anda para a esquerda na �rvore
        } else {
            p = p->right; // Sen�o, anda para a direita
        }
    }

    if (p == NULL) { // Se o n� n�o foi encontrado
        cout << "Valor n�o encontrado" << endl;
        return 0; // Retorna 0 indicando falha na remo��o
    }

    if (p->left != NULL && p->right != NULL) { // Se o n� tem dois filhos
        Node* minNode = p->right; // Cria ponteiro para o menor n� da sub�rvore direita
        Node* minNodeParent = p; // Cria ponteiro para o pai do menor n�
        while (minNode->left != NULL) { // Percorre a sub�rvore direita at� encontrar o menor n�
            minNodeParent = minNode;
            minNode = minNode->left;
        }

        p->setKey(minNode->getKey()); // Substitui o valor do n� a ser removido pelo menor valor da sub�rvore direita
        p = minNode; // Atualiza o ponteiro p para o n� a ser removido (menor n� da sub�rvore direita)
        pai = minNodeParent; // Atualiza o ponteiro pai para o pai do menor n� da sub�rvore direita
    }

    if (p == root) { // Se o n� a ser removido � a raiz da �rvore
        root = (p->left != NULL) ? p->left : p->right; // Atualiza a raiz com o filho n�o nulo (se houver)
    } else if (p == pai->left) { // Se o n� a ser removido � filho � esquerda do pai
        pai->left = (p->left != NULL) ? p->left : p->right; // Atualiza o filho esquerdo do pai com o filho n�o nulo (se houver)
    } else { // Sen�o, o n� a ser removido � filho � direita do pai
        pai->right = (p->left != NULL) ? p->left : p->right; // Atualiza o filho direito do pai com o filho n�o nulo (se houver)
    }

    delete p; // Remove o n�
    return 1; // Retorna 1 indicando sucesso na remo��o
}

#endif // TREE_H
