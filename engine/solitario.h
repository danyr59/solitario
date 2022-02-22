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
  // std::vector<Card> mazo = {
  //     {"AS", "T"}, {"2 ", "T"}, {"3 ", "T"}, {"4 ", "T"}, {"5 ", "T"},
  //     {"6 ", "T"}, {"7 ", "T"}, {"8 ", "T"}, {"9 ", "T"}, {"10", "T"},
  //     {"J ", "T"}, {"Q ", "T"}, {"K ", "T"}, {"AS", "D"}, {"2 ", "D"},
  //     {"3 ", "D"}, {"4 ", "D"}, {"5 ", "D"}, {"6 ", "D"}, {"7 ", "D"},
  //     {"8 ", "D"}, {"9 ", "D"}, {"10", "D"}, {"J ", "D"}, {"Q ", "D"},
  //     {"K ", "D"}, {"AS", "C"}, {"2 ", "C"}, {"3 ", "C"}, {"4 ", "C"},
  //     {"5 ", "C"}, {"6 ", "C"}, {"7 ", "C"}, {"8 ", "C"}, {"9 ", "C"},
  //     {"10", "C"}, {"J ", "C"}, {"Q ", "C"}, {"K ", "C"}, {"AS", "P"},
  //     {"2 ", "P"}, {"3 ", "P"}, {"4 ", "P"}, {"5 ", "P"}, {"6 ", "P"},
  //     {"7 ", "P"}, {"8 ", "P"}, {"9 ", "P"}, {"10", "P"}, {"J ", "P"},
  //     {"Q ", "P"}, {"K ", "P"}};
  // necesito crear las escaleras
  // por lo tanto neceito 7 pilas
public:
  Solitario();
  void initialize();
  void start();
  void check(int colS, int colM);
  void verificarA();
  void mover(std::string &);
  void reset();
  void tablero();
  void debug();
  void random();
  ~Solitario();
};

#endif // !SOLITARIO
