#pragma once
#include "Movil.h"
#include "Abogado.h"

class Comentario : public Movil {
private:

public:
	Comentario() {}
	Comentario(int x, int y, int indiceY, float ancho, float alto) : Movil(x, y, ancho, alto) {
		EsVisible = true;
		indiceX = 0;
		this->indiceY = indiceY;
		this->y = y;
		this->x = x;
	}
	~Comentario() {}

	void Mover(BufferedGraphics^ g, Bitmap^ bmp, Abogado* abogado) {
		x = abogado->getX() - 75;
	}

	void GenerarComentario() {
		indiceY = 1 + rand() % 8;
	}
};