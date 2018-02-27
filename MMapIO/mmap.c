#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
int fd;
char *map;
struct stat sbuf;
int i;
char str[50];

int main(){
    fd=open("mmap.txt",O_RDWR);
    if(fd==-1){
        perror("Opening mmap.txt");
    	exit(1);
    }
    if(stat("mmap.txt",&sbuf)==-1){
        perror("stat");
    	exit(1);
    }
    memset(str,'a',50);
    write(fd,str,50);
    map = mmap((caddr_t)0, sbuf.st_size, (PROT_WRITE |  PROT_READ), MAP_SHARED,
    fd, 0);
   
    map[26]='b';
    map[27]='b';
    map[28]='b';
    //printf("%s \n",map);


   for(i=0;i<50;i++){
        if(i%10==9){
            printf("%c \n",map[i]);
        }else{
            printf("%c",map[i]);
        }
    }
    
    close(fd);
}
