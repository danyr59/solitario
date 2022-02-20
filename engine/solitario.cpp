#include "solitario.h"
#include "card.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

/**
 * @function Solitario
 * @param {type: int , name: cantidad} -> cantidad de cartas en el juego
 * @make constructor
 * @return void
 *
 */

Solitario::Solitario() : cantidad_cartas(52) {
  this->card = new Card[this->cantidad_cartas];
  this->initialize();
}

/**
 * @function Solitario::Start
 * @make empieza el juego , cuando el usuario lo desee
 * @return void
 *
 */
void Solitario::start() {}

/**
 * @function Solitario::Start
 * @make empieza el juego , cuando el usuario lo desee
 * @return void
 *
 */
void Solitario::reset() { this->initialize(); }

/**
 * @function Solitario::Start
 * @make empieza el juego , cuando el usuario lo desee
 * @return void
 *
 */
void Solitario::initialize() {
  std::string familia;
  int cont = 0;
  for (int j = 1; j <= 4; j++) {
    if (j == 1) {
      familia = "treboles";
    } else if (j == 2) {
      familia = "diamantes";
    } else if (j == 3) {
      familia = "corazones";
    } else if (j == 4) {
      familia = "picas";
    }
    for (int i = 1; i <= this->cantidad_cartas / 4; i++, cont++) {
      // std::cout << cont << std::endl;
      switch (i) {
      case 1:
        this->card[cont].setValue("As");
        this->card[cont].setFamily(familia);
        break;
      case 2:
        this->card[cont].setValue("2");
        this->card[cont].setFamily(familia);
        break;
      case 3:
        this->card[cont].setValue("3");
        this->card[cont].setFamily(familia);
        break;
      case 4:
        this->card[cont].setValue("4");
        this->card[cont].setFamily(familia);
        break;
      case 5:
        this->card[cont].setValue("5");
        this->card[cont].setFamily(familia);
        break;
      case 6:
        this->card[cont].setValue("6");
        this->card[cont].setFamily(familia);
        break;
      case 7:
        this->card[cont].setValue("7");
        this->card[cont].setFamily(familia);
        break;
      case 8:
        this->card[cont].setValue("8");
        this->card[cont].setFamily(familia);
        break;
      case 9:
        this->card[cont].setValue("9");
        this->card[cont].setFamily(familia);
        break;
      case 10:
        this->card[cont].setValue("10");
        this->card[cont].setFamily(familia);
        break;
      case 11:
        this->card[cont].setValue("J");
        this->card[cont].setFamily(familia);
        break;
      case 12:
        this->card[cont].setValue("Q");
        this->card[cont].setFamily(familia);
        break;
      case 13:
        this->card[cont].setValue("K");
        this->card[cont].setFamily(familia);
        break;
      default:
        this->card[cont].setValue("ningun");
        this->card[cont].setFamily("ningun");
        break;
      }
    }
  }
}
void Solitario::debug() {
  for (int i = 0; i < 52; i++) {
    std::cout << this->card[i].getValue() << std::endl;
    std::cout << this->card[i].getFamily() << std::endl << std::endl;
  }
}
Solitario::~Solitario() { delete[] card; }

// static const treboles All[] = {treboles::AS, treboles::DOS, treboles::TRES};
// enum class diamantes {
//   AS = 1,
//   DOS,
//   TRES,
//   CUATRO,
//   CINCO,
//   SEIS,
//   SIETE,
//   OCHO,
//   NUEVE,
//   DIEZ,
//   J,
//   Q,
//   K
// };
// enum class corazones {
//   AS = 1,
//   DOS,
//   TRES,
//   CUATRO,
//   CINCO,
//   SEIS,
//   SIETE,
//   OCHO,
//   NUEVE,
//   DIEZ,
//   J,
//   Q,
//   K
// };
// enum class picas {
//   AS = 1,
//   DOS,
//   TRES,
//   CUATRO,
//   CINCO,
//   SEIS,
//   SIETE,
//   OCHO,
//   NUEVE,
//   DIEZ,
//   J,
//   Q,
//   K
// };

// namespace Mazo {
// const char *names[] = {"AS", "2", "3",  "4", "5", "6", "7",
//                        "8",  "9", "10", "J", "Q", "K"};
// enum num : int {
//   AS = 0,
//   DOS,
//   TRES,
//   CUATRO,
//   CINCO,
//   SEIS,
//   SIETE,
//   OCHO,
//   NUEVE,
//   DIEZ,
//   J,
//   Q,
//   K
// };
// } // namespace Mazo
