#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Invalid arguments!\n");
    return 1;
  }

  rename(argv[1], argv[2]);
  printf("File rename successful!\n");
}
