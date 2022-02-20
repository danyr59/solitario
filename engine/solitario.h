#ifndef SOLITARIO
#define SOLITARIO
#include "card.h"
#include <iostream>
/**
 * @class Solitario

 *
 *
 */

class Solitario {
private:
  int cantidad_cartas;
  Card *card;

public:
  Solitario();
  void initialize();
  void start();
  void reset();
  void debug();
  ~Solitario();
};

#endif // !SOLITARIO
