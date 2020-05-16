/*
  Libreria de RobotCar
Universidad de El Salvador, Sede Santa Ana
ciclo I-2019   DEFINA LAS SIGUIENTES CLASES
+ inidica miembro publico
- indicam miembro privado
+ miembro : tipodedatos
*/

#ifndef robot - car - arduino_h
#define robot -car - arduino_h
#include <Arduino.h>

/*************************    
	Clase Ultrasonido
**************************
- distancia : long
+ pinEcho : byte*
+ pinTrigger: byte*
**************************
+ medirCM() : int
+ Ultrasonido(byte*,byte*)
****************************/
class Ultrasonido
{
private:
	long distancia;

public:
	byte *pinEcho;
	byte *pinTrigger;

	//Constructor parametrizado recibe como parametro Trigger y Echo como byte
	Ultrasonido(byte *_pinTrigger, byte *_pinEcho);
	Ultrasonido();

	//Mide la distancia al sensor es preciso hasta 3.5mts
	// por tanto el valor maximo es 350 cm
	int medirCM();
};

class Carro
{
public:
	byte encoderI = 2;		 //pin del encoder de la llanta izquierda
	byte encoderD = 3;		 //pin del encoder de la llanta derecha
	byte adelanteI = 4;		 //pin avance adelante llanta izquierda
	byte atrasI = 5;		 //pin de reversa llanta izquierda
	byte potenciaI = 6;		 // pin de potencia llanta izquiera pin PWM
	byte adelanteD = 7;		 //Adelante llanta derecha
	byte atrasD = 8;		 //atras llanta derecha
	byte potenciaD = 9;		 //potencia llanta derecha pin PWM
	byte sensortrigerC = 10; //sensor ultrasonido central trigger
	byte sensorechoC = 11;	 //sensor ultrasonido central trigger
	byte sensortrigerI = 12; //sensor ultrasonido izquierda trigger
	byte sensorechoI = 13;	 //sensor ultrasonido izquierda trigger
	byte sensortrigerD = 10; //sensor ultrasonido derecha trigger
	byte sensorechoD = 11;	 //sensor ultrasonido Derecha trigger
	byte potenciaMAX = 200;

	Ultrasonido UltraC; //se declara como puntero
	Ultrasonido UltraI; //en el cpp se va a instancia y a referir
	Ultrasonido UltraD;
	//Ultrasonido UltraC //Forma alternativa como objeto
	//Ultrasonido &UltraC //forma alternativa como alias

	//Definiendo las interrupciones-- usan miembros estaticos
	static volatile unsigned int contaI; //contador de las vueltas de la llanta izquierda
	static volatile unsigned int contaD; //contador de las vueltas de la llanta Derecha
	//Contadores de ruedas izquiera y derecha
	static void contarRuedaI(); //metodo a registrar con la interrupcion en constructor
	static void contarRuedaD();

	//Constructor -- configura variables, sensores e interrupciones
	Carro();

	//acciona el motor, recibe como parametro la accion en la llanta izquierda y la llanta derecha
	// el valor de cada llanta si es positivo movera la llanta hacia adelante
	// si es negativo movera la llanta hacia atras
	// el numero representara la potencia aplicada a cada llanta
	// los valores pueden ir de -10 hasta 10
	void mover(int Izquierda, int Derecha);

	//Gira la cantidad de grados especifica: - a la izquierda, + derecha
	//usa los contadores de vuelta para la precision al girar
	//tu decides si usas dos llantas para girar o solo una
	void girar(int grados);
};

/*******************************************************************************
						Clase Carro
********************************************************************************

+ encoderI : byte = 2 //pin del encoder de la llanta izquierda
+ encoderD : byte = 3 // pin del encoder de la llanta derecha
+ adelanteI : byte =4; // pin avance adelante llanta Izquierda
+ atrasI : byte =5;    // pin de reversa llanta izquierda
+ potenciaI : byte =6; // pin de potencia llanta Izquierda pin PWM
+ adelanteD : byte =7; // Adelante llanta Derecha
+ atrasD : byte =8;  // atras llanta Derecha
+ potenciaD : byte =9;  // potencia llanta Derecha pin PWM
+ sensortrigerC : byte =10; //Sensor Ultrasonido Central Trigger
+ sensorechoC : byte =11; //Sensor Ultrasonido Central Echo
+ sensortrigerI : byte =12; //Sensor Ultrasonido Izquierda Trigger
+ sensorechoI : byte =13; //Sensor Ultrasonido Izquierda Echo
+ sensortrigerD : byte =14; //Sensor Ultrasonido Derecha Trigger
+ sensorechoD : byte =15; //Sensor Ultrasonido Derecha Echo
+ potenciaMAX: byte =200;  //limite regulador de la potencia maxima
+ UltraC : Ultrasonido* // Se declara como PUNTEROS
+ UltraI : Ultrasonido* // en el cpp se va a instanciar y a referir
+ UltraD : Ultrasonido*
  //DEFINIENDO LAS INTERRUPCIONES--USAN MIEMBROS ESTATICOS
  static volatile unsigned int contaI; //contador de las vueltas de la llanta Izquierda
  static volatile unsigned int contaD; //contador de las vueltas de la llanta Derecha
 *************************************************************************************
	//METODOS CONTADORES DE RUEDAS IZQUIERDA Y DERECHA
	static void contarRuedaI(); //metodo a registrar con la interrupcion en constructor
	static void contarRuedaD();
	
	//Constructor -- configura variables, sensores e interrupciones
	+ Carro()

	//acciona el motor, recibe como parametro la accion en la llanta izquierda y la llanta derecha
	// el valor de cada llanta si es positivo movera la llanta hacia adelante
	// si es negativo movera la llanta hacia atras
	// el numero representara la potencia aplicada a cada llanta
	// los valores pueden ir de -255 hasta 255
	+ mover(int Izquierda, int Derecha) : void
	
	//Gira la cantidad de grados especifica: - a la izquierda, + derecha
	//usa los contadores de vuelta para la precision al girar
	//tu decides si usas dos llantas para girar o solo una
	+ girar(int grados): void

*****************************************************************************/

#endif