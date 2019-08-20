#ifndef FECHA_H_
#define FECHA_H_
class Fecha {
	private:
		int dia;
		int mes;
		int anio;
	public:
		Fecha(int = 3, int = 4, int = 2014); // Constructor
		void inicializaFecha(int, int, int); // Metodo
		int convierte(); // Metodo
		void muestraFecha(); // Metodo
};
#endif