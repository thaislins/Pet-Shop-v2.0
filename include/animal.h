/**
 * @file	animal.h
 * @brief	Definição da classe Animal e seus respectivos
 *			tipos: Anfíbio, Mamífero, Reptíl e Ave. 
 * @author	Thais Fernandes Lins
 * @since	28/10/2016
 * @date	06/11/2016
 */

 #include <iostream>
using std::endl;
using std::cin;
using std::cout;
using std::cerr;

#include <sstream>
using std::istringstream;

#include <map>
using std::map;

#include <vector>
using std::vector;

#include "funcionario.h"
#include "exceptions.h"

#ifndef ANIMAL_H
#define ANIMAL_H

/** 
 * @class 	Animal animal.h
 * @brief 	Classe abstrata que representa um Animal
 * @details	Os atributos de um animal são o id, a classe, o nome, o nome científico,
 *			o sexo, o tamanho, a sue dieta, seu respectivo veterinário, seu respectivo
 * 			tratador, e seu nome de batismo
 */
class Animal {
	private:
		virtual ostream& output(ostream&) const = 0;
		virtual istream& input(istream& is) = 0;
	protected:
		int id;
		int idv;
		int idt;
		string classe;
		string nome;
		string cientifico;
		char sexo;
		float tamanho;
		string dieta;
		Funcionario* veterinario;
		Funcionario* tratador;
		string batismo;
	public:
		Animal();
		Animal(int i,string c,string n,string ci,char sx,float tam,string dt,Veterinario* v, Tratador* t,string bt);
		virtual ~Animal() = 0;

		int getId();
		void setId(int i);
		int getIdVet();
		void setIdVet(int iv);
		int getIdTrat();
		void setIdTrat(int it);
		string getClasse();
		void setClasse(string c);
		string getNome();
		void setNome(string n);
		string getCientifico();
		void setCientifico(string c);
		char getSexo();
		void setSexo(char s);
		float getTamanho();
		void setTamanho(float t);
		string getDieta();
		void setDieta(string d);
		Funcionario* getVeterinario();
		void setVeterinario(Funcionario *v);
		Funcionario* getTratador();
		void setTratador(Funcionario *t);
		string getBatismo();
		void setBatismo(string b);
		string returnVetNome();
		string returnTratNome();
		void getMapInfoVet(map<int, Funcionario*> f);
		void getMapInfoTrat(map<int, Funcionario*> f);
		void ConsultaVet(int id, map<int, Animal*> a);
		
		friend istream& operator>>(istream &is, Animal &a);
		friend ostream& operator<<(ostream &o, const Animal &a);

		/** @brief Sobrecarga do operador de extracao de stream */
};

/** 
 * @class 	Anfibio animal.h
 * @brief 	Classe que representa um Anfibio
 * @details	Os atributos de um anfíbio são o total de mudas e 
 *			a sua data de última muda,além dos atributos herdados 
 *			de sua classe mãe que é a classe "Animal"
 */
class Anfibio : public Animal {
	protected:
		int total_mudas;
		string ultima_muda;
	public:
		Anfibio();
		~Anfibio();
	
		int getTotalMudas();
		void setTotalMudas(int tm);
		string getUltimaMuda();
		void setUltimaMuda(string um);
};

/** 
 * @class 	Sapo animal.h
 * @brief 	Classe que representa um Sapo
 * @details	Os atributos de um Sapo são herdados de sua 
 *			classe mãe que é a classe "Anfibio", que
 *			herda atributos da classe "Animal"
 */
class Sapo : public Anfibio {
	protected:
		istream& input(istream& is);
		ostream& output(ostream&) const;
	public:
		Sapo();
		~Sapo();
};

/** 
 * @class 	Mamifero animal.h
 * @brief 	Classe que representa um Mamifero
 * @details	O atributo de um mamifero é a cor de seu pelo, 
 *			além dos atributos herdados de sua classe mãe 
 *			que é a classe "Animal"
 */
class Mamifero : public Animal {
	protected:
		string cor_pelo;
	public:
		Mamifero();
		~Mamifero();

		string getCorPelo();
		void setCorPelo(string cp);
};

/** 
 * @class 	Leao animal.h
 * @brief 	Classe que representa um Leao
 * @details	Os atributos de um Leão são herdados de sua 
 *			classe mãe que é a classe "Mamifero", que
 *			herda atributos da classe "Animal"
 */
class Leao : public Mamifero {
	protected:
		istream& input(istream& is);
		ostream& output(ostream&) const;
	public:
		Leao();
		~Leao();
};

/** 
 * @class 	Reptil animal.h
 * @brief 	Classe que representa um Reptil
 * @details	Os atributos de um reptil são se ele é venenoso e o
 *			tipo de veneno, além dos atributos herdados de sua 
 *			classe mãe que é a classe "Animal"
 */
class Reptil : public Animal {
	protected:
		bool venenoso;
		string tipo_veneno;
	public:
		Reptil();
		~Reptil();

		bool getVenenoso();
		void setVenenoso(bool v);
		string getTipoVeneno();
		void setTipoVeneno(string tv);
};

/** 
 * @class 	Tartaruga animal.h
 * @brief 	Classe que representa um Tartaruga
 * @details	Os atributos de um Tartaruga são herdados de sua 
 *			classe mãe que é a classe "Reptil", que
 *			herda atributos da classe "Animal"
 */
class Tartaruga : public Reptil {
	protected:
		istream& input(istream& is);
		ostream& output(ostream&) const;
	public:
		Tartaruga();
		~Tartaruga();
};

/** 
 * @class 	Ave animal.h
 * @brief 	Classe que representa uma Ave
 * @details	Os atributos de uma ave são o tamanho de seu bico e 
 *			a envergadura, além dos atributos herdados de sua 
 *			classe mãe que é a classe "Animal"
 */
class Ave : public Animal {
	protected:
		int tamanho_bico;
		int envergadura;
	public:
		Ave();
		~Ave();

		int getTamanhoBico();
		void setTamanhoBico(int tb);
		int getEnvergadura();
		void setEnvergadura(int e);

};

/** 
 * @class 	AnimalSilvestre animalsilvestre.h
 * @brief 	Classe abstrata que representa um AnimalSilvestre
 * @details	O atributo de um animal silvestre é seu identificador
 *			no ibama
 */
class AnimalSilvestre {
	protected:
		string ibama;
	public:
		AnimalSilvestre();
		AnimalSilvestre(string i);
		virtual ~AnimalSilvestre() = 0;

		string getIbama();
		void setIbama(string i);

};

/** 
 * @class 	Nativo animalsilvestre.h
 * @brief 	Classe que representa um Animal Silvestre Nativo
 * @details	Os atributos de um animal silvestre nativo são a sua 
 *			unidade de federação e sua autorização, além dos atributos
 *			herdados da sua classe mãe que é a classe "Animal Silvestre"
 */
class Nativo : public AnimalSilvestre {
	protected:
		string uf_origem;
		string autorizacao;
	public:
		Nativo();
		Nativo(string uf, string a);
		~Nativo();

		string getUforigem();
		void setUforigem(string uf);
		string getAutorizacao();
		void setAutorizacao(string a);

};

/** 
 * @class 	Exotico animalsilvestre.h
 * @brief 	Classe que representa um Animal Silvestre Exotico
 * @details	O atributo de um animal silvestre exotico é o seu paiś 
 *			de origem, além dos atributos herdados da sua classe mãe que
 *			é a classe "Animal Silvestre"
 */
class Exotico : public AnimalSilvestre {
	protected:
		string pais_origem;
	public:
		Exotico();
		Exotico(string po);
		~Exotico();

		string getPaisOrigem();
		void setPaisOrigem(string po);

};

/** 
 * @class 	Papagaio animal.h
 * @brief 	Classe que representa um Papagaio
 * @details	Os atributos de um Papagaio são herdados de sua 
 *			classe mãe que é a classe "Ave", que
 *			herda atributos da classe "Animal"
 */
class Papagaio : public Ave, public Nativo {
	protected:
		istream& input(istream& is);
		ostream& output(ostream&) const;
	public:
		Papagaio();
		~Papagaio();
};

/** 
 * @class 	Tucano animal.h
 * @brief 	Classe que representa um Tucano
 * @details	Os atributos de um Tucano são herdados de sua 
 *			classe mãe que é a classe "Ave", que
 *			herda atributos da classe "Animal"
 */
class Tucano : public Ave, public Exotico {
	protected:
		istream& input(istream& is);
		ostream& output(ostream&) const;
	public:
		Tucano();
		~Tucano();
};

#endif