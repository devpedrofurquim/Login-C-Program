#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MIN 8
#define MAX 12

int main(int argc, char* argv[]) {
    int i = 0; // Value for iterating senha array
    int especialChar = 0; // Number of special chars
    int upperChar = 0;    // Number of upper char
    int lowerChar = 0;    // Number of lower char
    int length = 0;
    char *senha = NULL;
while (1) {
    printf("digite sua senha: ");
    scanf("%ms", &senha);
    length = strlen(senha);
    while(i++ < length)
    {
      if (length < MIN || length > MAX) 
      {
        printf("ERRO: Senha deve conter entre %d e %d caracteres\n", MIN, MAX);
        free(senha);
        senha = NULL;
        break;
      }

      for (int n = 0; n < length; n++) 
      {
        if (isupper(senha[n])) 
        {
          upperChar++;
        }
        if (islower(senha[n])) 
        {
          lowerChar++;
        }
      }
      
      for (int n = 0; n < length; n++) 
      {
       if(senha[n] == '!' || senha[n] == '@' || senha[n] == '#' || senha[n] == '$'
      || senha[n] == '%' || senha[n] == '^' || senha[n] == '&' || senha[n] == '*'
      || senha[n] == '(' || senha[n] == ')' || senha[n] == '-' || senha[n] == '{'
      || senha[n] == '}' || senha[n] == '[' || senha[n] == ']' || senha[n] == ':'
      || senha[n] == ';' || senha[n] == '"' || senha[n] == '\'' || senha[n] == '<'
      || senha[n] == '>' || senha[n] == '.' || senha[n] == '/' || senha[n] == '?'
      || senha[n] == '~' || senha[n] == '`' )
       {
         especialChar++;
       }
      }

      if (especialChar == 0) 
      {
        printf("ERRO: Senha deve conter 1 caractere especial e 1 caractere maiusculo\n");
        free(senha);
        senha = NULL;
        break;
      }

      if (upperChar == 0) 
      {
        printf("ERRO: Senha deve conter 1 caractere maiusculo\n");
        free(senha);
        senha = NULL;
        break;
      }

      if (lowerChar == 0) 
      {
        printf("ERRO: Senha deve conter 1 caractere minusculo\n");
        free(senha);
        senha = NULL;
        break;
      }

      if (senha != NULL) 
      {
        break;
      }
  }
  if (senha != NULL) 
  {
    printf("Senha cadastrada com sucesso!\n");
    break;
  }
}
    printf("Sua senha é %s e possui %d caracteres.\n", senha, length);
    free(senha);
    return 0;
}
