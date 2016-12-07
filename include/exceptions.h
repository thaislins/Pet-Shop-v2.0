/**
 * @file	exceptions.h
 * @brief	Definicao de classes de tratamento de erros
 * @author	Thais Fernandes Lins
 * @date	04/12/2016
 */

#include <exception>
#include <stdexcept>

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

/** 
 * @class 	FileNotFound exceptions.h
 * @brief 	Classe que realiza tratamento de erros de arquivos
 */
class FileNotFound : public std::exception {
	public:
		const char* what() {
		return "O arquivo não foi encontrado\nO programa será encerrado";
		}
};

/** 
 * @class 	InputError exceptions.h
 * @brief 	Classe que realiza tratamento de erros de entrada
 */
class InputError : public std::exception {
	public:
		const char* what() {
			return "Entrada Inválida";
		}
};

/** 
 * @class 	ValueLimit exceptions.h
 * @brief 	Classe que realiza tratamento de erros de argumentos inválidos
 */
class InvalidID : public std::invalid_argument {
	public:
		InvalidID() : std::invalid_argument("Operacao invalida: Id não foi encontrado") {}
};

#endif

