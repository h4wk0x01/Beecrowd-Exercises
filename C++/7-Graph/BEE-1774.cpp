

#include <string.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
Encontrar o SET de um determinado vértice do grafo
- Parâmetros:
S -> Matriz de subsets do grafo
V -> Número de vértices do grafo
num -> Vértice a ser localizado
*/
short int findSet( vector<vector<short int>> S, short int V, short int num ){

    short int set = -1;
    bool foundSet = false;

    int i = 0;
    while( i < V && foundSet == false ){
        int size = S[i].size();
        for( int j = 0; j < size; j++ ){
            if( S[i][j] == num ){
                set = i;
                foundSet = true;
                break;
            }
        }
        i++;
    }
    return set;

}

/*
Função para unir vértices do grafo. Cria uma aresta entre eles, unindo os subsets de X e Y
- Parâmetros:
S -> Matriz de sets
V -> Número de vértices do grafo
X, Y -> Primeiro e segundo elementos a serem unidos por aresta
*/
vector<vector<short int>> setUnion( vector<vector<short int>> S, short int V, short int x, short int y ){

    short int setX = findSet(S,V,x); 
    short int setY = findSet(S,V,y);

    short int sizeX = S[setX].size();

    // Apagar todos elementos do setX e adicioná-los no setY. ( UNION )
    int i = 0;
    while( i < sizeX ){
        S[setY].push_back(S[setX][i]);
        i++;
    }
    S[setX].clear();

    return S;

}

/*
Implementação do algoritmo de Kruskal
- Parâmetros:
M -> Matriz de adjacência
V -> Número de vértices do grafo
*/
short int Kruskal( vector<vector<short int>> M, short int V ){

    int minimo = 0; // Para armazenar a MST
    vector<vector<short int>> sets(V, vector<short int>(V));  // Criando vetor de SubSets

    // Preenche o vetor. ( Cria uma floresta )
    int w = 1;
    for(int p = 0; p < V; p++){
        sets[p][0] = w;
        w++;
    }

    short int x,y = -1;
    short int arestas = 0;
    while( arestas != V - 1 ){ // Número mínimo de arestas para tornar o grafo CONEXO
        short int menor = SHRT_MAX;
        for( int i = 0; i < V; i++ ){
            for( int j = 0; j < V; j++ ){
                if( M[i][j] < menor && findSet(sets,V,i+1) != findSet(sets,V,j+1)  ){ // Se for menor que o valor atual E SE i e j não estiverem no mesmo SubSet
                    menor = M[i][j];
                    x = i+1; y = j+1; // Salva os valores de X e Y para realizar a união 
                    // ( +1 para representar um grafo que começa com o vértice de número 1 ( e não zero ) )
                }
            }
        }

        sets = setUnion(sets,V,x,y); // Unir X e Y
        arestas++; // Ao unir criamos uma aresta
        minimo += menor;

    }
    return minimo;
}

int main(){

    short int num_vertices, num_arestas;
    short int router_a, router_b, price;

    short int resp;

    cin >> num_vertices;
    cin >> num_arestas;

    vector<vector<short int>> adjacency_matrix(60, vector<short int>(60)); // Declarando matriz de adjacência. A matriz é inicializada com '0' em todas as posições.
    for( int i = 0; i < num_vertices; i++ ){
        for( int j = 0; j < num_vertices; j++ ){
            adjacency_matrix[i][j] = SHRT_MAX; // Define a posição da matriz como o MAIOR número do tipo 'SHORT INT' em C++ ( 32767 )
        }
    }

    for( int k = 0; k < num_arestas; k++ ){
        cin >> router_a; cin >> router_b; cin >> price; // Ler par de vertices ( roteadores ) e peso da aresta ( preço do cabo ).
        adjacency_matrix[router_a-1][router_b-1] = price; // Criamos uma aresta ligando os dois vértices na matriz de adjacência, representando o seu peso.
        adjacency_matrix[router_b-1][router_a-1] = price; // Fazer o mesmo para o inverso ( pois caso contrário o grafo representado pela matriz de adjacência seria direcionado )
    }

    resp = Kruskal(adjacency_matrix, num_vertices);
    cout << resp << '\n';

    //system("PAUSE");

    return 0;
}
