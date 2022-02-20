#include "solitario.h"
#include "card.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#define IMPRESION_ESCALERA
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
enum num : int {
  AS = 0,
  DOS,
  TRES,
  CUATRO,
  CINCO,
  SEIS,
  SIETE,
  OCHO,
  NUEVE,
  DIEZ,
  J,
  Q,
  K
};
void Solitario::check(int colS, int colM) {
  // auto isNumber = [](std::string a) {
  //   if (a == "1" || a == "2" || a == "3" || a == "3" || a == "4" || a == "5"
  //   ||
  //       a == "6" || a == "7" || a == "8" || a == "9" || a == "10") {
  //     return true;
  //   }
  //   return false;
  // };

  auto cols = this->pilas[colS]->top()->getValue(),
       colm = this->pilas[colM]->top()->getValue();

  // std::cout << cols << " " << colm << std::endl;

  if (cols == "AS" && colm == "2 ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "2 " && colm == "3 ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "3 " && colm == "4 ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "4 " && colm == "5 ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "5 " && colm == "6 ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "6 " && colm == "7 ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "7 " && colm == "8 ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "8 " && colm == "9 ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "9 " && colm == "10") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "10" && colm == "J ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "J " && colm == "Q ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  } else if (cols == "Q " && colm == "K ") {
    this->pilas[colM]->push(this->pilas[colS]->top());
    this->pilas[colS]->pop();
  }
}

// else if (std::stoi(cols) == 2 && std::stoi(colm) == 3) {
//   this->pilas[colM]->push(this->pilas[colS]->top());
//   this->pilas[colS]->pop();
// }

// num a = this->pilas[colS]->top()->getValue();
// std::cout << this->pilas[colS]->top()->getValue() << std::endl;
// std::cout << this->pilas[colM]->top()->getValue() << std::endl;
void Solitario::mover(std::string &a) {
  // std::cout << a << a.size() << std::endl;
  int colS, colM;
  if (a.size() == 3) {
    colS = std::stoi(a.substr(0, 1)) - 1;
    colM = std::stoi(a.substr(2, 3)) - 1;
    // std::cout << colS << " " << colM << std::endl;
    this->check(colS, colM);
    // std::cout << a.substr(1, 2) << /* " " << colM << */ std::endl;
  }
}
void Solitario::start() {
  bool ok = true;
  std::string a;
  do {
    this->tablero();
    std::cout << "(columna seleccionada)-(columna a mover). ej=7-1 = ";
    std::cin >> a;
    this->mover(a);
    // std::cout << a << std::endl;
    std::cout << "0 - Salir" << std::endl << "1 - Continuar" << std::endl;
    std::cin >> ok;

  } while (ok);
}

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
      familia = "T";
    } else if (j == 2) {
      familia = "D";
    } else if (j == 3) {
      familia = "C";
    } else if (j == 4) {
      familia = "P";
    }
    for (int i = 1; i <= this->cantidad_cartas / 4; i++, cont++) {
      // std::cout << cont << std::endl;
      switch (i) {
      case 1:
        this->card[cont].setValue("AS");
        this->card[cont].setFamily(familia);
        break;
      case 2:
        this->card[cont].setValue("2 ");
        this->card[cont].setFamily(familia);
        break;
      case 3:
        this->card[cont].setValue("3 ");
        this->card[cont].setFamily(familia);
        break;
      case 4:
        this->card[cont].setValue("4 ");
        this->card[cont].setFamily(familia);
        break;
      case 5:
        this->card[cont].setValue("5 ");
        this->card[cont].setFamily(familia);
        break;
      case 6:
        this->card[cont].setValue("6 ");
        this->card[cont].setFamily(familia);
        break;
      case 7:
        this->card[cont].setValue("7 ");
        this->card[cont].setFamily(familia);
        break;
      case 8:
        this->card[cont].setValue("8 ");
        this->card[cont].setFamily(familia);
        break;
      case 9:
        this->card[cont].setValue("9 ");
        this->card[cont].setFamily(familia);
        break;
      case 10:
        this->card[cont].setValue("10");
        this->card[cont].setFamily(familia);
        break;
      case 11:
        this->card[cont].setValue("J ");
        this->card[cont].setFamily(familia);
        break;
      case 12:
        this->card[cont].setValue("Q ");
        this->card[cont].setFamily(familia);
        break;
      case 13:
        this->card[cont].setValue("K ");
        this->card[cont].setFamily(familia);
        break;
      default:
        this->card[cont].setValue("ningun");
        this->card[cont].setFamily("ningun");
        break;
      }
    }
  }
  this->random();
}
void Solitario::debug() {
  // #if IMPRESION_ESCALERA

  std::cout << "escalera7" << std::endl;
  for (int i = 0; i < 7; i++) {
    std::cout << this->escalera7.top()->getValue() << " "
              << this->escalera7.top()->getFamily() << std::endl;
    this->escalera7.pop();
  }

  std::cout << std::endl << "escalera6" << std::endl;
  for (int i = 0; i < 6; i++) {
    std::cout << this->escalera6.top()->getValue()
              << this->escalera6.top()->getFamily() << std::endl;
    this->escalera6.pop();
  }

  std::cout << std::endl << "escalera5" << std::endl;
  for (int i = 0; i < 5; i++) {
    std::cout << this->escalera5.top()->getValue()
              << this->escalera5.top()->getFamily() << std::endl;
    this->escalera5.pop();
  }
  std::cout << std::endl << "escalera4" << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cout << this->escalera4.top()->getValue()
              << this->escalera4.top()->getFamily() << std::endl;
    this->escalera4.pop();
  }
  std::cout << std::endl << "escalera3" << std::endl;
  for (int i = 0; i < 3; i++) {
    std::cout << this->escalera3.top()->getValue()
              << this->escalera3.top()->getFamily() << std::endl;
    this->escalera3.pop();
  }
  std::cout << std::endl << "escalera2" << std::endl;
  for (int i = 0; i < 2; i++) {
    std::cout << this->escalera2.top()->getValue()
              << this->escalera2.top()->getFamily() << std::endl;
    this->escalera2.pop();
  }
  std::cout << std::endl << "escalera1" << std::endl;
  for (int i = 0; i < 1; i++) {
    std::cout << this->escalera1.top()->getValue()
              << this->escalera1.top()->getFamily() << std::endl;
    this->escalera1.pop();
  }
  std::cout << std::endl << "resto" << std::endl;
  for (int i = 0; i < 24; i++) {
    std::cout << this->sobrantes.top()->getValue()
              << this->sobrantes.top()->getFamily() << std::endl;
    this->sobrantes.pop();
  }

  // #endif // IMPRESION_ESCALERA

  // for (int i = 0; i < 52; i++) {
  //   std::cout << this->card[i].getValue() << std::endl;
  //   std::cout << this->card[i].getFamily() << std::endl << std::endl;
  // }
}
void Solitario::random() {
  std::set<int> datos;
  std::vector<int> datos_desordenados;
  bool ok;
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<int> distr(0, 51);
  int num;
  do {
    num = distr(eng);
    ok = (datos.count(num) == 0);
    if (ok) {
      datos.insert(num);
      datos_desordenados.insert(datos_desordenados.begin(), num);
      // std::cout << num << std::endl;
    }
    // std::tie(ok, std::ignore) == datos.insert(num);
  } while (datos.size() < 52);

  // llenando las escaleras
  for (int i = 0; i < 52; i++) {
    if (i < 28) {
      if (i < 7) {
        this->escalera7.push(&card[datos_desordenados[i]]);
      }
      if (i < 13 && i >= 7) {
        this->escalera6.push(&card[datos_desordenados[i]]);
      }
      if (i < 18 && i >= 13) {
        this->escalera5.push(&card[datos_desordenados[i]]);
      }
      if (i < 22 && i >= 18) {
        this->escalera4.push(&card[datos_desordenados[i]]);
      }
      if (i < 25 && i >= 22) {
        this->escalera3.push(&card[datos_desordenados[i]]);
      }
      if (i < 27 && i >= 25) {
        this->escalera2.push(&card[datos_desordenados[i]]);
      }
      if (i < 28 && i >= 27) {
        this->escalera1.push(&card[datos_desordenados[i]]);
      }
    }
    if (i >= 28) {
      this->sobrantes.push(&card[datos_desordenados[i]]);
    }
    // datos_desordenados[i];
  }
  // for (auto posiciones : datos) {
  //   std::cout << posiciones << std::endl;
  // }
  // for (int n = 0; n < 10; n++) {
  //   std::cout << distr(eng) << std::endl;
  // }

  this->pilas[0] = &this->escalera1;
  this->pilas[1] = &this->escalera2;
  this->pilas[2] = &this->escalera3;

  this->pilas[3] = &this->escalera4;
  this->pilas[4] = &this->escalera5;
  this->pilas[5] = &this->escalera6;
  this->pilas[6] = &this->escalera7;

  // luego llenamos las escaleras
}

void Solitario::tablero() {
  for (int i = 1; i <= 7; i++) {

    // auto a =
    //     [this]() {
    //       std::cout << this->escalera1.top();
    //       return 1;
    //     }

    std::string space = "       ";
    std::string space_ = "      ";
    std::string x = space_ + "x";
    std::string a;
    // std::cout << i << std::endl;
    a = i == 1 ? this->escalera1.top()->getFamily() + " " +
                     this->escalera1.top()->getValue() + x + x + x + x + x + x
        : i == 2 ? space + this->escalera2.top()->getFamily() + " " +
                       this->escalera2.top()->getValue() + x + x + x + x + x
        : i == 3 ? space + space + this->escalera3.top()->getFamily() + " " +
                       this->escalera3.top()->getValue() + x + x + x + x
        : i == 4 ? space + space + space + this->escalera4.top()->getFamily() +
                       " " + this->escalera4.top()->getValue() + x + x + x
        : i == 5 ? space + space + space + space +
                       this->escalera5.top()->getFamily() + " " +
                       this->escalera5.top()->getValue() + x + x
        : i == 6 ? space + space + space + space + space +
                       this->escalera6.top()->getFamily() + " " +
                       this->escalera6.top()->getValue() + x
        : i == 7 ? space + space + space + space + space + space +
                       this->escalera7.top()->getFamily() + " " +
                       this->escalera7.top()->getValue()
                 : "";

    std::cout << a << std::endl;
  }
}

Solitario::~Solitario() { delete[] card; }

// static const treboles All[] = {treboles::AS, treboles::DOS,
// treboles::TRES}; enum class diamantes {
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
