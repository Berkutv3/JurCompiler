#include "LL1TAS.hpp"
/*
LL1TAS::LL1TAS(){
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            T[i][j] = "";
    
    T[0][0] = "<tipo>; <cuerpo>";T[0][10] = "<tipo>; <cuerpo>";T[0][11] = "<tipo>; <cuerpo>";
    T[1][0] = "<tipo>; <cuerpo>";T[1][10] = "<tipo>; <cuerpo>";T[1][11] = "<tipo>; <cuerpo>";T[1][14] = "&";
    T[2][0] = "<para>";T[2][10] = "<corta>";T[2][11] = "<corta>";
    T[3][0] = "for <inicialización> <modo_para>";
    T[4][13] = "<identificador> := <init> to <init> do";
    T[5][12] = "<const>";T[5][13] = "<identificador>";
    T[6][5] = "<largo>";T[6][10] = "<corta>";T[6][11] = "<corta>";
    T[7][5] = "begin <inst> end";
    T[8][0] = "<tipo>; <inst>";T[8][6] = "&";
    T[9][10] = "<modo> (<lista_expresiones>)";T[9][11] = "<modo> (<lista_expresiones>)";
    T[10][13] = "<identificador> <expresion>";
    T[11][8] = "&";T[11][9] = ", <identificador> <expresion>";
    T[12][10] = "write";T[12][11] = "read";
    T[13][12] = "entero";
    T[14][13] = "id";

    
    std::vector<int> produccion = {3,202,2};
    TA[0][0];

}*/

/**
 *  Devuelve la columna a la que pertenece el simbolo de entrada
 * 
 * 'for': 0
 * ':=': 1
 * 'to': 2
 * 'do': 3
 * ';': 4
 * 'begin': 5
 * 'end': 6
 * '(': 7
 * ')': 8
 * ',': 9
 * 'write': 10
 * 'read': 11
 * 'entero': 12
 * 'id': 13
 * '$': 14
 * 
*/
int LL1TAS::LL1TAS_getColumna(int token){
    //Fila terminales - LL1TAS ADP
    switch (token)
    {
    	case 100: return 0;
    	case 101: return 1;
    	case 102: return 2;
    	case 103: return 3;
    	case 104: return 4;
    	case 105: return 5;
    	case 106: return 6;
    	case 107: return 7;
    	case 108: return 8;
    	case 109: return 9;
    	case 110: return 10;
    	case 111: return 11;
    	case 112: return 12;
    	case 113: return 13;
    	case 114: return 14;
    	case 115: return 15;
    	case 116: return 16;
    	case 117: return 17;
    	case 118: return 18;
    	case 119: return 19;
    	case 120: return 20;
    	case 121: return 21;
    	case 122: return 22;
    	case 224: return 23;
    	case 300: return 24;
    	case 301: return 25;
    	case 302: return 26;
    	case 303: return 27;
    	case 123: return 28;
    	case 124: return 29;
        case 125: return 55;
    	case 200: return 30;
    	case 201: return 31;
    	case 202: return 32;
    	case 203: return 33;
    	case 204: return 34;
    	case 205: return 35;
    	case 206: return 36;
    	case 207: return 37;
    	case 208: return 38;
    	case 209: return 39;
    	case 210: return 40;
    	case 211: return 41;
    	case 212: return 42;
    	case 213: return 43;
    	case 214: return 44;
    	case 215: return 45;
    	case 216: return 46;
    	case 217: return 47;
    	case 400: return 48;
    	case 218: return 49;
    	case 219: return 50;
    	case 220: return 51;
    	case 221: return 52;
    	case 222: return 53;
    	case 223: return 54;
        case 225: return 56;
    	case -666: return 57;
		default: return -1;
	}
}

std::vector<int> LL1TAS::getProduction(int row, int col){
    return PT[row][col];
}
/*
bool LL1TAS::checkProduction(int row, int col){
    return LL1TASmatrix[row][col].empty();
}
*/

bool LL1TAS::checkProductionExists(int row, int col){
    std::vector<int> x = PT[row][col];
    return x.empty();
}