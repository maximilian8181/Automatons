#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int estado = 0;
    int band = 1;
    char ch;
    string lex = "";
    ifstream archivo;
    stack<char>pila;

    pila.push('Z');

    archivo.open("input.txt");

    if(!archivo.is_open()){
        cout << "El archivo no se pudo abrir." << endl;
        exit(0);
    }

    while(!archivo.eof()){
        ch = archivo.get();
        band = 1;
        cout << estado << " ";
        if(estado == -1){
            cout << endl << "Cadena no aceptada" << endl;
            break;
        }
        switch (estado)
        {
       
        case 0:
            if((ch >= 'A' && ch <= 'Z') && (pila.top() == 'Z')){
                pila.pop();
                pila.push('X');
                estado = 1;
            }
            else{
                estado = -1;
            }
            break;

        case 1:
            if(((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) && (pila.top() == 'X')){
                pila.pop();
                pila.push('X');
                estado = 1;
            }
            else if((ch == '=') && (pila.top() == 'X')){
                pila.pop();
                pila.push('P');
                pila.push('X');
                estado = 2;
            }
            else if(ch == ' '){
                estado = 6;
            }
            else{
                estado = -1;
            }
            break;

        case 2:
            if((ch >= 'A' && ch <= 'Z') && (pila.top() == 'X')){
                pila.pop();
                pila.push('V');
                estado = 3;
            }
            else if((ch >= '0' && ch <= '9') && (pila.top() == 'X')){
                pila.pop();
                pila.push('N');
                estado = 3;
            }
            else if((ch == '(') && (pila.top() == 'X')){
                pila.pop();
                pila.push('(');
                pila.push('X');
                estado = 2;
            }
            else if(ch == ' '){
                estado = 2;
            }
            else{
                estado = -1;
            }
            break;

        case 3:
            if(((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) && (pila.top() == 'V')){
                pila.pop();
                pila.push('V');
                estado = 3;
            }
            else if((ch >= '0' && ch <= '9') && (pila.top() == 'N')){
                pila.pop();
                pila.push('N');
                estado = 3;
            }
            else if((ch == ')') && (pila.top() == 'V' || pila.top() == 'N')){
                pila.pop();
                if(pila.top() == '('){
                    pila.pop();
                    estado = 3;
                }
                else{
                    estado = -1;
                }
            }
            else if(ch == ';'){
                if(pila.top() == 'V'){
                    pila.pop();
                    estado = 4;
                }
                else if(pila.top() == 'P'){
                    pila.pop();
                    pila.push('P');
                    estado = 4;
                }
                else if(pila.top() == 'N'){
                    pila.pop();
                    estado = 4;
                }
                else{
                    estado = -1;
                }
            }
            else if(ch == ' '){
                estado = 7;
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){
                if(pila.top() == 'P'){
                    pila.pop();
                    pila.push('P');
                    pila.push('X');
                    estado = 2;
                }
                else if(pila.top() == '('){
                    pila.pop();
                    pila.push('(');
                    pila.push('X');
                    estado = 2;
                }
                else if(pila.top() == 'V'){
                    pila.pop();
                    pila.push('X');
                    estado = 2;
                }
                else if(pila.top() == 'N'){
                    pila.pop();
                    pila.push('X');
                    estado = 2;
                }
                else{
                    estado = -1;
                }
            }
            else{
                estado = -1;
            }
            break;

        case 4:
            if((ch = ' ') && (pila.top() == 'P')){
                pila.top();
                pila.push('Z');
                estado = 5;
            }
            else{
                estado = -1;
            }
            break;

        case 5:
            if(pila.top() == 'Z'){
                cout << endl << "Cadena aceptada" << endl;
                estado = 5;
                lex.push_back(ch);
                band = 0;
            }
            else{
                estado = -1;
            }
            break;

        case 6:
            if(ch == ' '){
                estado = 6;
            }
            else if((ch == '=') && (pila.top() == 'X')){
                pila.pop();
                pila.push('P');
                pila.push('X');
                estado = 2;
            }
            else{
                estado = -1;
            }
            break;

        case 7:
            if(ch == ' '){
                estado = 7;
            }
            else if(ch == ';'){
                if(pila.top() == 'P'){
                    pila.top();
                    pila.push('P');
                    estado = 8;
                }
                else if(pila.top() == 'N'){
                    pila.pop();
                    estado = 8;
                }
                else if(pila.top() == 'V'){
                    pila.pop();
                    estado = 8;
                }
                else{
                    estado = -1;
                }
            }
            else{
                estado = -1;
            }
            break;

        case 8:
            if((ch == ' ') && (pila.top() == 'P')){
                pila.pop();
                pila.push('Z');
                estado = 5;
            }
            else{
                estado = -1;
            }
            break;
        
        default:
            lex = "";
            estado = 0;
            break;
        }
        /*if(band){
            lex = lex + ch;
        }*/
    }

    archivo.close();

    return 0;
}