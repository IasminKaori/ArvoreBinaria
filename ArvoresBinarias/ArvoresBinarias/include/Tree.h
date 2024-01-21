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

void Tree::clearTree() // define uma função chamada clearTree na classe Tree
{
    clearNodes(root); // chama a função recursiva clearNodes, passando o nó raiz como parâmetro
    root=NULL; // define que a raiz da árvore é NULL
    nodes=0; // zera a contagem de nós da árvore
}

bool Tree::isEmpty() // define uma função booleana chamada isEmpty na classe Tree
{
    return root==NULL; // retorna true se a raiz da árvore for NULL, caso contrário retorna false
}



void Tree::visitPreFixada() // define uma função chamada visitPreFixada na classe Tree
{
    stack<Node*> pilha; // cria uma pilha de ponteiros para nó
    Node* p = root; // cria um ponteiro para nó chamado p e o inicializa com o nó raiz da árvore

    while (p != NULL || !pilha.empty()) // enquanto p não for nulo OU a pilha não estiver vazia
    {
        if (p != NULL) { // se p não for nulo
            visit(p); // chama a função visit, passando o nó p como parâmetro
            pilha.push(p); // empilha o nó p na pilha
            p = p->left; // define p como o nó filho esquerdo de p
        }
        else { // se p for nulo
            p = pilha.top(); // define p como o nó que está no topo da pilha
            pilha.pop(); // remove o nó do topo da pilha
            p = p->right; // define p como o nó filho direito do nó anterior
        }
    }
}


void Tree::visit(Node* p) // define uma função chamada visit que recebe um ponteiro para nó como parâmetro
{
    cout << p->getKey() << ' '; // imprime a chave do nó na tela, seguido de um espaço em branco
}

void Tree::insertItem(int dado) // define uma função chamada insertItem na classe Tree, que recebe um inteiro como parâmetro
{
    Node *p=root; // cria um ponteiro para nó chamado p e o inicializa com o nó raiz da árvore
    Node *prev=NULL; // cria um ponteiro para nó chamado prev e o inicializa como nulo

    if(isEmpty()) // se a árvore estiver vazia
        root=new Node(dado); // cria um novo nó com o dado passado como parâmetro e o define como raiz da árvore
    else // se a árvore não estiver vazia
    {
        while(p!=NULL) // enquanto p não for nulo
        {
            prev=p; // define prev como p
            if(prev->getKey()<dado) // se a chave do nó prev for menor que o dado passado como parâmetro
                p=p->right; // define p como o nó filho direito de p
            else // caso contrário
                p=p->left; // define p como o nó filho esquerdo de p
        }
        if (prev->getKey()<dado) // se a chave do nó prev for menor que o dado passado como parâmetro
            prev->right = new Node(dado); // cria um novo nó com o dado passado como parâmetro e o define como filho direito do nó prev
        else // caso contrário
            prev->left = new Node(dado); // cria um novo nó com o dado passado como parâmetro e o define como filho esquerdo do nó prev
    }

    nodes++; // incrementa o contador de nós da árvore
}



int Tree::Prefixo(Node *p) // define uma função chamada Prefixo que recebe um ponteiro para nó como parâmetro
{
     if(p != NULL) // se o ponteiro para nó p não for nulo
    {
        visit(p); // chama a função visit, passando o nó p como parâmetro
        Prefixo(p->left); // chama a função Prefixo recursivamente, passando o nó filho esquerdo de p como parâmetro
        Prefixo(p->right); // chama a função Prefixo recursivamente, passando o nó filho direito de p como parâmetro
    }
}



int Tree::Posfixo(Node *p) // define uma função chamada Posfixo que recebe um ponteiro para nó como parâmetro
{
    if(p != NULL) // se o ponteiro para nó p não for nulo
    {
        Posfixo(p->left); // chama a função Posfixo recursivamente, passando o nó filho esquerdo de p como parâmetro
        Posfixo(p->right); // chama a função Posfixo recursivamente, passando o nó filho direito de p como parâmetro
        visit(p); // chama a função visit, passando o nó p como parâmetro
    }
}



int Tree::Inffixo(Node *p) // define uma função chamada Inffixo que recebe um ponteiro para nó como parâmetro
{
    if(p != NULL) // se o ponteiro para nó p não for nulo
    {
        Inffixo(p->left); // chama a função Inffixo recursivamente, passando o nó filho esquerdo de p como parâmetro
        visit(p); // chama a função visit, passando o nó p como parâmetro
        Inffixo(p->right); // chama a função Inffixo recursivamente, passando o nó filho direito de p como parâmetro
    }
}


int Tree::searchItem(int dado,Node* p) // define uma função chamada searchItem que recebe um valor inteiro e um ponteiro para nó como parâmetros
{
    if(p==NULL) // se o ponteiro para nó p for nulo
        return NULL; // retorna nulo
    if (dado==p->getKey()) // se o valor inteiro dado for igual à chave do nó p
        return p->getKey(); // retorna a chave do nó p
    else
        if (dado<p->getKey()) // se o valor inteiro dado for menor que a chave do nó p
            searchItem(dado,p->left); // chama a função searchItem recursivamente, passando o nó filho esquerdo de p como parâmetro
        else
            searchItem(dado,p->right); // chama a função searchItem recursivamente, passando o nó filho direito de p como parâmetro
}


int Tree::searchItemTree(int dado) // define uma função chamada searchItemTree que recebe um valor inteiro como parâmetro
{
    if (!isEmpty()) // se a árvore não estiver vazia
      return searchItem(dado,root); // chama a função searchItem com o valor inteiro dado e o ponteiro para o nó raiz como parâmetros e retorna o resultado

    else
      return NULL; // se a árvore estiver vazia, retorna nulo
}


void Tree::getMinMax(int &minimo, int &maximo) // define uma função chamada getMinMax que recebe duas variáveis inteiras por referência
{
    Node *p=root; // define um ponteiro para nó chamado p que aponta para o nó raiz
    while (p->left != NULL) // enquanto houver um nó à esquerda de p
       p=p->left; // avança para a esquerda até encontrar o nó mais à esquerda da árvore, que será o menor valor
    minimo=p->getKey(); // atribui o valor chave do nó mais à esquerda à variável minimo
    p=root; // redefine o ponteiro p para apontar para o nó raiz
    while(p->right!=NULL) // enquanto houver um nó à direita de p
       p=p->right; // avança para a direita até encontrar o nó mais à direita da árvore, que será o maior valor
    maximo=p->getKey(); // atribui o valor chave do nó mais à direita à variável maximo
}



void Tree::breadthSearch()
{
    queue<Node*> fila; // Cria uma fila vazia de ponteiros para nós.
    Node *p=root; // Define o ponteiro p como a raiz da árvore.

    if (p!=NULL) // Se a árvore não estiver vazia
    {
       fila.push(p); // Insere o ponteiro p na fila.
       while(!fila.empty()) // Enquanto a fila não estiver vazia
       {
           p=fila.front(); // Define p como o primeiro elemento da fila.
           fila.pop(); // Remove o primeiro elemento da fila.
           visit(p); // Chama a função visit() para o nó p.
           if(p->left!=NULL) // Se o nó p tiver um filho esquerdo
              fila.push(p->left); // Insere o filho esquerdo na fila.
           if(p->right!=NULL) // Se o nó p tiver um filho direito
              fila.push(p->right); // Insere o filho direito na fila.
       }
    }
    else
        cout << "Arvore vazia." << endl; // Caso a árvore esteja vazia, exibe essa mensagem.
}


void Tree::clearNodes(Node* p)
{
queue<Node*> fila; // Declaração de uma fila para armazenar os nós a serem deletados.

   cout << "Deletando Árvore..." << endl; // Imprime uma mensagem de aviso que a árvore está sendo deletada.

if (!isEmpty()) // Verifica se a árvore não está vazia.
{
    fila.push(p); // Adiciona o nó raiz na fila.
    while(!fila.empty()) // Enquanto a fila não estiver vazia, repita.
    {
        p=fila.front(); // Armazena o primeiro nó da fila na variável p.
        fila.pop(); // Remove o primeiro nó da fila.
        if(p->left!=NULL) // Se o nó tem um filho à esquerda.
            fila.push(p->left); // Adiciona o filho à esquerda na fila.
        if(p->right!=NULL) // Se o nó tem um filho à direita.
            fila.push(p->right); // Adiciona o filho à direita na fila.
        delete p; // Deleta o nó armazenado em p.
        nodes--; // Diminui o contador de nós da árvore.
    }
}
else // Se a árvore estiver vazia.
    cout << "Arvore vazia." << endl; // Imprime uma mensagem de aviso que a árvore está vazia.

}

void Tree::iterativePreorder()
{
    stack <Node*> pilha; //cria uma pilha de ponteiros para nós
    Node *p=root; //inicializa o ponteiro "p" com o nó raiz
    if (p!=NULL) //se a árvore não estiver vazia
    {
        pilha.push(p); //empilha o nó raiz
    }
    while(!pilha.empty()) //enquanto a pilha não estiver vazia
    {
        p=pilha.top(); //atribui a "p" o nó que está no topo da pilha
        pilha.pop(); //remove o nó do topo da pilha
        visit(p); //visita o nó atual
        if  (p->right != NULL) //se o nó atual tiver um filho à direita
            pilha.push(p->right); //empilha o filho à direita do nó atual
        if (p->left != NULL) //se o nó atual tiver um filho à esquerda
            pilha.push(p->left); //empilha o filho à esquerda do nó atual
    }
}


void Tree::iterativePosOrdem()
{
    stack<Node*> pilha;
    Node* p = root;
    Node* last = NULL;
/*
Cria-se uma pilha de ponteiros de nós, um ponteiro p que será usado para
percorrer a árvore e um ponteiro last que armazenará o último nó visitado.
 */
    while (p != NULL || !pilha.empty())
    {
/*
Enquanto p não for nulo ou a pilha não estiver vazia:
 */
        if (p != NULL)
        {
            pilha.push(p);
            p = p->left;
        }
/*
Se p não for nulo, o nó atual é empilhado e p avança para seu filho à esquerda.
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
Caso contrário, o nó no topo da pilha é desempilhado e armazenado em aux.
Se o filho direito de aux não for nulo e não tiver sido visitado, p avança
para o filho direito. Caso contrário, aux é visitado e last é atualizado, e p
permanece nulo. O nó aux é removido da pilha.
*/
    }
}
//O loop termina quando a pilha estiver vazia e todos os nós tiverem sido visitados.

void Tree::iterativeInorder()
{
    stack<Node*> pilha;     // cria uma pilha vazia
    Node* p = root;         // define o nó atual como a raiz da árvore
    while (p != NULL || !pilha.empty())   // executa enquanto o nó atual não for nulo ou a pilha não estiver vazia
    {
        while (p != NULL)   // executa enquanto o nó atual não for nulo
        {
            pilha.push(p);  // adiciona o nó atual na pilha
            p = p->left;    // define o nó atual como o filho esquerdo do nó atual
        }
        p = pilha.top();    // define o nó atual como o elemento do topo da pilha
        pilha.pop();        // remove o elemento do topo da pilha
        visit(p);           // visita o nó atual
        p = p->right;       // define o nó atual como o filho direito do nó atual
    }
}

// Função que encontra o nó com a menor chave a partir de um nó dado
Node* Tree::minNode(Node* node) {
  Node* current = node;
    while (current->left != NULL) { // Enquanto o nó atual tiver um filho à esquerda
    current = current->left; // Avança para o filho à esquerda
        }
    return current; // Retorna o nó com a menor chave
}

// Função para remover um nó por meio da técnica de merge
// Recebe a raiz da árvore e o valor do nó a ser removido
// Usa ponteiro para ponteiro para conseguir modificar a raiz da árvore
int Tree::removeNodeByMerge(Node*& root, int valor)
{
// Inicializa ponteiros para percorrer a árvore
Node* p = root;
Node* pai = NULL;

  // Verifica se a árvore está vazia
if (root == NULL) {
    cout << "Arvore Vazia" << endl;
}
// Busca pelo nó a ser removido
while (p != NULL && p->getKey() != valor) {
    pai = p;
    if (valor < p->getKey()) {
        p = p->left;
    }
    else {
        p = p->right;
    }
}

// Caso o nó tenha sido encontrado
if (p != NULL) {
    // Caso o nó tenha somente um filho ou nenhum filho
    if (p->left == NULL) {
        Node* temp = p->right;
        if (pai == NULL) {
            root = temp; // Atualiza a raiz da árvore
        }
        else if (p == pai->left) {
            pai->left = temp; // Atualiza o filho à esquerda do pai
        }
        else {
            pai->right = temp; // Atualiza o filho à direita do pai
        }
        delete p; // Libera a memória alocada para o nó
    }
    else if (p->right == NULL) {
        Node* temp = p->left;
        if (pai == NULL) {
            root = temp; // Atualiza a raiz da árvore
        }
        else if (p == pai->left) {
            pai->left = temp; // Atualiza o filho à esquerda do pai
        }
        else {
            pai->right = temp; // Atualiza o filho à direita do pai
        }
        delete p; // Libera a memória alocada para o nó
    }
    // Caso o nó tenha dois filhos, utiliza-se a técnica de remoção por merge
    else {
        Node* temp = minNode (p->right); // Encontra o menor nó da subárvore direita
        p->setKey(temp->getKey()); // Substitui o valor do nó a ser removido pelo menor valor da subárvore direita

        // Percorre a subárvore direita a partir do menor nó para encontrar o pai do menor nó
        Node* tempPai = p;
        Node* tempCurrent = p->right;
        while (tempCurrent != temp) {
            tempPai = tempCurrent;
            tempCurrent = tempCurrent->left;
        }

        // Atualiza o filho do pai do menor nó para o filho direito do menor nó (ou NULL)
        if (temp == tempPai->left) {
            tempPai->left = (temp->right != NULL) ? temp->right : NULL;
        } else {
            tempPai->right = (temp->right != NULL) ? temp->right : NULL;
        }

        delete temp; // Libera a memória alocada para o menor nó
    }
  }
}
int Tree::removeNodeByCopy(Node*& root, int valor) {
    Node* p = root; // Cria ponteiro p para a raiz da árvore
    Node* pai = NULL; // Cria ponteiro pai inicializado como nulo
    while (p != NULL && p->getKey() != valor) { // Percorre a árvore até encontrar o nó ou o final da árvore
        pai = p; // Atualiza o ponteiro pai com o nó anterior
        if (valor < p->getKey()) { // Se o valor a ser removido é menor do que o valor do nó atual
            p = p->left; // Anda para a esquerda na árvore
        } else {
            p = p->right; // Senão, anda para a direita
        }
    }

    if (p == NULL) { // Se o nó não foi encontrado
        cout << "Valor não encontrado" << endl;
        return 0; // Retorna 0 indicando falha na remoção
    }

    if (p->left != NULL && p->right != NULL) { // Se o nó tem dois filhos
        Node* minNode = p->right; // Cria ponteiro para o menor nó da subárvore direita
        Node* minNodeParent = p; // Cria ponteiro para o pai do menor nó
        while (minNode->left != NULL) { // Percorre a subárvore direita até encontrar o menor nó
            minNodeParent = minNode;
            minNode = minNode->left;
        }

        p->setKey(minNode->getKey()); // Substitui o valor do nó a ser removido pelo menor valor da subárvore direita
        p = minNode; // Atualiza o ponteiro p para o nó a ser removido (menor nó da subárvore direita)
        pai = minNodeParent; // Atualiza o ponteiro pai para o pai do menor nó da subárvore direita
    }

    if (p == root) { // Se o nó a ser removido é a raiz da árvore
        root = (p->left != NULL) ? p->left : p->right; // Atualiza a raiz com o filho não nulo (se houver)
    } else if (p == pai->left) { // Se o nó a ser removido é filho à esquerda do pai
        pai->left = (p->left != NULL) ? p->left : p->right; // Atualiza o filho esquerdo do pai com o filho não nulo (se houver)
    } else { // Senão, o nó a ser removido é filho à direita do pai
        pai->right = (p->left != NULL) ? p->left : p->right; // Atualiza o filho direito do pai com o filho não nulo (se houver)
    }

    delete p; // Remove o nó
    return 1; // Retorna 1 indicando sucesso na remoção
}

#endif // TREE_H
