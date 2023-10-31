#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Hola Mundo\n");
  int rc = fork();
  printf("%d\n", rc);
  if (rc < 0)
    printf("Falló el fork\n");
  else if (rc == 0)
    printf("Soy el hijo\n");
  else
    printf("Yo soy tu padre\n");
  return 0;
}
