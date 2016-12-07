#include <cstdlib>
using std::exit;
#include <cstring>

#include "../include/op.h"

#define LIM_ANIM 5
#define LIM_FUNC 4

int main(int argc, char const *argv[]) {
	
	ifstream tipoclasse,petfera,funcionarios,tipofunc;
	funcionarios.open("funcionarios");
	tipofunc.open("funcionarios");
	tipoclasse.open("petfera");
	petfera.open("petfera");

	map<int, Animal*> a1;
	map<int, Funcionario*> f1;

	try {
	if(!funcionarios || !petfera || !tipoclasse || !tipofunc)
		throw FileNotFound();
	} 
	catch (FileNotFound &ex) {
		std::cerr << ex.what() << std::endl;
		exit(1);
	}

	//Cadastro Funcionários
	for (int i = 0; i < LIM_FUNC; i++) {
 		string linha, tipo_f;
		int id;

		getline(tipofunc, linha);
		istringstream iss(linha);
		iss >> id;	
		iss.ignore();
		getline(iss, tipo_f, ';');	

		CadastroFuncionario(f1,tipo_f,funcionarios,id);
 	}


	//Cadastro Animais
 	for (int i = 0; i < LIM_ANIM; i++) {
 		int id;
 		string classe,linha2,nome;
	
 		tipoclasse >> id;
 		tipoclasse.ignore();
		getline(tipoclasse, classe, ';');
		getline(tipoclasse, nome, ';');
		getline(tipoclasse, linha2);
					

		CadastroAnimal(a1,f1,classe,petfera,id,nome);
 	}
 			
 	tipofunc.close();
 	tipoclasse.close();
 	petfera.close();
 	funcionarios.close();

 	string classe = " ", vet = " ", trat = " ", nomearquivo = " ";

 	 //strcmp(items[n], "ae") == 0
 	for (int i = 0; i < argc; i++) {
 		
 		if(strcmp(argv[i], "-c") == 0)
 			classe = argv[i+1];
 		else if (strcmp(argv[i], "-v") == 0)
 			vet = argv[i+1];
 		if(strcmp(argv[i], "-t") == 0)
 			trat = argv[i+1];
 	}

 	nomearquivo = argv[argc-1];

 	ofstream exportar; 
 	exportar.open(nomearquivo);

 	std::map<int, Animal*>::iterator it;

 	if (classe != " " and vet != " " and trat != " ") {

 		for (it = a1.begin(); it != a1.end(); ++it) {
			if(it->second->getClasse() == classe and it->second->getVeterinario()->getNome() == vet and it->second->getTratador()->getNome() == trat)
				exportar <<  (*it->second) << endl;
				cout << endl;
		}
 	}
 	else if (classe != " " and vet != " " and trat == " ") {

 		for (it = a1.begin(); it != a1.end(); ++it) {
			if(it->second->getClasse() == classe and it->second->getVeterinario()->getNome() == vet)
				exportar <<  (*it->second) << endl;
				exportar << endl;
		}
 	}
 	else if (classe != " " and trat != " " and vet == " ") {

 		for (it = a1.begin(); it != a1.end(); ++it) {
			if(it->second->getClasse() == classe and it->second->getTratador()->getNome() == trat)
				exportar <<  (*it->second) << endl;
				exportar << endl;
		}
 	}
 	else if (trat != " " and vet != " " and classe == "") {

 		for (it = a1.begin(); it != a1.end(); ++it) {
			if(it->second->getVeterinario()->getNome() == vet and it->second->getTratador()->getNome() == trat)
				exportar <<  (*it->second) << endl;
				exportar << endl;
		}
 	}
 	else if (classe != " " and trat == " " and vet == " ") {

 		for (it = a1.begin(); it != a1.end(); ++it) {
			if(it->second->getClasse() == classe)
				exportar <<  (*it->second) << endl;
				exportar << endl;
		}
 	}
 	else if (vet != " " and classe == " " and trat == " ") {

 		for (it = a1.begin(); it != a1.end(); ++it) {
			if(it->second->getVeterinario()->getNome() == vet)
				exportar <<  (*it->second) << endl;
				exportar << endl;
		}
 	}
 	else if (trat != " " and classe == " " and vet == " ") {

 		for (it = a1.begin(); it != a1.end(); ++it) {
			if(it->second->getTratador()->getNome() == trat)
				exportar <<  (*it->second) << endl;
				exportar << endl;
		}
 	}
 	else {
 		for (it = a1.begin(); it != a1.end(); ++it) {
				exportar <<  (*it->second) << endl;
				exportar << endl;
		}
 	}


	return 0;
}