#include <stdio.h>
#include <string.h>

#include "dotenvarus.h"

#ifdef _WIN32
    #include <direct.h>
    #define getcwd _getcwd
#else
    #include <unistd.h>
#endif

int main(int argc, char** argv) {
    char path[DOTENV_MAX_PATH];
    char var[DOTENV_MAX_PATH];

    if(argc != 2 && argc != 3)
        fprintf(stderr, "Usage: envarus <variable> <path>\n");
    else {
        snprintf(var, DOTENV_MAX_PATH, "%s", argv[1]);
        if (argc == 2) {
            getcwd(path, DOTENV_MAX_PATH);
            set_env_path(path);
        }
        else {
            snprintf(path, DOTENV_MAX_PATH, "%s", argv[2]);
            set_env_path(path);
        }
        fprintf(stdout, "%s", get_var(var));
    }
    return 0;
}
