#pragma once

#include "CImagen.hpp"
using namespace System;
using namespace System::Drawing;

ref class CSprite : public CImagen
{
	short n_subimagenes;
	short indice;
public:
	CSprite(String^ ruta, Rectangle area_dibujo, short n_subimagenes)
		: CImagen(ruta, area_dibujo), n_subimagenes(n_subimagenes), indice(0) {}
	void dibujar(Graphics^ graficador) override {
		Rectangle area_recorte = this->calcular_area_recorte();
		graficador->DrawImage(this->imagen, this->area_dibujo, area_recorte, GraphicsUnit::Pixel);
		//if (++this->indice == this->n_subimagenes) this->indice = 0;
		++this->indice %= this->n_subimagenes;
	}
private:
	Rectangle calcular_area_recorte() {
		short ancho = this->imagen->Width / this->n_subimagenes;
		short alto = this->imagen->Height;
		short x = this->indice * ancho;
		short y = 0;
		return Rectangle(x, y, ancho, alto);
	}
};

