/*
Autor: Giovanny Alexis Reyes Vilchis
Matricula: 2163031812
*/

#include <iostream>
#include <string.h>

using namespace std;

string concatenarLenguajes(string L1, string L2);	// Función para la concatenación de lenguajes
string cerraduraDeKleene(string L, int n);	// Función que realiza la operación unaria L*, llamada Cerradura de Kleene

int main() {
    int menu=0, submenu=0, opcion=0, n=0;	// n -> potencias para la Cerradura de Kleene
	string alfabeto="", L_abecedario="", L_numeros="", L_a="", L_n="", L1="", L2="", L_x="";

	//Primero inicializo el alfabeto Σ

	// Abecedario en mayusculas de la A-Z
	// for (int i = 65; i <= 67; i++)	//90 para llega a la Z
	// {
	// 	alfabeto += i;
	// 	alfabeto += ",";
	// }
	// Lo dejo comentado ya que no es necesario para esta tarea

	// Abecedario en minusculas de la a-z
	for (int i = 97; i <= 122; i++)	// Para una mejor vizualización se pueden reducir las letras, por ejemplo hasta 99 que en ASCII sería la c
	{
		alfabeto += i;
		alfabeto += ",";
	}

	// Números del 1-9
	for (int i = 48; i <= 57; i++)	// Para una mejor vizualización se pueden reducir los números, por ejemplo hasta 50 para llegar al 2
	{
		if (i == 57)	// Si se realiza el cambio anterior, de igual manera aqui se tiene que reducir para una mejor impresión de datos
		{
			alfabeto += i;
		}
		else
		{
			alfabeto += i;
			alfabeto += ",";
		}
	}

    do
    {
		cout<<endl<<"Expresion Regular y el Lenguaje de los Identificadores de un Lenguaje X:"<<endl;	// Bienvenida
		cout<<"Este programa genera el Lenguaje (el conjunto de cadenas) de los identificadores de un cierto Lenguaje de Programacion."<<endl;
		cout<<"Al cual se le llamara como Lenguaje X."<<endl;
		cout<<"Usando para este programa dos alfabetos, los Lenguajes elementales y las operaciones de las Expresiones Regulares."<<endl;
		cout<<"Nota: Uso el simbolo '#' para representar a la Cadena Vacia."<<endl<<endl;
		cout<<"Escribe 1 para continuar con el programa."<<endl;
		cout<<"Escribe 2 para salir del programa."<<endl;
        cout<<"--->"; cin>>menu;
		system("cls");
        switch (menu)
        {
            case 1:
				cout<<"Alfabeto: = { "<<alfabeto<<" }"<<endl<<endl;	// Imprimo el alfabeto

				system("pause");

				cout<<endl;
				cout<<"Lenguajes elementales:"<<endl<<endl;	// Imprimo los lenguajes elementales o simples
				for (int i = 0; i < alfabeto.length(); i=i+2)
				{
					cout<<"L["<<i<<"] = "<<"{"<<alfabeto[i]<<"}"<<endl;
				}

				cout<<endl;
				system("pause");
				
				cout<<endl;
				cout<<"Seleccion entre alternativas:"<<endl<<endl;	// Imprimo la selección entre alternativas
				cout<<"L_abecedario = ";	// Y al mismo tiempo las voy uniendo al lenguaje que pertenecen
				for (int i = 0; i < alfabeto.length(); i=i+2)
				{
					if (alfabeto[i] >= 65 && alfabeto[i] <= 90 || alfabeto[i] >= 97 && alfabeto[i] <= 122)
					{
						if (alfabeto[i] == 122)	// Si se realiza el cambio de reducir el alfabeto igual reducirlo aqui, ejemplo == 99 para la letra c
						{
							L_abecedario += alfabeto[i];
							cout<<"L("<<alfabeto[i]<<")";	// L(a) | L(b)...
						}
						else
						{
							L_abecedario += alfabeto[i];
							L_abecedario += ",";
							cout<<"L("<<alfabeto[i]<<") | ";
						}
						// En esta parte se hace un if-else para diferenciar si es la ultima cadena a instrodur o no
					}
				}

				cout<<endl<<endl;
				cout<<"L_numeros = ";	// Para los numeros pasa lo mismo que con el abecedario
				for (int i = 0; i < alfabeto.length(); i=i+2)
				{
					if (alfabeto[i] >= 48 && alfabeto[i] <= 57)	// Si se realiza el cambio de reducir losnumeors igual reducirlo aqui, por ejemplo hasta 50 para llegar al 2
					{
						if (alfabeto[i] == 57)	// Y aqui de igual manera
						{
							L_numeros += alfabeto[i];
							cout<<"L("<<alfabeto[i]<<")";
						}
						else
						{
							L_numeros += alfabeto[i];
							L_numeros += ",";
							cout<<"L("<<alfabeto[i]<<") | ";
						}
						
					}
				}

				cout<<endl<<endl;
				system("pause");
				
				// Imprimo los lenguajes con los que se trabajara
				cout<<endl;
				cout<<"L_abecedario = { "<<L_abecedario<<" }"<<endl<<endl;
				cout<<"L_numeros = { "<<L_numeros<<" }"<<endl<<endl;

				system("pause");

				// Pregunto hasta que potencia se hará la Cerradura de Kleene
				cout<<endl<<"Escribe hasta que potencia se hara la operacion de la Cerradura de Kleene."<<endl;
				cout<<"Se recomienda no pasar de una potencia 3 (a menos que se tenga una pc poderosa XD)."<<endl;
				cout<<"--->"; cin>>n;

				// Imprimo el resultado de aplicar la operacion de la Cerradura de Kleene a L_abecedario
				cout<<endl;
				cout<<"Operacion de la Cerradura de Kleene a L_abecedario:"<<endl<<endl;
				L_a = cerraduraDeKleene(L_abecedario, n);
				cout<<"L_abecedario* = { "<<L_a<<" }";

				cout<<endl<<endl;
				system("pause");

				// Imprimo el resultado de aplicar la operacion de la Cerradura de Kleene a L_numeros
				cout<<endl;
				cout<<"Operacion de la Cerradura de Kleene a L_numeros"<<endl<<endl;
				L_n = cerraduraDeKleene(L_numeros, n);
				cout<<"L_numeros* = { "<<L_n<<" }";

				cout<<endl<<endl;
				system("pause");

				// fflush(stdin);
				// Imprimo el resultado de concatenar L_abecedario con L_abecedario*
				cout<<endl;
				cout<<"Concatenacion de: L_abecedario L_abecedario*"<<endl<<endl;
				L1 = concatenarLenguajes(L_abecedario, L_a);
				cout<<"L1 = L_abecedario L_abecedario* = { "<<L1<<" }";

				// cout<<endl<<endl;
				// system("pause");

				// Dejo comentado la operación siguiente de concatención, ya que, como se menciono en la ultima clase
				// Se necestan las letras solas en el resultado final por lo que no hay que hacer la operación de concatenacion
				// Entre L_numeros con L_numeros*
				// cout<<endl;
				// cout<<"Concatenacion de: L_numeros L_numeros*"<<endl<<endl;
				// L2 = concatenarLenguajes(L_numeros, L_n);
				// cout<<"L2 = L_numeros L_numeros* = { "<<L2<<" }";

				cout<<endl<<endl;
				system("pause");
				cout<<endl;

				// De igual manera dejo comentado el resultadoque se habia planteado en un principio
				// cout<<"Resutado:"<<endl<<endl;
				// L_x = concatenarLenguajes(L1, L2);
				// cout<<"Lenguaje X = L1 L2 = L1 L_digitos* = { "<<L_x<<" }";
				
				// Para finalizar imprimo el resultado comentado en clase
				cout<<"Resutado:"<<endl<<endl;
				L_x = concatenarLenguajes(L1, L_n);	//En L1 esta guardado el resultado de la concatenacion de L_abecedario L_abecedario*
				// Y en L_n esta el resultado de la operación de la Cerradura de Kleene de L_numeros*
				cout<<"Lenguaje X = L1 L_numeros* = { "<<L_x<<" }";
                do{
					cout<<endl<<endl;
					cout<<"Sub-Menu..."<<endl;
					cout<<"Escribe 1 para volver a ejecutar el programa."<<endl;
					cout<<"Escribe 2 para salir del programa."<<endl;
					cout<<"--->"; cin>>submenu;
					system("cls");
					switch(submenu){
						case 1:
                            // Se regresa al menu principal
							break;
						case 2:
							menu = 2;
							cout<<"Hasta pronto!!!"<<endl;	// Sale del programa
							break;
						default:
							cout<<endl<<"Opcion No valida, elije una opcion del sub-menu..."<<endl;
							break;
					}
				}while(submenu != 1 && submenu != 2);
                break;
            case 2:
                cout<<"Hasta pronto!!! "<<endl; // Sale del programa
                break;
            default:
            	cout<<endl<<"Esta opcion no corresponde al menu..."<<endl;
                break;
        }
    } while (menu != 2);
    
    return 0;
}

// La Cerradua de Klenne tiene dos operaciones
// Potencia y Union
string cerraduraDeKleene(string L, int n) {
	string Lr="", aux="";
	int i=1;

	if (n == 0)		// L^0
	{
		Lr = "#";		// Contiene la cadena vacía ε
		return Lr;
	}
	else if(n >= 1)
	{
		if (n == 1)		// L^1
		{
			Lr = "#,"+L;
		}
		else	// L*
		{
			Lr = L+",";
			aux = L;
			while (i < n)	// Esta parte se encarga de realizar las Potencias
			{
				aux = concatenarLenguajes(aux, L);	// Se utiliza la función de concatenación ya utilizada en la tarea 1
				Lr += aux;	// Esta parte se encarga de realizar la Union de cada potencia realizada hasta el momento
				i++;
			}
			Lr = "#,"+Lr;
		}
		return Lr;
	}
	else	// Imprimra Error en caso de no ingresar una potencia válida
	{
		return "Error";
	}
}

// Esta función como ya se mencionó en el encabezado, concatena dos lenguajes
// Aquí resalto la importancia de separar cada cadena con una coma, ya que, de lo contrario
// la función no podrá concatenar los lenguajes que se le introduzcan
string concatenarLenguajes(string L1, string L2) {
	string Lr = "", aux1, aux2;
	int n1 = 0, n2;
	// Su función es simple, se toma la cadena 1 del lenguaje L1 y
	// se concatena con cada cadena del lenguaje L2, después se repite el proceso
	// para cada cadena del lenguaje L1
	while (n1 < L1.length())
	{
		aux1 = "";
		if (L1[n1] != ',') {
			while (L1[n1] != ',' && n1 < L1.length()) {
				aux1 += L1[n1];
				n1++;
			}
			n2 = 0;
			while (n2 < L2.length())
			{
				aux2 = "";
				if (L2[n2] != ',') {
					if (L2[n2] == '#')		// La unica diferencia que tiene esta función con la realizada en la tarea 1 es que,
					{						// esta función pregunta si en la segunda cadena se encuentra la cadena vacía
						Lr += aux1+',';		// de ser así esta parte se encarga de eliminar por así decirlo, a la cadena vacia
						n2++;				// para solo concatenar las cadenas de los lenguajes que son validas
					}
					else
					{
						while (L2[n2] != ',' && n2 < L2.length()) {
							aux2 += L2[n2];
							n2++;
						}
						Lr += aux1+aux2+',';
					}
				}
				else {
					n2++;
				}
			}
		}
		else {
			n1++;
		}
	}
	return Lr;
}
