/*
 * Carro.cpp
 *
 *  Created on: 17 de abr de 2017
 *      Author: bruno
 */

#include "include/Carro.h"
#include "include/Parque.h"
#include <Windows.h> // lib do Sleep

const int Carro::CAPACIDADE = 5;
int Carro::numPassageiros = 0;

Carro::Carro() {
	this->voltas = 0;
}

Carro::~Carro() {
}

void Carro::esperaEncher() {
	while(Carro :: numPassageiros < Carro:: CAPACIDADE){
            Sleep(2); // delay p verificar se o carro ta cheio
    }
}

void Carro::daUmaVolta() {
 voltaAcabou = false;
 Sleep(4); // tempo da volta
 voltaAcabou = true;
}

void Carro::esperaEsvaziar() {

	while (Carro :: numPassageiros > 0){
            Sleep(2); // delay p esperar esvaziar
    }
}

int Carro::getNVoltas() {
	return voltas;
}

void Carro::run() {
	while (Parque::numPessoas > 0) {
		esperaEncher();

		daUmaVolta();

		esperaEsvaziar();

		voltas++;
	}
}
