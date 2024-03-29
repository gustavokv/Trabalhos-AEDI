#include <stdio.h>
#include <math.h>

int main () {
    int andar, novoandar; 
    int quantsoma=0, un, dez, cent, m1, m2, m3, mi;
    int i;

    //Entrada do andar.
    printf("-> Digite o andar que deseja modificar:\n");
    scanf("%d", &andar);
    while(andar<1||andar>pow(10, 6)) {
        printf("\n-> O andar esta num valor incorreto, deve ser de 1 ate 10^6.\nDigite novamente:\n");
        scanf("%d", &andar);
    }

    novoandar = andar;

    //i vai de 0 ate o andar digitado, em ordem crescente.
    for(i=0;i<=novoandar;i++) {
        
        //Conversao de casas.
        un = i % 10;
        dez = (i % 100 - i % 10) / 10;
        cent = (i % 1000 - i % 100) / 100;
        m1 = (i % 10000 - i % 1000) / 1000;
        m2 = (i % 100000 - i % 10000) / 10000;
        m3 = (i % 1000000 - i % 100000) / 100000;
        mi = (i % 10000000 - i % 1000000) / 1000000;

        //Caso i possua 4 ou 13, sera somado +1 no valor total.
        if(un==4||dez==4||cent==4||m1==4||m2==4||m3==4||(dez==1&&un==3)||(cent==1&&dez==3)||(m1==1&&cent==3)||(m2==1&&m1==3)||(m3==1&&m2==3)||(mi==1&&m3==3)) {
            novoandar++;
            quantsoma++;
        }
    }

    printf("\n-> O andar %d recebeu %d somas, se tranformando no andar %d!\n", andar, quantsoma, novoandar);

    return 0;
}