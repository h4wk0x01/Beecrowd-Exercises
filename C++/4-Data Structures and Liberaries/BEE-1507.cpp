


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    short int ammount;
    short int test_ammount; 

    int length;
    int test_length;
    int x;

    string str;
    string test_str;

    bool found;

    cin >> ammount;
    for( int i = 0; i < ammount; i++ ){

        cin >> str;
        cin >> test_ammount;

        length = str.length();

        for( int j = 0; j < test_ammount; j++ ){

            cin >> test_str;
            test_length = test_str.length();

            found = false;
            x = 0;
            for( int k = 0; k < length; k++ ){ // Neste loop buscamos pelos 'matchs' dos caracteres.

                if( test_str[x] == str[k] ){
                    x++;
                }

                if( x == test_length ){
                    found = true;
                    break;
                }

            }

            if( found ){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }

        }

    }

    return 0;
}
