#include <stdio.h>

int main()//inizio
{
float a=0;
float b=0;
float Quadrato=0;

printf("Inserisci un valore di a");
scanf("%f",&a);
printf("inserisci un valore di b");
scanf("%f", &b);

Quadrato= b*b;
printf ("Il quadrato è: %F, quadrato:");

if(a==Quadrato){
printf("il primo valore %f corrisponde al quadrato del secondo %f" ,a,b);

printf("Il primo valore %F non corrisponde al quadrato del secondo %f", a,b);

}

}
