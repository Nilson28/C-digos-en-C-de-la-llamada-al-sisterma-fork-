/**                                                                                    
Enunciado: "Write another program using fork() . The child process should              
print “hello”; the parent process should print “goodbye”. You should try to            
ensure that the child process always prints first; can you do this without             
calling wait() in the parent?"                                                         
                                                                                                                                                                        
*/                                                                                     
                                                                                                                                     
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>
#include <stdio.h>
                                                                                       
int main(int argc, char** argv) {                                                      
  pid_t pid;                                                                           
  int status;
                                                                            
  pid= fork();

  if (pid == 0) {                                                                      
    printf("Hijo: Hello\n");                          
  } else {                                                                             
    
    waitpid(pid, &status, 0);
    printf("Padre: goodbye\n");                      
  }                                                                                    
}
