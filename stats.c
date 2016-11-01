#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <string.h> 
#include <sys/types.h>


int toOctal(int n){
  if (n == 0) return 0;
  if (n < 8) return n;
  return (n % 8) + 10 * toOctal(n/8);
}

void lsStyle( int n ) {
  n = toOctal(n);
  int three = n%10;
  int two = n%100/10;
  int one = n%1000/100;
  char arr[10] = "----------";
  if( one >= 4 )
    arr[1] = 'r';
  if( one >= 6 )
    arr[2] = 'w';
  if( one == 7 )
    arr[3] = 'x';
  if( two >= 4 )
    arr[4] = 'r';
  if( two >= 6 )
    arr[5] = 'w';
  if( two == 7 )
    arr[6] = 'x';
  if( three >= 4 )
    arr[7] = 'r';
  if( three >= 6 )
    arr[8] = 'w';
  if( three == 7 )
    arr[9] = 'x';
  printf( "%s\n", arr);
}


void printStats(char * file){
  struct stat *filestruct = (struct stat*)malloc(sizeof(struct stat));
  
  if(!file){
    printf("No file");
    return;
  }

  if(stat(file, filestruct) == 0){
    printf("\n=====Stats of %s=====\n", file);
    printf("size: %lld B\n", filestruct->st_size);
    printf("mode: %o\n", filestruct->st_mode);
    printf("last access: %s\n", ctime(&(filestruct->st_atime)));

    printf("File permissions (ls -l style):\n");
    printf( (S_ISDIR(filestruct->st_mode)) ? "d" : "-");
    printf( (filestruct->st_mode & S_IRUSR) ? "r" : "-");
    printf( (filestruct->st_mode & S_IWUSR) ? "w" : "-");
    printf( (filestruct->st_mode & S_IXUSR) ? "x" : "-");
    printf( (filestruct->st_mode & S_IRGRP) ? "r" : "-");
    printf( (filestruct->st_mode & S_IWGRP) ? "w" : "-");
    printf( (filestruct->st_mode & S_IXGRP) ? "x" : "-");
    printf( (filestruct->st_mode & S_IROTH) ? "r" : "-");
    printf( (filestruct->st_mode & S_IWOTH) ? "w" : "-");
    printf( (filestruct->st_mode & S_IXOTH) ? "x" : "-");
    printf( "\n\nFile permissions via octals:\n");
    lsStyle( filestruct->st_mode );
  }
  else
    printf("error %d: %s\n", errno, strerror(errno));

  free(filestruct);
}

int main(){
  printStats("test.txt");

  return 0;
}
