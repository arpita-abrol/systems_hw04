#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <string.h> 
#include <sys/types.h>


void printStats(char * file){
  struct stat *filestruct = (struct stat*)malloc(sizeof(struct stat));
  
  if(!file){
    printf("No file");
    return;
  }

  if(stat(file, filestruct) == 0){
    printf("=====Stats of %s=====\n", file);
    printf("size: %lld\n", filestruct->st_size);
    printf("mode: %o\n", filestruct->st_mode);
    //printf("last access: %s\n", ctime(&(filestruct->st_atim)));
  }
  else
    printf("error %d: %s\n", errno, strerror(errno));

  free(filestruct);
}

int main(){
  printStats("test.txt");

}
