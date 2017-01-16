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


/*
vector< vector <Identificador_Mapa*> > Mapa::retornaVectoresMapa()
{
	return this->mapa;
}


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
}

vector <vector <Identificador_Mapa *> > Mapa::mudaPosicoesSeresemCampo(bool ataca) {
	
	vector < vector <Identificador_Mapa *> > mAux = this->mapa;
	vector < Ser * > seresMovidos; bool serMovido;
	int limites[2] = { col, lin };
	int* novasCoord;
	Ser *sAux;
	//Edificio *edAux;
	for (int i = 0; i < this->col; i++) {
		for (int j = 0; j < this->lin; j++) {

			/*
			vector <Ser *> 
			if (mAux[i][j]->getTipoEdificio == "castelo") {
				edAux = mAux[i][j]->getEdificio();
				edAux->retornaSeres();

			}


			if (mAux[i][j]->getSer() != false) {
				serMovido = false;
				sAux = mAux[i][j]->getSer();

				//verifica se o ser já foi movido
				for (int verifica = 0; verifica < seresMovidos.size(); verifica++)
					if (seresMovidos[verifica] == sAux)
						serMovido = true;

				if (serMovido == false) {
					novasCoord = sAux->moveSer(sAux->getVelocidade(), sAux->getPos(), limites);

					mAux[i][j]->addSer(nullptr);
					mAux[novasCoord[0]][novasCoord[1]]->addSer(sAux);
				
					seresMovidos.push_back(sAux); // regista o ser que movimentou
					sAux = nullptr;
				}

				//ataque aqui. dá dano
				//se uma criatura morrer, guardamos o seu id e eliminamos do mapa no fim dos for's
				
			} // end if encontrou ser

		} //end for j
	} //end for i

	this->mapa = mAux;

	return mAux;
}
*/

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
int Mapa::distancia(int x, int y,int _x,int _y)
{
	int cateto1, cateto2;
	cateto1 = abs(_x - x);
	cateto2 = abs(_y - y);

	return(sqrt((cateto1*cateto1) + (cateto2*cateto2)));
}

int Mapa::ProcuraEdInimigos(int x,int y)
{
	int dist = distancia(0,0,this->col,this->lin); // distancia do mapa
	int pos[2];

	for (int i = 0; i < this->col; i++) {
		for (int j = 0; j < this->lin; j++) {
			if (mapa[i][j]->verificaEdificio() == true || mapa[i][j]->verificaCasetelo() == true) {
				int nova_distancia = distancia(x, y, i, j);
				if (nova_distancia < dist) {
					dist = nova_distancia;
					pos[0] = i;
					pos[0] = j;
				}
			}
		}
	}
	return *pos;
}
int Mapa::ProcuraSerInimigos(int x, int y)
{
	int dist = distancia(0, 0, this->col, this->lin); // distancia do mapa
	int pos[2];

	for (int i = 0; i < this->col; i++) {
		for (int j = 0; j < this->lin; j++) {
			if (mapa[i][j]->verificaSer() == true) {
				int nova_distancia = distancia(x, y, i, j);
				if (nova_distancia < dist) {
					dist = nova_distancia;
					pos[0] = i;
					pos[0] = j;
				}
			}
		}
	}
	return *pos;
}

int Mapa::calcula_direcaoMove(int x, int y, int _x, int _y)
{
	int pos[2];
	if (x > _x) {
		pos[0] = -1;
	}
	else {
		if (x == _x) {
			pos[0] = 0;
		}
		else {
			pos[0] = 1;
		}
	}

	if (y > _y) {
		pos[1] = -1;
	}
	else {
		if (y == _y) {
			pos[1] = 0;
		}
		else {
			pos[1] = 1;
		}
	}
	return *pos;
	//retorna -1 0 1 
	//exemplo -1 = x-- | 0 = x | 1 = x++ mesmo se aplica para o y
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

void Mapa::RetiraSeresDoCastelo()
{
	int pos[2];
	int numSer;
	for (int i = 0; i < this->col; i++) {
		for (int j = 0; j < this->lin; j++) {
			if (mapa[i][j]->verificaCasetelo() == true) { 
				do {
					numSer = mapa[i][j]->retornaNumSeres(); // obter numero de seres do castelo
					pos[2] = verificaPosVolta(i, j); // retorna uma posicao disponivel
					if (pos[0] != -1 && pos[1] != -1) {
						Ser *aux = mapa[i][j]->getSerDoCastelo(numSer); // apanhao ultimo ser do Castelo
						mapa[i][j]->RetiraCastelo(numSer); //Remove o ultimo Ser do castelo
						mapa[pos[0]][pos[1]]->addSer(aux); //Adiciona o ser a posicao disponivel ao volta do castelo
					}
					else { // se a pos[0] e pos[0] forem = -1 significa que nao existem mais posicoes disponiveis
						numSer = 0;
					}
				} while (numSer == 0);
			}
		}
	}
}

int Mapa::verificaPosVolta(int col, int lin)
{
	//funcao nao testada 100%
	int _x = col--;
	int _y = lin--;
	int pos[2];
	bool volta = false;
	do {
		if (mapa[_x][_y]->PremissaoParaMover() == true) {
			pos[0] = _x;
			pos[1] = _y;
			volta = true;
		}
		else {
			_y++;
			if (_y == col + 1) {
				_x++;
				_y = col--;
			}
		}
	} while (_x == col + 2);
	if (volta == false){
		pos[0] = -1;
		pos[1] = -1;
		return *pos;
	}
	else {
		return *pos;
	}
}

void Mapa::MoveSeres(){
	int pos[2];
	int xy[2];
	for (int i = 0; i < this->col; i++) {
		for (int j = 0; i < this->lin; j++) {
			if (mapa[i][j]->verificaSer() == true) {
				
				//necessario verificar a caracteristica do ser
				// se for a de procurar Edificios
					//pos[2] = this->ProcuraEdInimigos(i, j);
				// senao procura seres
					pos[2] = this->ProcuraSerInimigos(i, j);

					xy[2] = calcula_direcaoMove(i, j, pos[0], pos[1]);  // recebe se deve decrementar ou incrementar a posicao atual do ser
																		// exemplo : caso seja -1 0 e a posicao do ser seja 10 10 a
																		//			  posicao nova dele sera 9 10 (10 + (-1)) (10 + 0)
				if (pos[0] != -1 && pos[1] != -1) {
					Ser *aux = mapa[i][j]->getSer();
					mapa[i][j]->RetiraSerDoMapa();
					mapa[i+xy[0]][j+xy[1]]->addSer(aux); // racicio em cima
				}

			}
		}
	}
	this->AtualizaPosicoesMapa();
}

void Mapa::AtualizaPosicoesMapa()
{
	for (int i = 0; i < this->col; i++) {
		for (int j = 0; j < this->lin; j++) {
			if (mapa[i][j]->verificaSer() == true) {
				mapa[i][j]->atualizaPosSer(i, j);
			}
		}
	}
}
