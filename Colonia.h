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
	Castelo *castelo;
    vector <Perfil *> perfis;
    vector <Ser *> seres;
    vector <Edificio *> edificos;

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
	bool getOrdem();
	void setOrdem(bool ordem);
	vector <Ser*> getSeresCastelo();
	
};

#endif /* COLONIA_H */
