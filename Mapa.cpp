#include "Mapa.h"

Mapa::Mapa(int linhas,int colunas): lin(linhas),col(colunas) {
	this->tamanho = linhas * colunas;
	
	for (int i = 0; i < col; i++) {
		vector<Identificador_Mapa*> linha;
		for (int j = 0; j < lin; j++) {
			linha.push_back(new Identificador_Mapa(j, i));
		}
		this->mapa.push_back(linha);
	}
}

int Mapa::getLin()
{
	return this->lin;
}
int Mapa::getCol()
{
	return this->col;
}
int Mapa::getTamanho()
{
	return this->tamanho;
}
Identificador_Mapa * Mapa::getCelula(int lin, int col)
{
	return this->mapa[col][lin];
}
void Mapa::setLin(int lin){
	this->lin = lin;
}
void Mapa::setCol(int lin) {
	this->col = col;
}



vector< vector <Identificador_Mapa*> > Mapa::retornaVectoresMapa()
{
	return this->mapa;
}

/*
bool Mapa::mudaPosicao(Ser * s, int new_position)
{
	vector<Identificador_Mapa*> Vaux = this->mapa;
	for (int i = 0; i < Vaux.size(); i++) {
		if (Vaux[i]->getSer() == false) {
			return false;
		}
		Ser *Saux = Vaux[i]->getSer(); // unable to read memory

		if (Saux->getID() == s->getID() && Saux == NULL) {
			Vaux[i]->setSer(nullptr);
			if (Vaux[new_position]->getSer() == nullptr)
				Vaux[new_position]->addSer(s);
			else {
				Vaux[i]->setSer(Saux);
				return false;
			}
				
		}
	}

	return true;
}*/

vector<vector<Identificador_Mapa *>> Mapa::mudaPosicoesSeresemCampo() {
	
	vector < Ser * > seresMovidos; bool serMovido;
	int limites[2] = { col, lin };
	for (int i = 0; i < this->col; i++) {
		for (int j = 0; j < this->lin; j++) {

			if (mapa[i][j]->getSer() != false) {
				serMovido = false;
				int* novasCoord;
				Ser *sAux;
				vector<int> posOcupadas;

				sAux = mapa[i][j]->getSer();

				//verifica se o ser já foi movido
				for (int verifica = 0; verifica < seresMovidos.size(); verifica++)
					if (seresMovidos[verifica] == sAux)
						serMovido = true;

				if (serMovido == false) {
					
					bool ocupado;
					do {
						novasCoord = sAux->moveSer(sAux->getVelocidade(), sAux->getPos(), limites, posOcupadas);
						ocupado = mapa[novasCoord[0]][novasCoord[1]]->verificaOcupado();
						if (ocupado == true) {
							posOcupadas.push_back(novasCoord[0]);
							posOcupadas.push_back(novasCoord[1]);
						}
					} while (ocupado == true); // se ocupado == false, continua:


					mapa[i][j]->addSer(nullptr);
					mapa[novasCoord[0]][novasCoord[1]]->addSer(sAux);

					seresMovidos.push_back(sAux); // regista o ser que movimentou
					sAux = nullptr;
				}

				
			} // end if encontrou ser

		} //end for j
	} //end for i

	return mapa;
}

void Mapa::colocaSeresemCampo(vector<Ser*> Saux)						// vector out of range
//falta resolver a questão de se não podem sair mais seres, 
//max 8 seres se o castelo não estiver numa borda.
{
	Ser* sAux;	
	int limites[2] = { col, lin };
	vector<int> posOcupadas;

	for (int i = 0; i < sizeof(Saux); i++) {
		sAux = Saux[i];
		int* novasCoord; 
		bool ocupado;
		do {
			novasCoord = sAux->moveSer(sAux->getVelocidade(), sAux->getPos(), limites, posOcupadas);
			ocupado = mapa[novasCoord[0]][novasCoord[1]]->verificaOcupado();
			if (ocupado == true) {
				posOcupadas.push_back(novasCoord[0]);
				posOcupadas.push_back(novasCoord[1]);
			}
		} while (ocupado == true); // se ocupado == false, continua:


		mapa[novasCoord[0]][novasCoord[1]]->addSer(sAux);

		sAux = nullptr;
	}

}


void Mapa::preencheMapaEcrajogo(int x, int y)
{
	int limX = x + 20;
	int limY = y + 40;

	for (int i = x; i < limX; i++)
		for (int j = y; j < limY; j++) {
			Consola::gotoxy(9 + ((j - y) * 4), 5 + ((i - x) * 2));
			mapa[i][j]->imprime();
		}
}
bool Mapa::SetMapaSer(int _x, int _y,Ser *s){
	if (this->mapa[_x][_y]->getSer() == false && this->mapa[_x][_y]->getEdificio() == false) {
		this->mapa[_x][_y]->addSer(s);
		return true;
	}
	else
		return false;
}
bool Mapa::SetMapaEdificio(int _x, int _y, Edificio * e){
	if (this->mapa[_x][_y]->getSer() == false && this->mapa[_x][_y]->getEdificio() == false) {
		this->mapa[_x][_y]->addEdificio(e);
		return true;
	}
	else
		return false;

}
bool Mapa::SetMapaCastelo(int _x, int _y, Castelo * c) {
	if (this->mapa[_x][_y]->getSer() == false && this->mapa[_x][_y]->getEdificio() == false) {
		this->mapa[_x][_y]->addCastelo(c);
		return true;
	}
	else
		return false;

}
