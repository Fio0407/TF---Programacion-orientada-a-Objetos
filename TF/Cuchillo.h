#pragma once
#include "Movil.h"
#include "Abogado.h"

class Cuchillo : public Movil{
public:
	Direcciones ultimaTecla;
	Direcciones direccion;

	Cuchillo(){}
	Cuchillo(float ancho, float alto, Abogado* abogado, int i) :Movil(ancho, alto) {
		zoomXY = 0.3;
		if (i == 0) {
			direccion = Derecha;
			x = abogado->getX() + 100;
		}
		else {
			direccion = Izquierda;
			x = abogado->getX() - 20;
		}
		
		y = 470;
	}
	~Cuchillo() {}

	void Mover(BufferedGraphics^ bg, Bitmap^ bmcuchillo) {
		switch (direccion) {
		case Derecha:
			indiceY = 0;
			dx = 15;
			x += dx;
			ultimaTecla = Derecha;
			break;

		case Izquierda:
			indiceY = 1;
			dx = -15;
			x += dx;
			ultimaTecla = Izquierda;
			break;
		}
	}
};