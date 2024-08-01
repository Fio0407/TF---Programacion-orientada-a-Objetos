#pragma once
#include "Movil.h"
#include "Abogado.h"

class BarraDeVida: public Movil {
public:
	BarraDeVida(){}
	BarraDeVida(float ancho, float alto):Movil(ancho, alto){
		x = 10;
		y = 10;
		Hp = 55;
		indiceX = 7;
		indiceY = 7;
	}
	~BarraDeVida() {}

	void Mover(BufferedGraphics^ bg, Bitmap^ bm, Abogado* abogado) {
		Hp = abogado->getHp();

		if (Hp >= 0 && Hp < 8) {
			indiceY = 0;
			indiceX = Hp - (8 * 0); //Para entender esto hay que ver el sprite, aqui el 8 es el numero de columnas (de 1-8) y el 0 es el numero de filas (de 0-6)
		}
		else if (Hp >= 8 && Hp < 16) {
			indiceY = 1;
			indiceX = Hp - (8 * 1);
		}
		else if (Hp >= 16 && Hp < 24) {
			indiceY = 2;
			indiceX = Hp - (8 * 2);
		}
		else if (Hp >= 24 && Hp < 32) {
			indiceY = 3;
			indiceX = Hp - (8 * 3);
		}
		else if (Hp >= 32 && Hp < 40) {
			indiceY = 4;
			indiceX = Hp - (8 * 4);
		}
		else if (Hp >= 40 && Hp < 48) {
			indiceY = 5;
			indiceX = Hp - (8 * 5);
		}
		else if (Hp >= 48 && Hp < 56) {
			indiceY = 6;
			indiceX = Hp - (8 * 6);
		}
	}
};