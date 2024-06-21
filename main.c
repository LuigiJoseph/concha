#include <cstdlib>
int main(int argc, char **argv)
{
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}

void lsh_loop(void){
    char *line;
    char **args;
    int status;

    do{
        printf("> ");
        line = lsh_read_line();
        args = lsh_split_line(line);
    
        //this is used to determine when to exit the loop
        status = lsh_execute(args);

        free(line);
        free(args);
    } while (status);

}