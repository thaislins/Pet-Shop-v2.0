/**
 * @file	funcionario.h
 * @brief	Definição da classe Funcionario e seus respectivos
 *			tipos: Veterinario e Tratador. 
 * @author	Thais Fernandes Lins
 * @since	28/10/2016
 * @date	06/11/2016
 */

#include <string>
using std::string;

#include <fstream>
using std::istream;
using std::ostream;

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

/** 
 * @class 	Funcionario funcionario.h
 * @brief 	Classe abstrata que representa um Funcionario
 * @details	Os atributos de um funcionario são o id, seu tipo (função), o nome, 
 *			o cpf, a idade, o tipo sanguínero, o fator RH e sua especialidade
 */
class Funcionario {
	protected:
		int id;
		string tipofunc;
		string nome;
		string cpf;
		short idade;
		char tipo_sanguineo;
		string fatorRH;
		string especialidade;
	public:
		Funcionario();
		Funcionario(int i, string tf, string n, string c, short ia, char ts, string rh, string e);
		virtual ~Funcionario() = 0;
		int getId();
		void setId(int i);
		string getNome();
		void setNome(string n);
		string getCpf();
		void setCpf(string c);
		short getIdade();
		void setIdade(short i);
		char getTipoS();
		void setTipoS(char ts);
		string getFatorRH();
		void setFatorRH(string rh);
		string getEspecialidade();
		void setEspecialidade(string e);
		string getTipoFunc();
		void setTipoFunc(string t);

		friend istream& operator>> (istream &is, Funcionario &f);
		friend ostream& operator<< (ostream &os, Funcionario &f);
};

/** 
 * @class 	Veterinario funcionario.h
 * @brief 	Classe que representa um Veterinario
 * @details	Os atributos de um funcionario são herdados da sua classe 
 * 			mãe que é a classe "Funcionario"
 */
class Veterinario : public Funcionario {
	public:
		Veterinario();
		~Veterinario();
};

/** 
 * @class 	Tratador funcionario.h
 * @brief 	Classe que representa um Tratador
 * @details	Os atributos de um funcionario são herdados da sua classe 
 * 			mãe que é a classe "Funcionario"
 */
class Tratador : public Funcionario {
	public:
		Tratador();
		~Tratador();
};

#endif