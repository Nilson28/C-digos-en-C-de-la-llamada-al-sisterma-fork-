/*                                                                                     
Enunciado: "Write a program that opens a file (with the open() system call)            
and then calls fork() to create a new process. Can both the child and parent           
access the file descriptor returned by open()? What happens when they are              
writing to the file concurrently, i.e., a t the same time?"                            
                                                                                                                                                                   
                                                                                  
*/                                                                                     
                                                                                       
// Incluir archivos de cabecera para las funciones que requiere para                   
// solucionar el enunciado                                                             

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv) {                                                      
  // Usar estas variables                                                              
  int x;                                                                               
  pid_t pid;                                                                           
  char *filename="code-02.txt";                                                        
  int fd;                                                                              
                                                                                                                                                               
  // Instrucciones para abrir archivo de lectura/escritura)                                                                              
  fd= open(filename, O_WRONLY | O_CREAT);
  if(fd == -1){
	printf("Error");
}                                                                                   
                                                                                    
  x = 100;                                                                             
  pid = fork();
                                                                        
  if (pid == 0) {                                                                      
    x++;	
    dprintf(fd, "Soy el hijo, valor de x: %d\n",x);                                                     
  } else {                                                                             
    x+=2;
    	                                                                              
    dprintf(fd, "Soy el padre, valor de x: %d\n",x);
                                                     
  }
                                                                                                                                                                           
  close(fd);

  return 0;
} 
