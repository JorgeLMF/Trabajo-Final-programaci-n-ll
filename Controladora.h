#pragma once
#include"Laberinto.h"
class controladora
{
	Mapa *escenario;
public:
	controladora() {
		escenario = new Mapa();
	}
	~controladora() {}
	void dibujo(Graphics^ g, Bitmap^ bmpbloque, Bitmap^ bmpbase)
	{
		escenario->pintar(g, bmpbase);
		escenario->dibujarmatriz(g, bmpbloque);		
	}
	void mapaleatorio()
	{
		escenario->generarmapa();
	}

};