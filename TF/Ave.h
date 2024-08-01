#pragma once
#include "Enemigo.h"

class Ave :public Enemigo {
private:
	int orientacion; // 1: este a oeste    2: oeste a este

public:
	Ave(int x, int y, int ancho, int alto, int orientacion) : Enemigo(x, y, ancho, alto) {
		this->idx = 0;
		this->idy = 0;
		this->x = x;
		this->y = y;
		this->dx = 14 + rand() % (18 + 1 - 14); // 18 valos maximo de velocidad, 14 minimo valor
		this->orientacion = orientacion;
	}

	~Ave() {}

	void draw(BufferedGraphics^ bg, Bitmap^ bmp) { //Graphics -> Canvas // Bitmap -> Image
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.3, alto * 1.3);
		bg->Graphics->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(BufferedGraphics^ bg, Bitmap^ bm) {
		switch (orientacion)
		{
		case 1:
			if (x > 0) {
				x -= dx;
				idx++;
				if (idx > 4) {
					idy++;
					idx = 0;
				}
				if (idx == 4 && idy == 3) {
					idx = 0;
					idy = 0;
				}
			}
			else {
				x = 1300;
			}
			break;
		case 2:
			if (x + ancho + dx < 1430) {
				x += dx;
				idx++;
				if (idx > 4) {
					idy++;
					idx = 0;
				}
				if (idx == 4 && idy == 3) {
					idx = 0;
					idy = 0;
				}
			}
			else {
				x = 0;
			}
			break;
		default:
			break;
		}
	}

};