#pragma once
#include <iostream>

using namespace System::Drawing;
using namespace std;

class Enemigo {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int idx, idy; //indice
	bool EsVisible;
	int Hp;
	bool CausaDanioAlHeroe; //es para que solo dañe al primer contacto con el heroe y no le quite todas sus vidas de una
	Direcciones direccion;

public:
	Enemigo() {};

	Enemigo(int x, int y, int ancho, int alto) {
		this->ancho = ancho;
		this->alto = alto;
		this->x = x;
		this->y = y;
		dx = dy = 10;
		idx = idy = 0;
		direccion = Ninguna;
		EsVisible = true;
		Hp = 1;
		CausaDanioAlHeroe = false; //Todavia no ha casuado daño
	}

	bool getEsVisible() {
		return EsVisible;
	}
	int getX() {
		return x;
	}
	int getHp() {
		return Hp;
	}

	bool getCausaDanioAlHeroe() {
		return CausaDanioAlHeroe;
	}

	void setCausaDanioAlHeroe(bool CausaDanioAlHeroe) {
		this->CausaDanioAlHeroe = CausaDanioAlHeroe;
	}

	void setEsVisible(bool EsVisible) {
		this->EsVisible = EsVisible;
	}

	void PerderVidas() {
		Hp--;
		if (Hp == 0)
			this->EsVisible = false;
	}

	~Enemigo() {}

	virtual void draw() {}
	virtual void move() {}
};