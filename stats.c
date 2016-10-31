#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <string.h> 
#include <sys/types.h>

int toBinary(int n){
  if (n == 0) return 0;
  if (n == 1) return 1;
  return (n % 2) + 10 * toBinary(n/2);
}


void printStats(char * file){
  struct stat *filestruct = (struct stat*)malloc(sizeof(struct stat));
  
  if(!file){
    printf("No file");
    return;
  }

  if(stat(file, filestruct) == 0){
    printf("\n=====Stats of %s=====\n", file);
    printf("size: %lld\n", filestruct->st_size);
    printf("mode: %o\n", filestruct->st_mode);
    printf("last access: %s\n", ctime(&(filestruct->st_atime)));
  }
  else
    printf("error %d: %s\n", errno, strerror(errno));

  free(filestruct);
}

int main(){
  printStats("test.txt");
  
  int a = toBinary(6);
  int b = toBinary(4);
  printf("%d\n", a);
  printf("%d\n", b);

  return 0;
}
