#ifndef LEXER_HPP
#define LEXER_HPP
#include <cctype>
#include <iostream>
#include <fstream>
//#include <boost/algorithm/string.hpp>

class Lexer
{
private:
    std::string reservada[26] = {"entero","flotante","caracter","cadena","booleano","vacio","principal","clase","Funcion","llamar",
                                "objeto","para","mientras","si","sino","eleccion","break","caso","predeterminado","leer","escribir",
                                "rtrn","constante","true","false","nuevo"};
    std::string operador[26] = {".","++","--","*","/","-","+","<",">","=>","=<","==","!=","!","&&","||","(",")","[","]","{","}",
                                ",",";","<=",":"};
    std::string file;
    std::string buffer,aux[2];
    int index=0,i,j=0,token,e_principal=400;
    int TABLA_TRANSICION_ID[4][4] = {
        {1,-1,-1,-1},//ESTADO INICIAL
        {1,2,3,4},//ESTADO LETRA
        {1,2,3,4},//ESTADO DIGITO
        {1,2,3,4}//ESTADO GUION BAJO
    };
    
    int TABLA_TRANSICION_CONST[5][5] = {
        {1,-1,3,-1,4},
        {1,2,5,5,5},
        {1,5,5,5,5},//FILA ESTADO FLOAT
        {3,3,5,3,3},//ESTADO CADENA
        {4,4,4,4,5}//FILA ESTADO CARACTER
    };
    

    int AFD_ID(){
        int ESTADO_ACT = 0,ESTADO_SIG;
        aux[0]="",aux[1]="",j=0;
        char c = file[index];
        if (!isalpha(c)){
            return 300;
        }else{
            ESTADO_SIG = TABLA_TRANSICION_ID[ESTADO_ACT][scaner_id(c)];
            for(;;){
                if (ESTADO_SIG == 4){
                    j=0;return 400;
                }
                else{
                    buffer += c;
                    ++index;
                    token = buscar_pal_reserv(buffer);//buscar siempre palabras reservadas
                    if (token != 400){
                        aux[j] = buffer;
                        ++j;
                        buffer = "";
                        //return token;
                    }
                    c = file[index];
                    ESTADO_SIG = TABLA_TRANSICION_ID[ESTADO_SIG][scaner_id(c)];
                    //boost::trim(buffer);
                    trim(buffer);
                    //retorna el numero de AFD para seguir leyendo caracteres y continuar el loop del afd principal
                }
            }
        }
    }

    int AFD_CONST(){
        int ESTADO_ACT = 0, ESTADO_SIG,caracter=0;
        char c = file[index];
        if (!(isdigit(c)) && !(c == '"') && !(c == '@')) {// || c != '"' || c != '@'
            return 200;
        } else {
            ESTADO_SIG = TABLA_TRANSICION_CONST[ESTADO_ACT][scaner_const(c)];
            
            if(ESTADO_SIG == 4)
                caracter = 1;
            
            for (;;){
                if (ESTADO_SIG == 5 && !checkfloat(buffer) && !(c=='"'))
                    return 300;
                else if (ESTADO_SIG == 5 && checkfloat(buffer)&& !(c=='"'))
                    return 301;
                else if (ESTADO_SIG == 5 && c == '"')
                {
                    ++index;
                    return 303;
                }
                else{
                    
                    buffer += c;
                    ++index;
                    c = file[index];
                    ESTADO_SIG = TABLA_TRANSICION_CONST[ESTADO_SIG][scaner_const(c)];
                    //boost::trim(buffer);
                    trim(buffer);
                    
                    if(caracter == 1 && file[index+1] == '@' && buffer.length() <= 1)
                    {
                        ++index;
                        ++index;
                        caracter = 0;
                        return 302;
                    }
                    if(caracter == 1 && c == '@' && buffer.length() <= 1)
                    {
                        ++index;
                        caracter = 0;
                        return 302;
                    }
                }
            }
        }
    }

    int AFD_SIMB(){
        char c = file[index];
        buffer += c;
        token = buscar_operador(buffer);
        c = file[++index];
        buffer += c;
        token = buscar_operador(buffer);
        if (token < 200 || token > 225){
            c = file[--index];
            buffer = "";
            buffer += c;
            token = buscar_operador(buffer);
        }
        return token;
    }

    int scaner_id(char c){
        if (isalpha(c))
            return 0;
        else if (isdigit(c))
            return 1;
        else if (c=='_')
            return 2;
        else
            return 3;
    }

    int scaner_const(char c){
        if (isdigit(c)) 
            return 0;
        else if (c =='.')
            return 1;
        else if (c =='"')
            return 2; 
        else if (c =='@')
            return 4;
        else 
            return 3;
    }

    int buscar_operador(std::string x){
        for (i = 0; i < 26; i++) {
            if(x == operador[i])
                return 200+i;
        }
        return -666;
    }

    int buscar_pal_reserv(std::string x){
        for (i = 0; i < 26; i++) {
            if(x == reservada[i])
                return 100+i;
        }
        return 400;
    }

    bool reserv_check(){
        for (int k = 0; k < 2; k++)
        {
            if (aux[k]=="")
                return false;
        }
        return true;
    }

    bool checkfloat(std::string x){
        char c;
        for (size_t k = 0; k < x.length(); k++)
        {
            c = x[k];
            if (c == '.')
                return true;
        }
        return false;
    }

    void trim(std::string & line){
        int size = static_cast<int>(line.size());
        if(size == 0) return;
        if(size == 1 && !std::isspace(line[0])) return;
        int first = 0;
        for(int k = 0; k < size; ++k){
            if (!std::isspace(line[k])){
                first = k;
                break;
            }
        }
        int last = 0;
        for(int k = size - 1; k >= 0; --k){ // size - 1 could be negative here
            if (!std::isspace(line[k])){
                last = k+1;
                break;
            }
            if(k == 0){
                last = 0;
                break;
            }
        }
        line = line.substr(first, last-first);
    } 

public:
    std::string cadena;
    Lexer(std::string);
    int AFD_MAIN();
};

#endif