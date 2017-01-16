#pragma once

#include "Ser.h"

#include <vector>


#ifndef CASTELO_H
#define CASTELO_H

class Castelo {
	char id_col;
	int custo;
	int saude;
	int defesa;
	int posicao[2];
	vector <Ser *> edSeres;
	bool ordem; // toggle para os comandos "ataca" e "recolhe"
public:
	Castelo();
	//void InfoEdificio(ostringstream  & os);
	char getIdColonia();
	void SetIdentificaCol(char id);
	void setPosEdificio(int col, int lin);
	int* getPosEdificio();
	bool addSer(Ser *s);
	vector<Ser*> retornaSeres();
	void setOrdem(bool ordem);
	bool getOrdem();

};

#endif