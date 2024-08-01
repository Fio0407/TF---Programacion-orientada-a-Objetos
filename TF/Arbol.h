#pragma once
#include <time.h>
#include "Movil.h"

class Arbol : public Movil {
private:
	time_t Crecimiento;
	bool crecimientoCompletado;

public:
	Arbol(){}
	Arbol(int x,int y, float ancho, float alto): Movil(x, y, ancho, alto) {
		EsVisible = true;
		indiceX = 0;
		indiceY = 0;
		y = 390;
		this->x = x;
		Crecimiento = time(0);
		crecimientoCompletado = false;
	}
	~Arbol() {}

	bool getcrecimientoCompletado() {
		return crecimientoCompletado;
	}

	void Mover(BufferedGraphics^ g, Bitmap^ bmp) {
		if (difftime(time(0), Crecimiento) >= 3) {
			indiceX = 1;
		}
		if (difftime(time(0), Crecimiento) >= 6) {
			indiceX = 2;
		}
		if (difftime(time(0), Crecimiento) >= 9) {
			indiceX = 3;
		}
		if (difftime(time(0), Crecimiento) >= 12) {
			indiceX = 4;
		}
		if (difftime(time(0), Crecimiento) >= 15) {
			indiceX = 5;
		}
		if (difftime(time(0), Crecimiento) >= 18) {
			EsVisible = false;
			crecimientoCompletado = true;
		}
	}
};