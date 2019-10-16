#include <iostream>
using namespace std;

class Temperatura {
private:
  double gradosKelvin;
public:
  void setTemperaturaEnKelvin(double tem);
  void settemperaturaEnFahrenheit(double tem);
  void setTemperaturaEnCelsius(double tem);
  double getTemperaturaEnKelvin();
  double getTemperaturaEnFahrenheit();
  double getTemperaturaEnCelsius();
};

void Temperatura::setTemperaturaEnKelvin(double tem) {
  gradosKelvin = tem;
}

void Temperatura::setTemperaturaEnCelsius(double tem) {
  gradosKelvin = tem + 273.15;
}
void Temperatura::settemperaturaEnFahrenheit(double tem) {
  gradosKelvin = (tem - 32.0) * (5 / 9.0) + 273.15;
}
double Temperatura::getTemperaturaEnCelsius() {
  return gradosKelvin - 273.15;
}
double Temperatura::getTemperaturaEnFahrenheit() {
  return (gradosKelvin - 273.15) * (9.0 / 5) + 32;
}
double Temperatura::getTemperaturaEnKelvin() {
  return gradosKelvin;
}

int main() {
  Temperatura t;
  double kelvin;
  cin >> kelvin;
  t.setTemperaturaEnKelvin(kelvin);
  cout << "Grados Kelvin: " << kelvin << endl;
  
  t.settemperaturaEnFahrenheit(t.getTemperaturaEnFahrenheit());
  cout << "Grados Fahrenheit: " << t.getTemperaturaEnFahrenheit() << endl;

  t.setTemperaturaEnCelsius(t.getTemperaturaEnCelsius());
  cout << "Grados Celsius: " << t.getTemperaturaEnCelsius() << endl;
}