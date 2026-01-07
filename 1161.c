#include <stdio.h>
#include <stdio.h>

int main(){
  unsigned short primeiro_numero, segundo_numero;
  unsigned i;
  long double resultado = 1, resultado2 = 1;

  while (scanf("%hd %hd", &primeiro_numero, &segundo_numero) != EOF){
    for (i = primeiro_numero; i > 0; i--){
      resultado* = i;
    }
    for (i = segundo_numero; i > 0; i--){
      resultado2* = i;
    }
    
    printf("%.0Lf\n", resultado + resultado2);
    resultado = 1;
    resultado2 = 1;
  }
}
