#include "LL1Parser.hpp"

LL1Parser::LL1Parser(std::string x) : L(x){
    stack.push_back(-666);
    stack.push_back(0);
    //Parse();
}

int LL1Parser::Parse(){

    int X,exit_code = 0;
    int token = getToken();// bota terminales
    std::cout<<std::left<<std::setw(60)<<"PILA";std::cout<<"ACCION\n";
    while (!stack.empty() && exit_code == 0)
    {
        printStack();
        X = stack.back();
        //std::cout<<std::left<<std::setw(50)<<L.cadena;
        if (X > 73 || X == -666) //Si X es un terminal o $
        {
            if (X == token)
            {
                stack.pop_back();
                //entrada(token);//cambio en la cadena de entrada
                token = getToken();//consumir token
            }
            else
                exit_code = error();
        }
        else if (X >= 0 && X <= 73){
            if (X == 73)//si es una produccion vacia o 
                stack.pop_back();
            else if (!T.checkProductionExists(X,T.LL1TAS_getColumna(token))){//si existe interserccion
                stack.pop_back();
                std::vector<int> produccion = T.getProduction(X,T.LL1TAS_getColumna(token));
                std::cout<<"\t"<<symbol(X)<<"->";
                for (auto i = produccion.end()-1; i != produccion.begin()-1; i--)
                    stack.push_back(*i);
                for (auto i = produccion.begin(); i != produccion.end(); i++)
                    std::cout<<symbol(*i);
            }
            else if (T.checkProductionExists(X,T.LL1TAS_getColumna(token)))//si no existe entonces error
                exit_code = error();
            
        }
        std::cout<<std::endl;
    }
    //std::cout<<"ENTRADA ACEPTADA\n";
    std::cout<<"exit code "<<exit_code<<"\n";
    return exit_code;
}
//retorna el token devuelto por el lexer
int LL1Parser::getToken(){
    return L.AFD_MAIN();
}
//imprime toda la pila
void LL1Parser::printStack(){
    /*
    for (auto i = stack.end()-1; i != stack.begin()-1 ; i--)
        std::cout<<symbol(*i)<<" ";
    std::cout<<"\n";
    */
    std::string p;
    for (auto i = stack.end()-1; i != stack.begin()-1 ; i--)
    {   
        p +=  symbol(*i);
    }
    std::cout<<std::left<<std::setw(50)<<p;
}

//retorna el simbolo Vn o Vt a imprimir
std::string LL1Parser::symbol(int x){
    switch (x)
    {
        //No terminales 
        case 0: return "<S>";
        case 1: return "<constantes>";
        case 2: return "<mas_constante>";
        case 3: return "<constante>";
        case 4:	return "<clase_principal>";
        case 5:	return "<clase>";
        case 6:	return "<clase_cuerpo>";
        case 7:	return "<funcion>";
        case 8:	return "<atributos>";
        case 9:	return "<list_identificadores>";
        case 10: return "<list_identificadores'>";
        case 11: return "<modo_id>";
        case 12: return "<modo_declarar_arr>";
        case 13: return "<modo_declarar> ";
        case 14: return "<list_const>";
        case 15: return "<list_const'>";
        case 16: return "<declarar>";
        case 17: return "<constructores>";
        case 18: return "<constructores'>";
        case 19: return "<constructor>";
        case 20: return "<metodos>";
        case 21: return "<tipo_metodo>";
        case 22: return "<con_retorno>";
        case 23: return "<sin_retorno>";
        case 24: return "<argumentos>";
        case 25: return "<argumentos'>";
        case 26: return "<parametros>";
        case 27: return "<parametros'>";
        case 28: return "<nuevo_objeto>";
        case 29: return "<llamar>";
        case 30: return "<llamar_miembro>";
        case 31: return "<llamar_miembro'>";
        case 32: return "<asignacion>";
        case 33: return "<modo_asignar>";
        case 34: return "<otro_modo>";
        case 35: return "<n>";
        case 36: return "<expresion_condicional>";
        case 37: return "<expresion_o_condicional>";
        case 38: return "<expresion_y_condicional>";
        case 39: return "<expresion_y_condicional�>";
        case 40: return "<expresion_!_negancion>";
        case 41: return "<expresion_!_negancion�>";
        case 42: return "<expresion_equivalencia>";
        case 43: return "<expresion_equivalencia�>";
        case 44: return "<expresion_relacion>";
        case 45: return "<expresion_relacion'>";
        case 46: return "<expresion_adicion>";
        case 47: return "<expresion_adicion�>";
        case 48: return "<expresion_multiplicacion>";
        case 49: return "<expresion_multiplicacion'>";
        case 50: return "<expresion_postfija>";
        case 51: return "<para>";
        case 52: return "<inicializacion>";
        case 53: return "<para_condicion>";
        case 54: return "<incremento>";
        case 55: return "<si_sino>";
        case 56: return "<sino>";
        case 57: return "<mientras>";
        case 58: return "<eleccion>";
        case 59: return "<eleccion_cuerpo>";
        case 60: return "<eleccion_def>";
        case 61: return "<modo>";
        case 62: return "<instrucciones>";
        case 63: return "<sentencia>";
        case 64: return "<instruccion>";
        case 65: return "<lectura>";
        case 66: return "<escritura>";
        case 67: return "<op_relac>";
        case 68: return "<op_aritmetico_simple>";
        case 69: return "<op_aritmetico_doble>";
        case 70: return "<tipo>";
        case 71: return "<const>";
        case 72: return "<identificador>";
		case 73: return "";
        

        //Simbolos de entrada (Vt+$)

        case 100: return "entero";
        case 101: return "flotante";
        case 102: return "caracter";
        case 103: return "cadena";
        case 104: return "booleano";
        case 105: return "vacio";
        case 106: return "principal";
        case 107: return "clase";
        case 108: return "Funcion";
        case 109: return "llamar";
        case 110: return "objeto";
        case 111: return "para";
        case 112: return "mientras";
        case 113: return "si";
        case 114: return "sino";
        case 115: return "eleccion";
        case 116: return "break";
        case 117: return "caso";
        case 118: return "predeterminado";
        case 119: return "leer";
        case 120: return "escribir";
        case 121: return "rtrn";
        case 122: return "constante";
        case 123: return "true";
        case 124: return "false";
        case 125: return "nuevo";

        case 200: return ".";
        case 201: return "++";
        case 202: return "--";
        case 203: return "*";
        case 204: return "/";
        case 205: return "-";
        case 206: return "+";
        case 207: return "<";
        case 208: return ">";
        case 209: return "=>";
        case 210: return "=<";
        case 211: return "==";
        case 212: return "!=";
        case 213: return "!";
        case 214: return "&&";
        case 215: return "||";
        case 216: return "(";
        case 217: return ")";
        case 218: return "[";
        case 219: return "]";
        case 220: return "{";
        case 221: return "}";
        case 222: return ",";
        case 223: return ";";
        case 224: return "<=";
        case 225: return ":";

        case 300: return "k_entero";
        case 301: return "k_real";
        case 302: return "letra";
        case 303: return "frase";

        case 400: return "id";
        case -666: return "$";
        default: return "error";
                
    }
}

void LL1Parser::entrada(int token){
    size_t i = 0;
    char c;
    std::string buffer = "";
    std::string aux = "";
    while (aux == "")
    {
        c = L.cadena[i];
        if(c != ' '){
            buffer += c;
            if (buffer == symbol(token))
            {
                ++i;
                for (;i < L.cadena.size(); i++)
                {
                    c = L.cadena[i];
                    aux += c;
                }
                L.cadena = aux;
            }
        }
        ++i;
    }
}