#include <stdio.h>
#define SIZE 3
#define CHAR_INIZIALE '|'
#define CERCHIO 'o'
#define CROCE 'x'

void inizializzazione(char schema[][SIZE]);

void stampaSchema(char schema[][SIZE]);

int tris(char schema[][SIZE], char c);

int main() {
 char schema[SIZE][SIZE];
 inizializzazione(schema);
 int occupati = 0;
 char giocatore;
 int riga, colonna;
 int trisCerchio = 0, trisCroce = 0;

while (occupati != SIZE*SIZE && !trisCroce && !trisCerchio) {
 stampaSchema(schema);
 if(occupati%2 == 0) {
 giocatore = CROCE;
} else {
 giocatore = CERCHIO;
}

int cellaValida;

do {
  cellaValida = 1;
printf("Giocatore %d:\n\t> Inserisci la riga e la colonna della cella dove vuoi inserire %c: ", occupati%2 + 1, giocatore);
scanf("%d%d", &riga, &colonna);

if(riga < 1 || riga > 3 || colonna < 1 || colonna > 3) {
printf("——ERRORE—-\nCella inesistente.\n\n");
cellaValida = 0;
} else if(schema[riga - 1][colonna - 1] != CHAR_INIZIALE) {
printf("——ERRORE—-\nCella già occupata.\n\n");
cellaValida = 0;
}
} while (!cellaValida);

schema[riga - 1][colonna - 1] = giocatore;
occupati++;

trisCerchio = tris(schema, CERCHIO);
trisCroce = tris(schema, CROCE);

} // chiude il while di gioco

printf("\n");
if (trisCroce) {
 printf(">Il Giocatore 1 ha vinto!");
} else if(trisCerchio) {
 printf(">Il Giocatore 2 ha vinto!");
} else {
 printf("Pareggio!");
}
printf("\n");

} // chiude il main

void inizializzazione(char schema[][SIZE]) {

for(int i = 0; i < SIZE; i++) {
 for(int j = 0; j < SIZE; j++) {
  schema[i][j] = CHAR_INIZIALE;
}
}
}

void stampaSchema(char schema[][SIZE]) {
printf("\n\n");

for(int i = 0; i < SIZE; i++) {
printf("\t");
 for(int j = 0; j < SIZE; j++) {
printf("%c ", schema[i][j]);
}
printf("\n");
}

printf("\n\n");
}

int tris(char schema[][SIZE], char c) {
if ((schema[0][0] == c && schema[1][1] == c && schema[2][2] == c) || (schema[0][2] == c && schema[1][1] == c && schema[2][0] == c)) {
 return 1; // tris diagonale
}

for(int i = 0; i < SIZE; i++) {
 for(int j = 0; j < SIZE; j++) {
 if(schema[i][0] == c && schema[i][1] == c && schema[i][2] == c) {
 return 1;
} 

if(schema[0][j] == c && schema[1][j] == c && schema[2][j] == c) {
 return 1;
}
}
}

return 0;
}