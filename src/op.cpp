/**
 * @file	op.cpp
 * @brief	Implementação de operações a serem realizadas sobre
 *			os animais e funcionários por meio de uma lista encadeada
 * @author	Thais Fernandes Lins
 * @since	28/10/2016
 * @date	06/11/2016
 */

#define LIM_FUNC 4
#define LIM_ANIM 4

#include "../include/op.h"

/**
 * @brief 		 Realiza o cadastro de animais 
 * @param a 	 Lista simplesmente encadeada que armazena 
 *				 objetos do tipo "Animal*" 
 * @param classe Classe de animais
 * @param is 	 Arquivo que contém informações sobre dados cadastrais
 * @param x 	 Posição
 * @param nome 	 Nome do animal
 */

void CadastroAnimal(map<int, Animal*> &a, map<int, Funcionario*> &f, string classe, ifstream &is, int x, string nome) {

	Animal *a1;

	try {
		if (classe == "Mammalia") {
			a1 = new Leao;
			is >> (*a1);
			a[x] = a1;
			a1->getMapInfoVet(f);
			a1->getMapInfoTrat(f);
			}
		else if (classe == "Amphibia") { 
			a1 = new Sapo;
			is >> (*a1);
			a[x] = a1;
			a1->getMapInfoVet(f);
			a1->getMapInfoTrat(f);
			}
		else if (classe == "Reptilia") {
			a1 = new Tartaruga;
			is >> (*a1);
			a[x] = a1;
			a1->getMapInfoVet(f);
			a1->getMapInfoTrat(f);
			}
		else if (classe == "Ave") {
		
			if(nome == "Papagaio"){
				a1 = new Papagaio;
				is >> (*a1);
				a[x] = a1;
				a1->getMapInfoVet(f);
				a1->getMapInfoTrat(f);
			}

			else{
				a1 = new Tucano;
				is >> (*a1);
				a[x] = a1;
				a1->getMapInfoVet(f);
				a1->getMapInfoTrat(f);
			}
		}
		else {
			throw InputError();
		}
	} catch (InputError &ex) {
		cerr << ex.what() << endl;
	}
}


void CadastroFuncionario(map<int, Funcionario*> &f, string tipo, ifstream &is, int x) {

	Funcionario* f1;

	try {
		if (tipo == "Veterinario") {
			f1 = new Veterinario;
			is >> (*f1);
			f[x] = f1;
		}
		else if (tipo == "Tratador") {
			f1 = new Tratador;
			is >> (*f1);
			f[x] = f1;
		}
		else {
			throw InputError();
		}
	} catch (InputError &ex) {
		cerr << ex.what() << endl;
	}
}


void ConsultaAnimal(map<int, Animal*> &a) {

	int id;

	cout << "Defina qual o id do animal que se busca: ";
	cin >> id;

	try {
		map<int, Animal*>::iterator busca = a.find(id);
		if (busca != a.end()){
			cout << (*a[id]);
		}
		else{
			throw InvalidID();
		}
	} catch (InvalidID &ex) {
		cerr << ex.what() << endl;
	}
}


void ConsultaFuncionario(map<int, Funcionario*> &f) {

	int id;

	cout << "Defina qual o id do funcionário que se busca: ";
	cin >> id;

	map<int, Funcionario*>::iterator busca = f.find(id);
	
	try {
		if (busca != f.end()){
			cout << (*f[id]);
		}
		else{
			throw InvalidID();	
		}
	} catch (InvalidID &ex) {
		cerr << ex.what() << endl;
	} 
}

void RemoveAnimal(map<int, Animal*> &a, int id) {

	map<int, Animal*>::iterator busca = a.find(id);

	try {
		if (busca != a.end()){
			a.erase(id);
			cout << "Animal foi removido com sucesso" << endl;
		}
		else{
			throw InvalidID();		
		}
	} catch (InvalidID &ex) {
		cerr << ex.what() << endl;
	}
}

void RemoveFuncionario(map<int, Funcionario*> &f) {

	int id;

	cout << "Defina qual o id do funcionário que será removido: ";
	cin >> id;

	map<int, Funcionario*>::iterator busca = f.find(id);
	
	try {
		if (busca != f.end()){
			f.erase(id);
			cout << "Funcionário foi removido com sucesso" << endl;
		}
		else{
			throw InvalidID();	
		}
	} catch (InvalidID &ex) {
		cerr << ex.what() << endl;
	}
}

void AlteraAnimal(map<int, Animal*> &a) {

	/*int id;
	string classe;

	cout << "Defina qual o id do animal que se deseja alterar dados: ";
	cin >> id;

	map<int, Animal*>::iterator busca = a.find(id);
	if (busca != a.end()){
		cout << "Estes são os dados do animal: ";
		cout << (*a[id]);
		//i = 1;
	}
	else{
		cout << "ID inválido" << endl;	
	}

	classe = busca->second->getClasse();
	cout << classe << endl;*/

}

void ConsultaVetOuTrat(map<int, Animal*> &a) {

	string func;
	int id;
	std::map<int, Animal*>::iterator it;

	cout << "Defina qual tipo de funcionário se deseja (veterinario ou tratador): ";
	cin >> func;

	try {
		if(func == "veterinario") {
			cout << "Defina qual sérá o id do veterinário: ";
			cin >> id;
			
			for (it = a.begin(); it != a.end(); ++it) {
				if(it->second->getVeterinario()->getId() == id)
					cout <<  (*it->second) << endl;
			}
		}
		else if(func == "tratador") {
			cout << "Defina qual sérá o id do tratador: ";
			cin >> id;

			for (it = a.begin(); it != a.end(); ++it) {
				if(it->second->getVeterinario()->getId() == id)
					cout <<  (*it->second) << endl;
			}
		}
		else {
			throw InputError();
		}
	} catch (InputError &ex) {
		ex.what();
	}	
}
