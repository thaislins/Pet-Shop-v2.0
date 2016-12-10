/**
 * @file	main.cpp
 * @brief	Demonstração da implementação do pet shop PetFera
 * @author	Thais Fernandes Lins
 * @since	28/10/2016
 * @date	06/11/2016
 */

#include <cstdlib>
using std::exit;

#include "../include/op.h"
#include "../include/animal.h"

#define LIM_FUNC 4
#define LIM_ANIM 5

/** @brief Funcao principal */
int main() {

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


 	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "   SEJA BEM VINDO AO PET FERA" << endl;
	cout << "-------------------------------------" << endl;

 	while(1) {

 		try {
 			int escolha;

			cout << "\nOperações disponíveis: " << endl;
			cout << "	-1. Cadastro " << endl;
			cout <<	"	-2. Consulta de veterinário  " << endl;
			cout << "	-3. Consulta aos dados cadastrais de um determinado animal " << endl;
			cout << "	-4. Remoção de Animais " << endl;
			cout << "	-5. Remoção de Funcionários" << endl;
			cout << "	-6. Alteração de dados cadastrais de um animal" << endl;
			cout << "	-7. Consulta de animais sob responsabilidade de um determinado funcionário" << endl;
			cout << "	-Aperte Ctrl + c para sair do programa." << endl;
			cout << "	Obs: Deve se realizar o cadastro para que as outras operações possam " << endl;
			cout <<	"	ser realizadas corretamente. " << endl;
			cout << endl;

			cin >> escolha;

 			switch(escolha) {
 				case 1:
 					//Funcionários
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


					//Animais
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

 					cout << "Os dados foram Cadastrados" << endl;
 					break;
 				
 				case 2:
 					ConsultaFuncionario(f1);
 					break;
 				case 3:
 					ConsultaAnimal(a1);
 					break;
 				case 4:
 					 int id;

					cout << "Defina qual o id do animal que será removido: ";
					cin >> id;
 					RemoveAnimal(a1,id);
 					break;
 				case 5:
 					RemoveFuncionario(f1);
 					break;
 				case 6:
 					AlteraAnimal(a1);
 					break;
 				case 7:
 					ConsultaVetOuTrat(a1);
 				default:
 					throw InputError();
 					break;
 			}
 		}	catch (InputError &ex) {
 				cerr << ex.what() << endl;
	 }
 }
	return 0;
}