#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MIN 8
#define MAX 12

int main(int argc, char* argv[]) {
    int n = 0;
    int i = 0;
    int j = 0;
    char *email = NULL;

while (1) {
    free(email);
    printf("Digite seu email: ");
    scanf("%ms", &email);
    if(isspace(email[n])) {
        printf("Space over here");
        continue;
    }
    while (email[n] != '\0') {
            ++n;
            ++i;
            if (email[n] == '@') {
                j++;
        }
            if (email[n] == '*' || email[n] == '$' || email[n] == '%' || email[n] == '"' || email[n] == '#' || email[n] == '(' || email[n] == ')' || email[n] == '&' || email[n] == ' ') {
                printf("ERRO: USO DE CHAR PROIBIDO NO EMAIL\n");
                free(email);
                i = 0;
                j = 0;
                n = 0;
                email = NULL;
                break;
            }
            if (isupper(email[n])) {
                printf("ERRO: USO DE CHAR MAIUSCULO NO EMAIL\n");
                free(email);
                i = 0;
                j = 0;
                n = 0;
                email = NULL;
                break;
            } else if (j != 1) {
                printf("ERRO: USO DE MAIS DE 1 CHAR @ NO EMAIL\n");
                free(email);
                i = 0;
                j = 0;
                n = 0;
                email = NULL;
                break;
            }
        }
        if (email != NULL) {
                break;
            }
    }
    printf("%s\n", email);
    printf("%i\n", i);
    free(email);
    return 0;
}
