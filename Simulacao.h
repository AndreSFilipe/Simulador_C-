#pragma once
#include <vector>
#include <iostream>

#include "Configuracao.h"
#include "Colonia.h"
#include "Mapa.h"
#include "Simulacao.h"
#include "Ser.h"
#include "Consola.h"


class Simulacao {
	Mapa *m;
	vector<Colonia *> colonias;

	int foco[2];
	bool comInv, nextT;
public:
	Simulacao(Mapa *mapa, vector<Colonia *> col);
	void processaComando(string primeira, string segunda, string terceira);
	void imprimeEdificios();
	void incubadora(int nr, char perfil);
	void movimentodeSeres();
	void moveSeres();
	void atualizaPos();
	int getfocoX();
	int getfocoY();

};

