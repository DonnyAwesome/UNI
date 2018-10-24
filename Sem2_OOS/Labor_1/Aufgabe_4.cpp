/*

Spiel Tsching, Tschang, Tschong

Regeln:
Es gibt zwei Spieler: der Programmierer und der Computer.
Beide Spieler waehlen gleichzeitig eines der drei Objekte
Stein, Schere und Papier. Beide können das gleiche Objekt wählen.
Der Spieler, der das mächtigere Objekt gewählt hat gewinnt.
SCHERE kann einen STEIN nicht zerschneiden, d.h. STEIN ist 
mächtiger als SCHERE. PAPIER wickelt STEIN ein, d.h. PAPIER ist 
mächtiger als STEIN. SCHERE zerschneidet PAPIER, d. h. SCHERE 
ist maechtiger als PAPIER

*/

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

// Aufzählungstyp für Stein etc.
enum objectType { STEIN, SCHERE, PAPIER };

// Struktur für einen Spieler bestehend aus Name und Wahl 
// des Spielers
struct player {
	char * name;
	objectType choice;
};

// Variable für den Namen des Spielers 
char name[15];

// Name des Spielers eingeben
char * enterName(char str[])
{
	cout << "Name des Spielers: ";
	cin >> str;
	return str;
}

// Den Computer zufällig waehlen lassen. 
// Nutzen Sie srand(...) und rand().
objectType randomChoice()
{




}

// Die Wahl von STEIN etc. als String zurückgeben lassen
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
	cout << "Name: "<< p.name << endl;	
	cout << "Choice: " << object2str(p.choice) << endl;
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
		player_choice = SCHERE;		
	} else if (wahl == 2){
		player_choice = STEIN;
	} else if (wahl == 3){
		player_choice = PAPIER;	
	} 
	return player_choice;
}

// Die Wahl bestimmen, die gewonnen hat
objectType winningObject(objectType obj1, objectType obj2)
{






}

// Ausgeben, wer gewonnen hat
void showWinner(player p1, player p2)
{












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






