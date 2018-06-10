#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "dotenvarus.h"

void test_set_env_path() {
    char* path = "mypath";
    int ret = set_env_path(path);
    int cmp = strcmp(path, get_env_path());
    assert(ret == 0);
    assert(cmp == 0);
}

void test_get_var() {
    int reset_env = set_env_path("");
    assert(reset_env == 0);

#undef ENV_FILE
#define ENV_FILE ".env.example"

    int cmp = strcmp("thisisatest", get_var("TEST"));

    assert(cmp == 0);
}

int main() {
    test_set_env_path();
    test_get_var();

    return 0;
}
