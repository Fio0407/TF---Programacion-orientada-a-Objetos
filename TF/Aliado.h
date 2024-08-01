#pragma once
#include "Movil.h"
#include "Abogado.h"

enum Lo_que_hace { NO, Se_va,  Regresa, Al_Ataque };

class Aliado : public Movil{
public:

	Direcciones ultimaTecla;
	Lo_que_hace direccion;

	Aliado(int x, int y, float ancho, float alto) :Movil(x, y, ancho, alto) {
		ultimaTecla = Derecha;
		direccion = NO;
		EsVisible = false;
		zoomXY = 3.0;
	}

	~Aliado() {}

	void Dibujar(BufferedGraphics^ g, Bitmap^ bmp) { //Graphics -> Canvas // Bitmap -> Image
		if (EsVisible == true) {
			Rectangle sectionShown = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
			Rectangle escala = Rectangle(x, y, ancho * 3.0, alto * 3.0);
			g->Graphics->DrawImage(bmp, escala, sectionShown, GraphicsUnit::Pixel);
			x += dx;
		}
	}

	void Mover(BufferedGraphics^ bg, Bitmap^ bm, Abogado* abogado) {
		switch (this->direccion)
		{
		case Se_va: 
			this->indiceY = 1;
			if (this->indiceX >= 0 && this->indiceX < 3) {
				this->indiceX++;
			}
			else {
				this->indiceX = 0;
			}

			this->dx = 10;
			this->dy = 0;
			this->ultimaTecla = Derecha;
			if (this->x >= abogado->getX()) {
				indiceX = 0;
				direccion = Regresa;
			}
			break;

		case Regresa:
			this->indiceY = 3;
			if (this->indiceX >= 0 && this->indiceX < 3) {
				this->indiceX++;
			}
			else {
				this->indiceX = 0;
			}

			this->dx = -10;
			this->dy = 0;
			this->ultimaTecla = Izquierda;
			if (x <= -50) {
				dx = 0;
				EsVisible = false;
			}
			break;
		case Al_Ataque:
			this->indiceY = 8;
			if (this->indiceX >= 0 && this->indiceX < 2) {
				this->indiceX++;
			}
			else {
				this->indiceX = 0;
			}

			this->dx = 30;
			this->dy = 0;
			this->ultimaTecla = Derecha;
			if (this->x+50 >= bg->Graphics->VisibleClipBounds.Width) {
				indiceX = 0;
				direccion = Regresa;
			}
			break;
		}
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 3.0, alto * 3.0);
	}
};
