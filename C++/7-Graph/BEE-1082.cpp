


#include <bits/stdc++.h>
using namespace std;

#define maxVertices 26 // Número máximo de vértices

// VETORS GLOBAIS
vector<vector<int>> matriz(maxVertices, vector<int>(maxVertices)); // Matriz de adjacência
vector<int> vertices(maxVertices);  // Vértices 'a-z'
vector<int> flag_array(maxVertices); // Flags
vector<char> component_set(0); // Vetor que armazenará os vértices dos subgrafos

/* 
-> Função DFS ( passa pelos vértices de componente(s) de um grafo )
-> Auxiliar para encontrar número de componentes de um grafo
*/
void DFS(int k, int flag, int V){
    flag_array[k] = 1;
    // Rodar por todos os vértices
    for( int i = 0; i < V; i++ ){
        if( matriz[k][i] == 1 ){ // Se for adjacente ao vértice atual
            if( flag_array[i] == -1 ){ // Se a flag do vértice adjacente for = -1
                component_set.push_back(vertices[i]); // Adiciona o vértice encontrado com flag '-1' ao vetor de vértices do componente atual
                DFS(i,flag,V);
            }
        }
    }
}

// Função para encontrar componentes conexos
void componentes(int V){

    // Preencher vetor de vértices de "a-z"
    int aux = 97;
    for( int z = 0; z < V; z++ ){
        vertices[z] = aux;
        aux++;
    }

    // Setar todas as flags como -1
    for( int i = 0; i < V; i++ ){
        flag_array[i] = -1;
    }

    int count = 0;
    for( int k = 0; k < V; k++ ){
        component_set.clear();
        if( flag_array[k] == -1 ){
            cout << '\n';
            component_set.push_back(vertices[k]); // Adiciona o vértice encontrado com flag '-1' ao vetor de vértices do componente atual
            DFS(k,-1,V);
            sort(component_set.begin(), component_set.end());
            for( int z = 0; z < component_set.size(); z++ ){ // Rodar vetor onde estão armazenados os vértices ("a-z") do componente atual
            cout << component_set[z] << ','; // Mostrar vértices na tela
            }
            count++;
        }
    }
    cout << '\n' << count << " connected components\n\n";
}

int main(){

    int N; // Quantidade de casos de teste
    int V; // Vértices
    int E; // Edges (arestas)

    char vA;
    char vB;

    cin >> N;

    for( int i = 0; i < N; i++ ){

        cin >> V;
        cin >> E;

        // Limpar vetores globais
        vertices.clear(); 
        flag_array.clear();
        matriz.clear();
        // Resize de tamanho de vetores globais para número de Vértices (V).
        vertices.resize(V); 
        flag_array.resize(V);
        matriz.resize(V, vector<int>(V));

        for( int j = 0; j < E; j++ ){
            cin >> vA;
            cin >> vB;
            // Adicionando arestas na matriz de adjacência
            matriz[((int)vA)-97][((int)vB)-97] = 1;
            matriz[((int)vB)-97][((int)vA)-97] = 1; // Inverso, grafo não direcionado
        }
        cout << "Case #" << i+1 << ':';
        componentes(V);
    }

    return 0;
}
