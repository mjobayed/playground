#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  printf("Hello, World!\n");
  printf("The file/folder name is: %s\n", argv[1]);

  struct stat file_stat;
  if (stat(argv[1], &file_stat) == 0) {
    printf("The file/folder exists!\n");

    if (S_ISDIR(file_stat.st_mode)) {
      printf("It's a directory!\n");
    }

    if (file_stat.st_mode & S_IRUSR) {
      printf("File has owner Read permission.\n");
    }
    if (file_stat.st_mode & S_IWUSR) {
      printf("File has owner Write permission.\n");
    }
    if (file_stat.st_mode & S_IXUSR) {
      printf("File has owner Execute permission.\n");
    }

  } else {
    printf("The file/folder doesn't exist!\n");
  }

  return 0;
}
