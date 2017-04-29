#include <iostream>
#include <cstdio>

using namespace std;

char Direccion_Archivo_Avion[] = { "avion.dat" };

struct avion
{
	int IdAvion; // 4
	char descripcion[30]; // 4 * 30
	int nroAsientos; // 4
};

int cantidadRegistros()
{
	FILE *ptr = fopen(Direccion_Archivo_Avion, "rb");
	if (ptr != NULL)
	{
		fseek(ptr, 0, SEEK_END);
		return ftell(ptr) / sizeof(avion);
	}
}

void nuevoAvion(avion a)
{
	FILE *ptr = fopen(Direccion_Archivo_Avion, "ab");
	if (ptr != NULL)
	{
		fwrite(&a, sizeof(a), 1, ptr);
	}
	fclose(ptr);
}

void editarAvion()
{
	FILE *ptr = fopen(Direccion_Archivo_Avion, "wb+");
}