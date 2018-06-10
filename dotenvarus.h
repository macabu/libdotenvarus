#ifndef _DOTENVARUS_H_
#define _DOTENVARUS_H_

#define ENV_FILE ".env"

#define DOTENV_MAX_PATH 256
#define DOTENV_MAX_ENV_VARS 512 + 1
#define DOTENV_MAX_BUF_SIZE (4096 * 2) + 1

int set_env_path(char *restrict);
const char* get_env_path(void);
const char* get_var(const char *restrict);

#endif
