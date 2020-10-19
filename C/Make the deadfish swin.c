#include <stdlib.h>

int* parse(char* program){
  
  //finite machine state
  int *v = (int*) malloc (1 * sizeof (int));
  int count = 0;
  v[count] = 0;
  
  for(int i = 0; program[i] != '\0'; i++){
    switch(program[i]){
        case 'i':
          v[count] = v[count] + 1;
        break;
          
        case 'd':
          v[count] = v[count] - 1;
        break;
        
        case 's':
          v[count] = v[count] * v[count];
        break;
        
        case 'o':
          count++;
          v = (int*) realloc(v, (count+1)*sizeof(int));
          v[count] = v[count-1];
        break;
    }
  }
  
  return v;  
  
}