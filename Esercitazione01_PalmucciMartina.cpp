// Esercitazione01_PalmucciMartina.cpp

// Nome e Cognome: Martina Palmucci
// Numero di matricola: 097506
// Classe: L-35 Matematica e Applicazioni

// ESERCITAZIONE N°1
// CALCOLATRICE DEI NUMERI COMPLESSI

// Questo programma realizza delle operazioni su due numeri complessi
// presi in input dall'utente. Le operazioni da eseguire sono selezionabili
// tramite un menu principale di scelta delle possibilità.
// Si posso eseguire: somma, moltiplicazione, divisione,
// conversione in coordinate polari, coniugato,
// sostituzione dell'ultimo risultato con uno dei due numeri,
// visualizzazione dell'ultimo risultato.

#include "pch.h"
#include <iostream>
#include <math.h>

// INIZIALIZZAZIONI / DICHIARAZIONI GLOBALI
// - variabili
const float PI = 3.14159265;	// pi greco
const int n1 = 0;				// indice di array primo numero complesso
const int n2 = 1;				// indice di array secondo numero complesso
const int n = 2;				// indice di array risultato complesso

// - strutture
struct complex_number			// strutture di un numero complesso
{
	float real_part;			// parte reale
	float imaginary_part;		// parte immaginaria
	bool status;				// stato ('vero' se è stato inserito o calcolato, 
									// altrimenti 'falso')
};

struct polar_form				// struttura di un numero complesso in forma polare
{
	float magnitude;			// modulo
	float argument;				// fase o argomento
};

struct menu						// di supporto allo sviluppo di menu secondari
{
	int c;						// contatore
	int options[n + 1];			// vettore delle opzioni
									// qui salvo le opzioni presenti nel menu
};

// - funzioni
complex_number create_complex_number();						// crea un numero complesso
void print_complex_number(complex_number);					// stampa in output di un numero complesso
void print_expression(char, complex_number[]);				// stampa in output di una espressione
complex_number get_sum(complex_number, complex_number);		// somma due numeri complessi
complex_number get_product(complex_number, complex_number);	// moltiplica due numeri complessi
complex_number get_division(complex_number, complex_number);// divide due numeri complessi
menu print_menu(int, complex_number[]);					    // stampa e controlla il funzionamento di menu secondari
polar_form complex_magnitude_and_argument(complex_number);  // converte un numero complesso in modulo e fase
complex_number get_conjugate(complex_number);				// calcola il coniugato complesso

// CORPO DEL CODICE
int main()
{
	// INIZIALIZZAZIONI / DICHIARAZIONI LOCALI
	complex_number number_one = { 0,0, false };		// primo numero complesso
	complex_number number_two = { 0,0, false };		// secondo numero complesso
	complex_number result = { 0,0, false };			// salvo qui l'ultimo risultato complesso

	complex_number complex[3] = { number_one, number_two, result };		// array dei numeri complessi

	polar_form polar_form;				// salvo qui l'ultima conversione in forma polare

	char choice;		// variabile di scelta del menu principale

	// menu principale
	// imposto il menu principale attraverso la combinazione delle funzioni
	// do-while e switch-cases
	//
	// do-while mi permette di visualizzare il menu la prima volta
	// e poi dopo ogni conclusione di operazione fino alla condizione di uscita,
	// switch-case mi permette di sviluppare ogni operazione o funzione
	// espressa tra le opzioni del menu principale
	do
	{
		std::cout << ">> MENU' <<" << std::endl					// testo di menu principale
			<< "Opzioni" << std::endl
			<< "1 - Inserisci il primo numero" << std::endl
			<< "2 - Inserisci il secondo numero" << std::endl
			<< "3 - Somma" << std::endl
			<< "4 - Prodotto" << std::endl
			<< "5 - Divisione" << std::endl
			<< "6 - Modulo e fase" << std::endl
			<< "7 - Complesso coniugato" << std::endl
			<< "8 - Sostituzione dell'ultimo risultato ad uno dei numeri" << std::endl
			<< "9 - Visualizza l'ultimo risultato" << std::endl
			<< "0 - Esci" << std::endl
			<< std::endl
			<< "Seleziona una delle opzioni precedenti: ";
		std::cin >> choice;		// chiedo in input all'utente l'opzione che vuole eseguire
		std::cout << std::endl;

		switch (choice)	// controllo la scelta dell'utente
						// e in ogni case sviluppo operazioni e funzioni da svolgere
		{
		case '1':		// creazione del primo numero
		{
			std::cout << "Primo numero\n" << std::endl
				<< "Inserisci il primo numero complesso:\n";
			complex[n1] = create_complex_number();
			print_complex_number(complex[n1]);
			std::cout << std::endl << std::endl;
		}
			break;
		case '2':		// creazione del secondo numero
		{
			std::cout << "Secondo numero\n" << std::endl
				<< "Inserisci il secondo numero complesso:\n";
			complex[n2] = create_complex_number();
			print_complex_number(complex[n2]);
			std::cout << std::endl << std::endl;
		}
			break;
		case '3':		// operazione somma
			// prima controllo che i due numeri siano stati inseriti
			// se non sono stati inseriti
			// stampa un messaggio di errore,
			// se sono stati inseriti correttamente
			// esegue la somma e stampa l'espressione corrispondente
		{
			if ((complex[n1].status == false) | (complex[n2].status == false))
				std::cout << "Errore: Non hai inserito tutti i valori necessari ad eseguire questa operazione.\n"
						<< std::endl;
			else
			{
				std::cout << "Somma:\n";
				complex[n] = get_sum(complex[n1], complex[n2]);		// calcola la somma
				print_expression(choice, complex);	// stampa l'espressione di somma
			}
		}
		break;
		case '4':		// operazione moltiplicazione
			// prima controllo che i due numeri siano stati inseriti
			// se non sono stati inseriti
			// stampa un messaggio di errore,
			// se sono stati inseriti correttamente
			// esegue la moltiplicazione e stampa l'espressione corrispondente
		{
			if ((complex[n1].status == false) | (complex[n2].status == false))
				std::cout << "Errore: Non hai inserito tutti i valori necessari ad eseguire questa operazione.\n"
							<< std::endl;
			else
			{
				std::cout << "Prodotto:\n";
				complex[n] = get_product(complex[n1], complex[n2]); // calcola il prodotto
				print_expression(choice, complex); // stampa l'espressione di moltiplicazione
			}
		}
		break;
		case '5':		// operazione divisione
			// prima controllo che i due numeri siano stati inseriti
			// se non sono stati inseriti
			// stampa un messaggio di errore,
			// se sono stati inseriti correttamente...
		{
			if ((complex[n1].status == false) | (complex[n2].status == false))
				std::cout << "Errore: Non hai inserito tutti i valori necessari ad eseguire questa operazione.\n"
							<< std::endl;			
			else
				// ...allora controlla il denominatore
				// se il denominatore è uguale a zero
				// stampa un messaggio di soluzione impossibile,
				// altrimenti esegue la divisione e stampa l'espressione corrispondente
			{
				std::cout << "Divisione:\n";
				if ((complex[n2].real_part == 0) & (complex[n2].imaginary_part == 0))
					std::cout << "Stai cercando di dividere per zero. Soluzione impossibile 0/0.\n" 
								<< std::endl;
				else
				{
					complex[n] = get_division(complex[n1], complex[n2]); // calcola la divisione 
					print_expression(choice, complex);	// stampa l'espressione di divisione
				}
			}
		}
		break;
		case '6':		// conversione in modulo e fase di un numero complesso
			// prima controlla che ci sia almeno un numero complesso da poter convertire
			// se non c'è
			// stampa un messaggio di errore
			// se c'è
			// allora si apre un menu secondario
			// in cui poter selezionare il numero da convertire
			// tra quelli già inseriti o già calcolati precedentemente
		{
			std::cout << "Modulo e fase:\n";
			int choice_case;	// variabile di scelta del menu secondario
			int c;	// contatore
					// salverà il numero massimo di opzioni
					// che si visualizzeranno nel menu secondario

			if ((complex[n1].status == false) & (complex[n2].status == false) & (complex[n].status == false))
				std::cout << "Non hai inserito alcun numero.\n" << std::endl;
			else
			{
				do	// attraverso il do-while
					// il menu secondario viene visualizzato la prima volta
					// e tutte le volte successive
					// ad una scelta incoerente 
					// da parte dell'utente 
					// rispetto alle opzioni disponibili
				{
					menu menu;							// attraverso la variabile menu
					menu = print_menu(n, complex);		// e attraverso la funzione di stampa del menu
														// stampiamo le opzioni disponibili
														// e  le salviamo in un vettore (option di menu),
														// salviamo anche il numero massimo
														// di opzioni visualizzate (c di menu)
					c = menu.c; // salvo il numero massimo di opzioni visualizzate
								// in una variabile esterna alla funzione do
								// per poterlo sfruttare
								// come condizione di uscita dal menu secondario
					std::cout << std::endl << "Seleziona una delle opzioni precedenti: ";
					std::cin >> choice_case; // chiedo in input all'utente l'opzione che vuole eseguire

					// se la scelta non e' coerente
					// stampa un messaggio di errore,
					// altrimenti... 
					if ((choice_case < 1) | (choice_case > c))
						std::cout << "Errore. Prova di nuovo.\n" << std::endl;
					else
					{
						std::cout << "Conversione del numero complesso\n";
						int index = menu.options[choice_case - 1];	// converte 
																	// il valore selezionato dall'utente 
																	// con il giusto indice 
																	// per l'array dei numeri complessi

						// ...prima controlla se possono risultare forma indeterminate come x/0
						// se sì, stampa un messaggio di errore
						// se no, esegue la conversione
						if ((complex[index].real_part == 0) & (complex[index].imaginary_part != 0))
							std::cout << "x/0 forma indeterminata\n" << std::endl;
						else
						{
							polar_form = complex_magnitude_and_argument(complex[index]);  // esegue la conversione

							print_complex_number(complex[index]);		// stampa il risultato della conversione
							std::cout << std::endl
								<< "modulo = " << polar_form.magnitude << std::endl
								<< "fase (in degrees) = " << polar_form.argument << std::endl
								<< std::endl;
						}
					}
				} while ((choice_case < 1) | (choice_case > c));	// condizione di uscita dal menu secondario
				c = 0; // riporto il contatore a zero
			}
		}
		break;
		case '7':		// coniugato di un numero complesso
			// prima controlla che ci sia almeno un numero complesso da coniugare
			// se non c'è
			// stampa un messaggio di errore
			// se c'è
			// allora si apre un menu secondario
			// in cui poter selezionare il numero da coniugare
			// tra quelli già inseriti o già calcolati precedentemente
		{
			std::cout << "Coniugato:\n";
			int choice_case;	// variabile di scelta del menu secondario
			int c;	// contatore
					// salverà il numero massimo di opzioni
					// che si visualizzeranno nel menu secondario

			if ((complex[n1].status == false) & (complex[n2].status == false) & (complex[n].status == false))
				std::cout << "Non hai inserito alcun numero.\n" << std::endl;
			else
			{
				do
				{
					menu menu;							// attraverso la variabile menu
					menu = print_menu(n, complex);		// e attraverso la funzione di stampa del menu
														// stampiamo le opzioni disponibili
														// e  le salviamo in un vettore (option di menu),
														// salviamo anche il numero massimo
														// di opzioni visualizzate (c di menu)
					c = menu.c; // salvo il numero massimo di opzioni visualizzate
								// in una variabile esterna alla funzione do
								// per poterlo sfruttare
								// come condizione di uscita dal menu secondario
					std::cout << std::endl << "Seleziona una delle opzioni precedenti: ";
					std::cin >> choice_case;	// chiedo in input all'utente l'opzione che vuole eseguire

					// se la scelta non e' coerente
					// stampa un messaggio di errore,
					// altrimenti
					// calcola il coniugato del numero complesso
					// selezionato dall'utente
					if ((choice_case < 1) | (choice_case > c))
						std::cout << "Errore. Prova di nuovo.\n" << std::endl;
					else
					{
						int index = menu.options[choice_case - 1];	// converte 
																	// il valore selezionato dall'utente 
																	// con il giusto indice 
																	// per l'array dei numeri complessi
						
						complex[n] = get_conjugate(complex[index]); // calcola il coniugato

						std::cout << "Il coniugato di (";			// stampa il risultato
						print_complex_number(complex[index]);
						std::cout << ") e' (";
						print_complex_number(complex[n]);
						std::cout << ")\n" << std::endl;
					}
				} while ((choice_case < 1) | (choice_case > c));	// condizione di uscita dal menu secondario
				c = 0; // riporto il contatore a zero
			}
		}
		break;
		case '8':		// sostituzione di uno dei due numero con l'ultimo risultato
			// prima controlla che ci sia almeno un risultato 
			// se non c'è
			// stampa un messaggio di errore
			// se c'è
			// allora sicuramente c'è anche almeno un numero a cui sostituirlo
			// quindi si apre un menu secondario
			// in cui poter selezionare il numero da sostituire
			// tra quelli già inseriti precedentemente
		{
			std::cout << "Sostituzione:\n";
			int choice_case;	// variabile di scelta del menu secondario
			int c;	// contatore
					// salverà il numero massimo di opzioni
					// che si visualizzeranno nel menu secondario

			if (complex[n].status == false)
				std::cout << "Nessun risultato disponibile per la sostituzione.\n" << std::endl;
			else
			{
				do
				{
					menu menu;							// attraverso la variabile menu
					menu = print_menu(n-1, complex);		// e attraverso la funzione di stampa del menu
														// stampiamo le opzioni disponibili
														// e  le salviamo in un vettore (option di menu),
														// salviamo anche il numero massimo
														// di opzioni visualizzate (c di menu)
					c = menu.c; // salvo il numero massimo di opzioni visualizzate
								// in una variabile esterna alla funzione do
								// per poterlo sfruttare
								// come condizione di uscita dal menu secondario
					std::cout << std::endl << "Al posto di quale numero vuoi sostituire ";
					print_complex_number(complex[n]);
					std::cout << " ?" << std::endl << "Seleziona una delle opzioni precedenti: ";
					std::cin >> choice_case;	// chiedo in input all'utente l'opzione che vuole eseguire

					// se la scelta non e' coerente
					// stampa un messaggio di errore,
					// altrimenti
					// sostituisce il numero complesso
					// selezionato dall'utente
					if ((choice_case < 1) | (choice_case > c))
						std::cout << "Errore. Prova di nuovo.\n" << std::endl;
					else
					{
						int index = menu.options[choice_case - 1];	// converte 
																	// il valore selezionato dall'utente 
																	// con il giusto indice 
																	// per l'array dei numeri complessi

						complex[index] = complex[n]; // applica la sostituzione
						std::cout << std::endl;
					}
				} while ((choice_case < 1) | (choice_case > c));	// condizione di uscita dal menu secondario
				c = 0;	// riporto il contatore a zero
			}
		}
		break;
		case '9':		// visualizzazione dell'ultimo risultato ottenuto
			// prima controlla che ci sia un risultato 
			// se non c'è
			// stampa un messaggio di errore
			// se c'è
			// stampa in output l'ultimo risultato
		{
			std::cout << "Last result:\n";
			if (complex[n].status == false)
				std::cout << "Any last result available.\n" << std::endl;
			else
			{
				print_complex_number(complex[n]);  // stampa l'ultimo risultato
				std::cout << std::endl << std::endl;
			}
		}
		break;
		case '0':		// uscita
			std::cout << "Esci\n" << std::endl;
			break;
		default:		// stampa messaggio di errore di scelta dell'opzione di menu principale
			std::cout << "Errore: Valore inserito non valido.\n" << std::endl;
			break;
		}

	} while (choice != '0'); // condizione di uscita dal menu principale

	return 0;
}

// FUNZIONI

complex_number create_complex_number()	// Crea un numero complesso.
										// Questa funzione
										// non prende nulla in input,
										// restituisce in output un numero complesso.							
{
	complex_number number;
	std::cout << "Numero complesso:\n"		// Richiede durante l'esecuzione della funzione
											// l'inserimento da parte dell'utente
		<< "Parte reale: ";					// della parte reale
	std::cin >> number.real_part;
	std::cout << "Parte immaginaria: ";		// e della parte immaginaria
	std::cin >> number.imaginary_part;
	std::cout << std::endl;					// del numero complesso da creare.
	number.status = true;					// Infine cambia in vero lo stato del numero creato.
	return number;
}

void print_complex_number(complex_number number)	// Stampa in output di un numero complesso.
													// Questa funzione
													// prende in input un numero complesso,
													// restituisce in output a video il numero complesso.
{
	std::cout << number.real_part;							// Stampa prima la parte reale, poi controlla
															// la parte immaginari del numero inserto		
	if (number.imaginary_part < 0)							// se è negativa
		std::cout << " - i" << abs(number.imaginary_part);	// stampa un -i seguito 
															// dal modulo della parte immaginaria
	else													// altrimenti
		std::cout << " + i" << number.imaginary_part;		// stampa un +i seguito 
															// dal modulo della parte immaginaria
}

void print_expression(char choice, complex_number number[]) // Stampa in output di una espressione.
															// Questa funzione
															// prende in input
															// la scelta di menu principale
															// (che contraddistingue l'operazione)
															// e l'array dei numeri complessi,
															// stampa in output l'espressione
															// che compone i due numeri
															// con il risultato.
{
	char op;
	switch (choice)
	{
	case '3':
		op = '+'; break;
	case '4':
		op = '*'; break;
	case '5':
		op = '/'; break;
	default:
		op = '0'; 	break;
	}

	std::cout << "(";
	print_complex_number(number[n1]);
	std::cout << ") " << op << " (";
	print_complex_number(number[n2]);
	std::cout << ") = (";
	print_complex_number(number[n]);
	std::cout << ")\n" << std::endl;
}

complex_number get_sum(complex_number numberOne, 
						complex_number numberTwo)	// Somma due numeri complessi.
													// Questa funzione
													// prende in input due numeri complessi
													// restituisce in output un numero complesso
													// che è la somma dei due precedenti.
{
	complex_number result;
	result.real_part = numberOne.real_part + numberTwo.real_part;
	result.imaginary_part = numberOne.imaginary_part + numberTwo.imaginary_part;
	result.status = true;							// Infine cambia lo stato del risultato.
	return result;
}

complex_number get_product(complex_number numberOne,
							complex_number numberTwo)	// Moltiplica due numeri complessi.
														// Questa funzione
														// prende in input due numeri complessi
														// restituisce in output un numero complesso
														// che è il prodotto dei due precedenti.
{
	complex_number result;
	result.real_part = (numberOne.real_part * numberTwo.real_part)
						- (numberOne.imaginary_part * numberTwo.imaginary_part);
	result.imaginary_part = (numberOne.imaginary_part * numberTwo.real_part)
							+ (numberOne.real_part * numberTwo.imaginary_part);
	result.status = true;								// Infine cambia lo stato del risultato.
	return result;
}

complex_number get_division(complex_number numberOne,
							complex_number numberTwo)	// Divide due numeri complessi.
														// Questa funzione
														// prende in input due numeri complessi
														// restituisce in output un numero complesso
														// che è il quoziente dei due precedenti.
{
	complex_number result;
	complex_number numerator;
	float denominator;
	
	denominator = pow(numberTwo.real_part, 2) + pow(numberTwo.imaginary_part, 2);
	numerator.real_part = (numberOne.real_part * numberTwo.real_part)
							+ (numberOne.imaginary_part * numberTwo.imaginary_part);
	numerator.imaginary_part = (numberTwo.real_part * numberOne.imaginary_part)
								- (numberOne.real_part * numberTwo.imaginary_part);
	result.real_part = numerator.real_part / denominator;
	result.imaginary_part = numerator.imaginary_part / denominator;
	result.status = true;								// Infine cambia lo stato del risultato.
	return result;
}

menu print_menu(int max_choices,				// Stampa e controlla il funzionamento di menu secondari.
					complex_number number[]) 
// Questa funzione
// prende in input un numero intero
// ( potenziale numero massimo 
// di scelte visualizzabili dal menu)
// e l'array dei numeri complessi,
// restituisce in output
// una struttura combinazione di
// un intero (effettivo numero massimo 
// di scelte visualizzate dal menu)
// e di un vettore (salva i numeri complessi
// disponibili)
{
	menu menu;
	menu.c = 0; // il contatore parte da zero
	for (int k = 0; k <= max_choices; k++) // il ciclo for
		// cicla tutti i valori dell'array dei numeri complessi
		// fino a quello di indice 'max_choices'
		// ogni volta che uno di questi valori ha stato vero
		// il contatore si incrementa di uno
		// stampa il contatore, stampa il valore.
		// Ottengo così a video tutte le scelte 
		// salezionabili dei numeri complessi 
	{
		if (number[k].status == true)
		{
			menu.options[menu.c] = k;
			menu.c++;
			std::cout << menu.c << ") ";
			print_complex_number(number[k]);
			std::cout << std::endl;
		}
	}
	return menu;
}

polar_form complex_magnitude_and_argument(complex_number number) 
// Converte un numero complesso in modulo e fase.
// Questa funzione
// prende in input un numero complesso
// restituisce in output la corrispondente
// conversione in coordinate polari.
{
	polar_form polar_form;
	polar_form.magnitude = sqrt((pow(number.real_part, 2) + pow(number.imaginary_part, 2)));
	
	if ((number.real_part == 0) & (number.imaginary_part == 0))
		polar_form.argument = 0;
	else
		polar_form.argument = (atan2(number.imaginary_part, number.real_part)) * 180 / PI;
	return polar_form;
}

complex_number get_conjugate(complex_number number) // Calcola il coniugato complesso.
// Questa funzione
// prende in input un numero complesso
// restituisce in output il corrispondente
// coniugato complesso.
{
	complex_number result;
	result.real_part = number.real_part;
	if (number.imaginary_part > 0)
		result.imaginary_part = -abs(number.imaginary_part);
	else
		result.imaginary_part = abs(number.imaginary_part);
	result.status = true;
	return result; // Infine cambia lo stato del risultato. 
}

// The End.