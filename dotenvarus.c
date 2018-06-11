#include "dotenvarus.h"

#include <stdio.h>
#include <string.h>

#ifndef ENV_FILE
    #undef ENV_FILE
    #define ENV_FILE ".env"
#endif

#ifdef _WIN32
    #define LINE_END "\r\n"
#else
    #define LINE_END "\n"
#endif

char env_path[DOTENV_MAX_PATH] = "";

int set_env_path(char *restrict path) {
    snprintf(env_path, DOTENV_MAX_PATH, "%s", path);
    return strncmp(env_path, path, DOTENV_MAX_PATH);
}

const char* get_env_path(void) {
    return env_path;
}

const char* get_var(const char *restrict variable) {
    char buf[DOTENV_MAX_BUF_SIZE];

    struct {
        const char* variable;
        const char* value;
    } env_vars[DOTENV_MAX_ENV_VARS];
    
    {
        FILE* fd;
        size_t fs, fr;
        char file[DOTENV_MAX_ENV_VARS];
        
        if (env_path[0] == '\0')
            snprintf(file, DOTENV_MAX_PATH, "%s", ENV_FILE);
        else
            snprintf(file, DOTENV_MAX_PATH, "%s/%s", env_path, ENV_FILE);

        if ((fd = fopen(file, "r")) != NULL) {
            fseek(fd, 0L, SEEK_END);
            fs = ftell(fd);
            fseek(fd, 0L, SEEK_SET);

            if (!(fr = fread(buf, (size_t)1, fs, fd))) {
                fprintf(stderr, "Failed to load contents of file %s to buffer\n", file);
                return "";
            }

            fclose(fd);
        } else {
            fprintf(stderr, "Failed to open file %s\n", file);
            return "";
        }
    }

    {
        char* token;
        char lines[DOTENV_MAX_ENV_VARS][DOTENV_MAX_ENV_VARS * 2];
        size_t i = 0, j = 0;

        token = strtok(buf, LINE_END);
        while (token != NULL) {
            snprintf(lines[i], sizeof(lines[i]), "%s", token);
            i++;
            token = strtok(NULL, LINE_END);
        }

        for (i = 0; lines[i] != NULL && i < (sizeof(lines)/sizeof(lines[0])); i++) {
            token = strtok(lines[i], "=");
            env_vars[j].variable = token;
            if ((token = strtok(NULL, "=")) == NULL)
                break;
            env_vars[j].value = token;
            j++;
        }
    }

    for(size_t i = 0; env_vars[i].variable != NULL; i++)
        if (!strncmp(env_vars[i].variable, variable, DOTENV_MAX_ENV_VARS))
            return env_vars[i].value;

    return "";
}
