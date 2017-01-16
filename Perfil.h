#pragma once

#ifndef PERFIL_H
#define PERFIL_H
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Perfil;
class Caracteristica {
protected:
	int id;
	string nome;
	int custo;
	int forca;
public:
	Caracteristica(string _nome,int _id,int _custo, int _forca);
	int getForca();
	int getCusto();
	string getNome();
	virtual void infoCaracteristica(ostringstream & os);
	virtual Caracteristica *clone();						// incluir esta vitual em todos

};
class Bandeira : public Caracteristica {
public:
	Bandeira(int cust,int forc);
	virtual void infoCaracteristica(ostringstream & os);
	//virtual Bandeira *clone();
};
class Superior : public Caracteristica {
	int up_saude;
public:
	Superior(int cust, int forc);
	virtual void infoCaracteristica(ostringstream & os);
	int getSau();
};
class PeleDura : public Caracteristica {
	int upDef;
public:
	PeleDura(int cust, int forc);
	//virtual void infoCaracteristica(ostringstream & os);
	int getDef();

};
class Armadura : public Caracteristica {
	int upDef;
public:
	Armadura(int cust, int forc);
	//virtual void infoCaracteristica(ostringstream & os);
	int getDef();
};

class Faca : public Caracteristica {
	int upAtk;
public:
	Faca(int cust, int forc);
	//virtual void infoCaracteristica(ostringstream & os);
	int getAtk();

};

class Espada : public Caracteristica {
	int numAtk;
	int upAtk;
	bool reload;
public:
	Espada(int custo, int forc);
	//virtual void infoCaracteristica(ostringstream & os);
	int getAtk();
	void setAtk(int _upAtk);
	int getNumAtk();
	void setNumAtk(int _NumAtk);
	bool getReload();
	void setRealod(bool _reload);
};

class Perfil {
private:
	char id;
	int forca;
	int custo;
	//updates do ser
	int defesa;
	int hp;
	int ataque;
	vector<Caracteristica *> caracteristicas;
	vector<string> nomesCar;

public:
	Perfil(char i);
	Perfil(Perfil & p);
	bool addCarateristica(Caracteristica * c);
	void subCarateristica(int i);
	void perfilMenu(string nome);
	char getID();
	int getForca();
	void setForca(int _f);
	int getCusto();
	void setCusto(int _c);
	vector<string> getCar();
	void infoPerfil() const;
};
#endif
