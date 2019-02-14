/*
Spiel Tsching, Tschang, Tschong
Regeln:
Es gibt zwei Spieler: der Programmierer und der Computer.
Beide Spieler waehlen gleichzeitig eines der drei Objekte
Stein, Schere und Papier. Beide k�nnen das gleiche Objekt w�hlen.
Der Spieler, der das m�chtigere Objekt gew�hlt hat gewinnt.
SCHERE kann einen STEIN nicht zerschneiden, d.h. STEIN ist 
m�chtiger als SCHERE. PAPIER wickelt STEIN ein, d.h. PAPIER ist 
m�chtiger als STEIN. SCHERE zerschneidet PAPIER, d. h. SCHERE 
ist maechtiger als PAPIER
*/
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

// Aufz�hlungstyp f�r Stein etc.
enum objectType { STEIN, SCHERE, PAPIER };

// Struktur f�r einen Spieler bestehend aus Name und Wahl 
// des Spielers
struct player {
	char * name;
	objectType choice;
};

// Variable f�r den Namen des Spielers 
char name[15];

// Name des Spielers eingeben
char * enterName(char str[])
{
	cout << "Name des Spielers: ";
	cin >> str;
	return str;
}

// Den Computer zuf�llig waehlen lassen. 
// Nutzen Sie srand(...) und rand().
objectType randomChoice()
{
	int wahl;
	objectType random_choice;

	srand(time(0));
	wahl = rand() % 3 + 1;
	
	if (wahl == 1){
		random_choice = SCHERE;		
	} else if (wahl == 2){
		random_choice = STEIN;
	} else if (wahl == 3){
		random_choice = PAPIER;	
	} 
	return random_choice;
}

// Die Wahl von STEIN etc. als String zur�ckgeben lassen
char * object2str(objectType o)
{	
	char * str;
	if (o == SCHERE){
		str = "SCHERE";		
	} else if (o == STEIN){
		str = "STEIN";
	} else if (o == PAPIER){
		str = "PAPIER";	
	} else {		
		exit;
	}
	return str;
}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void showPlayer(player p)
{
	cout << p.name << " hat das Objekt " << object2str(p.choice) << " gewaehlt." << endl << endl;	
}

// Die Wahl des Spielers abfragen
objectType enterChoice()
{
	objectType player_choice;
	int wahl = 0;
	cout << "Bitte Objektwahl eingeben (1 - Stein, 2 - Schere, 3 - Papier): " << endl;
	cin >> wahl;	
	cout << endl;
	
	if (wahl == 1){
		player_choice = STEIN;		
	} else if (wahl == 2){
		player_choice = SCHERE;
	} else if (wahl == 3){
		player_choice = PAPIER;	
	} else {
		player_choice = randomChoice();
	}
	return player_choice;
}

// Die Wahl bestimmen, die gewonnen hat
objectType winningObject(objectType obj1, objectType obj2)
{
	objectType winner_obj;
	if ((obj1 == SCHERE && obj2 == PAPIER) || (obj1 == STEIN && obj2 == SCHERE) || (obj1 == PAPIER && obj2 == STEIN)){
		winner_obj = obj1;	
	} 	
	if ((obj2 == SCHERE && obj1 == PAPIER) || (obj2 == STEIN && obj1 == SCHERE) || (obj2 == PAPIER && obj1 == STEIN)){
		winner_obj = obj2;	
	} 	
	return winner_obj;
}

// Ausgeben, wer gewonnen hat
void showWinner(player p1, player p2)
{
	player winner;
	//winner = winningObject(p1.choice, p2.choice);
	
	if ((p1.choice == SCHERE && p2.choice == PAPIER) || (p1.choice == STEIN && p2.choice == SCHERE) || (p1.choice == PAPIER && p2.choice == STEIN)){
		winner = p1;	
	} 	
	if ((p2.choice == SCHERE && p1.choice == PAPIER) || (p2.choice == STEIN && p1.choice == SCHERE) || (p2.choice == PAPIER && p1.choice == STEIN)){
		winner = p2;	
	} 	
	if ((p2.choice == SCHERE && p1.choice == SCHERE) || (p2.choice == STEIN && p1.choice == STEIN) || (p2.choice == PAPIER && p1.choice == PAPIER)){
		winner.name = "Keiner!!!";	
	}
	cout << "Gewinner ist: " << winner.name << endl;
}

int main()
{
	player player1, player2;
	player1.name = "Computer";
	player1.choice = randomChoice();
	cout << "Der Computer hat sein Wahl getroffen." << endl;
	player2.name = enterName(name);
	player2.choice = enterChoice();
	showPlayer(player1);
	showPlayer(player2);
	showWinner(player1, player2);
}
