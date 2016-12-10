/**
 * @file	animal.cpp
 * @brief	Implementação dos métodos getters, setters, da 
 *			sobrecarga de operadores, dos construtores e destrutores
 * @author	Thais Fernandes Lins
 * @since	28/10/2016
 * @date	06/11/2016
 */


#include "../include/animal.h"
#define LIM_VET 2


/**
 * @details	Este construtor define os valores iniciais
 *			dos atributos da classe "Animal"
 */
Animal::Animal() {
	id = 0;
	classe = "";
	nome = "";
	cientifico = "";
	sexo = '\0';
	tamanho = 0.0;
	dieta = "";
	veterinario = new Veterinario;
	tratador = new Tratador;
	batismo = "";
}

/**
 * @details	Este construtor recebe valores e dá esses valores		
 *			aos atributos da classe "Animal"
 * @param 	i   Identificador do animal
 * @param 	c   Classe do animal
 * @param 	n   Nome do animal
 * @param 	ci  Nome científico do animal
 * @param 	sx  Sexo do animal
 * @param 	tam Tamanho médio em metros do animal
 * @param 	dt  Dieta predominante do animal
 * @param 	v   Veterinário associado ao animal
 * @param 	t   Tratador associado ao animal
 * @param 	bt  Nome de batismo do animal
 */
Animal::Animal(int i,string c,string n,string ci,char sx,float tam,string dt,Veterinario* v, Tratador* t,string bt) :
	id(i), nome(n), cientifico(ci), sexo(sx), tamanho(tam), dieta(dt), veterinario(v), tratador(t), batismo(bt) {

}

/**
 * @details	Destrutor vazio da classe "Animal"
 */
Animal::~Animal() {

}

/** @return Identificador do animal */
int Animal::getId() {
	return id;
}

/** @param i Identificador do animal */	
void Animal::setId(int i) {
	id = i;
}

/** @return Identificador do veterinario */
int Animal::getIdVet() {
	return idv;
}

/** @param iv Identificador do veterinario */
void Animal::setIdVet(int iv) {
	idv = iv;
}

/** @return Identificador do tratador */
int Animal::getIdTrat() {
	return idt;
}

/** @param it Identificador do tratador */
void Animal::setIdTrat(int it) {
	idt = it;
}


/** @return Classe do animal */
string Animal::getClasse() {
	return classe;
}

/** @param c Classe do animal */
void Animal::setClasse(string c) {
	classe = c;
}

/** @return Nome do animal */
string Animal::getNome() {
	return nome;
}

/** @param n Nome do animal */	
void Animal::setNome(string n) {
	nome = n;
}

/** @return Nome científico do animal */
string Animal::getCientifico() {
	return cientifico;
}

/** @param c Nome científico do animal */	
void Animal::setCientifico(string c) {
	cientifico = c;
}

/** @return Sexo do animal */		
char Animal::getSexo() {
	return sexo;
}

/** @param s Sexo do animal */	
void Animal::setSexo(char s) {
	sexo = s;
}

/** @return Tamanho médio em metros */
float Animal::getTamanho() {
	return tamanho;
}
		
/** @param t Tamanho médio em metros do animal */
void Animal::setTamanho(float t) {
	tamanho = t;
}

/** @return Dieta predominante do animal */	
string Animal::getDieta() {
	return dieta;
}

/** @param d Dieta predominante do animal */
void Animal::setDieta(string d) {
	dieta = d;
}

/** @return Veterinário associado ao animal */
Funcionario* Animal::getVeterinario() {
	return veterinario;
}

/** @param v Veterinário associado ao animal */
void Animal::setVeterinario(Funcionario *v) {
	veterinario = v;
}

/** @return Tratador associado ao animal */
Funcionario* Animal::getTratador() {
	return tratador;
}

/** @param t Tratador associado ao animal */
void Animal::setTratador(Funcionario *t) {
	tratador = t;
}

/** @return Nome de batismo do animal */
string Animal::getBatismo() {
	return batismo;
}

/** @param b Nome de batismo animal */
void Animal::setBatismo(string b) {
	batismo = b;
}

void Animal::getMapInfoVet(map<int, Funcionario*> f) {

	if(veterinario->getId() == 0) {
		veterinario->setNome("Não há veterinário associado a esse animal");
	}
	else {

		try {
			map<int, Funcionario*>::iterator busca = f.find(veterinario->getId());
			if (busca != f.end()){
				veterinario->setNome(f[veterinario->getId()]->getNome());
			}
			else {
				throw InvalidID();
			}
		} catch (InvalidID &ex) {
			cerr << ex.what() << endl;
		}
	}
}

void Animal::getMapInfoTrat(map<int, Funcionario*> f) {

	if(tratador->getId() == 0) {
		tratador->setNome("Não há tratador associado a esse animal");
	}
	else {

		try {
			map<int, Funcionario*>::iterator busca = f.find(tratador->getId());
			if (busca != f.end()){
				tratador->setNome(f[tratador->getId()]->getNome());
			}
			else {
				throw InvalidID();
			}
		} catch (InvalidID &ex) {
			cerr << ex.what() << endl;
		}
	}
}

/**
 * @details	Sobrecarga do operador de inserção (>>)
 * @param 	is Input stream
 */
istream& operator>>(istream &is, Animal &a){
	return a.input(is);
}

/**
 * @details	Sobrecarga do operador de impressão (<<)
 * @param 	os Output stream
 */
ostream& operator<<(ostream &o, const Animal &a){
	return a.output(o);
}

/**
 * @details	Este construtor define os valores iniciais
 *			dos atributos da classe "Anfibio"
 */
Anfibio::Anfibio() {
	total_mudas = 0;
	ultima_muda = "";
}

/**
 * @details	Destrutor vazio da classe "Anfibio"
 */
Anfibio::~Anfibio() {

}

/** @return Valor do total de mudas do anfíbio */
int Anfibio::getTotalMudas() {
	return total_mudas;
}

/** @param tm Valor do total de mudas do anfíbio */
void Anfibio::setTotalMudas(int tm) {
	total_mudas = tm;
}

/** @return Data da última muda do anfíbio */
string Anfibio::getUltimaMuda() {
	return ultima_muda;
}

/** @param um Data da última muda do anfíbio */	
void Anfibio::setUltimaMuda(string um) {
	ultima_muda = um;
}

/**
 * @details	Construtor vazio da classe "Sapo"
 */
Sapo::Sapo() {

}

/**
 * @details	Destrutor vazio da classe "Sapo"
 */
Sapo::~Sapo() {

}

/**
 * @details	Sobrecarga do operador de inserção (>>)
 *			para a classe "Sapo"
 * @param 	is Input stream
 */
istream& Sapo::input(istream& is) {
	
	string line;

	getline(is, line);
	istringstream iss(line);

	iss>> id;
	iss.ignore();
	getline(iss, classe, ';');
	getline(iss, nome, ';');
	getline(iss, cientifico, ';');
	iss>> sexo;
	iss.ignore();
	iss>> tamanho;
	iss.ignore();
	getline(iss, dieta, ';');
	iss >> idv; 
	veterinario->setId(idv);
	iss.ignore();
	iss >> idt; 
	tratador->setId(idt);
	iss.ignore();
	getline(iss, batismo, ';');
	iss >> total_mudas;
	iss.ignore();
	getline(iss, ultima_muda, ';');
	
	return is;
}

/**
 * @details	Sobrecarga do operador de impressão (<<)
 *			para a classe "Sapo"
 * @param 	os Output stream
 */
ostream& Sapo::output(ostream& o) const{

	//string nomevet = returnVetNome(idv);
	
	o << "ID do animal: " << id << endl;
	o << "Classe do animal: " << classe << endl;
	o << "Nome do animal: " << nome << endl;
	o << "Nome cientifico do animal: " << cientifico << endl; 
	o << "Sexo do animal: " << sexo << endl;
	o << "Tamanho médio em metros: " << tamanho << endl;
	o << "Dieta do animal: " << dieta << endl;
	o << "Veterinário associado: " << veterinario->getNome() << endl;
	o << "Tratador responsável: " << tratador->getNome() << endl;
	o << "Nome de batismo do animal: " << batismo << endl;
	o << "Total de mudas do animal: " << total_mudas << endl;
	o << "Ultima muda do animal: " << ultima_muda << endl;

	return o;
}

/**
 * @details	Este construtor define os valores iniciais
 *			dos atributos da classe "Mamifero"
 */
Mamifero::Mamifero() {
	cor_pelo = "";
}

/**
 * @details	Destrutor vazio da classe "Mamifero"
 */
Mamifero::~Mamifero() {

}

/** @return Cor do pelo do mamífero */
string Mamifero::getCorPelo() {
	return cor_pelo;
}

/** @param cp Cor do pelo do mamífero */	
void Mamifero::setCorPelo(string cp) {
	cor_pelo = cp;
}

/**
 * @details	Construtor vazio da classe "Leao"
 */
Leao::Leao() {

}

/**
 * @details	Destrutor vazio da classe "Leao"
 */
Leao::~Leao() {

}

/**
 * @details	Sobrecarga do operador de inserção (>>)
 *			para a classe "Leao"
 * @param 	is Input stream
 */
istream& Leao::input(istream& is) {
			
	string line;
	int idv, idt;

	getline(is, line);
	istringstream iss(line);

	iss>> id;
	iss.ignore();
	getline(iss, classe, ';');
	getline(iss, nome, ';');
	getline(iss, cientifico, ';');
	iss>> sexo;
	iss.ignore();
	iss>> tamanho;
	iss.ignore();
	getline(iss, dieta, ';');
	iss >> idv; 
	veterinario->setId(idv);
	iss.ignore();
	iss >> idt; 
	tratador->setId(idt);
	iss.ignore();
	getline(iss, batismo, ';');
	getline(iss, cor_pelo, ';');
	
	return is;
}	

/**
 * @details	Sobrecarga do operador de impressão (<<)
 *			para a classe "Leao"
 * @param 	os Output stream
 */
ostream& Leao::output(ostream& o) const{
	
	o << "ID do animal: " << id << endl;
	o << "Classe do animal: " << classe << endl;
	o << "Nome do animal: " << nome << endl;
	o << "Nome cientifico do animal: " << cientifico << endl; 
	o << "Sexo do animal: " << sexo << endl;
	o << "Tamanho médio em metros:  " << tamanho << endl;
	o << "Dieta do animal: " << dieta << endl;
	o << "Veterinário associado: " << veterinario->getNome() << endl;
	o << "Tratador responsável: " << tratador->getNome() << endl;
	o << "Nome de batismo do animal: " << batismo << endl;
	o << "Cor do pelo do animal: " << cor_pelo << endl;

	return o;
}

/**
 * @details	Este construtor define os valores iniciais
 *			dos atributos da classe "Reptil"
 */
Reptil::Reptil() {
	venenoso = false;
	tipo_veneno = "";
}

/**
 * @details	Destrutor vazio da classe "Reptil"
 */
Reptil::~Reptil() {

}

/** @return Verdadeiro se o reptil for venenoso, falso caso contrario */
bool Reptil::getVenenoso() {
	return venenoso;
}


/** @param v Verdadeiro se o reptil for venenoso, falso caso contrario */
void Reptil::setVenenoso(bool v) {
	venenoso = v;
}

/** @return Tipo de veneno do reptil */
string Reptil::getTipoVeneno() {
	return tipo_veneno;
}

/** @param tv Tipo de veneno do reptil */
void Reptil::setTipoVeneno(string tv) {
	tipo_veneno = tv;
}

/**
 * @details	Construtor vazio da classe "Tartaruga"
 */
Tartaruga::Tartaruga() {

}

/**
 * @details	Destrutor vazio da classe "Tartaruga"
 */
Tartaruga::~Tartaruga() {

}

/**
 * @details	Sobrecarga do operador de inserção (>>)
 *			para a classe "Tartaruga"
 * @param 	is Input stream
 */
istream& Tartaruga::input(istream& is) {
			
	string line;
	int idv, idt;

	getline(is, line);
	istringstream iss(line);

	iss>> id;
	iss.ignore();
	getline(iss, classe, ';');
	getline(iss, nome, ';');
	getline(iss, cientifico, ';');
	iss>> sexo;
	iss.ignore();
	iss>> tamanho;
	iss.ignore();
	getline(iss, dieta, ';');
	iss >> idv; 
	veterinario->setId(idv);
	iss.ignore();
	iss >> idt; 
	tratador->setId(idt);
	iss.ignore();
	getline(iss, batismo, ';');
	iss >> venenoso;
	iss.ignore();
	getline(iss, tipo_veneno, ';');
	
	return is;
}	

/**
 * @details	Sobrecarga do operador de impressão (<<)
 *			para a classe "Tartaruga"
 * @param 	os Output stream
 */
ostream& Tartaruga::output(ostream& o) const{
	
	o << "ID do animal: " << id << endl;
	o << "Classe do animal: " << classe << endl;
	o << "Nome do animal: " << nome << endl;
	o << "Nome cientifico do animal: " << cientifico << endl; 
	o << "Sexo do animal: " << sexo << endl;
	o << "Tamanho médio em metros:  " << tamanho << endl;
	o << "Dieta do animal: " << dieta << endl;
	o << "Veterinário associado: " << veterinario->getNome() << endl;
	o << "Tratador responsável: " << tratador->getNome() << endl;
	o << "Nome de batismo do animal: " << batismo << endl;
	o << "Venenoso: " << venenoso << endl;
	if(venenoso)
	o << "Tipo do veneno: " << tipo_veneno << endl;

	return o;
}

/**
 * @details	Este construtor define os valores iniciais
 *			dos atributos da classe "Ave"
 */
Ave::Ave() {
	tamanho_bico = 0;
	envergadura = 0;
}

/**
 * @details	Destrutor vazio da classe "Ave"
 */
Ave::~Ave() {

}

/** @return Tamanho do bico da ave */
int Ave::getTamanhoBico() {
	return tamanho_bico;
}

/** @param tb Tamanho do bico da ave */
void Ave::setTamanhoBico(int tb) {
	tamanho_bico = tb;
}

/** @return Envergadura da ave */
int Ave::getEnvergadura() {
	return envergadura;
}

/** @param e Envergadura da ave */
void Ave::setEnvergadura(int e) {
	envergadura = e;
}

/**
 * @details	Este construtor define os valores iniciais
 *			dos atributos da classe "AnimalSilvestre"
 */
AnimalSilvestre::AnimalSilvestre() {
	ibama = "";
}

/**
 * @details	Este construtor recebe um valor e dá esse valor		
 *			ao atributo da classe "AnimalSilvestre"
 * @param 	i   Identificador do animal silvestre no ibama
 */
AnimalSilvestre::AnimalSilvestre(string i) :
	ibama(i) {
}

/**
 * @details	Destrutor vazio da classe "AnimalSilvestre"
 */
AnimalSilvestre::~AnimalSilvestre() {

}

/** @return Identificador do animal silvestre no ibama */
string AnimalSilvestre::getIbama() {
	return ibama;
}

/** @param i Identificador do animal silvestre no ibama */
void AnimalSilvestre::setIbama(string i) {
	ibama = i;
}

/**
 * @details	Este construtor define os valores iniciais
 *			dos atributos da classe "Nativo"
 */
Nativo::Nativo() {
	uf_origem = "";
	autorizacao = "";
}

/**
 * @details	Este construtor recebe valores e e dá esse valores		
 *			aos atributos da classe "Nativo"
 * @param 	uf   Unidade de Federação do animal nativo
 * @param 	a    Autorização do animal nativo
 */		
Nativo::Nativo(string uf, string a) :
	uf_origem(uf), autorizacao(a) {

}

/**
 * @details	Destrutor vazio da classe "Nativo"
 */
Nativo::~Nativo() {

}

/** @return Unidade de Federação do animal nativo */
string Nativo::getUforigem() {
	return uf_origem;
}

/** @param uf Unidade de Federação do animal nativo */
void Nativo::setUforigem(string uf) {
	uf_origem = uf;
}

/** @return Autorização do animal nativo */
string Nativo::getAutorizacao() {
	return autorizacao;
}

/** @param a Autorização do animal nativo */
void Nativo::setAutorizacao(string a) {
	autorizacao = a;
}

/**
 * @details	Este construtor define os valores iniciais
 *			dos atributos da classe "Exotico"
 */
Exotico::Exotico() {
	pais_origem = "";
}

/**
 * @details	Este construtor recebe um valor e e dá esse valor		
 *			ao atributo da classe "Exotico"
 * @param 	po   País de origem do animal exótico
 */	
Exotico::Exotico(string po) :
	pais_origem(po) {
}

/**
 * @details	Destrutor vazio da classe "Exotico
 */
Exotico::~Exotico() {

}

/** @return País de origem do animal exótico */
string Exotico::getPaisOrigem() {
	return pais_origem;
}

/** @param po País de origem do animal exótico */	
void Exotico::setPaisOrigem(string po) {
	pais_origem = po;
}

/**
 * @details	Construtor vazio da classe "Papagaio"
 */
Papagaio::Papagaio() {

}

/**
 * @details	Destrutor vazio da classe "Papagaio"
 */
Papagaio::~Papagaio() {

}

/**
 * @details	Sobrecarga do operador de inserção (>>)
 *			para a classe "Papagaio"
 * @param 	is Input stream
 */
istream& Papagaio::input(istream& is) {
			
	string line;
	int idv, idt;

	getline(is, line);
	istringstream iss(line);

	iss>> id;
	iss.ignore();
	getline(iss, classe, ';');
	getline(iss, nome, ';');
	getline(iss, cientifico, ';');
	iss>> sexo;
	iss.ignore();
	iss>> tamanho;
	iss.ignore();
	getline(iss, dieta, ';');
	iss >> idv; 
	veterinario->setId(idv);
	iss.ignore();
	iss >> idt; 
	tratador->setId(idt);
	iss.ignore();
	getline(iss, batismo, ';');
	iss >> tamanho_bico;
	iss.ignore();
	iss >> envergadura;
	iss.ignore();
	getline(iss, ibama, ';');
	getline(iss, uf_origem, ';');
	getline(iss, autorizacao, ';');
	
	return is;
}	

/**
 * @details	Sobrecarga do operador de impressão (<<)
 *			para a classe "Papagaio"
 * @param 	os Output stream
 */
ostream& Papagaio::output(ostream& o) const {
	
	o << "ID do animal: " << id << endl;
	o << "Classe do animal: " << classe << endl;
	o << "Nome do animal: " << nome << endl;
	o << "Nome cientifico do animal: " << cientifico << endl; 
	o << "Sexo do animal: " << sexo << endl;
	o << "Tamanho médio em metros:  " << tamanho << endl;
	o << "Dieta do animal: " << dieta << endl;
	o << "Veterinário associado: " << veterinario->getNome() << endl;
	o << "Tratador responsável: " << tratador->getNome() << endl;
	o << "Nome de batismo do animal: " << batismo << endl;
	o << "Tamanho do bico do animal: " << tamanho_bico << endl;
	o << "Envergadura do animal: " << envergadura << endl;
	o << "Situação do animal no IBAMA: " << ibama << endl;
	o << "Estado de origem do animal: " << uf_origem << endl;
	o << "Status de autorização do animal: " << autorizacao << endl;

	return o;
}

/**
 * @details	Construtor vazio da classe "Tucano"
 */
Tucano::Tucano() {

}

/**
 * @details	Destrutor vazio da classe "Tucano"
 */
Tucano::~Tucano() {

}

/**
 * @details	Sobrecarga do operador de inserção (>>)
 *			para a classe "Tucano"
 * @param 	is Input stream
 */
istream& Tucano::input(istream& is) {
			
	string line;
	int idv, idt;

	getline(is, line);
	istringstream iss(line);

	iss>> id;
	iss.ignore();
	getline(iss, classe, ';');
	getline(iss, nome, ';');
	getline(iss, cientifico, ';');
	iss>> sexo;
	iss.ignore();
	iss>> tamanho;
	iss.ignore();
	getline(iss, dieta, ';');
	iss >> idv; 
	veterinario->setId(idv);
	iss.ignore();
	iss >> idt; 
	tratador->setId(idt);
	iss.ignore();
	getline(iss, batismo, ';');
	iss >> tamanho_bico;
	iss.ignore();
	iss >> envergadura;
	iss.ignore();
	getline(iss, ibama, ';');
	getline(iss, pais_origem, ';');
	
	return is;
}	

/**
 * @details	Sobrecarga do operador de impressão (<<)
 *			para a classe "Tucano"
 * @param 	os Output stream
 */
ostream& Tucano::output(ostream& o) const {
	
	o << "ID do animal: " << id << endl;
	o << "Classe do animal: " << classe << endl;
	o << "Nome do animal: " << nome << endl;
	o << "Nome cientifico do animal: " << cientifico << endl; 
	o << "Sexo do animal: " << sexo << endl;
	o << "Tamanho médio em metros:  " << tamanho << endl;
	o << "Dieta do animal: " << dieta << endl;
	o << "Veterinário associado: " << veterinario->getNome() << endl;
	o << "Tratador responsável: " << tratador->getNome() << endl;
	o << "Nome de batismo do animal: " << batismo << endl;
	o << "Tamanho do bico do animal: " << tamanho_bico << endl;
	o << "Envergadura do animal: " << envergadura << endl;
	o << "Situação do animal no IBAMA: " << ibama << endl;
	o << "País de origem do animal: " << pais_origem << endl;

	return o;
}