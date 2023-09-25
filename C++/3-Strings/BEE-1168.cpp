/*
AUTORES: Gabriel Gomides Dutra Paiva, Joao Gabriel Sena Fernandes
UNIVERSIDADE: PUC MINAS
COMPLEXIDADE:
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    int length;
    int counter;
    string aux;
    int vector[] = {6,2,5,5,4,5,6,3,7,6};

    cin >> N;

    for( int i=0; i<N; i++ ){
        counter = 0;
        cin >> aux;
        length = aux.size();
        for( int j=0; j<length; j++ ){
            switch( aux[j] ){
                case '0':
                    counter+=vector[0];
                    break;
                case '1':
                    counter+=vector[1];
                    break;
                case '2':
                    counter+=vector[2];
                    break;
                case '3':
                    counter+=vector[3];
                    break;
                case '4':
                    counter+=vector[4];
                    break;
                case '5':
                    counter+=vector[5];
                    break;
                case '6':
                    counter+=vector[6];
                    break;
                case '7':
                    counter+=vector[7];
                    break;
                case '8':
                    counter+=vector[8];
                    break;
                case '9':
                    counter+=vector[9];
                    break;
                default:
                    //cout << "Invalid number";
                    break;
            } // end switch case
        } // internal loop
        cout << counter << " leds" << endl;
    } // external loop
    return 0;
}
