#pragma once
#include "Enemigo.h"

class Soldado : public Enemigo {
private:

public:
	Soldado(int x, int y, int ancho, int alto) : Enemigo(x, y, ancho, alto) {
		this->idx = 10;
		this->ancho = ancho;
		this->alto = alto;
		this->x = x;
		this->y = y;
		Hp = 2;
		if (x == 1200) {
			direccion = Izquierda;
		}
		if (x == 55) {
			direccion = Derecha;
			this->idx = 0;
		}
	}

	~Soldado(){}

	void draw(BufferedGraphics^ bg, Bitmap^ bmp) { //Graphics -> Canvas // Bitmap -> Image
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 3.2, alto * 3.2);
		bg->Graphics->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(BufferedGraphics^ bg, Bitmap^ bm) {
		switch (direccion) {
		case Izquierda:
			idy = 0;
			x -= dx;
			idx--;
			if (idx == 0)idx = 10;
			break;
		case Derecha:
			idy = 1;
			x += dx;
			idx++;
			if (idx == 10)idx = 0;
			break;
		}
	}
	Rectangle getRectangule() {
		return Rectangle(x, y, ancho * 3.2, alto * 3.2);
	}
};
