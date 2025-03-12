#include "pipex.h"

char **parse(int argc, char *argv[])
{
    int j;
    int i;
    int k;
    char **args;
    char **temp;

    k = 0;
    i = 1;
    while (i < argc) {
        temp = ft_split(argv[i], ' ');
        j = 0;
        while (temp[j])
        {
            args = (char **)realloc(args, (k + 1) * sizeof(char *));
            args[k] = strdup(temp[j]);
            k++;
            j++;
        }
            free(temp); 
        
        i++;
    }
    args = (char **)realloc(args, (k + 1) * sizeof(char *));
    args[k] = NULL;
    
    return args;
}

int main(int argc, char *argv[])
{
    int i;

    i = 0;
parse(argc, argv);
while (parse(argc, argv)[i] != NULL)
{ 
    
    ft_printf("%s\n", parse(argc, argv)[i]);
    i++;
}
return 0;
}