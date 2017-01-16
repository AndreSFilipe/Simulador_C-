#pragma once

#include "Edificio.h"
#include "Castelo.h"

#include <iostream>
#include <vector>

#ifndef COLONIA_H
#define COLONIA_H

using namespace std;

class Colonia {
private:
    char id;
	static char aux;
	int moedas;
	bool Comando; // ataca ou recolhe -true (ataca) e -false(recolhe)
	Castelo *castelo;
    vector <Perfil *> perfis;
    vector <Ser *> seres;
    vector <Edificio *> edificos;

//	bool ataca; passar para o castelo
public:
    Colonia(Castelo *c);
	bool AddPerfil(Perfil *p);
	//bool AddSer(Ser *s);
	bool AddEdificio(Edificio *e);
	bool BuildSer(char perfil, char id_col);
	char getIDCol();
	//bool ConfirmaPagamentoSer();
	//bool ConfirmaPagamentoEdificios();
	int getMoedas();
	void setMoedas(int moedas);
	void infoColonia();
	int posPerfil(char perfil);
	Edificio * getCast();

	bool getComando();
	void setComando(bool n);
	
};

#endif /* COLONIA_H */
