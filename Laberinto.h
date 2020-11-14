#pragma once

#include<ctime>
#include <stdlib.h>
#define filas 13
#define columnas 23
using namespace System::Drawing;

class Mapa
{
private:
	int **matriz;
public:
	Mapa()
	{
		matriz = new int*[filas];
	}
	~Mapa(){}

	void generarmapa()
	{
		for (int i = 0;i < filas;i++)
		{
			matriz[i] = new int[columnas];
		}
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0;j < columnas;j++)
			{
				if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1)//bordes
					matriz[i][j] = 1;
				else
				{
					//bloques fijos
					if (i % 2 == 0 && j % 2 == 0)
						matriz[i][j] = 1;
					else
					{
						//Donde se mueve
						if ((i == 1 && (j == 1 || j == 2)) || (j == 1 && i == 2) || (i == filas - 2 && (j == columnas - 3 || j == columnas - 2)) || (i == filas - 3 && j == columnas - 2))
							matriz[i][j] = 0;
						else
						
							matriz[i][j] = (rand() % 4) + 2;
					}
				}
			}
		}

	}
	void pintar(Graphics^ g, Bitmap^ bmpbase)
	{
		int x, y;
		x = y = 0;
		for (int i = 0;i < filas ; i++)
		{
			x = 0;
			for (int j = 0; j< columnas ; j++)
			{
				if (matriz[i][j] == 1 || matriz[i][j] == 3 )
			
					g->DrawImage(bmpbase, x, y, 50, 50);

				x += 50;
			}
			y += 50;
		}
	}
	void dibujarmatriz(Graphics^ g, Bitmap^ bmpbloque)
	{
		int x, y;
		x = y = 0;
		for (int i = 0;i < filas; i++)
		{
			x = 0;
			for (int j = 0; j < columnas; j++)
			{
				if (matriz[i][j] == 0 || matriz[i][j] == 2 || matriz[i][j] == 5 || matriz[i][j] == 4 || matriz[i][j] == 6)
					g->DrawImage(bmpbloque, x, y, 50, 50);
				x += 50;
			}
			y += 50;
		}
	}
	int **getmat()
	{
		return matriz;
	}
};