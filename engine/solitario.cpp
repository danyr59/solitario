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

static int m;
// static int mazo_aux;
/**
 * @function Solitario
 * @param none
 * @make constructor
 *
 */

Solitario::Solitario() : cantidad_cartas(52) {
  this->card = new Card[this->cantidad_cartas];
  this->initialize();
}

/**
 * @function Solitario::Start
 * @make empieza el juego , cuando el usuario lo desee
 * @return int -> EXIT
 *
 */
int Solitario::start() {
  bool ok = true;
  int exit;
  std::string a;
  do {
    this->tablero();

    std::cin >> a;

    exit = this->mover(a);
    if (exit == 1) {
      ok = false;
    }

  } while (ok);
  return exit;
}

/**
 * @function Solitario::VerificarEscaleras
 * @make hace la verificacion de las operaciones correpondientes entre escaleras
 * o stacks
 * @return void
 *
 */
void Solitario::VerificarEscaleras(int colS, int colM) {
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

  // std::cout << cols << "::" << colm << "::" << cantPop << std::endl;

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
    } else if (a == 12 && b == 13) {
      return true;
    }
  }
  return false;
}

/**
 * @function Solitario::verificacionCartaMazo
 * @make  realiza la verificacion y cambio cuando se pide una carta del mazo,
 * de no haber una carta con la que sea compatible , se depositara en una
 * pila secundaria
 * @return void
 *
 */

void Solitario::verificacionCartaMazo() {
  auto anadir = [this](int i, int b) -> bool {
    for (int w = 0; w < 7; w++) {
      // std::cout << "en mover" << std::endl;

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

  if (this->sobrantes[1].empty() && this->sobrantes[0].empty())
    return;

  bool ok;
  if (this->estadoMazo && m != 0) {
    std::cout << "en uno" << std::endl;
    ok = anadir(1, 0);
    if (!ok) {
      this->sobrantes[0].push(this->sobrantes[1].top());
      this->sobrantes[1].pop();
    }
    m--;
  } else if (m != 0) {
    std::cout << "en dos" << std::endl;
    ok = anadir(0, 1);
    if (!ok) {
      this->sobrantes[1].push(this->sobrantes[0].top());
      this->sobrantes[0].pop();
    }
    m--;
  }

  if (this->sobrantes[1].empty()) {
    this->estadoMazo = false;
    m = this->sobrantes[0].size();

  } else if (this->sobrantes[0].empty()) {
    this->estadoMazo = true;
    m = this->sobrantes[1].size();
  }
}

;

/**
 * @function Solitario::mover
 * @make  hace la administracion de los eventos
 * @return void
 *
 */

int Solitario::mover(std::string &a) {

  int colS, colM;
  for (auto pilas : aux_pilas) {
    if (pilas.size() == 13) {
      std::cout << "HAZ GANADO!" << std::endl;
      return 1;
    }
  }

  if (a.size() == 3) {
    colS = std::stoi(a.substr(0, 1)) - 1;
    colM = std::stoi(a.substr(2, 3)) - 1;

    this->VerificarEscaleras(colS, colM);
  } else if (a == "y") {
    this->verificacionCartaMazo();

  } else if (a == "n") {
    // this->verificarA();
  } else if (a == "s") {
    return 1;
  }
  return 0;
}

/**
 * @function Solitario::reset
 * @make  hace un reset
 * @return void
 *
 */

void Solitario::reset() { this->initialize(); }

/**
 * @function Solitario::initialize
 * @make  inicializa las memoria dinamica de cartas
 * @return void
 *
 */
void Solitario::initialize() {
  std::vector<Card> mazo = {
      {"AS", "T", "1"},  {"2 ", "T", "2"},  {"3 ", "T", "3"},
      {"4 ", "T", "4"},  {"5 ", "T", "5"},  {"6 ", "T", "6"},
      {"7 ", "T", "7"},  {"8 ", "T", "8"},  {"9 ", "T", "9"},
      {"10", "T", "10"}, {"J ", "T", "11"}, {"Q ", "T", "12"},
      {"K ", "T", "13"}, {"AS", "P", "1"},  {"2 ", "P", "2"},
      {"3 ", "P", "3"},  {"4 ", "P", "4"},  {"5 ", "P", "5"},
      {"6 ", "P", "6"},  {"7 ", "P", "7"},  {"8 ", "P", "8"},
      {"9 ", "P", "9"},  {"10", "P", "10"}, {"J ", "P", "11"},
      {"Q ", "P", "12"}, {"K ", "P", "13"}, {"AS", "D", "1"},
      {"2 ", "D", "2"},  {"3 ", "D", "3"},  {"4 ", "D", "4"},
      {"5 ", "D", "5"},  {"6 ", "D", "6"},  {"7 ", "D", "7"},
      {"8 ", "D", "8"},  {"9 ", "D", "9"},  {"10", "D", "10"},
      {"J ", "D", "11"}, {"Q ", "D", "12"}, {"K ", "D", "13"},
      {"AS", "C", "1"},  {"2 ", "C", "2"},  {"3 ", "C", "3"},
      {"4 ", "C", "4"},  {"5 ", "C", "5"},  {"6 ", "C", "6"},
      {"7 ", "C", "7"},  {"8 ", "C", "8"},  {"9 ", "C", "9"},
      {"10", "C", "10"}, {"J ", "C", "11"}, {"Q ", "C", "12"},
      {"K ", "C", "13"}};

  int i = 0;
  for (auto card : mazo) {
    this->card[i] = card;
    i++;
  }
  // for (int w = 0; w < 52; w++) {
  //   std::cout << this->card[w] << std::endl;
  // }

  this->random();
}

/**
 * @function Solitario::random
 * @make  inicializa las pilas (escaleras del juego) con los elementos random
 * (memoria)
 * @return void
 *
 */

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
    }
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
  }

  this->pilas[0] = &this->escalera1;
  this->pilas[1] = &this->escalera2;
  this->pilas[2] = &this->escalera3;

  this->pilas[3] = &this->escalera4;
  this->pilas[4] = &this->escalera5;
  this->pilas[5] = &this->escalera6;
  this->pilas[6] = &this->escalera7;

  for (int i = 0; i < 7; i++) {
    this->aux_pilas[i].push_back(this->pilas[i]->top());
  }
}

/**
 * @function Solitario::tablero
 * @make  representa el tablero por consola
 * @return void
 *
 */

void Solitario::tablero() {
  std::string space = " ";
  std::string space_ = "      ";
  std::string x = space + "  x " + space;
  int i = 1;
  std::string xs[7];
  for (int r = 0; r < 7; r++) {
    for (int j = 0; j < r; j++) {
      xs[r] += x;
    }
  }
  for (auto arr : this->aux_pilas) {
    std::cout << i << ")" << xs[i - 1];
    for (auto elementos : arr) {
      std::cout << " " << elementos->getFamily() << " " << elementos->getValue()
                << " ";
    }

    i++;
    std::cout << std::endl;
  }

  // mazo sobrante

  std::cout << std::endl;
  if (this->estadoMazo && m != 0) {
    std::cout << "carta del mazo:" << this->sobrantes[1].top()->getFamily()
              << " " << this->sobrantes[1].top()->getValue() << std::endl;
  } else if (m != 0) {
    std::cout << "carta del mazo :" << this->sobrantes[0].top()->getFamily()
              << " " << this->sobrantes[0].top()->getValue() << std::endl;
    // std::cout << "si hay una carta del mazo que quiere presionar `n`"
  }
  std::cout << "Presionar `s` para salir" << std::endl;

  std::cout << "desea pedir una carta de la mano? (y/n)" << std::endl;
  std::cout << "(fila seleccionada)-(fila a mover). ej.`7-1` or `y/n` = ";
}

/**
 * @function Solitario::~Solitario
 * @make  elimina memoria dinamica del juego
 * @return void
 *
 */

Solitario::~Solitario() { delete[] card; }
