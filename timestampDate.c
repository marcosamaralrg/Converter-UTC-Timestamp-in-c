#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{


void  getTimestamp (int ano,int mes, int dia, int hora, int minuto, int segundo) {
		//int segundosPorAno = 31557600;
		//long segundosPorAno = 31536000;
		int segundosPorDia = 86400;

        // Passo 1.
        long anosDesde1970 = ano - 1970;

        // Passo 2.
        long periodosDe400Anos = anosDesde1970 / 400;
        int anoNoPeriodoDe400Anos = anosDesde1970 % 400;

        // Passo 3.
        int periodosDe4AnosNos400 = anoNoPeriodoDe400Anos / 4;
        int anoNoPeriodoDe4Anos = anoNoPeriodoDe400Anos % 4;

        // Passo 4.
        int diasNosAnosAnterioresDoPeriodoDe4Anos = 365 * anoNoPeriodoDe4Anos + (anoNoPeriodoDe4Anos == 3 ? 1 : 0);
		long segundosPorAno = segundosPorDia * diasNosAnosAnterioresDoPeriodoDe4Anos;
        // Passo 5.
        long diasNoAno = dia - 1;
        int tabelaDeMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 0; i < mes - 1; i++) {
            diasNoAno += tabelaDeMeses[i];
        }

        // Passo 6.
        long dias = diasNoAno
                + diasNosAnosAnterioresDoPeriodoDe4Anos
                + periodosDe4AnosNos400 * 1461
                + periodosDe400Anos * 146097;

        // Passo 7.
        if (anoNoPeriodoDe4Anos == 2 && mes > 2) dias++;
        if (anoNoPeriodoDe400Anos > 130 || (anoNoPeriodoDe400Anos == 130 && mes > 2)) dias--;
        if (anoNoPeriodoDe400Anos > 230 || (anoNoPeriodoDe400Anos == 230 && mes > 2)) dias--;
        if (anoNoPeriodoDe400Anos > 330 || (anoNoPeriodoDe400Anos == 330 && mes > 2)) dias--;

        // Passo 8.
        //return segundo + 60 * minuto + 60 * 60 * hora + 60 * 60 * 24 * dias;
        long timeStamp = segundo + 60 * minuto + 60 * 60 * hora + 60 * 60 * 24 * dias;
       
        //return 60;
        printf("Primeiro valor: %li \n", timeStamp);
        
    }
    getTimestamp(2035,2,9,1,4,56); //Ano, mes, dia, hora, mim, seg
}
