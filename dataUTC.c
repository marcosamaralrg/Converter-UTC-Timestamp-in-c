#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{

int segundo=0, minuto=0, hora=0, dia=0, mes=0;
long ano=0;
//printf("Valor: %d \n", hora);
void dataUTC(long timestampUnix){
	// Passo 1
	long minutosUnix = timestampUnix / 60;
	segundo = timestampUnix % 60;
	
	//Passo 2
	long horasUnix = minutosUnix / 60;
	minuto = minutosUnix % 60;
	
	//Passo 3
	long diasUnix = horasUnix / 24;
	hora = horasUnix % 24;
	
	//Passo 4
	long ciclosDe400Anos = diasUnix / 146097;
	int diasEm400Anos = diasUnix % 146097;
	
	//Passo 5
	if (diasEm400Anos >= 32 * 1461 + 789) diasEm400Anos++;
    if (diasEm400Anos >= 57 * 1461 + 789) diasEm400Anos++;
    if (diasEm400Anos >= 82 * 1461 + 789) diasEm400Anos++;
    
    // Passo 6.
	int ciclosDe4Anos = diasEm400Anos / 1461;
	int diasEm4Anos = diasEm400Anos % 1461;

	// Passo 7.
	if (diasEm4Anos >= 59) diasEm4Anos++;
	if (diasEm4Anos >= 425) diasEm4Anos++;
	if (diasEm4Anos >= 1157) diasEm4Anos++;

	// Passo 8.
	int anoEm4Anos = diasEm4Anos / 366;
	int diasNoAno = diasEm4Anos % 366;

	// Passo 9.
	ano = anoEm4Anos + ciclosDe4Anos * 4 + ciclosDe400Anos * 400 + 1970;

	// Passo 10.
	int tabelaDeMeses[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int contagemDeMeses = 0;
	while (diasNoAno >= tabelaDeMeses[contagemDeMeses]) {
		diasNoAno -= tabelaDeMeses[contagemDeMeses];
		contagemDeMeses++;
	}
	mes = contagemDeMeses + 1;
	dia = diasNoAno + 1;
}
dataUTC(1518307200); //Example use function
printf("Valor: %d \n", hora);
printf("%d / %d / %li - %d : %d : %d \n", dia, mes, ano, hora, minuto, segundo);

}
