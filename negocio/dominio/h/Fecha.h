#ifndef FECHA_H
#define FECHA_H
class Fecha{
	
private:
	int dia;
	int mes;
	int anio;
	
public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	
	int getDia();
	int getMes();
	int getAnio();
	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);
	
	virtual ~Fecha();
};
#endif
