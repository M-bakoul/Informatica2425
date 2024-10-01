#include <stdio.h>

int main()
{
  int num1=0;
  printf("Inserisci un valore ");
  scanf("%d", &num1);

  if(num1%3==0){
    if(num1%5==0){
      printf("Il numero è divisibile sia per 3 che per 5");
    }
    else{
      printf("Il numero è divisibile per 3 ma non per 5");
    }
  }
  else{
    printf("Il numero non è divisibile per 3");
  }

  return 0;
}