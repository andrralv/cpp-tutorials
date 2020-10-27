#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

using namespace std;

// declaracion de prototipos
void printMessage();
int getRandomNumber(int rango);
void printEndProgramMessage();
char matrix[5][5] = {};
string board[5][5] = {};
char premios[10] = {'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e'};
int posicionX = 0;
int posicionY = 0;
char entrada;

int main() {
  srand(time(NULL)+getpid());
  // se llaman las funciones en orden dentro de main
  printMessage();

  for (int i=0;i<5;i++) {
    for (int j=0;j<5;j++) {
      matrix[i][j] = '-';
    }
  }

  // agregado de premios
  for (int i=0;i<10;i++) {
    char premio = premios[i];
    int numeroRandomX = getRandomNumber(5);
    int numeroRandomY = getRandomNumber(5);
    if (matrix[numeroRandomX][numeroRandomY] == '-') {
      matrix[numeroRandomX][numeroRandomY] = premio;

    // condiciones por si el espacio ya esta ocupado por un premio
    } else {
      if (matrix[numeroRandomX][numeroRandomY+1] == '-' && numeroRandomY+1 < 5) {
        matrix[numeroRandomX][numeroRandomY+1] = premio;
      } 
      else if (matrix[numeroRandomX][numeroRandomY-1] == '-' && numeroRandomY-1 >= 0) {
        matrix[numeroRandomX][numeroRandomY-1] = premio;
      } 
      else if (matrix[numeroRandomX+1][numeroRandomY] == '-' && numeroRandomX+1 < 5) {
        matrix[numeroRandomX+1][numeroRandomY] = premio;
      }
      else if (matrix[numeroRandomX-1][numeroRandomY] == '-' && numeroRandomX-1 >= 0) {
        matrix[numeroRandomX-1][numeroRandomY] = premio;
      }
    }
  }

  // cout << "\nMatriz de parejas de premios";

  // for (int i=0;i<5;i++) {
  //   cout << '\n';
  //   for (int j=0;j<5;j++) {
  //     cout << matrix[i][j] << ' ';
  //   }
  // }

  cout << "\nUtilice las teclas WASD para moverse. \nPresione ENTER para continuar o presione ESC durante el juego para salir.\n";
  getchar();

  // Set terminal to raw mode 
  system("stty raw"); 

  // Wait for single character  
  while ((int) entrada != 27) {
    system("clear");

    for (int i=0;i<5;i++) {
      for (int j=0;j<5;j++) {
        if (posicionX == i && posicionY == j) {
          board[i][j] = "[x]";
        } else {
          board[i][j] = "[ ]";
        }
      }
    }

    for (int i=0;i<5;i++) {
      cout << "\r\n";
      for (int j=0;j<5;j++) {
        cout << board[i][j] << ' ';
      }
    }
    cout << "\r\n>>";

    entrada = getchar();

    if (entrada == 'd') {
      if (posicionY + 1 >= 5) {
        posicionY = 0;
      } else {
        posicionY++;
      }
    }
    if (entrada == 'a') {
      if (posicionY - 1 < 0) {
        posicionY = 4;
      } else {
        posicionY--;
      }
    }
    if (entrada == 'w') {
      if (posicionX - 1 < 0) {
        posicionX = 4;
      } else {
        posicionX--;
      }
    }
    if (entrada == 's') {
      if (posicionX + 1 >= 5) {
        posicionX = 0;
      } else {
        posicionX++;
      }
    }
  }

  // Reset terminal to normal "cooked" mode 
  system("stty cooked"); 

  printEndProgramMessage();
  // fin de programa de C++ se ejecuta con return 0
  return 0;
}


void printMessage() {
  string mensaje = "Bienvenido al juego de premios tuanix.\n\n";
  std::cout << mensaje;
}

int getRandomNumber(int rango) {
  int numeroRandom;
  // esto agarra la hora de la compu y la utiliza para
  // generar un numero random, a este proceso se le llama
  // 'seeding'

  // esto genera un numero random del 0 al 9
  // variable numeroRandom dentro del scope de getRandomNumber
  numeroRandom = rand() % rango + 0;
  // utiliza la palabra return porque es una funcion tipo INT
  return numeroRandom;
};

void printEndProgramMessage() {
  cout << "\n\n************* FIN DE PROGRAMA *************\n";
};

