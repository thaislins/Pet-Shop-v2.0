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
 * @param a 	 map que armazena objetos do tipo "Animal*"
 * @param f 	 map que armazena objetos do tipo "Funcionario*"			 
 * @param classe Classe de animais
 * @param is 	 Arquivo que contém informações sobre dados cadastrais
 * @param x 	 Id do animal
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

/**
 * @brief 		 Realiza o cadastro de funcionários
 * @param f 	 map que armazena objetos do tipo "Funcionario*" 
 * @param tipo	 Função do funcionário
 * @param is 	 Arquivo que contém informações sobre dados cadastrais
 * @param x 	 Id do funcioário
 */
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

/**
 * @brief 		 Realiza a consulta dos dados dos animais
 * @param a 	 map que armazena objetos do tipo "Animal*" 
 */
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

/**
 * @brief 		 Realiza a consulta dos dados dos funcionários
 * @param f 	 map que armazena objetos do tipo "Funcionario*" 
 */
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

/**
 * @brief 		 Realiza a remoção dos dados do animal
 * @param a 	 map que armazena objetos do tipo "Animal*" 
 */
void RemoveAnimal(map<int, Animal*> &a) {

	int id;

	cout << "Defina qual o id do animal que será removido: ";
	cin >> id;

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

/**
 * @brief 		 Realiza a remoção dos dados dos funcionários
 * @param f 	 map que armazena objetos do tipo"Funcionario*" 
 */
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

/**
 * @brief 		 Realiza a alteração dos dados dos funcionários
 * @param a 	 map que armazena objetos do tipo "Animal*"
 */
void AlteraAnimal(map<int, Animal*> &a) {

	int id;
	double tamanho;
	string dieta, nomebatismo;

	cout << "Defina qual o id do animal que se deseja alterar dados: ";
	cin >> id;

	map<int, Animal*>::iterator busca = a.find(id);
	if (busca != a.end()){
		cout << "Estes são os dados do animal: ";
		cout << (*a[id]);
	}
	else{
		cout << "ID inválido" << endl;	
	}

	cout << endl << "Realize a alteração dos dados: " << endl;
	cout << "Obs: somente alguns dados podem ser alterados " << endl << endl;

	if (busca->second->getClasse() == "Amphibia") {

		Anfibio* m = new Sapo;

		int totalmudas;
		string ultimamuda;

		m->setId(busca->second->getId());
		m->setClasse(busca->second->getClasse());
		m->setNome(busca->second->getNome());
		m->setCientifico(busca->second->getCientifico());
		m->setSexo(busca->second->getSexo());
		m->setVeterinario(busca->second->getVeterinario());
		m->setTratador(busca->second->getTratador());
		m->setBatismo(busca->second->getBatismo());
		cout << "Tamanho médio em metros: ";
		cin >> tamanho;
		m->setTamanho(tamanho);
		cout << "Dieta do animal: ";
		cin >> dieta;
		m->setDieta(dieta);
		cout << "Total de mudas: ";
		cin >> totalmudas;
		m->setTotalMudas(totalmudas);
		cout << "Data da ultima muda: ";
		cin >> ultimamuda;
		m->setUltimaMuda(ultimamuda);

		a.at(busca->second->getId()) = m;
	}

	else if (busca->second->getClasse() == "Mammalia") {

		Mamifero* m = new Leao;

		string cor_pelo;

		m->setId(busca->second->getId());
		m->setClasse(busca->second->getClasse());
		m->setNome(busca->second->getNome());
		m->setCientifico(busca->second->getCientifico());
		m->setSexo(busca->second->getSexo());
		m->setVeterinario(busca->second->getVeterinario());
		m->setTratador(busca->second->getTratador());
		m->setBatismo(busca->second->getBatismo());
		cout << "Tamanho médio em metros: ";
		cin >> tamanho;
		m->setTamanho(tamanho);
		cout << "Dieta do animal: ";
		cin >> dieta;
		m->setDieta(dieta);
		cout << "Cor do pelo do animal: ";
		cin >> cor_pelo;
		m->setCorPelo(cor_pelo);

		a.at(busca->second->getId()) = m;
	}
	else if (busca->second->getClasse() == "Reptilia") {

		Reptil* m = new Tartaruga;

		bool venenoso;
		string tipo_veneno;

		m->setId(busca->second->getId());
		m->setClasse(busca->second->getClasse());
		m->setNome(busca->second->getNome());
		m->setCientifico(busca->second->getCientifico());
		m->setSexo(busca->second->getSexo());
		m->setVeterinario(busca->second->getVeterinario());
		m->setTratador(busca->second->getTratador());
		m->setBatismo(busca->second->getBatismo());
		cout << "Tamanho médio em metros: ";
		cin >> tamanho;
		m->setTamanho(tamanho);
		cout << "Dieta do animal: ";
		cin >> dieta;
		m->setDieta(dieta);
		cout << "Venenoso: ";
		cin >> venenoso;
		m->setVenenoso(venenoso);
		if(venenoso == 1) {
			cout << "Tipo de veneno: ";
			cin >> tipo_veneno;
			m->setTipoVeneno(tipo_veneno);
		}

		a.at(busca->second->getId()) = m;
	}
	else {

		if (busca->second->getNome() == "Papagaio") {
			Papagaio* m = new Papagaio;

			int bico,envergadura;
			string ibama, origem,autorizacao;

			m->setId(busca->second->getId());
			m->setClasse(busca->second->getClasse());
			m->setNome(busca->second->getNome());
			m->setCientifico(busca->second->getCientifico());
			m->setSexo(busca->second->getSexo());
			m->setVeterinario(busca->second->getVeterinario());
			m->setTratador(busca->second->getTratador());
			m->setBatismo(busca->second->getBatismo());
			cout << "Tamanho médio em metros: ";
			cin >> tamanho;
			m->setTamanho(tamanho);
			cout << "Dieta do animal: ";
			cin >> dieta;
			m->setDieta(dieta);
			cout << "Tamanho do bico: ";
			cin >> bico;
			m->setTamanhoBico(bico);
			cout << "Envergadura: ";
			cin >> envergadura;
			m->setEnvergadura(envergadura);
			cout << "Situação do animal no IBAMA: ";
			cin >> ibama;
			m->setIbama(ibama);
			cout << "Status de autorização do animal: ";
			cin >> autorizacao;
			m->setAutorizacao(autorizacao);

			a.at(busca->second->getId()) = m;
		}
		else {
			Tucano* m = new Tucano;

			int bico,envergadura;
			string ibama;

			m->setId(busca->second->getId());
			m->setClasse(busca->second->getClasse());
			m->setNome(busca->second->getNome());
			m->setCientifico(busca->second->getCientifico());
			m->setSexo(busca->second->getSexo());
			m->setVeterinario(busca->second->getVeterinario());
			m->setTratador(busca->second->getTratador());
			m->setBatismo(busca->second->getBatismo());
			cout << "Tamanho médio em metros: ";
			cin >> tamanho;
			m->setTamanho(tamanho);
			cout << "Dieta do animal: ";
			cin >> dieta;
			m->setDieta(dieta);
			cout << "Tamanho do bico: ";
			cin >> bico;
			m->setTamanhoBico(bico);
			cout << "Envergadura: ";
			cin >> envergadura;
			m->setEnvergadura(envergadura);
			cout << "Situação do animal no IBAMA: ";
			cin >> ibama;
			m->setIbama(ibama);

			a.at(busca->second->getId()) = m;
		}
	}
}

/**
 * @brief 		 Realiza a consulta de dados por responsabilidade
 * 				 de um veterinário ou tratador
 * @param a 	 map que armazena objetos do tipo "Animal*" 
 */
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
