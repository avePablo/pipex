#include "pipex.h"


void parse(int argc, char *argv[])
{
    int i;
    int j;
   
    char **args;
    
    i = 1;
    while (i < argc)
    {
        args = ft_split(argv[i], ' ');
            j = 0;
            while(args[j])
            {
              ft_printf("%s\n",args[j]);
                j++;
            }      
       i++;
    }
}


int main(int argc, char *argv[])
{
parse(argc, argv);
return 0;
}