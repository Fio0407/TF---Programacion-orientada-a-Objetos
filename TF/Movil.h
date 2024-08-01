#pragma once
enum Direcciones { Ninguna, Izquierda, Derecha, AtaqueDerecha, AtaqueIzquierda };

using namespace System::Drawing;

class Movil {
protected:
	int x, y;
	int dx, dy;
	float ancho, alto;
	int indiceX, indiceY;
	bool EsVisible;
	int Hp;
	float zoomXY;

public:
	Movil() {}

	Movil(int x, int y, float ancho, float alto) {
		this->ancho = ancho;
		this->alto = alto;
		this->x = x;
		this->y = y;
		dx = 0;
		dy = 0;
		indiceX = 0;
		indiceY = 0;
		zoomXY = 1.0;
		EsVisible = true;
	}

	Movil(float ancho, float alto) {
		x = 500;
		y = 400;
		this->ancho = ancho;
		this->alto = alto;
		dx = 0;
		dy = 0;
		indiceX = 0;
		indiceY = 0;
		zoomXY = 1.0;
		EsVisible = true;
	}

	~Movil() {}

	//getters
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getIndiceX() {
		return indiceX;
	}
	bool getEsVisible() {
		return EsVisible;
	}
	int getHp() {
		return Hp;
	}
	//setters
	void setIndiceX(int indiceX) {
		this->indiceX = indiceX;
	}
	void setEsVisible(int EsVisible) {
		this->EsVisible = EsVisible;
	}
	void PerderVidas() {
		Hp--;
		if (Hp == 0)
			this->EsVisible = false;
	}

	void Dibujar(BufferedGraphics^ bg, Bitmap^ bm)
	{
		if (EsVisible == true) {
			Rectangle area = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
			Rectangle escala = Rectangle(x, y, ancho * zoomXY, alto * zoomXY);
			bg->Graphics->DrawImage(bm, escala, area, GraphicsUnit::Pixel);
		}
	}

	virtual void Mover(BufferedGraphics^ bg, Bitmap^ bm){}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * zoomXY, alto * zoomXY);
	}
};