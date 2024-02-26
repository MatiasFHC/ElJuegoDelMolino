#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int turno_de_jugador = 0;
char jugador_1[20];
char jugador_2[20];
char ficha1 = 79;
char ficha2 = 79;
int color1;
int color2;
int primer_jugador;

void gotoxy(int x, int y)
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void colores(int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}

//tablero
int tablero[25][65] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,5,13,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,5,10,0,0,0,0,0,0,0,0,0,2,5,11,0,0,0,0,0,5,12,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,10,1,0,0,5,9,1,0,0,0,6,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,6,8,0,0,0,1,5,4,0,0,1,11,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,2,2,2,2,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,6,13,0,0,0,0,0,0,0,6,5,2,0,0,0,0,0,0,0,0,6,6,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,5,6,0,0,0,0,0,0,0,0,0,0,0,0,0,5,7,2,0,0,0,0,0,0,0,0,0,0,0,0,0,5,8,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0}
};

//
void color_ficha(int x, char ficha) {
    switch (x) {
    case 1:
        colores(1);

        break;
    case 2:
        colores(2);

        break;
    case 3:
        colores(3);

        break;
    case 4:
        colores(4);

        break;
    case 5:
        colores(5);

        break;
    case 6:
        colores(6);

        break;
    }
}

void jugador1() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    gotoxy(5, 8); cout << "Ingrese el nombre del jugador 1: "; cin >> jugador_1;
    cout << endl;
    do {
        gotoxy(5, 10); cout << "Elige el color de tus fichas: " << endl << endl;
        gotoxy(5, 11); SetConsoleTextAttribute(hConsole, 1); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << " [1] Azul" << endl;
        gotoxy(5, 12); SetConsoleTextAttribute(hConsole, 2); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << " [2] Verde" << endl;
        gotoxy(5, 13); SetConsoleTextAttribute(hConsole, 3); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << " [3] Celeste" << endl;
        gotoxy(5, 14); SetConsoleTextAttribute(hConsole, 4); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << " [4] Rojo" << endl;
        gotoxy(5, 15); SetConsoleTextAttribute(hConsole, 5); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << " [5] Morado" << endl;
        gotoxy(5, 16); SetConsoleTextAttribute(hConsole, 6); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << " [6] Amarillo" << endl << endl;
        gotoxy(5, 18); SetConsoleTextAttribute(hConsole, 1); cout << "> ";
        SetConsoleTextAttribute(hConsole, 7); cin >> color1;
    } while (!(color1 <= 6));
    cout << endl;
}

void jugador2() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    gotoxy(60, 8); cout << "Ingrese el nombre del jugador 2: "; cin >> jugador_2;
    cout << endl;
    do {
        gotoxy(60, 10); cout << "Elige el color de tus fichas: " << endl;
        gotoxy(60, 11); SetConsoleTextAttribute(hConsole, 1); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << "[1] Azul" << endl;
        gotoxy(60, 12); SetConsoleTextAttribute(hConsole, 2); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << "[2] Verde" << endl;
        gotoxy(60, 13); SetConsoleTextAttribute(hConsole, 3); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << "[3] Celeste" << endl;
        gotoxy(60, 14); SetConsoleTextAttribute(hConsole, 4); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << "[4] Rojo" << endl;
        gotoxy(60, 15); SetConsoleTextAttribute(hConsole, 5); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << "[5] Morado" << endl;
        gotoxy(60, 16); SetConsoleTextAttribute(hConsole, 6); cout << char(254); SetConsoleTextAttribute(hConsole, 7); cout << "[6] Amarillo" << endl << endl;
        gotoxy(60, 18); SetConsoleTextAttribute(hConsole, 1); cout << "> ";
        SetConsoleTextAttribute(hConsole, 7); cin >> color2;
    } while (!(color2 <= 6));
    cout << endl;
}

//escoger aleatoriamente quien comienza
void jugador_comienza() {
    srand(time(NULL));
    primer_jugador = 1 + rand() % (3 - 1);
    if (primer_jugador == 1) {
        cout << "Comienza " << jugador_1 << endl;
    }
    if (primer_jugador == 2) {
        cout << "Comienza " << jugador_2 << endl;
    }
}

//dibujar tablero
void DibujarTablero()
{
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 60; j++) {
            switch (tablero[i][j]) {
            case 1:
                colores(6);
                cout << char(219);
                break;
            case 2:
                colores(6);
                cout << char(219);
                break;
            case 4:
                colores(7);
                cout << "6";
                break;
            case 5:
                colores(7);
                cout << "1";
                break;
            case 6:
                colores(7);
                cout << "2";
                break;
            case 7:
                colores(7);
                cout << "3";
                break;
            case 8:
                colores(7);
                cout << "4";
                break;
            case 9:
                colores(7);
                cout << "5";
                break;
            case 10:
                colores(7);
                cout << "7";
                break;
            case 11:
                colores(7);
                cout << "8";
                break;
            case 12:
                colores(7);
                cout << "9";
                break;
            case 13:
                colores(7);
                cout << "0";
                break;
            case 14:
                color_ficha(color1, ficha1);
                cout << ficha1;
                break;
            case 15:
                color_ficha(color2, ficha2);
                cout << ficha2;
                break;
            default:
                cout << " ";
                break;
            }
        }
        cout << endl;
    }
    gotoxy(2, 4); cout << jugador_1;
    gotoxy(57, 4); cout << jugador_2;
    color_ficha(color1, ficha1);
    for (int i = 0; i < 9; i++) {
        gotoxy(5, i + 6);
        cout << ficha1 << endl;
    }
    color_ficha(color2, ficha2);
    for (int i = 0; i < 9; i++) {
        gotoxy(60, i + 6);
        cout << ficha2 << endl;
    }
    colores(7);
}


//ingresa la posicion
int ingreso_de_la_posicion(int& cont1, int& cont2) {
    cout << "Turno de ";
    if (primer_jugador == 1) {
        if (turno_de_jugador % 2 == 0) {
            cout << jugador_1;
            cont1++;
        }
        else {
            cout << jugador_2;
            cont2++;
        }
        cout << ": ";
        int posicion;
        cin >> posicion;
        return posicion;
    }
    if (primer_jugador == 2) {
        if (turno_de_jugador % 2 == 0) {
            cout << jugador_2;
            cont2++;
        }
        else {
            cout << jugador_1;
            cont1++;
        }
        cout << ": ";
        int posicion;
        cin >> posicion;
        return posicion;
    }
}

void contador_fichas_robo(int& cont3, int& cont4) {
    if (primer_jugador == 1) {
        if (turno_de_jugador % 2 == 0) {
            cont3++;
        }
        else {
            cont4++;
        }
    }
    if (primer_jugador == 2) {
        if (turno_de_jugador % 2 == 0) {
            cont4++;
        }
        else {
            cont3++;
        }
    }
}

//cambio de jugador
void cambiar_de_jugador(int x, int y) {
    if (primer_jugador == 1) {
        if (turno_de_jugador % 2 == 0) {
            tablero[x][y] = 14;
        }
        else {
            tablero[x][y] = 15;
        }
    }
    if (primer_jugador == 2) {
        if (turno_de_jugador % 2 == 0) {
            tablero[x][y] = 15;
        }
        else {
            tablero[x][y] = 14;
        }
    }
    turno_de_jugador++;
}

//posicion de la ficha
void posicion_libre(int posicion) {
    if (posicion >= 1 && posicion <= 24) {
        switch (posicion) {
        case 1:
            if (tablero[1][13] == NULL) {
                cambiar_de_jugador(1, 13);
            }
            break;
        case 2:
            if (tablero[1][34] == NULL) {
                cambiar_de_jugador(1, 34);
            }
            break;
        case 3:
            if (tablero[1][54] == NULL) {
                cambiar_de_jugador(1, 54);
            }
            break;
        case 4:
            if (tablero[22][13] == NULL) {
                cambiar_de_jugador(22, 13);
            }
            break;
        case 5:
            if (tablero[22][34] == NULL) {
                cambiar_de_jugador(22, 34);
            }
            break;
        case 6:
            if (tablero[22][54] == NULL) {
                cambiar_de_jugador(22, 54);
            }
            break;
        case 7:
            if (tablero[11][13] == NULL) {
                cambiar_de_jugador(11, 13);
            }
            break;
        case 8:
            if (tablero[11][54] == NULL) {
                cambiar_de_jugador(11, 54);
            }
            break;
        case 9:
            if (tablero[4][18] == NULL) {
                cambiar_de_jugador(4, 18);
            }
            break;
        case 10:
            if (tablero[4][34] == NULL) {
                cambiar_de_jugador(4, 34);
            }
            break;
        case 11:
            if (tablero[4][49] == NULL) {
                cambiar_de_jugador(4, 49);
            }
            break;
        case 12:
            if (tablero[19][18] == NULL) {
                cambiar_de_jugador(19, 18);
            }
            break;
        case 13:
            if (tablero[19][34] == NULL) {
                cambiar_de_jugador(19, 34);
            }
            break;
        case 14:
            if (tablero[19][49] == NULL) {
                cambiar_de_jugador(19, 49);
            }
            break;
        case 15:
            if (tablero[11][18] == NULL) {
                cambiar_de_jugador(11, 18);
            }
            break;
        case 16:
            if (tablero[11][49] == NULL) {
                cambiar_de_jugador(11, 49);
            }
            break;
        case 17:
            if (tablero[8][24] == NULL) {
                cambiar_de_jugador(8, 24);
            }
            break;
        case 18:
            if (tablero[8][34] == NULL) {
                cambiar_de_jugador(8, 34);
            }
            break;
        case 19:
            if (tablero[8][43] == NULL) {
                cambiar_de_jugador(8, 43);
            }
            break;
        case 20:
            if (tablero[16][24] == NULL) {
                cambiar_de_jugador(16, 24);
            }
            break;
        case 21:
            if (tablero[16][34] == NULL) {
                cambiar_de_jugador(16, 34);
            }
            break;
        case 22:
            if (tablero[16][43] == NULL) {
                cambiar_de_jugador(16, 43);
            }
            break;
        case 23:
            if (tablero[11][24] == NULL) {
                cambiar_de_jugador(11, 24);
            }
            break;
        case 24:
            if (tablero[11][43] == NULL) {
                cambiar_de_jugador(11, 43);
            }
            break;
        }
    }
}

//
//robo funcion
void robo(int ficha_robada) {
    switch (ficha_robada) {
    case 1:
        tablero[1][13] = NULL;
        break;
    case 2:
        tablero[1][34] = NULL;
        break;
    case 3:
        tablero[1][54] = NULL;
        break;
    case 4:
        tablero[22][13] = NULL;
        break;
    case 5:
        tablero[22][34] = NULL;
        break;
    case 6:
        tablero[22][54] = NULL;
        break;
    case 7:
        tablero[11][13] = NULL;
        break;
    case 8:
        tablero[11][54] = NULL;
        break;
    case 9:
        tablero[4][18] = NULL;
        break;
    case 10:
        tablero[4][34] = NULL;
        break;
    case 11:
        tablero[4][49] = NULL;
        break;
    case 12:
        tablero[19][18] = NULL;
        break;
    case 13:
        tablero[19][34] = NULL;
        break;
    case 14:
        tablero[19][49] = NULL;
        break;
    case 15:
        tablero[11][18] = NULL;
        break;
    case 16:
        tablero[11][49] = NULL;
        break;
    case 17:
        tablero[8][24] = NULL;
        break;
    case 18:
        tablero[8][34] = NULL;
        break;
    case 19:
        tablero[8][43] = NULL;
        break;
    case 20:
        tablero[16][24] = NULL;
        break;
    case 21:
        tablero[16][34] = NULL;
        break;
    case 22:
        tablero[16][43] = NULL;
        break;
    case 23:
        tablero[11][24] = NULL;
        break;
    case 24:
        tablero[11][43] = NULL;
        break;
    }
}

//fichas robadas
bool molino1 = true, molino2 = true, molino3 = true, molino4 = true, molino5 = true, molino6 = true;
bool molino7 = true, molino8 = true, molino9 = true, molino10 = true, molino11 = true, molino12 = true;
bool molino13 = true, molino14 = true, molino15 = true, molino16;
void fichas_robadas(int& cont3, int& cont4) {
    int ficha_robo;
    char jugars;
    if (molino1 == true && tablero[1][13] == tablero[22][13] && tablero[1][13] == tablero[11][13] && tablero[1][13] != NULL) {
        molino1 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino1 == false && tablero[11][13] == NULL && tablero[1][13] == tablero[22][13] && tablero[1][13] != NULL ||
        molino1 == false && tablero[22][13] == NULL && tablero[1][13] == tablero[11][13] && tablero[1][13] != NULL ||
        molino1 == false && tablero[1][13] == NULL && tablero[22][13] == tablero[11][13] && tablero[22][13] != NULL) {
        molino1 = true;
    }

    if (molino2 == true && tablero[1][54] == tablero[22][54] && tablero[1][54] == tablero[11][54] && tablero[1][54] != NULL) {
        molino2 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino2 == false && tablero[1][54] == tablero[22][54] && tablero[11][54] == NULL && tablero[1][54] != NULL ||
        molino2 == false && tablero[1][54] == tablero[11][54] && tablero[22][54] == NULL && tablero[1][54] != NULL ||
        molino2 == false && tablero[1][54] == NULL && tablero[22][54] == tablero[11][54] && tablero[11][54] != NULL) {
        molino2 = true;
    }

    if (molino3 == true && tablero[1][13] == tablero[1][34] && tablero[1][13] == tablero[1][54] && tablero[1][13] != NULL) {
        molino3 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino3 == false && tablero[1][13] == tablero[1][34] && tablero[1][54] == NULL && tablero[1][13] != NULL ||
        molino3 == false && tablero[1][13] == tablero[1][54] && tablero[1][34] == NULL && tablero[1][13] != NULL ||
        molino3 == false && tablero[1][13] == NULL && tablero[1][34] == tablero[1][54] && tablero[1][34] != NULL) {
        molino3 = true;
    }

    if (molino4 == true && tablero[22][13] == tablero[22][34] && tablero[22][13] == tablero[22][54] && tablero[22][13] != NULL) {
        molino4 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino4 == false && tablero[22][13] == tablero[22][34] && tablero[22][54] == NULL && tablero[22][13] != NULL ||
        molino4 == false && tablero[22][13] == tablero[22][54] && tablero[22][34] == NULL && tablero[22][13] != NULL ||
        molino4 == false && tablero[22][13] == NULL && tablero[22][34] == tablero[22][54] && tablero[22][34] != NULL) {
        molino4 = true;
    }

    if (molino5 == true && tablero[1][34] == tablero[4][34] && tablero[1][34] == tablero[8][34] && tablero[1][34] != NULL) {
        molino5 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino5 == false && tablero[1][34] == tablero[4][34] && tablero[8][34] == NULL && tablero[1][34] != NULL ||
        molino5 == false && tablero[1][34] == tablero[8][34] && tablero[4][34] == NULL && tablero[1][34] != NULL ||
        molino5 == false && tablero[1][34] == NULL && tablero[4][34] == tablero[8][34] && tablero[4][34] != NULL) {
        molino5 = true;
    }

    if (molino6 == true && tablero[22][34] == tablero[19][34] && tablero[22][34] == tablero[16][34] && tablero[22][34] != NULL) {
        molino6 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino6 == false && tablero[22][34] == tablero[19][34] && tablero[16][34] == NULL && tablero[22][34] != NULL ||
        molino6 == false && tablero[22][34] == tablero[16][34] && tablero[19][34] == NULL && tablero[22][34] != NULL ||
        molino6 == false && tablero[22][34] == NULL && tablero[19][34] == tablero[16][34] && tablero[19][34] != NULL) {
        molino6 = true;
    }

    if (molino7 == true && tablero[11][13] == tablero[11][18] && tablero[11][13] == tablero[11][24] && tablero[11][13] != NULL) {
        molino7 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino7 == false && tablero[11][13] == tablero[11][18] && tablero[11][24] == NULL && tablero[11][13] != NULL ||
        molino7 == false && tablero[11][13] == tablero[11][24] && tablero[11][18] == NULL && tablero[11][13] != NULL ||
        molino7 == false && tablero[11][13] == NULL && tablero[11][18] == tablero[11][24] && tablero[11][18] != NULL) {
        molino7 = true;
    }

    if (molino8 == true && tablero[11][54] == tablero[11][49] && tablero[11][54] == tablero[11][43] && tablero[11][54] != NULL) {
        molino8 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino8 == false && tablero[11][54] == tablero[11][49] && tablero[11][43] == NULL && tablero[11][54] != NULL ||
        molino8 == false && tablero[11][54] == tablero[11][43] && tablero[11][49] == NULL && tablero[11][54] != NULL ||
        molino8 == false && tablero[11][54] == NULL && tablero[11][49] == tablero[11][43] && tablero[11][43] != NULL) {
        molino8 = true;
    }

    if (molino9 == true && tablero[4][18] == tablero[4][34] && tablero[4][18] == tablero[4][49] && tablero[4][18] != NULL) {
        molino9 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino9 == false && tablero[4][18] == tablero[4][34] && tablero[4][49] == NULL && tablero[4][18] != NULL ||
        molino9 == false && tablero[4][18] == tablero[4][49] && tablero[4][34] == NULL && tablero[4][18] != NULL ||
        molino9 == false && tablero[4][18] == NULL && tablero[4][34] == tablero[4][49] && tablero[4][34] != NULL) {
        molino9 = true;
    }

    if (molino10 == true && tablero[19][18] == tablero[19][34] && tablero[19][18] == tablero[19][49] && tablero[19][18] != NULL) {
        molino10 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino10 == false && tablero[19][18] == tablero[19][34] && tablero[19][49] == NULL && tablero[19][18] != NULL ||
        molino10 == false && tablero[19][18] == tablero[19][49] && tablero[19][34] == NULL && tablero[19][18] != NULL ||
        molino10 == false && tablero[19][18] == NULL && tablero[19][34] == tablero[19][49] && tablero[19][34] != NULL) {
        molino10 = true;
    }

    if (molino11 == true && tablero[4][18] == tablero[19][18] && tablero[4][18] == tablero[11][18] && tablero[4][18] != NULL) {
        molino11 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino11 == false && tablero[4][18] == tablero[19][18] && tablero[11][18] == NULL && tablero[4][18] != NULL ||
        molino11 == false && tablero[4][18] == tablero[11][18] && tablero[19][18] == NULL && tablero[4][18] != NULL ||
        molino11 == false && tablero[4][18] == NULL && tablero[19][18] == tablero[11][18] && tablero[19][18] != NULL) {
        molino11 = true;
    }

    if (molino12 == true && tablero[4][49] == tablero[19][49] && tablero[4][49] == tablero[11][49] && tablero[4][49] != NULL) {
        molino12 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino12 == false && tablero[4][49] == tablero[19][49] && tablero[11][49] == NULL && tablero[4][49] != NULL ||
        molino12 == false && tablero[4][49] == tablero[11][49] && tablero[19][49] == NULL && tablero[4][49] != NULL ||
        molino12 == false && tablero[4][49] == NULL && tablero[19][49] == tablero[11][49] && tablero[19][49] != NULL) {
        molino12 = true;
    }

    if (molino13 == true && tablero[8][24] == tablero[8][34] && tablero[8][24] == tablero[8][43] && tablero[8][24] != NULL) {
        molino13 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino13 == false && tablero[8][24] == tablero[8][34] && tablero[8][43] == NULL && tablero[8][24] != NULL ||
        molino13 == false && tablero[8][24] == tablero[8][43] && tablero[8][34] == NULL && tablero[8][24] != NULL ||
        molino13 == false && tablero[8][24] == NULL && tablero[8][34] == tablero[8][43] && tablero[8][34] != NULL) {
        molino13 = true;
    }

    if (molino14 == true && tablero[16][24] == tablero[16][34] && tablero[16][24] == tablero[16][43] && tablero[16][24] != NULL) {
        molino14 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino14 == false && tablero[16][24] == tablero[16][34] && tablero[16][43] == NULL && tablero[16][24] != NULL ||
        molino14 == false && tablero[16][24] == tablero[16][43] && tablero[16][34] == NULL && tablero[16][24] != NULL ||
        molino14 == false && tablero[16][24] == NULL && tablero[16][34] == tablero[16][43] && tablero[16][34] != NULL) {
        molino14 = true;
    }

    if (molino15 == true && tablero[8][24] == tablero[11][24] && tablero[8][24] == tablero[16][24] && tablero[8][24] != NULL) {
        molino15 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino15 == false && tablero[8][24] == tablero[11][24] && tablero[16][24] == NULL && tablero[8][24] != NULL ||
        molino15 == false && tablero[8][24] == tablero[16][24] && tablero[11][24] == NULL && tablero[8][24] != NULL ||
        molino15 == false && tablero[8][24] == NULL && tablero[11][24] == tablero[16][24] && tablero[11][24] != NULL) {
        molino15 = true;
    }

    if (molino16 == true && tablero[8][43] == tablero[11][43] && tablero[8][43] == tablero[16][43] && tablero[8][43] != NULL) {
        molino16 = false;
        cout << "Formaste un molino!!!" << endl;
        cout << "Escoge la posicion de una de las fichas de tu contrincante: " << endl;
        cin >> ficha_robo;
        robo(ficha_robo);
        contador_fichas_robo(cont3, cont4);
    }
    else if (molino16 == false && tablero[8][43] == tablero[11][43] && tablero[16][43] == NULL && tablero[8][43] != NULL ||
        molino16 == false && tablero[8][43] == tablero[16][43] && tablero[11][43] == NULL && tablero[8][43] != NULL ||
        molino16 == false && tablero[8][43] == NULL && tablero[11][43] == tablero[16][43] && tablero[11][43] != NULL) {
        molino16 = true;
    }
}

//
//ingreso de la ficha a mover
int ingreso_de_la_posicion_a_mover(int& cont1, int& cont2) {
    cout << "Turno de ";
    if (primer_jugador == 1) {
        if (turno_de_jugador % 2 == 0) {
            cout << jugador_1;
            cont1++;
        }
        else {
            cout << jugador_2;
            cont2++;
        }
        cout << endl;
        cout << "Ingrese la posicion de la ficha que desea mover " << endl;
        int posicion;
        cin >> posicion;
        return posicion;
    }
    if (primer_jugador == 2) {
        if (turno_de_jugador % 2 == 0) {
            cout << jugador_2;
            cont2++;
        }
        else {
            cout << jugador_1;
            cont1++;
        }
        cout << endl;
        cout << "Ingrese la posicion de la ficha que desea mover " << endl;
        int posicion;
        cin >> posicion;
        return posicion;
    }
}

//lugar en el que esta la ficha a mover (quedara vacio)
void lugar_a_dejar(int x, int y, int& cont5, int& cont6) {
    if (primer_jugador == 1) {
        if (turno_de_jugador % 2 == 0) {
            tablero[x][y] = NULL;
            cont5++;
        }
        else {
            tablero[x][y] = NULL;
            cont6++;
        }
    }
    if (primer_jugador == 2) {
        if (turno_de_jugador % 2 == 0) {
            tablero[x][y] = NULL;
            cont6++;
        }
        else {
            tablero[x][y] = NULL;
            cont5++;
        }
    }
}

//lugar a llenar
void escoger_lugar_a_dejar(int jugada, int& cont5, int& cont6) {
    if (jugada >= 1 && jugada <= 24) {
        switch (jugada) {
        case 1:
            lugar_a_dejar(1, 13, cont5, cont6);
            break;
        case 2:
            lugar_a_dejar(1, 34, cont5, cont6);
            break;
        case 3:
            lugar_a_dejar(1, 54, cont5, cont6);
            break;
        case 4:
            lugar_a_dejar(22, 13, cont5, cont6);
            break;
        case 5:
            lugar_a_dejar(22, 34, cont5, cont6);
            break;
        case 6:
            lugar_a_dejar(22, 54, cont5, cont6);
            break;
        case 7:
            lugar_a_dejar(11, 13, cont5, cont6);
            break;
        case 8:
            lugar_a_dejar(11, 54, cont5, cont6);
            break;
        case 9:
            lugar_a_dejar(4, 18, cont5, cont6);
            break;
        case 10:
            lugar_a_dejar(4, 34, cont5, cont6);
            break;
        case 11:
            lugar_a_dejar(4, 49, cont5, cont6);
            break;
        case 12:
            lugar_a_dejar(19, 18, cont5, cont6);
            break;
        case 13:
            lugar_a_dejar(19, 34, cont5, cont6);
            break;
        case 14:
            lugar_a_dejar(19, 49, cont5, cont6);
            break;
        case 15:
            lugar_a_dejar(11, 18, cont5, cont6);
            break;
        case 16:
            lugar_a_dejar(11, 49, cont5, cont6);
            break;
        case 17:
            lugar_a_dejar(8, 24, cont5, cont6);
            break;
        case 18:
            lugar_a_dejar(8, 34, cont5, cont6);
            break;
        case 19:
            lugar_a_dejar(8, 43, cont5, cont6);
            break;
        case 20:
            lugar_a_dejar(16, 24, cont5, cont6);
            break;
        case 21:
            lugar_a_dejar(16, 34, cont5, cont6);
            break;
        case 22:
            lugar_a_dejar(16, 43, cont5, cont6);
            break;
        case 23:
            lugar_a_dejar(11, 24, cont5, cont6);
            break;
        case 24:
            lugar_a_dejar(11, 43, cont5, cont6);
            break;
        }
    }
}

//posicion nueva
void nueva_posicion_fase2(int& ficha) {
    int posicionNueva;
    if (ficha == 1) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 2 || posicionNueva == 7));
        switch (posicionNueva) {
        case 2:
            cambiar_de_jugador(1, 34);
            break;
        case 7:
            cambiar_de_jugador(11, 13);
            break;
        }
    }
    if (ficha == 2) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 1 || posicionNueva == 3 || posicionNueva == 10));
        switch (posicionNueva) {
        case 1:
            cambiar_de_jugador(1, 13);
            break;
        case 3:
            cambiar_de_jugador(1, 54);
            break;
        case 10:
            cambiar_de_jugador(4, 34);
            break;
        }
    }
    if (ficha == 3) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 2 || posicionNueva == 8));
        switch (posicionNueva) {
        case 2:
            cambiar_de_jugador(1, 34);
            break;
        case 8:
            cambiar_de_jugador(11, 54);
            break;
        }
    }
    if (ficha == 4) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 7 || posicionNueva == 5));
        switch (posicionNueva) {
        case 7:
            cambiar_de_jugador(11, 13);
            break;
        case 5:
            cambiar_de_jugador(22, 34);
            break;
        }
    }
    if (ficha == 5) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 4 || posicionNueva == 6 || posicionNueva == 13));
        switch (posicionNueva) {
        case 4:
            cambiar_de_jugador(22, 13);
            break;
        case 6:
            cambiar_de_jugador(22, 54);
            break;
        case 13:
            cambiar_de_jugador(19, 34);
            break;
        }
    }
    if (ficha == 6) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 5 || posicionNueva == 8));
        switch (posicionNueva) {
        case 5:
            cambiar_de_jugador(22, 34);
            break;
        case 8:
            cambiar_de_jugador(11, 54);
            break;
        }
    }
    if (ficha == 7) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 4 || posicionNueva == 1 || posicionNueva == 15));
        switch (posicionNueva) {
        case 1:
            cambiar_de_jugador(1, 13);
            break;
        case 4:
            cambiar_de_jugador(22, 13);
            break;
        case 15:
            cambiar_de_jugador(11, 18);
            break;
        }
    }
    if (ficha == 8) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 3 || posicionNueva == 6 || posicionNueva == 16));
        switch (posicionNueva) {
        case 3:
            cambiar_de_jugador(1, 54);
            break;
        case 6:
            cambiar_de_jugador(22, 54);
            break;
        case 16:
            cambiar_de_jugador(11, 49);
            break;
        }
    }
    if (ficha == 9) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 15 || posicionNueva == 10));
        switch (posicionNueva) {
        case 10:
            cambiar_de_jugador(4, 34);
            break;
        case 15:
            cambiar_de_jugador(11, 18);
            break;
        }
    }
    if (ficha == 10) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 2 || posicionNueva == 9 || posicionNueva == 11 || posicionNueva == 18));
        switch (posicionNueva) {
        case 2:
            cambiar_de_jugador(1, 34);
            break;
        case 9:
            cambiar_de_jugador(4, 18);
            break;
        case 11:
            cambiar_de_jugador(4, 49);
            break;
        case 18:
            cambiar_de_jugador(8, 34);
            break;
        }
    }
    if (ficha == 11) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 10 || posicionNueva == 16));
        switch (posicionNueva) {
        case 10:
            cambiar_de_jugador(4, 34);
            break;
        case 16:
            cambiar_de_jugador(11, 49);
            break;
        }
    }
    if (ficha == 12) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 13 || posicionNueva == 15));
        switch (posicionNueva) {
        case 13:
            cambiar_de_jugador(19, 34);
            break;
        case 15:
            cambiar_de_jugador(11, 18);
            break;
        }
    }
    if (ficha == 13) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 14 || posicionNueva == 12 || posicionNueva == 5 || posicionNueva == 21));
        switch (posicionNueva) {
        case 12:
            cambiar_de_jugador(19, 18);
            break;
        case 14:
            cambiar_de_jugador(19, 49);
            break;
        case 5:
            cambiar_de_jugador(22, 34);
            break;
        case 21:
            cambiar_de_jugador(16, 34);
            break;
        }
    }
    if (ficha == 14) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 13 || posicionNueva == 16));
        switch (posicionNueva) {
        case 13:
            cambiar_de_jugador(19, 34);
            break;
        case 16:
            cambiar_de_jugador(11, 49);
            break;
        }
    }
    if (ficha == 15) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 7 || posicionNueva == 9 || posicionNueva == 12 || posicionNueva == 23));
        switch (posicionNueva) {
        case 7:
            cambiar_de_jugador(11, 13);
            break;
        case 9:
            cambiar_de_jugador(4, 18);
            break;
        case 12:
            cambiar_de_jugador(19, 18);
            break;
        case 23:
            cambiar_de_jugador(11, 24);
            break;
        }
    }
    if (ficha == 16) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 8 || posicionNueva == 11 || posicionNueva == 14 || posicionNueva == 24));
        switch (posicionNueva) {
        case 8:
            cambiar_de_jugador(11, 54);
            break;
        case 11:
            cambiar_de_jugador(4, 49);
            break;
        case 14:
            cambiar_de_jugador(19, 49);
            break;
        case 24:
            cambiar_de_jugador(11, 43);
            break;
        }
    }
    if (ficha == 17) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 18 || posicionNueva == 23));
        switch (posicionNueva) {
        case 18:
            cambiar_de_jugador(8, 34);
            break;
        case 23:
            cambiar_de_jugador(11, 24);
            break;
        }
    }
    if (ficha == 18) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 10 || posicionNueva == 17 || posicionNueva == 19));
        switch (posicionNueva) {
        case 10:
            cambiar_de_jugador(4, 34);
            break;
        case 17:
            cambiar_de_jugador(8, 24);
            break;
        case 19:
            cambiar_de_jugador(8, 43);
            break;
        }
    }
    if (ficha == 19) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 18 || posicionNueva == 24));
        switch (posicionNueva) {
        case 18:
            cambiar_de_jugador(8, 34);
            break;
        case 24:
            cambiar_de_jugador(11, 43);
            break;
        }
    }
    if (ficha == 20) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 21 || posicionNueva == 23));
        switch (posicionNueva) {
        case 21:
            cambiar_de_jugador(16, 34);
            break;
        case 23:
            cambiar_de_jugador(11, 24);
            break;
        }
    }
    if (ficha == 21) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 13 || posicionNueva == 20 || posicionNueva == 22));
        switch (posicionNueva) {
        case 13:
            cambiar_de_jugador(19, 34);
            break;
        case 20:
            cambiar_de_jugador(16, 24);
            break;
        case 22:
            cambiar_de_jugador(16, 43);
            break;
        }
    }
    if (ficha == 22) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 21 || posicionNueva == 24));
        switch (posicionNueva) {
        case 21:
            cambiar_de_jugador(16, 34);
            break;
        case 24:
            cambiar_de_jugador(11, 43);
            break;
        }
    }
    if (ficha == 23) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 17 || posicionNueva == 15 || posicionNueva == 20));
        switch (posicionNueva) {
        case 17:
            cambiar_de_jugador(8, 24);
            break;
        case 15:
            cambiar_de_jugador(11, 18);
            break;
        case 20:
            cambiar_de_jugador(16, 24);
            break;
        }
    }
    if (ficha == 24) {
        do {
            cout << "Ingrese una posicion adyacente: ";
            cin >> posicionNueva;
        } while (!(posicionNueva == 19 || posicionNueva == 16 || posicionNueva == 22));
        switch (posicionNueva) {
        case 19:
            cambiar_de_jugador(8, 43);
            break;
        case 16:
            cambiar_de_jugador(11, 49);
            break;
        case 22:
            cambiar_de_jugador(16, 43);
            break;
        }
    }
}

//menu de ficha a dejar
void nueva_posicion_adyacente(int& cont1, int& cont2, int& cont5, int& cont6) {
    int ficha;
    int posicionNueva;
    ficha = ingreso_de_la_posicion_a_mover(cont1, cont2);
    escoger_lugar_a_dejar(ficha, cont5, cont6);
    cout << endl;
    nueva_posicion_fase2(ficha);
}

//fase 3
void fase3(int& cont1, int& cont2, int& cont5, int& cont6) {
    int ficha;
    int posicionNueva;
    ficha = ingreso_de_la_posicion_a_mover(cont1, cont2);
    escoger_lugar_a_dejar(ficha, cont5, cont6);
    cout << endl;
    cout << "Ingrese la nueva posicion de la ficha " << endl;
    cin >> posicionNueva;
    posicion_libre(posicionNueva);
}

//ganador logo
void corona() {
    system("color f9");
    int logo_corona[25][65]{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0},
    {0,0,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,2,0,0},
    {0,0,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,2,0,0},
    {0,0,2,1,1,1,2,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,2,1,1,1,2,0,0},
    {0,0,0,2,1,1,2,0,0,0,0,0,0,2,1,1,1,2,0,0,0,0,0,0,0,0,0,2,2,2,1,1,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,2,1,1,1,2,0,0,0,0,0,0,2,1,1,2,0,0,0},
    {0,0,0,0,2,1,1,2,0,0,0,0,0,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,2,0,0,0,0,0,2,1,1,2,0,0,0,0},
    {0,0,0,0,0,2,1,2,0,0,0,0,0,0,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,2,0,0,0,0,0,0,2,1,2,0,0,0,0,0},
    {0,0,0,0,0,2,1,1,2,0,0,0,0,0,2,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,1,1,2,0,0,0,0,0,2,1,1,2,0,0,0,0,0},
    {0,0,0,0,0,0,2,1,1,2,2,0,0,0,2,1,1,1,1,2,2,0,0,0,0,0,0,0,0,2,2,1,1,1,2,2,0,0,0,0,0,0,0,0,2,2,1,1,1,1,2,0,0,0,2,2,1,1,2,0,0,0,0,0,0},
    {0,0,0,0,0,0,2,1,1,1,1,2,0,0,2,1,1,1,1,1,1,2,0,0,0,0,0,0,2,1,1,1,1,1,1,1,2,0,0,0,0,0,0,2,1,1,1,1,1,1,2,0,0,2,1,1,1,2,2,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,2,1,1,1,1,2,0,2,1,1,1,1,1,1,1,2,0,0,0,0,2,1,1,1,1,1,1,1,1,1,2,0,0,0,0,2,1,1,1,1,1,1,1,2,0,2,1,1,1,1,2,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,2,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,2,0,0,2,1,1,1,1,1,1,1,1,1,1,1,2,0,0,2,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,2,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 65; j++) {
            switch (logo_corona[i][j]) {
            case 1:
                colores(6);
                cout << char(219);
                break;
            case 2:
                colores(0);
                cout << char(219);
                break;
            case 0:
                colores(15);
                cout << char(219);
                break;
            default:
                cout << " ";
                break;
            }
        }
        cout << endl;
    }
}

//juego de fichas
int juego_fichas() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    int posicion;
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;
    int cont4 = 0;
    int cont5 = 0;
    int cont6 = 0;
    int robar1 = 0;
    int robar2 = 0;
    jugador1();
    jugador2();
    system("cls");
    colores(1);
    gotoxy(56, 10); jugador_comienza();
    colores(8);
    gotoxy(44, 15); system("pause");
    while (true) {
        system("cls");
        DibujarTablero();
        cout << endl << endl << endl;
        cout << endl << endl << endl;
        cout << endl << endl << endl;
        cout << endl;
        posicion = ingreso_de_la_posicion(cont1, cont2);
        posicion_libre(posicion);
        fichas_robadas(cont3, cont4);
        cout << endl;
        gotoxy(70, 10);
        cout << "El numero de jugadas del " << jugador_1 << " son: " << cont1 << endl;
        gotoxy(70, 12);
        cout << "El numero de jugadas del " << jugador_2 << " son: " << cont2 << endl;
        cout << endl;
        gotoxy(70, 15);
        cout << "Fichas del " << jugador_1 << ": " << cont1 - cont4;
        gotoxy(70, 16);
        cout << "Fichas del " << jugador_2 << ": " << cont2 - cont3;
        gotoxy(70, 20);
        system("pause");
        int num = cont1 + cont2;
        while (num >= 18) {
            system("cls");
            DibujarTablero();
            cout << endl << endl << endl;
            cout << endl << endl << endl;
            cout << endl << endl << endl;
            cout << endl;
            nueva_posicion_adyacente(cont1, cont2, cont5, cont6);
            fichas_robadas(cont3, cont4);
            cout << endl;
            gotoxy(70, 10);
            cout << "El numero de jugadas del " << jugador_1 << " son: " << cont1 << endl;
            gotoxy(70, 12);
            cout << "El numero de jugadas del " << jugador_2 << " son: " << cont2 << endl;
            cout << endl;
            robar1 = cont1 - (cont4 + cont6);
            robar2 = cont2 - (cont3 + cont5);
            gotoxy(70, 15);
            cout << "Fichas del " << jugador_1 << ": " << robar2;
            gotoxy(70, 16);
            cout << "Fichas del " << jugador_2 << ": " << robar1;
            gotoxy(70, 20);
            system("pause");
            if (robar1 == 2) {
                system("cls");
                cout << jugador_1 << " es el GANADOR" << endl << endl << endl;
                cout << jugador_2 << " es el PERDEDOR" << endl << endl << endl;
                corona();
                system("pause");
                return 0;
            }
            if (robar2 == 2) {
                system("cls");
                cout << jugador_2 << " es el GANADOR" << endl << endl << endl;
                cout << jugador_1 << " es el PERDEDOR" << endl << endl << endl;
                corona();
                system("pause");
                return 0;
            }
            while (robar1 == 3) {
                system("cls");
                DibujarTablero();
                cout << endl << endl << endl;
                cout << endl << endl << endl;
                cout << endl << endl << endl;
                cout << endl;
                cout << "Inica la fase 3:" << endl;
                cout << "FASE DEL VUELO!!!" << endl;
                fase3(cont1, cont2, cont5, cont6);
                fichas_robadas(cont3, cont4);
                cout << endl;
                gotoxy(70, 10);
                cout << "El numero de jugadas del " << jugador_1 << " son: " << cont1 << endl;
                gotoxy(70, 12);
                cout << "El numero de jugadas del " << jugador_2 << " son: " << cont2 << endl;
                cout << endl;
                robar1 = cont1 - (cont4 + cont6);
                robar2 = cont2 - (cont3 + cont5);
                gotoxy(70, 15);
                cout << "Fichas del " << jugador_1 << ": " << robar2;
                gotoxy(70, 16);
                cout << "Fichas del " << jugador_2 << ": " << robar1;
                gotoxy(70, 20);
                system("pause");
            }
            while (robar2 == 3) {
                system("cls");
                DibujarTablero();
                cout << endl << endl << endl;
                cout << endl << endl << endl;
                cout << endl << endl << endl;
                cout << endl;
                cout << "Inica la fase 3:" << endl;
                cout << "FASE DEL VUELO!!!" << endl;
                fase3(cont1, cont2, cont5, cont6);
                fichas_robadas(cont3, cont4);
                cout << endl;
                gotoxy(70, 10);
                cout << "El numero de jugadas del " << jugador_1 << " son: " << cont1 << endl;
                gotoxy(70, 12);
                cout << "El numero de jugadas del " << jugador_2 << " son: " << cont2 << endl;
                cout << endl;
                robar1 = cont1 - (cont4 + cont6);
                robar2 = cont2 - (cont3 + cont5);
                gotoxy(70, 15);
                cout << "Fichas del " << jugador_1 << ": " << robar2;
                gotoxy(70, 16);
                cout << "Fichas del " << jugador_2 << ": " << robar1;
                gotoxy(70, 20);
                system("pause");
            }
        }
    }
}

//logo UPC
void logo_UPC() {
    colores(4);
    int logo[20][40]{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            if (logo[i][j] == 1) {
                cout << char(219);
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

//presentación
void logo() {
    colores(7);
    gotoxy(21, 1); cout << "\t\t\t\t\t\t¡Juego del Molino!" << endl << endl;
    colores(14);
    gotoxy(30, 4); cout << "\t\t\t#########    #### " << endl;
    gotoxy(30, 5); cout << "\t\t\t#########    #### " << endl;
    gotoxy(30, 6); cout << "\t\t\t###          ####      " << endl;
    gotoxy(30, 7); cout << "\t\t\t#########    ####      " << endl;
    gotoxy(30, 8); cout << "\t\t\t#########    ####      " << endl;
    gotoxy(30, 9); cout << "\t\t\t###          ####      " << endl;
    gotoxy(30, 10); cout << "\t\t\t#########    ########   " << endl;
    gotoxy(30, 11); cout << "\t\t\t#########    ########   " << endl;
    gotoxy(30, 12); cout << endl << endl;
    colores(6);
    gotoxy(30, 15); cout << "\t\t\t###      ### ######### ###       ### ###      ### #########   " << endl;
    gotoxy(30, 16); cout << "\t\t\t###      ### ###   ### ###       ### ###      ### ###   ###   " << endl;
    gotoxy(30, 17); cout << "\t\t\t####    #### ###   ### ###       ### ####     ### ###   ###   " << endl;
    gotoxy(30, 18); cout << "\t\t\t### #  # ### ###   ### ###       ### ### #    ### ###   ###   " << endl;
    gotoxy(30, 19); cout << "\t\t\t###  ##  ### ###   ### ###       ### ###  #   ### ###   ###   " << endl;
    gotoxy(30, 20); cout << "\t\t\t###   #  ### ###   ### ###       ### ###   #  ### ###   ###   " << endl;
    gotoxy(30, 21); cout << "\t\t\t###      ### ###   ### ###       ### ###    # ### ###   ###   " << endl;
    gotoxy(30, 22); cout << "\t\t\t###      ### ###   ### ###       ### ###     #### ###   ###   " << endl;
    gotoxy(30, 23); cout << "\t\t\t###      ### ###   ### ######### ### ###      ### ###   ###   " << endl;
    gotoxy(30, 24); cout << "\t\t\t###      ### ###   ### ######### ### ###      ### ###   ###   " << endl;
    gotoxy(30, 25); cout << "\t\t\t###      ### ######### ######### ### ###      ### #########   " << endl;
    gotoxy(30, 26); cout << endl << endl;
    colores(7);
}


void menu() {
    gotoxy(50, 27); cout << "\t\tMenu" << endl << endl;
    gotoxy(50, 29); colores(11); cout << "[1] "; colores(7); cout << "Reglas del juego " << endl;
    gotoxy(50, 30); colores(11); cout << "[2] "; colores(7); cout << "Comenzar a jugar" << endl;
    gotoxy(50, 31); colores(11); cout << "[3] "; colores(7); cout << "Salir" << endl << endl;
}

void reglas() {
    colores(13);
    gotoxy(25, 4);
    for (int i = 0; i < 125; i++) {
        cout << char(205);
    }
    colores(2);
    gotoxy(79, 6); cout << "REGLAS DEL JUEGO" << endl << endl;
    gotoxy(42, 7); cout << "----------------------------------------------------------------------------------------" << endl << endl << endl;
    colores(7);
    gotoxy(37, 8); cout << "1. Para comenzar a jugar, debes ingresar tu nombre y escoger el color de tu ficha." << endl;
    gotoxy(37, 9); cout << "2. Para la primera fase del juego, cada jugador debera colocar una ficha en el tablero. " << endl;
    gotoxy(37, 10); cout << "Para esto, debes escribir la posicion en la cual quieras colocarla. Recuerda que el objetivo del juego es " << endl;
    gotoxy(37, 11); cout << "formar una linea de 3 fichas horizontal, vertical o diagonal (molino)." << endl;
    gotoxy(37, 12); cout << "3. Al formar un molino, puedes eliminar una ficha de tu oponente. Debes senalar la posicion de la ficha " << endl;
    gotoxy(37, 13); cout << "a robar." << endl;
    gotoxy(37, 14); cout << "4. La segunda fase del juego comienza cuando los jugadores hayan colocado todas sus fichas en el tablero. " << endl;
    gotoxy(37, 15); cout << "Los jugadores podrán moverlas a sus posiciones adyacentes." << endl;
    gotoxy(37, 15); cout << "5. La tercera fase del juego ocurre cuando un jugador se quede con tres fichas, Podra moverlas a cuaquier " << endl;
    gotoxy(37, 16); cout << " posición." << endl;
    gotoxy(37, 16); cout << "6. El jugador que se quede con dos piezas o no pueda mover ninguna, es el PERDEDOR" << endl;
    gotoxy(37, 17); cout << "\t\t\t\t\tQue gane el mejor!" << endl << endl;
}

void creditos() {
    colores(11);
    gotoxy(77, 4); cout << "Integrantes: " << endl;
    gotoxy(40, 5); cout << "\t-----------------------------------------------------------------------------" << endl << endl;
    colores(13);
    gotoxy(35, 6); cout << "\t\t\t" << char(3); colores(7); cout << " Angela Adriana Collazos Zuniga \tU202213515" << endl;
    colores(2); gotoxy(35, 7); cout << "\t\t\t" << char(3); colores(7); cout << " Juan Eduardo Guerrero Ojeda \t\tU202212754" << endl;
    colores(1); gotoxy(35, 8); cout << "\t\t\t" << char(3); colores(7); cout << " Matias Fabian Hidalgo Castillo \tU202211900" << endl << endl;
    colores(11);
    gotoxy(76, 11); cout << "Programacion I" << endl << endl;
}

void jugar() {
    int opcion;
    while (true) {
        gotoxy(0, 8);
        logo_UPC();
        logo();
        menu();
        do {
            gotoxy(48, 34); cout << "Elija una opcion: > "; cin >> opcion;
        } while (!(opcion >= 1 && opcion <= 4));
        switch (opcion) {
        case 1:
            system("cls");
            reglas();
            colores(8);
            gotoxy(55, 21); system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            juego_fichas();
            cout << endl << endl << endl;
            colores(8);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            exit(0);
            break;
        }
    }
}

int main()
{
    jugar();
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    system("Pause");
}