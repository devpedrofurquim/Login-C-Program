#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MIN 16
#define MAX 46

int main(int argc, char* argv[]) {
    int i = 0;
    char *email = NULL;
    int length;
    int j;
    int containAt = 0;
    int containSpecialChar = 0;

while (1) {
    printf("Digite seu email: ");
    scanf("%ms", &email);
    length = strlen(email);
    while (i < length) 
    {
      if (length > MAX || length < MIN) 
      {
      printf("ERRO: Email deve conter entre %d e %d caracteres\n", MIN, MAX);
      free(email);
      email = NULL;
      break;
      }

      if (email[i] == '@') 
      {
        containAt++;
        printf("%d\n", containAt);
      }
      
      for (int n = 0; n < length; n++) 
      {
        if (email[n] == '!' || email[n] == '#' || email[n] == '$' || email[n] == '^' || email[n] == '&' ||
            email[n] == '*' || email[n] == '(' || email[n] == ')' || email[n] == '"' || email[n] == '{' ||
            email[n] == '}' || email[n] == '<' || email[n] == '>' || email[n] == '?' || email[n] == '[' ||
            email[n] == ']' || email[n] == '-') 
        {
          containSpecialChar = 1;
          break;
        }
      }
      i++;
    }

    if (email != NULL) 
      { 
        if (containAt != 1) 
        {
          printf("ERRO: Uso incorreto de caractere @\n");
          printf("%d", containAt);
          free(email);
          containAt = 0;
          email = NULL;
        } else  if (containSpecialChar == 1) {
          printf("ERRO: Uso de caracteres especiais\n");
          free(email);
          email = NULL;
          containAt = 0;
          containSpecialChar = 0;
        } else {
          break;
        }
      }
  }
    printf("Email cadastrado com sucesso! Seu email é %s\n", email);
    free(email);
    return 0;
}
