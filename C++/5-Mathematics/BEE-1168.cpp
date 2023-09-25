


#include <string>
#include <iostream>

using namespace std;

// Guardar qauntidade de LED´s para cada número
int led_vec[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){

    int ammount, led_counter, i = 0;
    cin >> ammount;
    string numero = "";

    while( i < ammount ){

        cin >> numero;

        int length = numero.length();
        led_counter = 0; // Reseta contador para cada string

        for( int j = 0; j < length; j++ ){

            char sChar = numero[j]; // Pegar char da posição atual
            int charToInt = sChar - '0'; // Converte o char para inteiro
            led_counter += led_vec[charToInt]; // Pular para o vetor na posição do caractere atual e somar sua respectiva quantidade de LED´s

        }

        cout << led_counter << " leds" << "\n";

        i++;

    }

    return 0;

}
