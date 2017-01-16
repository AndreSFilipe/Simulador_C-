#pragma once

#ifndef CONFIGURACAO_H
#define CONFIGURACAO_H
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <ctime>
#include "Perfil.h"

using namespace std;

class Configuracao {
	vector<string> caracteristicas;

	int dimLin, dimCol, moedas, opon, tamanho;
	bool dimT, moedasT, oponT, inicioT, comInv;
	bool setOp; // ?
	//vector<int> Pos_castelo;
	vector<Perfil *> perfis;
	vector<int> Cast_Y;
	vector<int> Cast_X;
public:
	Configuracao();
	void processaComando(string primeira, string segunda, string terceira, string quarta);
	void loadFile(string fich);
	void setInicio();
	void mkperfil(string segunda);
	void addperfil(string segunda, string terceira);
	void subperfil(string segunda, string terceira);
	void rmperfil(string segunda);
	vector<string> getCar(int i);


	/*FUNÇOES*/
	int getTamanho(int _x,int _y);
	void setDim(int lin, int col);
	int getDimLin();
	int getDimCol();
	void setMoedas(int n);
	int getMoedas();
	Perfil * getPerfil(int i);
	int getTamanhoVectorPerfil();
	//void posiciona_castelos(int n);
	void setOponentes(int op);
	int getOponentes();
	void setPosCastelo(string col, int x, int y);
	//int getPosInVector(int positionVetor);
	bool getInicio();
	// refere-se a posicao do vetor 0 1 2 3
	bool getcomInv();
	bool getdimT();
	bool getmoedasT();
	bool getoponT();
	int gettamvetor();
	char getcharperf(int i);
	int getForcaPerf(int i);
	int getCustoPerf(int i);
	void Castelos_menu(int _i);
	int getCast_X(int i);
	int getCast_Y(int i);

};

#endif // !CONFIGURACAO_H
