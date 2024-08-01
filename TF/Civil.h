#pragma once
#include "Enemigo.h"

class Civil :public Enemigo {
private:

public:
	Civil(int x, int y, int ancho, int alto) : Enemigo(x, y, ancho, alto) {
		this->idx = 5;
		//this->idy = 0;
		this->ancho = ancho;
		this->alto = alto;
		this->x = x;
		this->y = y;
		Hp = 1;
		if (x == 1300) {
			direccion = Izquierda;
		}
		if (x == 100) {
			direccion = Derecha;
			this->idx = 0;
		}
	}

	~Civil() {}

	void draw(BufferedGraphics^ bg, Bitmap^ bmp) { //Graphics -> Canvas // Bitmap -> Image
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		bg->Graphics->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(BufferedGraphics^ bg, Bitmap^ bm) {
		switch (direccion) {
		case Izquierda:
			idy = 0;
			x -= dx;
			idx--;
			if (idx == 0)idx = 5;
			break;
		case Derecha:
			idy = 1;
			x += dx;
			idx++;
			if (idx == 5)idx = 0;
			break;
		}
	}
	Rectangle getRectangule() {
		return Rectangle(x, y, ancho * 1.5, alto * 1.5);
	}
};