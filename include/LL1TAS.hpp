#ifndef LL1TAS_HPP
#define LL1TAS_HPP
#include <iostream>
#include <vector>
#include <unordered_map>

class LL1TAS
{
private:

    std::string T[15][15];

    std::vector<std::vector<std::vector<int>>> LL1TASmatrix;
    std::string Tcol[73] = {"<S>","<constantes>","<mas_constante>","<constante>","<clase_principal>","<clase>","<clase_cuerpo>",
                            "<funcion>","<atributos>","<list_identificadores>","<list_identificadores'>","<modo_id>","<modo_declarar_arr>",
                            "<modo_declarar>","<list_const>","<list_const'>","<declarar>","<constructores>","<constructores'>","<constructor>",
                            "<metodos>","<tipo_metodo>","<con_retorno>","<sin_retorno>","<argumentos>","<argumentos'>","<parametros>",
                            "<parametros'>","<nuevo_objeto>","<llamar>","<llamar_miembro>","<llamar_miembro'>","<asignacion>","<modo_asignar>",
                            "<otro_modo>","<n>","<expresion_condicional>","<expresion_o_condicional>","<expresion_y_condicional>","<expresion_y_condicional’>",
                            "<expresion_!_negancion>","<expresion_!_negancion’>","<expresion_equivalencia>","<expresion_equivalencia’>"
                            "<expresion_relacion>","<expresion_relacion'>","<expresion_adicion>","<expresion_adicion’>","<expresion_multiplicacion>",
                            "<expresion_multiplicacion'>","<expresion_postfija>","<para>","<inicializacion>","<para_condicion>","<incremento>","<si_sino>"
                            "<sino>","<mientras>","<eleccion>","<eleccion_cuerpo>","<eleccion_def>","<modo>","<instrucciones>","<sentencia>",
                            "<instruccion>","<lectura>","<escritura>","<op_relac>","<op_aritmetico_simple>","<op_aritmetico_doble>","<tipo>",
                            "<const>","<identificador>"};
    //filas: no terminales
    //columnas: terminales
    //devuelve el numero de columna en la LL1TAS es decir la columna del no terminal 
    //implementation of the Parser Analysis Table with a nested HashMap
    std::unordered_map<int, std::unordered_map<int, std::vector<int>>> PT;


public:
    //constructor
    LL1TAS():LL1TASmatrix(15,std::vector<std::vector<int>>(15)){
    	
    	std::vector<int> produccion_vacia = {73};
        std::vector<int> produccion1000 = {1,4,5};
    	std::vector<int> produccion1 = {3,2,223,1};
        std::vector<int> produccion2 = {222,72,224,71,2};
        std::vector<int> produccion3 = {70,122,72,224,71};
        std::vector<int> produccion4 = {106, 220, 62, 7, 221};
        std::vector<int> produccion5 = {107, 72, 220, 6,221, 5};
        std::vector<int> produccion6 = {8, 17, 20};
        std::vector<int> produccion7 = {108, 21, 221, 7};
        std::vector<int> produccion8 = {70, 9, 223, 8};
        std::vector<int> produccion9 = {72, 11 ,10};
        std::vector<int> produccion10 = {222, 72, 11, 10};
        std::vector<int> produccion11 = {218, 12,};std::vector<int> produccion111 = {224, 33, 35};
        std::vector<int> produccion12 = {219, 224,125, 220, 14, 221 };std::vector<int> produccion121 = {13, 219};
        std::vector<int> produccion13 = {72};std::vector<int> produccion131 = {300};
        std::vector<int> produccion14 = {71, 15};
        std::vector<int> produccion15 = {222, 71, 15};
        std::vector<int> produccion16 = {70, 9};
        std::vector<int> produccion17 = {19, 221,18};
        //std::vector<int> produccion18 = {19, 221, 18};
        std::vector<int> produccion19 = {72, 216, 24, 217, 220, 62};
        std::vector<int> produccion20 = {21, 221, 20};
        std::vector<int> produccion21 = {22};std::vector<int> produccion211 = {23};
        std::vector<int> produccion22 = {70, 72, 216, 24, 217, 220, 62, 121, 72, 223};
        std::vector<int> produccion23 = {105, 72, 216, 24, 217, 220, 62};
        std::vector<int> produccion24 = {70, 72, 25};
        std::vector<int> produccion25 = {222, 70, 72, 25};
        std::vector<int> produccion26 = {72, 27};
        std::vector<int> produccion27 = {222, 72, 27};
        std::vector<int> produccion28 = {110, 72, 224, 125, 72};
        std::vector<int> produccion29 = {109, 30, 216, 26, 217};
        std::vector<int> produccion30 = {72, 31};
        std::vector<int> produccion31 = {200, 72, 31};
        std::vector<int> produccion32 = {72, 34, 224, 33, 35};
        std::vector<int> produccion33 = {72, 34};std::vector<int> produccion331 = {71};std::vector<int> produccion332 = {29};
        std::vector<int> produccion34 = {200, 72, 31};std::vector<int> produccion341 = {218, 300, 219};
        std::vector<int> produccion35 = {68, 33, 35};
        std::vector<int> produccion36 = {38, 37};
        std::vector<int> produccion37 = {215, 36};
        std::vector<int> produccion38 = {40, 39};
        std::vector<int> produccion39 = {214, 38};
        std::vector<int> produccion40 = {42, 41};
        std::vector<int> produccion41 = {213, 40};
        std::vector<int> produccion42 = {44, 43};
        std::vector<int> produccion43 = {211, 44, 43};std::vector<int> produccion431 = {212, 44, 43};
        std::vector<int> produccion44 = {46, 45};
        std::vector<int> produccion45 = {207, 46, 45};std::vector<int> produccion451 = {208, 46, 45};std::vector<int> produccion452 = {209, 46, 45};std::vector<int> produccion453 = {210, 46, 45};
        std::vector<int> produccion46 = {48, 47};
        std::vector<int> produccion47 = {206, 48, 47};std::vector<int> produccion471 = {205, 48, 47};
        std::vector<int> produccion48 = {50, 49};
        std::vector<int> produccion49 = {203, 50, 49};std::vector<int> produccion491 = {204, 50, 49};
        std::vector<int> produccion50 = {33};std::vector<int> produccion501 = {216,33,217};
        std::vector<int> produccion51 = {111, 216, 52, 223, 53, 223, 54, 217, 61};
    	std::vector<int> produccion52 = {70, 72, 224, 33};
        std::vector<int> produccion53 = {72, 67, 33};
        std::vector<int> produccion54 = {72, 224, 33, 35};std::vector<int> produccion541= {69, 72};
        std::vector<int> produccion55 = {113, 216, 36, 217, 61, 56};
        std::vector<int> produccion56 = {114, 61};
        std::vector<int> produccion57 = {112, 216, 36, 217, 61};
        std::vector<int> produccion58 = {115, 216, 72, 217, 220, 59, 60, 221};
        std::vector<int> produccion59 = {117, 71, 225, 62, 116, 223, 59};
        std::vector<int> produccion60 = {118, 225, 62, 116, 223};
        std::vector<int> produccion61 = {220, 62, 221};
        std::vector<int> produccion62 = {64, 223, 62};std::vector<int> produccion621 = {63, 223, 62};
        std::vector<int> produccion63 = {51};std::vector<int> produccion631 = {57};std::vector<int> produccion632 = {55};std::vector<int> produccion633 = {58};
        std::vector<int> produccion64 = {29};std::vector<int> produccion641 = {32};std::vector<int> produccion642 = {65};std::vector<int> produccion643 = {66};std::vector<int> produccion644 = {28};std::vector<int> produccion645 = {16};
        std::vector<int> produccion65 = {119, 216, 72, 217};
        std::vector<int> produccion66 = {120, 216, 72, 27, 217};
        std::vector<int> produccion67 = {207};std::vector<int> produccion671 = {208};std::vector<int> produccion672 = {210};std::vector<int> produccion673 = {209};std::vector<int> produccion674 = {211};std::vector<int> produccion675 = {212};
        std::vector<int> produccion68 = {206};std::vector<int> produccion681 = {205};std::vector<int> produccion682 = {203};std::vector<int> produccion683 = {204};
        std::vector<int> produccion69 = {201};std::vector<int> produccion691 = {202};
        std::vector<int> produccion70 = {100};std::vector<int> produccion701 = {101};std::vector<int> produccion702 = {102};std::vector<int> produccion703 = {103};std::vector<int> produccion704 = {104};
        std::vector<int> produccion71 = {300};std::vector<int> produccion711 = {301};std::vector<int> produccion712 = {302};std::vector<int> produccion713 = {303};std::vector<int> produccion714 = {123};std::vector<int> produccion715 = {124};
        std::vector<int> produccion72 = {400};

        PT[0][0] = produccion1000;PT[0][1] = produccion1000;PT[0][2] = produccion1000;PT[0][3] = produccion1000;PT[0][4] = produccion1000;PT[0][6] = produccion1000;
        PT[1][0] = produccion1;PT[1][1] = produccion1;PT[1][2] = produccion1;PT[1][3] = produccion1;PT[1][4] = produccion1;PT[1][6] = produccion_vacia;
        PT[2][53] = produccion2;PT[2][54] = produccion_vacia;
        PT[3][0] = produccion3;PT[3][1] = produccion3;PT[3][2] = produccion3;PT[3][3] = produccion3;PT[3][4] = produccion3;
        PT[4][6] = produccion4;
        PT[5][7] = produccion5;PT[5][57] = produccion_vacia;
        PT[6][0] = produccion6;PT[6][1] = produccion6;PT[6][2] = produccion6;PT[6][3] = produccion6;PT[6][4] = produccion6;PT[6][48] = produccion6;
        PT[7][8] = produccion7;PT[7][52] = produccion_vacia;
        PT[8][0] = produccion8;PT[8][1] = produccion8;PT[8][2] = produccion8;PT[8][3] = produccion8;PT[8][4] = produccion8;PT[8][48] = produccion_vacia;
        PT[9][48] = produccion9;
        PT[10][53] = produccion10;PT[10][54] = produccion_vacia;
        PT[11][49] = produccion11;PT[11][23] = produccion111;PT[11][53] = produccion_vacia;PT[11][54] = produccion_vacia;
        PT[12][50] = produccion12;PT[12][48] = produccion121;PT[12][24] = produccion121;
        PT[13][48] = produccion13;PT[13][24] = produccion131;
        PT[14][24] = produccion14;PT[14][25] = produccion14;PT[14][26] = produccion14;PT[14][27] = produccion14;PT[14][28] = produccion14;PT[14][29] = produccion14;
        PT[15][53] = produccion15;PT[15][52] = produccion_vacia;
        PT[16][0] = produccion16;PT[16][1] = produccion16;PT[16][2] = produccion16;PT[16][3] = produccion16;PT[16][4] = produccion16;
        PT[17][48] = produccion17;
        PT[18][0] = produccion_vacia;PT[18][1] = produccion_vacia;PT[18][2] = produccion_vacia;PT[18][3] = produccion_vacia;PT[18][4] = produccion_vacia;PT[18][5] = produccion_vacia;PT[18][52] = produccion_vacia;PT[18][48] = produccion17;
        PT[19][48] = produccion19;
        PT[20][0] = produccion20;PT[20][1] = produccion20;PT[20][2] = produccion20;PT[20][3] = produccion20;PT[20][4] = produccion20;PT[20][5] = produccion20;PT[20][52] = produccion_vacia;
        PT[21][0] = produccion21;PT[21][1] = produccion21;PT[21][2] = produccion21;PT[21][3] = produccion21;PT[21][4] = produccion21;PT[21][5] = produccion211;
        PT[22][0] = produccion22;PT[22][1] = produccion22;PT[22][2] = produccion22;PT[22][3] = produccion22;PT[22][4] = produccion22;
        PT[23][5] = produccion23;
        PT[24][0] = produccion24;PT[24][1] = produccion24;PT[24][2] = produccion24;PT[24][3] = produccion24;PT[24][4] = produccion24;PT[24][47] = produccion_vacia;
        PT[25][53] = produccion25;PT[25][47] = produccion_vacia;
        PT[26][48] = produccion26;PT[26][47] = produccion_vacia;
        PT[27][53] = produccion27;PT[27][47] = produccion_vacia;
        PT[28][10] = produccion28;
        PT[29][9] = produccion29;
        PT[30][48] = produccion30;
        PT[31][30] = produccion31; PT[31][46] = produccion_vacia;
        PT[32][48] = produccion32;
        PT[33][48] = produccion33;PT[33][24] = produccion331;PT[33][25] = produccion331;PT[33][26] = produccion331;PT[33][27] = produccion331;PT[33][28] = produccion331;PT[33][29] = produccion331;PT[33][9] = produccion332;
        PT[34][30] = produccion34;PT[34][49] = produccion341;PT[34][23] = produccion_vacia;PT[34][33] = produccion_vacia;PT[34][34] = produccion_vacia;PT[34][35] = produccion_vacia;PT[34][36] = produccion_vacia;PT[34][37] = produccion_vacia;PT[34][38] = produccion_vacia;PT[34][39] = produccion_vacia;PT[34][40] = produccion_vacia;PT[34][41] = produccion_vacia;PT[34][42] = produccion_vacia;PT[34][42] = produccion_vacia;PT[34][43] = produccion_vacia;PT[34][44] = produccion_vacia;PT[34][45] = produccion_vacia;PT[34][47] = produccion_vacia;PT[34][53] = produccion_vacia;PT[34][54] = produccion_vacia;
        PT[35][33] = produccion35;PT[35][34] = produccion35;PT[35][35] = produccion35;PT[35][36] = produccion35;PT[35][47] = produccion_vacia;PT[35][53] = produccion_vacia;PT[35][54] = produccion_vacia;

        PT[36][24] = produccion36;PT[36][25] = produccion36;PT[36][26] = produccion36;PT[36][27] = produccion36;PT[36][28] = produccion36;PT[36][29] = produccion36;PT[36][46] = produccion36;PT[36][48] = produccion36;

        PT[37][45] = produccion37;PT[37][47] = produccion_vacia;

        PT[38][24] = produccion38;PT[38][25] = produccion38;PT[38][26] = produccion38;PT[38][27] = produccion38;PT[38][28] = produccion38;PT[38][29] = produccion38;PT[38][46] = produccion38;PT[38][48] = produccion38;

        PT[39][44] = produccion39;PT[39][45] = produccion_vacia;PT[39][47] = produccion_vacia;

        PT[40][24] = produccion40;PT[40][25] = produccion40;PT[40][26] = produccion40;PT[40][27] = produccion40;PT[40][28] = produccion40;PT[40][29] = produccion40;PT[40][46] = produccion40;PT[40][48] = produccion40;

        PT[41][43] = produccion41;PT[41][44] = produccion_vacia;PT[41][45] = produccion_vacia;PT[41][47] = produccion_vacia;
        
        PT[42][24] = produccion42;PT[42][25] = produccion42;PT[42][26] = produccion42;PT[42][27] = produccion42;PT[42][28] = produccion42;PT[42][29] = produccion42;PT[42][46] = produccion42;PT[42][48] = produccion42;

        PT[43][41] = produccion43;PT[43][42] = produccion431;PT[43][43] = produccion_vacia;PT[43][44] = produccion_vacia;PT[43][45] = produccion_vacia;PT[43][47] = produccion_vacia;

        PT[44][24] = produccion44;PT[44][25] = produccion44;PT[44][26] = produccion44;PT[44][27] = produccion44;PT[44][28] = produccion44;PT[44][29] = produccion44;PT[44][46] = produccion44;PT[44][48] = produccion44;

        PT[45][37] = produccion45;PT[45][38] = produccion451;PT[45][39] = produccion452;PT[45][40] = produccion453;PT[45][41] = produccion_vacia;PT[45][42] = produccion_vacia;PT[45][43] = produccion_vacia;PT[45][44] = produccion_vacia;PT[45][45] = produccion_vacia;PT[45][47] = produccion_vacia;

        PT[46][24] = produccion46;PT[46][25] = produccion46;PT[46][26] = produccion46;PT[46][27] = produccion46;PT[46][28] = produccion46;PT[46][29] = produccion46;PT[46][46] = produccion46;PT[46][48] = produccion46;

        PT[47][36] = produccion47;PT[47][35] = produccion471;PT[47][37] = produccion_vacia;PT[47][38] = produccion_vacia;PT[47][39] = produccion_vacia;PT[47][40] = produccion_vacia;PT[47][41] = produccion_vacia;PT[47][42] = produccion_vacia;PT[47][43] = produccion_vacia;PT[47][44] = produccion_vacia;PT[47][45] = produccion_vacia;PT[47][47] = produccion_vacia;

        PT[48][24] = produccion48;PT[48][25] = produccion48;PT[48][26] = produccion48;PT[48][27] = produccion48;PT[48][28] = produccion48;PT[48][29] = produccion48;PT[48][46] = produccion48;PT[48][48] = produccion48;

        PT[49][33] = produccion49;PT[49][34] = produccion491;PT[49][35] = produccion_vacia;PT[49][36] = produccion_vacia;PT[49][37] = produccion_vacia;PT[49][38] = produccion_vacia;PT[49][39] = produccion_vacia;PT[49][40] = produccion_vacia;PT[49][41] = produccion_vacia;PT[49][42] = produccion_vacia;PT[49][43] = produccion_vacia;PT[49][44] = produccion_vacia;PT[49][45] = produccion_vacia;PT[49][47] = produccion_vacia;

        PT[50][24] = produccion50;PT[50][25] = produccion50;PT[50][26] = produccion50;PT[50][27] = produccion50;PT[50][28] = produccion50;PT[50][29] = produccion50;PT[50][46] = produccion501;PT[50][48] = produccion50;

        PT[51][11] = produccion51;
        PT[52][0] = produccion52;PT[52][1] = produccion52;PT[52][2] = produccion52;PT[52][3] = produccion52;PT[52][4] = produccion52;
        PT[53][48] = produccion53;
        PT[54][48] = produccion54; PT[54][31] = produccion541;PT[54][32] = produccion541;
        PT[55][13] = produccion55;
        PT[56][14] = produccion56; PT[56][52] = produccion_vacia;PT[56][54] = produccion_vacia;//agregado, no esta en el LL1TAS
        PT[57][12] = produccion57;
        PT[58][15] = produccion58;
        PT[59][17] = produccion59; PT[59][18] = produccion_vacia;
        PT[60][18] = produccion60;
        PT[61][51] = produccion61;
        PT[62][0] = produccion62;PT[62][1] = produccion62;PT[62][2] = produccion62;PT[62][3] = produccion62;PT[62][4] = produccion62;PT[62][9] = produccion62;PT[62][10] = produccion62;PT[62][11] = produccion621;PT[62][12] = produccion621;PT[62][13] = produccion621;PT[62][15] = produccion621; PT[62][19] = produccion62;PT[62][20] = produccion62;PT[62][48] = produccion62;PT[62][8] = produccion_vacia;PT[62][16] = produccion_vacia;PT[62][21] = produccion_vacia;PT[62][52] = produccion_vacia;
        PT[63][11] = produccion63;PT[63][12] = produccion631;PT[63][13] = produccion632;PT[63][15] = produccion633;
        PT[64][0] = produccion645;PT[64][1] = produccion645;PT[64][2] = produccion645;PT[64][3] = produccion645;PT[64][4] = produccion645;PT[64][9] = produccion64;PT[64][10] = produccion644;PT[64][19] = produccion642;PT[64][20] = produccion643;PT[64][48] = produccion641;
        PT[65][19] = produccion65;
        PT[66][20] = produccion66;
        PT[67][37] = produccion67;PT[67][38] = produccion671;PT[67][39] = produccion672;PT[67][40] = produccion673;PT[67][41] = produccion674;PT[67][42] = produccion675;
        PT[68][36] = produccion68;PT[68][35] = produccion681;PT[68][34] = produccion682;PT[68][33] = produccion683;
        PT[69][31] = produccion69;PT[69][32] = produccion691;
        PT[70][0] = produccion70;PT[70][1] = produccion701;PT[70][2] = produccion702;PT[70][3] = produccion703;PT[70][4] = produccion704;
        PT[71][24] = produccion71;PT[71][25] = produccion711;PT[71][26] = produccion712;PT[71][27] = produccion713;PT[71][28] = produccion714;PT[71][29] = produccion715;
        PT[72][48] = produccion72;
    
    };
    int LL1TAS_getColumna(int);
    int LL1TAS_getFila(std::string);
    std::vector<int> getProduction(int,int);//debe tener parametros del mismo tipo
    //bool checkProduction(int,int);
    bool checkProductionExists(int,int);
    int Terminal(int);
};
#endif