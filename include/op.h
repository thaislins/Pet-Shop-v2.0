/**
 * @file	op.h
 * @brief	Protótipo de funções de operações do arquivo "op.cpp"
 * @author	Thais Fernandes Lins
 * @since	28/10/2016
 * @date	06/11/2016
 */

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

#include <map>
using std::map;

#include <vector>
using std::vector;

#include "animal.h"

#ifndef OP_H
#define OP_H

/**
 * @brief 		 Realiza o cadastro de animais 
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 * @param classe Classe de animais
 * @param is 	 Arquivo que contém informações sobre dados cadastrais
 * @param x 	 Posição
 * @param nome 	 Nome do animal
 */
void CadastroAnimal(map<int, Animal*> &a, map<int, Funcionario*> &f, string classe, ifstream &is, int x, string nome);

/**
 * @brief 		 Realiza o cadastro de funcionários
 * @param func 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Funcionario*" 
 * @param tipo	 Função do funcionário
 * @param is 	 Arquivo que contém informações sobre dados cadastrais
 * @param x 	 Posição
 */
void CadastroFuncionario(map<int, Funcionario*> &f, string tipo, ifstream &is, int x);

/**
 * @brief 		 Realiza a consulta dos dados dos animais
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 */
void ConsultaAnimal(map<int, Animal*> &a);

/**
 * @brief 		 Realiza a consulta dos dados dos funcionários
 * @param func 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Funcionário*" 
 */
void ConsultaFuncionario(map<int, Funcionario*> &f);

/**
 * @brief 		 Realiza a remoção dos dados do animal
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 */
void RemoveAnimal(map<int, Animal*> &a, int id);

/**
 * @brief 		 Realiza a remoção dos dados dos funcionários
 * @param func 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Funcionário*" 
 */
void RemoveFuncionario(map<int, Funcionario*> &f);

/**
 * @brief 		 Realiza a alteração dos dados dos funcionários
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 */
void AlteraAnimal(map<int, Animal*> &a);

/**
 * @brief 		 Realiza a consulta de dados por responsabilidade
 * 				 de um veterinário ou tratador
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 */
void ConsultaVetOuTrat(map<int, Animal*> &a);

#endif