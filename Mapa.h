#pragma once

#include "Identificador_Mapa.h"
#include "Consola.h"
#include "Castelo.h"


#include <sstream>
#include <iostream>
#include <vector>

#ifndef MAPA_H
#define MAPA_H

using namespace std;

class Mapa {
private:
	//LINHAS SAO Y E COLUNAS SAO X <- capslock da revolta
	int lin , col;
	int tamanho;
	vector < vector <Identificador_Mapa *> > mapa;
public:
	Mapa(int linhas, int colunas);

	//gets e set
	int getLin();
	int getCol();
	int getTamanho();
	Identificador_Mapa * getCelula(int lin, int col);
	void setLin(int lin);
	void setCol(int col);
	bool SetMapaSer(int _x, int _y, Ser *s);
	bool SetMapaEdificio(int _x, int _y, Edificio * e);
	bool SetMapaCastelo(int _x, int _y, Castelo * c);
	void RetiraSeresDoCastelo();
	int verificaPosVolta(int col, int lin);
	void MoveSeres();
	void AtualizaPosicoesMapa();
	void preencheMapaEcrajogo(int x, int y);
	int distancia(int x, int y, int _x, int _y); // x e y da posicao do ser e _x e _y coord do outro objecto
	int ProcuraEdInimigos(int x, int y);
	int ProcuraSerInimigos(int x, int y);
	int calcula_direcaoMove(int x, int y, int _x, int _y); // variaveis iguais a funcao distancia
	//int PosCoord_X(int pos);
	//int PosCoord_Y(int pos);
	//int CoordPos(int _x,int _y);
	//void InfoMapa();


	//vector <vector <Identificador_Mapa*> > retornaVectoresMapa();
	//vector <vector <Identificador_Mapa*> > mudaPosicoesSeresemCampo(bool ataca);
};

#endif