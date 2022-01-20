#include <bits/stdc++.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int estado = 0;
    char ch;
    string lex = "";
    int band = 1;
    ifstream archivo;

    archivo.open("input.txt");

    if(!archivo.is_open()){
        cout << "El archivo no se pudo abrir." << endl;
        exit(0);
    }

    while(!archivo.eof()){
        ch = archivo.get();
        band = 1;
        // cout << estado << endl;
        switch (estado)
        {
       
        case 0:
            if(ch == '-'){
                estado = 1;
            }
            else if(ch == '0'){
                estado = 3;
            }
            else if(ch >= '1' && ch <= '9'){
                estado = 2;
            }
            else{
                estado = -1;
            }
            break;

        case 1:
            if(ch == '0'){
                estado = 3;
            }
            else if(ch >= '1' && ch <= '9'){
                estado = 2;
            }
            else{
                estado = -1;
            }
            break;

        case 2:
            if(ch >= '0' && ch <= '9'){
                estado = 2;
                lex.push_back(ch);
                band = 0;
            }
            else if(ch == '.'){
                estado = 6;
            }
            else if(ch == 'E'){
                estado = 7;
            }
            else{
                cout << "Numero decimal: " << lex << endl;
                estado = -1;
            }
            break;

        case 3:
            if(ch >= '1' && ch <= '7'){
                estado = 4;
            }
            else if(ch == 'X'){
                estado = 5;
            }
            else if(ch == '.'){
                estado = 6;
            }
            else{
                estado = -1;
            }
            break;

        case 4:
            if(ch >= '1' && ch <= '7'){
                estado = 4;
                lex.push_back(ch);
                band = 0;
            }
            else{
                cout << "Numero octal: " << lex << endl;
                estado = -1;
            }
            break;

        case 5:
            if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F')){
                estado = 5;
                lex.push_back(ch);
                band = 0;
            }
            else{
                cout << "Numero hexadecimal: " << lex << endl;
                estado = -1;
            }
            break;

        case 6:
            if(ch >= '0' && ch <= '9'){
                estado = 6;
                lex.push_back(ch);
                band = 0;
            }
            else if(ch == 'E'){
                estado = 7;
            }
            else{
                cout << "Numero flotante: " << lex << endl;
                estado = -1;
            }
            break;

        case 7:
            if(ch == '+' || ch == '-'){
                estado = 8;
            }
            else{
                estado = -1;
            }
            break;

        case 8:
            if(ch >= '0' && ch <= '9'){
                estado = 8;
                lex.push_back(ch);
                band = 0;
            }
            else{
                cout << "Numero exponencial: " << lex << endl;
                estado = -1;
            }
            break;
        
        default:
            lex = "";
            estado = 0;
            break;
        }
        if(band){
            lex = lex + ch;
        }
    }

    archivo.close();

    return 0;
}