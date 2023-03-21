
#include <iostream>
#include<locale.h>
#include<time.h>
// --- CONSTANTES
#define MAX 32

using namespace std;

//DEFINICIONES DE FUNCIONES
void bienvenida();
int elegirNivel();
int elegirFilas(int nivel);
int elegirColumnas(int nivel);
int elegirMinas(int nivel);
void iniciarTablero(int fila, int columna,char space[MAX][MAX]);
void colocarMinas(int fila, int columna, char space[MAX][MAX], int minas);
void colocarNumeros(int fila, int columna, char space[MAX][MAX]);
void imprimirTablero(int jugada_fila, int jugada_columna, char space[MAX][MAX, char space2[MAX][MAX], int fila, int columna);
//_________________________

int main()
{
    setlocale(LC_ALL,"spanish"); //funci�n para poder mostrar � y acentos

    int nivel, fila, columna, minas;
    int jugada_fila, jugada_columna;
    char space[MAX][MAX], space2[MAX][MAX];

    bienvenida();

    nivel = elegirNivel();
    fila = elegirFilas(nivel);
    columna = elegirColumnas(nivel);
    minas = elegirMinas(nivel);
    iniciarTablero(fila, columna, space);
    colocarMinas(fila, columna, space2, minas);
    colocarNumeros(fila, columna, space2);

    while (1) {
        cout << "Ingrese la fila y la columna que desea voltear: ";
        cin >> jugada_fila >> jugada_columna;

        imprimirTablero(jugada_fila, jugada_columna, space, space2, fila, columna);

        cout << endl;
        for (int i = 1; i < fila + 1; i++)
        {
            for (int j = 1; j < columna + 1; j++)
            {
                cout << space2[i][j];
            }
            cout << endl;
        }
    }
    
    
}

// ----- IMPLEMENTACIONES DE FUNCIONES -----
void bienvenida()
{
    cout << " __________________________________________" << endl;
    cout << "|                                          |" << endl;
    cout << "|    Bienvenido al juego de Buscaminas!    |" << endl;
    cout << "|             by: <jomerdev>               |" << endl;
    cout << "|__________________________________________|" << endl << endl;
    cout << "----- Los niveles del juego son: -----\n" << endl;
    cout << " __________________________________________" << endl;
    cout << "|                                          |" << endl;
    cout << "| <1> Nivel principiante                   |" << endl;
    cout << "| <2> Nivel intermedio                     |" << endl;
    cout << "| <3> Nivel avanzado                       |" << endl;
    cout << "| <4> Nivel personalizado                  |" << endl;
    cout << "|__________________________________________|" << endl << endl;    
    
}

int elegirNivel()
{
    int niv;
    while (1) {
        cout << "Ingrese el nivel: ";
        cin >> niv;

        if (niv == 1) break;
        else if (niv == 2) break;
        else if (niv == 3) break;
        else if (niv == 4) break;
    }

    return niv;
}

int elegirFilas(int nivel)
{
    int fila=0;
    if (nivel == 1) fila = 8;
    else if (nivel == 2) fila = 16;
    else if (nivel == 3) fila = 16;
    else if (nivel == 4) {
        while (1) {
            cout << "Ingrese el n�mero de filas: ";
            cin >> fila;
            if (fila <= 30) break; // validamos que no tenga m�s de 30 filas
            cout << "El n�mero de filas no puede ser mayor a 30" << endl;
        }
    }
    return fila;
}

int elegirColumnas(int nivel)
{
    int columna=0;
    if (nivel == 1) columna = 8;
    else if (nivel == 2) columna = 16;
    else if (nivel == 3) columna = 30;
    else if (nivel == 4) {
        while (1) {
            cout << "Ingrese el n�mero de columnas: ";
            cin >> columna;
            if (columna <= 30) break; // validamos que no tenga m�s de 30 filas
            cout << "El n�mero de columnas no puede ser mayor a 30" << endl;
        }
    }
    return columna;
}

int elegirMinas(int nivel)
{
    int minas=0;
    if (nivel == 1) minas = 10;
    else if (nivel == 2) minas = 40;
    else if (nivel == 3) minas = 99;
    else if (nivel == 4) {
        while (1) {
            cout << "Ingrese el n�mero de minas: ";
            cin >> minas;
            if (minas <= 200) break; // validamos que no tenga m�s de 30 filas
            cout << "El n�mero de minas no puede ser mayor a 200" << endl;
        }
    }
    return minas;
}

void iniciarTablero(int fila, int columna, char space[MAX][MAX])
{
    for (int i = 0; i < fila + 2; i++)
    {
        for (int j = 0; j < columna + 2; j++) {
            space[i][j] = '0';
        }
    }

    cout << " ___________________________________________________________" << endl;
    cout << "|                                                           |" << endl;
    cout << "| --- El tablero ha sido creado, puedes empezar a jugar --- |" << endl;
    cout << "|                    El tablero actual es:                  |" << endl;
    cout << "|___________________________________________________________|" << endl << endl;
    
    for (int i = 1; i < fila + 1; i++)
    {
        for (int j = 1; j < columna + 1; j++) {
            cout << space[i][j];
        }
        cout << endl;
    }
}

void colocarMinas(int fila, int columna, char space[MAX][MAX], int minas)
{
    int pfila, pcol;
    for (int i = 0; i < fila + 2; i++)
    {
        for (int j = 0; j < columna + 2; j++)
        {
            space[i][j] = '0';
        }
    }

    srand(time(NULL));

    while(1) {
        pfila = 1+rand() % fila; // aleatorio de numero de filas, empezando desde 1, porque hay una columna 0 que no se muestra
        pcol = 1+rand() % columna; // aleatorio de numero de columnas, empezando desde 1, porque hay una columna 0 que no se muestra

        if (space[pfila][pcol] == '0') {
            space[pfila][pcol] = 'X';
            minas--;
        }
        if (minas == 0) break; // si ya no quedan minas por colocar salimos del bucle
    }
}

void colocarNumeros(int fila, int columna, char space[MAX][MAX])
{    
    int numero; // variable para ir determinando el n�mero de minas encontradas alrededor de la casilla actual

    for (int i = 1; i < fila + 1; i++)
    {
        for (int j = 1; j < columna + 1; j++)
        {
            if (space[i][j] == '0') {
                numero = 0;
                // verificamos si en alguna de las casillas alrededor hay minas
                if (space[i - 1][j] == 'X')numero++;
                if (space[i - 1][j - 1] == 'X')numero++;
                if (space[i - 1][j + 1] == 'X')numero++;
                if (space[i][j - 1] == 'X')numero++;
                if (space[i][j + 1] == 'X')numero++;
                if (space[i + 1][j] == 'X')numero++;
                if (space[i + 1][j - 1] == 'X')numero++;
                if (space[i + 1][j + 1] == 'X')numero++;

                if (numero == 0)space[i][j] = ' ';
                else space[i][j] = numero+'0'; // esto practicamente lo convierte a char
            }
        }
    }
}

void imprimirTablero(int jugada_fila, int jugada_columna, char space[MAX][MAX, char space2[MAX][MAX], int fila, int columna)
{
    space[jugada_fila][jugada_columna] = space2[jugada_fila][jugada_columna];
    for (int i = 1; i < fila + 1; i++)
    {
        for (int j = 1; j < columna + 1; j++)
        {
            cout << space[i][j];
        }
        cout << endl;
    }
}
