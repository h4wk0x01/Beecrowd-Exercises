
/*
Solução para calculo e soma de fatoriais a partir de n entradas.
Complexidade: O(n2)
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    long long i = 0.0; 

    // Tipo de variável long long utilizado para poder representar um valor com 15 dígitos.
    long long first_value = 0.0;
    long long second_value = 0.0;
    long long sum = 0.0;

    // Enquanto houverem entradas
    while( cin >> first_value ){

        cin >> second_value;

        // Se o valor for diferente de 0 ( porque fatorial de 0 é 1 )
        if ( first_value != 0 ){

            // Calculando o fatorial do primeiro número
            for ( i = first_value-1; i >= 1 ; i-- ){
                first_value = first_value * i; // Multiplica o valor sequenciamente por i
            }

        }else{
            first_value = 1;
        }

        // Repetir procedimento anterior para o segundo valor de entrada
        if ( second_value != 0 ){

            for ( i = second_value-1; i >= 1 ; i-- ){
                second_value = second_value * i;
            }

        }else{
            second_value = 1;
        }

        sum = first_value + second_value; // Aqui somamos os dois valores fatoriais obtidos.

        cout << sum << '\n'; // Mostrar resposta e pular linha.

    }

    return 0;
}
