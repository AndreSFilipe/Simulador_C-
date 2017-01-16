#pragma once

#include "Ser.h"

#include <vector>

#ifndef EDIFICIO_H
#define EDIFICIO_H

using namespace std;

class Edificio {
	static char aux;
protected:
	char id_col;
	char id;
	int custo;
	int saude;
	int defesa;
	int posicao[2];
public:
	Edificio(int custo, int saude, int def);
	void InfoEdificio(ostringstream  & os);
	char getIdEdificio();
	void SetIdentificaCol(char id);
	void setPosEdificio(int col, int lin);
	int* getPosEdificio();
	string getTipoEd();

};


class Torre : public Edificio {
	int ataque;
public:
	Torre(int custo, int saude, int def,int atk);
	virtual void InfoEdificio(ostringstream  & os);
	virtual char getIdEdificio();
	virtual void SetIdentificaCol(char id);
	virtual int* getPosEdificio();
	virtual bool PermissaoConstrucao(int col, int lin);
	virtual void setPosEdificio(int col, int lin);

};

class Quinta : public Edificio {
	int producao;
public:
	Quinta(int custo, int saude, int def, int prod);
	/*virtual void InfoEdificio(ostringstream & os);
	virtual char getIdEdificio();
	virtual void SetIdentificaCol(char id);
	virtual int* getPosEdificio();
	virtual bool PermissaoConstrucao(int col, int lin);
	virtual void setPosEdificio(int col, int lin);*/
};
/*
*/
#endif