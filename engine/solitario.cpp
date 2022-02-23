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
#include <vector>
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
  // this->aux_pilas.resize(7);
}

/**
 * @function Solitario::Start
 * @make empieza el juego , cuando el usuario lo desee
 * @return void
 *
 */
void Solitario::check(int colS, int colM) {
  std::string cols, colm;
  // verificar que en vector tenga solo una carta , ya que si
  // tiene mas de una el jugador tiene varias opciones

  int cantPop = this->aux_pilas[colS].size() - 1;

  // asigno el primer carta destapada en caso de haberla si no asigno el top de
  // la pila
  cols = this->aux_pilas[colS].size() > 1 ? this->aux_pilas[colS][0]->getValue()
         : !this->pilas[colS]->empty()    ? this->pilas[colS]->top()->getValue()
                                          : "false";
  colm = !this->pilas[colM]->empty() ? this->pilas[colM]->top()->getValue()
                                     : "false";
  // compruebo que la columna seleccionada tenga datos y no sea vacio
  if ((cols == "false" && colm != "false") ||
      (cols != "false" && colm == "false"))
    return;

  bool ok = this->aux_pilas[colS].size() > 1
                ? this->aux_pilas[colS][0]->getFamily() ==
                          this->pilas[colM]->top()->getFamily()
                      ? true
                      : false
            : this->pilas[colS]->top()->getFamily() ==
                    this->pilas[colM]->top()->getFamily()
                ? true
                : false;
  // son palos iguales
  if (ok)
    return;

#define iterarStack(cont) for (int i = 0; i <= cont; i++)

  std::cout << cols << "::" << colm << "::" << cantPop << std::endl;

  auto operation = [this, &colS, &colM, cantPop]() -> void {
    if (!this->pilas[colS]->empty()) {

      iterarStack(cantPop) {
        this->aux_pilas[colM].push_back(this->aux_pilas[colS][i]);
        this->pilas[colM]->push(this->aux_pilas[colS][i]);

        // this->aux_pilas[colS].pop_back();
        this->pilas[colS]->pop();
      }
      this->aux_pilas[colS].clear();
      if (!this->pilas[colS]->empty()) {
        this->aux_pilas[colS].push_back(this->pilas[colS]->top());
      }
    }

    // pop del elemento en la pila seleccionada
    // if (!this->pilas[colS]->empty()) {
    //   if (cantPop != 0) {
    //     iterarStack(cantPop) { this->pilas[colS]->pop(); }
    //   } else {
    //     this->pilas[colS]->pop();
    //   }

    //   if (!this->aux_pilas[colS].empty()) {
    //     if (cantPop != 0) {
    //       iterarStack(cantPop) { this->aux_pilas[colS].pop_back(); }
    //     } else {
    //       this->aux_pilas[colS].pop_back();
    //     }
    //     if (!this->pilas[colS]->empty()) {

    //       this->aux_pilas[colS].push_back(this->pilas[colS]->top());
    //     }
    //   }
    // }
  };

  if (cols == "AS" && colm == "2 ") {
    operation();
  } else if (cols == "2 " && colm == "3 ") {
    operation();
  } else if (cols == "3 " && colm == "4 ") {
    operation();
  } else if (cols == "4 " && colm == "5 ") {
    operation();
  } else if (cols == "5 " && colm == "6 ") {
    operation();
  } else if (cols == "6 " && colm == "7 ") {
    operation();
  } else if (cols == "7 " && colm == "8 ") {
    operation();
  } else if (cols == "8 " && colm == "9 ") {
    operation();
  } else if (cols == "9 " && colm == "10") {
    operation();
  } else if (cols == "10" && colm == "J ") {
    operation();
  } else if (cols == "J " && colm == "Q ") {
    operation();
  } else if (cols == "Q " && colm == "K ") {
    operation();
  }
}
void Solitario::verificarA() {
  int pila;
  std::string family;
  int escaleraA;
  for (int i = 0; i < 7; i++) {
    pila = !this->pilas[i]->empty() ? this->pilas[i]->top()->valor : -1;
    family =
        !this->pilas[i]->empty() ? this->pilas[i]->top()->getFamily() : "-1";

    if (pila == 1 && family == "C" && this->escalerasA[0].empty()) {
      this->escalerasA[0].push(this->pilas[i]->top());
      this->pilas[i]->pop();
      this->aux_pilas[i].pop_back();
    } /* else if() */
  }
}

bool verificarEscaleraA(int a, int b, std::string fA, std::string fB) {
  if (fA == fB) {
    if (a == 1 && b == 2) {
      return true;
    } else if (a == 2 && b == 3) {
      return true;
    } else if (a == 3 && b == 4) {
      return true;
    } else if (a == 4 && b == 5) {
      return true;
    } else if (a == 5 && b == 6) {
      return true;
    } else if (a == 6 && b == 7) {
      return true;
    } else if (a == 7 && b == 8) {
      return true;
    } else if (a == 8 && b == 9) {
      return true;
    } else if (a == 9 && b == 10) {
      return true;
    } else if (a == 10 && b == 11) {
      return true;
    } else if (a == 11 && b == 12) {
      return true;
    } else if (a == 12 && b == 12) {
      return true;
    }
  }
  return false;
}

bool verificarEscaleraD(int a, int b, std::string fA, std::string fB) {
  if (fA != fB) {
    if (a == 1 && b == 2) {
      return true;
    } else if (a == 2 && b == 3) {
      return true;
    } else if (a == 3 && b == 4) {
      return true;
    } else if (a == 4 && b == 5) {
      return true;
    } else if (a == 5 && b == 6) {
      return true;
    } else if (a == 6 && b == 7) {
      return true;
    } else if (a == 7 && b == 8) {
      return true;
    } else if (a == 8 && b == 9) {
      return true;
    } else if (a == 9 && b == 10) {
      return true;
    } else if (a == 10 && b == 11) {
      return true;
    } else if (a == 11 && b == 12) {
      return true;
    } else if (a == 12 && b == 12) {
      return true;
    }
  }
  return false;
}

void Solitario::mover(std::string &a) {
  auto anadirCartaMazo = [this]() -> void {
    auto anadir = [this](int i, int b) -> bool {
      for (int w = 0; w < 7; w++) {
        std::cout << "en mover" << std::endl;
        // std::cout << this->sobrantes[i].top()->valor << " "
        // << this->pilas[w]->top()->valor << std::endl;
        if (this->pilas[w]->empty() && this->sobrantes[i].top()->valor == 13) {
          this->pilas[w]->push(this->sobrantes[i].top());
          this->aux_pilas[w].push_back(this->sobrantes[i].top());
          this->sobrantes[i].pop();
        } else if (this->pilas[w]->empty()) {
          continue;
        }

        if (verificarEscaleraD(this->sobrantes[i].top()->valor,
                               this->pilas[w]->top()->valor,
                               this->sobrantes[i].top()->getFamily(),
                               this->pilas[w]->top()->getFamily())) {
          this->pilas[w]->push(this->sobrantes[i].top());
          this->aux_pilas[w].push_back(this->sobrantes[i].top());
          this->sobrantes[i].pop();
          return true;
        }
      }
      return false;
    };
    bool ok;
    if (this->sobrantes[0].size() < this->sobrantes[1].size()) {
      std::cout << "en uno" << std::endl;
      ok = anadir(1, 0);
      if (!ok) {
        this->sobrantes[0].push(this->sobrantes[1].top());
        this->sobrantes[1].pop();
      }
    } else if (this->sobrantes[1].size() < this->sobrantes[0].size()) {
      // std::cout << "en dos" << std::endl;
      ok = anadir(0, 1);
      if (!ok) {
        this->sobrantes[1].push(this->sobrantes[0].top());
        this->sobrantes[0].pop();
      }
    }
  };

  int colS, colM;
  for (auto pilas : aux_pilas) {
    if (pilas.size() == 13) {
      std::cout << "HAZ GANADO!" << std::endl;
    }
  }

  if (a.size() == 3) {
    colS = std::stoi(a.substr(0, 1)) - 1;
    colM = std::stoi(a.substr(2, 3)) - 1;

    // realiza la operatciones correspondiente
    this->check(colS, colM);
    // this->mostrarSobranteTop = false;
  } else if (a == "y") {
    // this->mostrarSobranteTop = a == "y" ? true : false;
    anadirCartaMazo();

    // colS = std::stoi(a.substr(0, 1)) - 1;
  } else if (a == "n") {
    // this->verificarA();
  }
}
void Solitario::start() {
  bool ok = true;
  std::string a;
  do {
    this->tablero();
    std::cout << "desea pedir una carta de la mano? (y/n)" << std::endl;
    std::cout
        << "(columna seleccionada)-(columna a mover). ej.`7-1` or `y/n` = ";
    std::cin >> a;

    this->mover(a);
    // std::cout << a << std::endl;
    std::cout << "0) Salir" << std::endl << "1) Continuar" << std::endl;
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
        this->card[cont].valor = 1;
        break;
      case 2:
        this->card[cont].setValue("2 ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 2;
        break;
      case 3:
        this->card[cont].setValue("3 ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 3;
        break;
      case 4:
        this->card[cont].setValue("4 ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 4;
        break;
      case 5:
        this->card[cont].setValue("5 ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 5;
        break;
      case 6:
        this->card[cont].setValue("6 ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 6;
        break;
      case 7:
        this->card[cont].setValue("7 ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 7;
        break;
      case 8:
        this->card[cont].setValue("8 ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 8;
        break;
      case 9:
        this->card[cont].setValue("9 ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 9;
        break;
      case 10:
        this->card[cont].setValue("10");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 10;
        break;
      case 11:
        this->card[cont].setValue("J ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 11;
        break;
      case 12:
        this->card[cont].setValue("Q ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 12;
        break;
      case 13:
        this->card[cont].setValue("K ");
        this->card[cont].setFamily(familia);
        this->card[cont].valor = 13;
        break;
      default:
        this->card[cont].setValue("ningun");
        this->card[cont].setFamily("ningun");
        this->card[cont].valor = -1;
        break;
      }
    }
  }
  this->random();
}
void Solitario::debug() {
#ifdef IMPRESION_ESCALERA

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
    std::cout << this->sobrantes[0].top()->getValue()
              << this->sobrantes[0].top()->getFamily() << std::endl;
    this->sobrantes[0].pop();
  }

#endif // IMPRESION_ESCALERA

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
      this->sobrantes[0].push(&card[datos_desordenados[i]]);
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

  // std::vector<Card *> cardTop;
  for (int i = 0; i < 7; i++) {
    this->aux_pilas[i].push_back(this->pilas[i]->top());
  }
  // luego llenamos las escaleras
}

void Solitario::tablero() {
  std::string space = " ";
  std::string space_ = "      ";
  std::string x = space + "  x " + space;
  // std::cout << i << std::endl;
  int i = 1;
  for (auto arr : this->aux_pilas) {
    std::cout << i << ")";
    for (auto elementos : arr) {
      std::cout << " " << elementos->getFamily() << " " << elementos->getValue()
                << " ";
    }

    i++;
    std::cout << std::endl;
  }

  // mazo sobrante

  std::cout << std::endl;
  // std::cout << "si hay una carta del mazo que quiere presionar `n`"
  // << std::endl;
  if (this->sobrantes[0].size() < this->sobrantes[1].size()) {
    std::cout << "carta del mazo:" << this->sobrantes[1].top()->getFamily()
              << " " << this->sobrantes[1].top()->getValue() << std::endl;
  } else if (this->sobrantes[1].size() < this->sobrantes[0].size()) {
    std::cout << "carta del mazo :" << this->sobrantes[0].top()->getFamily()
              << " " << this->sobrantes[0].top()->getValue() << std::endl;
  }

  // a = i == 1 ? !this->escalera1.empty()
  //                  ? this->escalera1.top()->getFamily() + " " +
  //                        this->escalera1.top()->getValue() + x + x + x + x
  //                        + x + x
  //                  : "x  " + x + x + x + x + x + x
  //     : i == 2
  //         ? !this->escalera2.empty()
  //               ? space + this->escalera2.top()->getFamily() + " " +
  //                     this->escalera2.top()->getValue() + x + x + x + x + x
  //               : "x  " + x + x + x + x + x
  //     : i == 3
  //         ? !this->escalera3.empty()
  //               ? space + space + this->escalera3.top()->getFamily() + " "
  //               +
  //                     this->escalera3.top()->getValue() + x + x + x + x
  //               : "x  " + x + x + x + x
  //     : i == 4
  //         ? !this->escalera4.empty()
  //               ? space + space + space +
  //               this->escalera4.top()->getFamily() +
  //                     " " + this->escalera4.top()->getValue() + x + x + x
  //               : "x  " + x + x + x
  //     : i == 5 ? !this->escalera5.empty()
  //                    ? space + space + space + space +
  //                          this->escalera5.top()->getFamily() + " " +
  //                          this->escalera5.top()->getValue() + x + x
  //                    : "x  " + x + x

  //     : i == 6 ? !this->escalera6.empty()
  //                    ? space + space + space + space + space +
  //                          this->escalera6.top()->getFamily() + " " +
  //                          this->escalera6.top()->getValue() + x
  //                    : "x  " + x

  //     : i == 7 ? !this->escalera7.empty()
  //                    ? space + space + space + space + space + space +
  //                          this->escalera7.top()->getFamily() + " " +
  //                          this->escalera7.top()->getValue()
  //                    : "x  "
  //              : "";

  // std::cout << a << std::endl;
  // }
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

// auto operation = [this, &colS, &colM, cantPop]() -> void {
//   // añadir a pila a mover
//   if (!this->pilas[colS]->empty()) {
//     if (cantPop != 0) {

//       iterarStack(cantPop) {
//         this->aux_pilas[colM].push_back(this->aux_pilas[colS][i]);
//         this->pilas[colM]->push(this->aux_pilas[colS][i]);
//       }

//     } else {
//       this->aux_pilas[colM].push_back(this->pilas[colS]->top());
//       this->pilas[colM]->push(this->pilas[colS]->top());
//     }
//   }

//   // pop del elemento en la pila seleccionada
//   if (!this->pilas[colS]->empty()) {
//     if (cantPop != 0) {
//       iterarStack(cantPop) { this->pilas[colS]->pop(); }
//     } else {
//       this->pilas[colS]->pop();
//     }

//     if (!this->aux_pilas[colS].empty()) {
//       if (cantPop != 0) {
//         iterarStack(cantPop) { this->aux_pilas[colS].pop_back(); }
//       } else {
//         this->aux_pilas[colS].pop_back();
//       }
//       if (!this->pilas[colS]->empty()) {

//         this->aux_pilas[colS].push_back(this->pilas[colS]->top());
//       }
//     }
//   }
// };
