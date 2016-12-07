/**
 * @file	funcionario.cpp
 * @brief	Implementação dos métodos getters, setters, da 
 *			sobrecarga de operadores, dos construtores e destrutores
 * @author	Thais Fernandes Lins
 * @since	28/10/2016
 * @date	06/11/2016
 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <fstream>
using std::ifstream;
using std::istream;
using std::ostream;

#include "../include/funcionario.h"

/**
 * @details	Este construtor define os valores iniciais
 *			dos atributos da classe "Funcionario"
 */
Funcionario::Funcionario() {
	id = 0;
	tipofunc = "";
	nome = "";
	cpf = "";
	idade = 0;
	tipo_sanguineo = '\0';
	fatorRH = '\0';
	especialidade = "";
}

/**
 * @details	Este construtor recebe valores e dá esses valores		
 *			aos atributos da classe "Funcionario"
 * @param 	i   Identificador do funcionário
 * @param 	tf  Função do funcionário 
 * @param 	n   Nome do funcionário
 * @param 	c  	CPF do funcionário
 * @param 	ia  Idade do funcionário
 * @param 	ts 	Tipo sanguíneo do funcionário
 * @param 	rh  Fator RH do funcionário
 * @param 	e   Especialidade do funcionário
 */
Funcionario::Funcionario(int i, string tf, string n, string c, short ia, char ts, string rh, string e) :	
	id(i), tipofunc(tf), nome(n), cpf(c), idade(ia), tipo_sanguineo(ts), fatorRH(rh), especialidade(e) {

}

/**
 * @details	Destrutor vazio da classe "Funcionario"
 */
Funcionario::~Funcionario() {

}

/** @return Identificador do funcionário */
int Funcionario::getId() {
	return id;
}

/** @param i Identificador do funcionário */	
void Funcionario::setId(int i) {
	id = i;
}

/** @return Tipo de função do funcionário */	
string Funcionario::getTipoFunc() {
	return tipofunc;
}

/** @param t Tipo de função do funcionário */	
void Funcionario::setTipoFunc(string t) {
	tipofunc = t;
}

/** @return Nome do funcionário */	
string Funcionario::getNome() {
	return nome;
}

/** @param n Nome do funcionário */		
void Funcionario::setNome(string n) {
	nome = n;
}

/** @return Nome do funcionário */		
string Funcionario::getCpf() {
	return cpf;
}

/** @param c CPF do funcionário */	
void Funcionario::setCpf(string c) {
	cpf = c;
}

/** @return Idade do funcionário */	
short Funcionario::getIdade() {
	return idade;
}

/** @param i Idade do funcionário */		
void Funcionario::setIdade(short i) {
	idade = i;
}

/** @return Tipo sanguíneo do funcionário */	
char Funcionario::getTipoS() {
	return tipo_sanguineo;
}

/** @param ts Tipo sanguíneo do funcionário */	
void Funcionario::setTipoS(char ts) {
	tipo_sanguineo = ts;
}

/** @return Fator RH do funcionário */	
string Funcionario::getFatorRH() {
	return fatorRH;
}

/** @param rh Fator RH do funcionário */	
void Funcionario::setFatorRH(string rh) {
	fatorRH = rh;
}

/** @return Especialidade do funcionário */	
string Funcionario::getEspecialidade() {
	return especialidade;
}

/** @param e Especialidade do funcionário */		
void Funcionario::setEspecialidade(string e) {
	especialidade = e;
}

/**
 * @details	Sobrecarga do operador de inserção (>>)
 * @param 	is Input stream
 * @param 	f  Objeto da classe "Funcionario"
 */
istream& operator>> (istream &is, Funcionario &f) {

	string line,tipo_f;
	int i;
	getline(is, line);
	istringstream iss(line);

	iss >> i;	
	iss.ignore();
	getline(iss, tipo_f, ';');

	f.id = i;
	f.tipofunc = tipo_f;
	getline(iss, f.nome, ';');			
    getline(iss, f.cpf, ';');	
    iss >> f.idade;						
    iss.ignore();						
    iss >> f.tipo_sanguineo;					
    iss.ignore();
	getline (iss,f.fatorRH, ';');						
    getline(iss, f.especialidade, ';');    


    return is;
}

/**
 * @details	Sobrecarga do operador de impressão (<<)
 * @param 	os Output stream
 * @param 	f  Objeto da classe "Funcionario"
 */
ostream& operator<< (ostream &os, Funcionario &f) {

	os << "Identificador do funcionário: " << f.id << endl;
	os << "Função: " << f.tipofunc << endl;
	os << "Nome do funcionário: " << f.nome << endl;
	os << "CPF do funcionário: " << f.cpf << endl;
	os << "Idade do funcionário: " << f.idade << endl;
	os << "Tipo Sanguíneo: " << f.tipo_sanguineo << endl;
	os << "Fator RH: " << f.fatorRH << endl;
	os << "Especialidade: " << f.especialidade << endl;
	cout << endl;

	return os;
}

/**
 * @details	Construtor vazio da classe "Veterinario"
 */
Veterinario::Veterinario() {

}

/**
 * @details	Destrutor vazio da classe "Veterinario"
 */
Veterinario::~Veterinario() {

}

/**
 * @details	Construtor vazio da classe "Tratador"
 */
Tratador::Tratador() {

}

/**
 * @details	Destrutor vazio da classe "Tratador"
 */
Tratador::~Tratador() {

}