#include <stdio.h>
#include "tp8.h"

char *const empty_argv = '\0';

void affiche_prompt(){
 

  int size = 20;
  char* hostname = malloc(size);  
  char* path = malloc(size*2);
  char* u;
  
  gethostname(hostname,size);
  path = get_current_dir_name();
  u = getenv("USER");
  if(strstr(path,u)){
    uint i;
    for(i = 0; i < strlen(path); i++ ){
      path[i] = path[i+14+strlen(u)];
    }
  }
  printf("%s@%s:~%s$ minishell",u,hostname,path);
  fflush(stdout);
  free(hostname);
  free(path);
}


char *** ligne_commande(int * flag, int * nb){

}


void execute_ligne_commande(){
  affiche_prompt();
  int flag;
  int nb  ;
  char *** elc;
  elc = ligne_commande(&flag, &nb);
  int i;

  if (elc!= NULL){
   for(i=0 ; i<nb ; i++){
    int pid = fork();
    if(pid==0){
      execvp(elc[i][0],elc[i]);
      printf("\nNe reconnait pas la ligne_commande\n");
      exit(EXIT_FAILURE);
    }
  }
  free(elc);

}