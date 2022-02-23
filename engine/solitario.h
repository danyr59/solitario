#ifndef SOLITARIO
#define SOLITARIO
#include "card.h"
#include <iostream>
#include <stack>
#include <vector>
/**
 * @class Solitario

 *
 *
 */

class Solitario {
private:
  int cantidad_cartas;
  // array de cards donde las cuales voy a apuntar
  Card *card;

protected:
  // bool comenzar;
  std::stack<Card *> escalera1;
  std::stack<Card *> escalera2;
  std::stack<Card *> escalera3;
  std::stack<Card *> escalera4;
  std::stack<Card *> escalera5;
  std::stack<Card *> escalera6;
  std::stack<Card *> escalera7;

  // bool
  bool mostrarSobranteTop = false;

  // sobrantes[2] representa:
  //[0]-> las cartas sobrantes del random inicial
  //[1]-> las cartas que se piden y no encajan las empujamos a esta pila
  std::stack<Card *> sobrantes[2];

  // array  de stack que representa las 7 escaleras del juego
  std::stack<Card *> *pilas[7];

  // este vector me es util para ver las cartas destapadas o que estan en el
  // tope de los stacks
  // y asi poder mapearlas
  std::vector<Card *> aux_pilas[7];

  std::stack<Card *> escalerasA[4];
  // necesito crear las escaleras
  // por lo tanto neceito 7 pilas

  bool estadoMazo = false;

public:
  Solitario();
  void initialize();
  int start();
  void VerificarEscaleras(int colS, int colM);
  int mover(std::string &);
  void reset();
  void verificacionCartaMazo();
  void tablero();
  void random();
  ~Solitario();
};

#endif // !SOLITARIO
