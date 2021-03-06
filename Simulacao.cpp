#include "Simulacao.h"

#include <string>
#include <vector>


Simulacao::Simulacao(Mapa *mapa, vector<Colonia *> col):colonias(col) {
	this->m = mapa;
	this->foco[0] = 0;
	this->foco[1] = 0;
	this->nextT = false;
	this->comInv = false;

	//this->m->SetMapaSer(5, 5, new Ser())    < invocar um ser para teste (incubadora?)

}


void Simulacao::processaComando(string primeira, string segunda, string terceira) {
	this->comInv = false;

	if (primeira == "next") {
		this->nextT = true;
		return;
	} else
		if (primeira == "foco") {
			this->foco[0] = stoi(segunda);
			this->foco[1] = stoi(terceira);
		} else
			if (primeira == "ser") {
				const int nr = stoi(segunda);
				const char *perfil = terceira.c_str();
				incubadora(nr, *perfil);
			}else 
				if (primeira == "ataca") {
					colonias[0]->setComando(true);
				} else
					if (primeira == "recolhe") {
						colonias[0]->setComando(false);
					}
}

void Simulacao::incubadora(int nr,char perfil){
	char id_col = 0; // <------------------------------- alterar
	for (int i = 0; i < nr; i++) {
		colonias[0]->BuildSer(perfil, id_col);
	}
}

void Simulacao::movimentodeSeres() {
	//bool ataca = this->colonias[0]->getAtaca();mudou para o Castelo

	//Comando da colonia ataque e recolhe apenas muda a boleano Comando
	//funcao chamada nos turnos
	for (int i = 0; i < colonias.size(); i++) {
		bool acao = colonias[i]->getComando();
		if (acao == true) {
			//ataca (1 move seres depois e que retira)
			m->MoveSeres();
			m->RetiraSeresDoCastelo();
		}
			
		if (acao == false) {
			//recolhe
		}
			
	}
	//m->mudaPosicoesSeresemCampo(ataca);
}

int Simulacao::getfocoX()
{
	return foco[0];
}
int Simulacao::getfocoY()
{
	return foco[1];
}
