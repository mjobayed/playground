#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Invalid arguments!\n");
    printf("Usage: rename-file <file-name> <new-file-name>\n");
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("File does not exist!\n");
    return 2;
  }
  fclose(file);

  rename(argv[1], argv[2]);
  printf("File rename successful!\n");
}
