#pragma once
#include <vector>
#include <time.h>
#include "Abogado.h"
#include "Cuchillo.h"
#include "Robot.h"
#include "Civil.h"
#include "Soldado.h"
#include "Aliado.h"
#include "BarraDeVida.h"
#include "Ave.h"
#include "Arbol.h"
#include "Comentario.h"

class Controlador {
private:
	//Nivel
	int nivel2;
	//Heroes
	Abogado* abogado;
	Aliado* perroV1;
	Aliado* perroV2;
	BarraDeVida* barraDeVida;
	Comentario* comentario;
	int contArboles;
	int ComentarioAleatorio;

	//Enemigos
	vector<Cuchillo*> cuchillos;
	vector<Robot*> robots;
	vector <Civil*> civiles;
	vector<Soldado*> soldados;
	vector<Ave*> aves;
	vector<Arbol*> arboles;

	time_t cambiaComentario;
	time_t spawnRobots;
	time_t spawnCiviles;
	time_t spawnSoldados;
	time_t spawnRobots2;
	time_t spawnCiviles2;
	time_t spawnSoldados2;

public:
	Controlador(Bitmap^bmAbogado, Bitmap^ bmCuchillo, Bitmap^ bmpAliado1, Bitmap^ bmpAliado2, Bitmap^ bmRobot, Bitmap^ bmSoldado, Bitmap^ bmCivil, Bitmap^ bmBarraDeVida, Bitmap^ bmAveEO, Bitmap^ bmAveOE, Bitmap^ bmComentario){
		nivel2 = 0;
		abogado = new Abogado(500, 400, bmAbogado->Width / 8, bmAbogado->Height / 6);
		perroV1 = perroV2 = new Aliado(0,475, bmpAliado1->Width / 4, bmpAliado1->Height / 9);
		perroV2 = perroV2 = new Aliado(0, 475, bmpAliado2->Width / 4, bmpAliado2->Height / 9);
		barraDeVida = new BarraDeVida(bmBarraDeVida->Width / 8, bmBarraDeVida->Height / 7);
		
		ComentarioAleatorio = 1 + rand() % 8;
		comentario = new Comentario(abogado->getX(),330, ComentarioAleatorio, bmComentario->Width, bmComentario->Height / 8);
		
		spawnRobots = time(0);
		spawnCiviles = time(0);
		spawnSoldados = time(0);
		spawnRobots2 = time(0);
		spawnCiviles2 = time(0);
		spawnSoldados2 = time(0);
		cambiaComentario = time(0);

		contArboles = 0;
		AgregarAves(bmAveEO, bmAveOE);
	}
	~Controlador() {}

	void setNivel(int nivel) {
		this->nivel2 = nivel;
	}

	void AgregarCuchillo(Bitmap^ bmCuchillo, int i) {
		cuchillos.push_back(new Cuchillo(bmCuchillo->Width, bmCuchillo->Height / 2, abogado, i));
	}
	void AgregarRobots(Bitmap^ bmRobot) {
		robots.push_back(new Robot(1400, 380, bmRobot->Width / 7, bmRobot->Height / 2));
	}
	void AgregarSoldados(Bitmap^ bmSoldado){
		soldados.push_back(new Soldado(1200, 429, bmSoldado->Width / 11, bmSoldado->Height / 2));
	}
	void AgregarCiviles(Bitmap^ bmCivil) {
		civiles.push_back(new Civil(1300, 430, bmCivil->Width / 6, bmCivil->Height/2));
	}

	void AgregarRobots2(Bitmap^ bmRobot) {
		if (nivel2 == 2) {
			robots.push_back(new Robot(0, 380, bmRobot->Width / 7, bmRobot->Height / 2));
		}
	}
	void AgregarSoldados2(Bitmap^ bmSoldado) {
		if (nivel2 == 2) {
			soldados.push_back(new Soldado(55, 429, bmSoldado->Width / 11, bmSoldado->Height / 2));
		}
	}
	void AgregarCiviles2(Bitmap^ bmCivil) {
		if (nivel2 == 2) {
			civiles.push_back(new Civil(100, 430, bmCivil->Width / 6, bmCivil->Height / 2));
		}
	}

	void AgregarAves(Bitmap^ bmAveEO, Bitmap^ bmAveOE) {
		aves.push_back(new Ave(1200, 170, bmAveEO->Width / 5, bmAveOE->Height / 4, 1));
		aves.push_back(new Ave(1200, 50, bmAveEO->Width / 5, bmAveOE->Height / 4, 1));
		aves.push_back(new Ave(0, 109, bmAveEO->Width / 5, bmAveOE->Height / 4, 2));
		aves.push_back(new Ave(0, 5, bmAveEO->Width / 5, bmAveOE->Height / 4, 2));
	}

	void AgregarArboles(Bitmap^ bmArbol) {
		arboles.push_back(new Arbol(abogado->getX(), 390, bmArbol->Width / 6, bmArbol->Height));
	}

	void Spawn(Bitmap^ bmRobot, Bitmap^ bmSoldado, Bitmap^ bmCivil) {
		if (difftime(time(0), spawnRobots) >= 14) { //Los robots apareceran cada 14 seg
			spawnRobots = time(0);
			AgregarRobots(bmRobot);
		}
		if (difftime(time(0), spawnSoldados) >= 9) { //Los civiles apareceran cada 9 seg
			spawnSoldados = time(0);
			AgregarSoldados(bmSoldado);
		}
		if (difftime(time(0), spawnCiviles) >= 5) { //Los civiles apareceran cada 5 seg
			spawnCiviles = time(0);
			AgregarCiviles(bmCivil);
		}

		if (difftime(time(0), cambiaComentario) >= 5) { //Cambia los comentarios cada 10 seg
			comentario->setEsVisible(false);

			if (difftime(time(0), cambiaComentario) >= 10) { //Cambia los comentarios cada 10 seg
				cambiaComentario = time(0);
				comentario->setEsVisible(true);
				comentario->GenerarComentario();
			}
		}

		if ((difftime(time(0), spawnRobots2) >= 9) && (nivel2 == 2)) { //Los robots apareceran cada 9 seg nivel2
			spawnRobots2 = time(0);
			AgregarRobots2(bmRobot);
		}
		if ((difftime(time(0), spawnSoldados2) >= 5) && (nivel2 == 2)) { //Los civiles apareceran cada 5 seg nivel 2
			spawnSoldados2 = time(0);
			AgregarSoldados2(bmSoldado);
		}
		if ((difftime(time(0), spawnCiviles2) >= 5) && (nivel2 == 2)) { //Los civiles apareceran cada 4 seg nivel 2
			spawnCiviles2 = time(0);
			AgregarCiviles2(bmCivil);
		}
	}

	void DibujarTodo(BufferedGraphics^ bg, Bitmap^ bmAbogado, Bitmap^ bmCuchillo, Bitmap^ bmpAliado1, Bitmap^ bmpAliado2, Bitmap^ bmRobot, Bitmap^ bmSoldado, Bitmap^ bmCivil, Bitmap^ bmBarraDeVida, Bitmap^ bmAveEO, Bitmap^ bmAveOE, Bitmap^ bmArbol, Bitmap^ bmComentario) {
		for (int i = 0; i < arboles.size(); i++) {
			arboles[i]->Dibujar(bg, bmArbol);
		}

		abogado->Dibujar(bg, bmAbogado);
		perroV1->Dibujar(bg, bmpAliado1);
		perroV2->Dibujar(bg, bmpAliado2);
		comentario->Dibujar(bg, bmComentario);
		
		for (int i = 0; i < cuchillos.size(); i++) {
			cuchillos[i]->Dibujar(bg, bmCuchillo);
		}
		for (int i = 0; i < robots.size(); i++) {
			robots[i]->draw(bg, bmRobot);
		}
		for (int i = 0; i < soldados.size(); i++) {
			soldados[i]->draw(bg, bmSoldado);
		}
		for (int i = 0; i < civiles.size(); i++) {
			civiles[i]->draw(bg, bmCivil);
		}
		for (int i = 0; i < aves.size(); i++) {
			if (i == 2 || i == 3) {
				aves[i]->draw(bg, bmAveOE);
			}
			else
			{
				aves[i]->draw(bg, bmAveEO);
			}
		}
		barraDeVida->Dibujar(bg, bmBarraDeVida);
	}
	void MoverTodo(BufferedGraphics^ bg, Bitmap^ bmAbogado, Bitmap^ bmCuchillo, Bitmap^ bmpAliado1, Bitmap^ bmpAliado2, Bitmap^ bmRobot, Bitmap^ bmSoldado, Bitmap^ bmCivil, Bitmap^ bmBarraDeVida, Bitmap^ bmAveEO, Bitmap^ bmAveOE, Bitmap^ bmArbol, Bitmap^ bmComentario) {
		abogado->Mover(bg, bmAbogado);
		barraDeVida->Mover(bg, bmBarraDeVida, abogado);
		comentario->Mover(bg, bmComentario, abogado);
		perroV1->Mover(bg, bmpAliado1, abogado);
		perroV2->Mover(bg, bmpAliado1, abogado);

		for (int i = 0; i < cuchillos.size(); i++) {
			cuchillos[i]->Mover(bg, bmCuchillo);
		}
		for (int i = 0; i < robots.size(); i++) {
			robots[i]->move(bg, bmRobot);
		}
		for (int i = 0; i < soldados.size(); i++) {
			soldados[i]->move(bg, bmSoldado);
		}
		for (int i = 0; i < civiles.size(); i++) {
			civiles[i]->move(bg, bmCivil);
		}
		for (int i = 0; i < aves.size(); i++) {
			if (i == 2 || i == 3) {
				aves[i]->move(bg, bmAveOE);
			}
			else
			{
				aves[i]->move(bg, bmAveEO);
			}
		}
		for (int i = 0; i < arboles.size(); i++) {
			arboles[i]->Mover(bg, bmArbol);
		}
	}
	void Colision(BufferedGraphics^ bg) {
		//Recargar Vidas y Semillas del Heroe
		if (abogado->getRectangle().IntersectsWith(perroV1->getRectangle()))
		{
			if (perroV1->getEsVisible() == true) {
				abogado->RecuperaVidasHeroe();
				abogado->RecuperaSemillasHeroe();
			}
		}
		//Marcar--------------->
		// 
		//Marcar cuando llegen a los limites de la pantalla
		//Los cuchillos
		for (int i = 0; i < cuchillos.size(); i++) {
			if (cuchillos[i]->ultimaTecla == Direcciones::Derecha)
			{
				if (cuchillos[i]->getX() > bg->Graphics->VisibleClipBounds.Width - 100) { //con el limite del ancho
					cuchillos[i]->setEsVisible(false);
				}
			}
			else if (cuchillos[i]->ultimaTecla == Direcciones::Izquierda)
			{
				if (cuchillos[i]->getX() < 60) {
					cuchillos[i]->setEsVisible(false);
				}
			}
		}
		//Los enemigos
		for (int i = 0; i < robots.size(); i++) {
			if (robots[i]->getX() <= -80) {
				robots[i]->setEsVisible(false);
			}
		}
		for (int i = 0; i < soldados.size(); i++) {
			if (soldados[i]->getX() <= -80) {
				soldados[i]->setEsVisible(false);
			}
		}
		for (int i = 0; i < civiles.size(); i++) {
			if (civiles[i]->getX() <= -80) {
				civiles[i]->setEsVisible(false);
			}
		}
		//Marcar cuando interactuen las balas con los enemigos o con el ataque del perro
		for (int i = 0; i < cuchillos.size(); i++) {
			for (int j = 0; j < robots.size(); j++) {
				if (cuchillos[i]->getRectangle().IntersectsWith(robots[j]->getRectangule())) {
					cuchillos[i]->setEsVisible(false);
					robots[j]->PerderVidas();
				}
			}
			for (int k = 0; k < soldados.size(); k++) {
				if (cuchillos[i]->getRectangle().IntersectsWith(soldados[k]->getRectangule())) {
					cuchillos[i]->setEsVisible(false);
					soldados[k]->PerderVidas();
				}
			}
			for (int l = 0; l < civiles.size(); l++) {
				if (cuchillos[i]->getRectangle().IntersectsWith(civiles[l]->getRectangule())) {
					cuchillos[i]->setEsVisible(false);
					civiles[l]->PerderVidas();
				}
			}
		}
		//Marcar cuando los enemigos impacten con el heroe o con el aliado
		for (int j = 0; j < robots.size(); j++) {
			if (robots[j]->getRectangule().IntersectsWith(abogado->getRectangle()))
				abogado->PerderVidas();

			if (perroV2->direccion == Lo_que_hace::Al_Ataque) {
				if (perroV2->getRectangle().IntersectsWith(robots[j]->getRectangule()))
					robots[j]->setEsVisible(false);
			}

		}
		for (int k = 0; k < soldados.size(); k++) {
			if (soldados[k]->getRectangule().IntersectsWith(abogado->getRectangle()))
				abogado->PerderVidas();

			if (perroV2->direccion == Lo_que_hace::Al_Ataque) {
				if (perroV2->getRectangle().IntersectsWith(soldados[k]->getRectangule()))
					soldados[k]->setEsVisible(false);
			}
		}
		for (int l = 0; l < civiles.size(); l++) {
			if (civiles[l]->getRectangule().IntersectsWith(abogado->getRectangle()))
				abogado->PerderVidas();

			if (perroV2->direccion == Lo_que_hace::Al_Ataque) {
				if (perroV2->getRectangle().IntersectsWith(civiles[l]->getRectangule()))
					civiles[l]->setEsVisible(false);
			}
		}

		//Marcar cuando los arboles cuando los enemigos con ellos
		for (int i = 0; i < arboles.size(); i++) {
			for (int j = 0; j < robots.size(); j++) {
				if (arboles[i]->getRectangle().IntersectsWith(robots[j]->getRectangule())) {
					arboles[i]->setEsVisible(false);
				}
			}
			for (int k = 0; k < soldados.size(); k++) {
				if (arboles[i]->getRectangle().IntersectsWith(soldados[k]->getRectangule())) {
					arboles[i]->setEsVisible(false);
				}
			}
			for (int l = 0; l < civiles.size(); l++) {
				if (arboles[i]->getRectangle().IntersectsWith(civiles[l]->getRectangule())) {
					arboles[i]->setEsVisible(false);
				}
			}
		}

		//Eliminar------------------>
		//cuchillos
		for (int i = 0; i < cuchillos.size(); i++) {
			if (cuchillos[i]->getEsVisible() == false) {
				cuchillos.erase(cuchillos.begin() + i);
			}
		}
		//robots
		for (int i = 0; i < robots.size(); i++) {
			if (robots[i]->getEsVisible() == false) {
				robots.erase(robots.begin() + i);
			}
		}
		//soldados
		for (int i = 0; i < soldados.size(); i++) {
			if (soldados[i]->getEsVisible() == false) {
				soldados.erase(soldados.begin() + i);
			}
		}
		//civiles
		for (int i = 0; i < civiles.size(); i++) {
			if (civiles[i]->getEsVisible() == false) {
				civiles.erase(civiles.begin() + i);
			}
		}
		//arboles
		for (int i = 0; i < arboles.size(); i++) {
			if (arboles[i]->getEsVisible() == false) {
				arboles.erase(arboles.begin() + i);
			}
		}
	}

	int getCantidadArbolesCrecCompleto() {
		for (int i = 0; i < arboles.size(); i++) {
			if (arboles[i]->getcrecimientoCompletado()) {
				contArboles++;
			}
		}
		return contArboles;
	}

	Abogado* getAbogado() {
		return abogado;
	}
	Aliado* getAliado1() {
		return perroV1;
	}
	Aliado* getAliado2() {
		return perroV2;
	}

};