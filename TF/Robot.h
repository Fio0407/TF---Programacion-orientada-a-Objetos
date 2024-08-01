#pragma once
#include "Enemigo.h"

class Robot :public Enemigo {
public:
	Robot(int x, int y, int ancho, int alto) : Enemigo(x, y, ancho, alto) {
		this->idx = 6;
		this->x = x;
		this->y = y;
		Hp = 3;
		if (x == 1400) {
			direccion = Izquierda;
		}
		if (x == 0) {
			direccion = Derecha;
			idx = 0;
		}

	}

	~Robot() {}

	void draw(BufferedGraphics^ bg, Bitmap^ bmp) { //Graphics -> Canvas // Bitmap -> Image
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.3, alto * 0.3);
		bg->Graphics->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(BufferedGraphics^ bg, Bitmap^ bm) {
		switch (direccion)
		{
		case Izquierda:
			idy = 0;
			x -= dx;
			idx--;
			if (idx == 0)idx = 6;
			break;
		case Derecha:
			idy = 1;
			x += dx;
			idx++;
			if (idx == 6)idx = 0;
			break;
		}
	}

	Rectangle getRectangule() {
		return Rectangle(x, y, ancho * 0.3, alto * 0.3);
	}

};