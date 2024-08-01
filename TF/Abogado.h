#pragma once
#include "Movil.h"

class Abogado : public Movil {
private:
	int nSemillas;

public:
	Direcciones ultimaTecla;
	Direcciones direccion;

	Abogado() {}

	Abogado(int x, int y, float ancho, float alto) :Movil(x, y, ancho, alto) {
		ultimaTecla = Derecha;
		direccion = Ninguna;
		Hp = 55;
		nSemillas = 10;
	}

	~Abogado() {}

	int getSemillas() {
		return nSemillas;
	}

	void Dibujar(BufferedGraphics^ bg, Bitmap^ bm) {
		Rectangle area = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle escala = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		bg->Graphics->DrawImage(bm, escala, area, GraphicsUnit::Pixel);
	}

	void Mover(BufferedGraphics^ bg, Bitmap^ bm) {
		switch (direccion) {
		case Derecha:
			if (x + ancho * 1.5 < bg->Graphics->VisibleClipBounds.Width) {
				indiceY = 2;
				if (indiceX >= 0 && indiceX < 7)
					indiceX++;
				else
					indiceX = 0;
				dx = 20;
				x += dx;
				dy = 0;
				ultimaTecla = Derecha;
			}
			break;

		case Izquierda:
			if (x > 0) {
				indiceY = 3;
				if (indiceX >= 0 && indiceX < 7)
					indiceX++;
				else
					indiceX = 0;
				dx = -20;
				x += dx;
				dy = 0;
				ultimaTecla = Izquierda;
			}
			else {
				direccion = Derecha;
				ultimaTecla = Derecha;
				dx = 20;
				x += dx;
			}
			break;
		case AtaqueDerecha:
			indiceY = 4;
			if (indiceX >= 0 && indiceX < 4)
				indiceX++;
			else
			{
				indiceX = 0;
				direccion = Ninguna;
			}
			ultimaTecla = Derecha;
			break;

		case AtaqueIzquierda:
			indiceY = 5;
			if (indiceX >= 0 && indiceX < 4)
				indiceX++;
			else
			{
				indiceX = 0;
				direccion = Ninguna;
			}
			ultimaTecla = Izquierda;
			break;

		case Ninguna:
			dx = 0;
			switch (ultimaTecla) {
			case Derecha:
				indiceY = 0;
				if (indiceX >= 0 && indiceX < 3)
					indiceX++;
				else
					indiceX = 0;
				break;
			case Izquierda:
				indiceY = 1;
				if (indiceX >= 0 && indiceX < 3)
					indiceX++;
				else
					indiceX = 0;
				break;
			}
			break;
		}
	}

	void RecuperaVidasHeroe() {
		Hp = 55;
	}

	void RecuperaSemillasHeroe() {
		nSemillas = 10;
	}

	void GastarSemillas() {
		nSemillas--;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 1.5, alto * 1.5);
	}
};