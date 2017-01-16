#pragma once

#include "Ser.h"
#include "Edificio.h"
#include "Castelo.h"

#include <sstream>
#include <iostream>
#include <string>

#ifndef IDENTIFICADOR_MAPA_H
#define IDENTIFICADOR_MAPA_H

using namespace std;

class Identificador_Mapa {
	Castelo * cast_pos;
	Ser * ser_pos;
	char colonia; // para sabermos a cor
	Edificio * edificio_pos;
	string edificio; // para sabermos que tipo de edificio
public:
	Identificador_Mapa(int linhas, int colunas);
	bool addSer(Ser * s); //estas funcoes têm que receber de que colonia são
	bool addEdificio(Edificio * e);
	bool addCastelo(Castelo *c);
	Ser* getSer();
	Edificio* getEdificio();
	bool verificaOcupado();
	bool setSer(Ser *s);
	void imprime();
	string getTipoEdificio();

};
#endif
