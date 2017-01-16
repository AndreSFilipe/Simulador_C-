#pragma once

#include "Perfil.h"

#include <sstream>
#include <iostream>
#include <vector>

#ifndef SER_H
#define SER_H



using namespace std;

class Ser {
private:
	Perfil * perf;
	char id_col;
	char id;
	static char aux;
	int ataque;
	int defesa;
	int forca;
	int saude;
	int custo;
	int posicao[2];
	int velocidade;

public:
    Ser(Perfil * p);
	int getSaude();
	void setSaude(int saude);
	int getCusto();
	void setCusto(int custo);
	int getForca();
	void setForca(int forca);

	void setPosicao(int lin, int col);
	int* getPos();
	int* moveSer(int velocidade, int posicao[], int limites[], vector<int> posOcupadas);
	void mostraSerInfo(ostringstream & os) const;
	int getVelocidade();
	char getID();
	void setIDCol(int n);
};

#endif
