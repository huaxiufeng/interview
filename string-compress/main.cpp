#include <stdio.h>
#include <string.h>
#include <assert.h>

int compress_string(const char *str, char *res, int res_capacity)
{
    assert(str);
    assert(res);
    assert(res_capacity > strlen(str));

    int str_len = strlen(str);
    if (str_len <= 2) {
        strcpy(res, str);
        return str_len;
    }

    char last_c = str[0];
    int res_index = 0;
    int count = 1;
    for (int i = 1; i < str_len+1; i++) {
        if (str[i] == last_c) {
            count++;
            continue;
        }
        res[res_index++] = last_c;
        res_index += sprintf(res + res_index, "%d", count);
        count = 1;
        last_c = str[i];
    }

    int ret = 0;
    if (str_len <= res_index) {
        strcpy(res, str);
        ret = str_len;
    }
    else {
        ret = res_index;
    }
    return ret;
}

int main()
{
    char str[] = "aabbbbbbbbbbbccccaaadd";
    char result[100];

    int ret = compress_string(str, result, sizeof(result));
    printf("compress %s to %s, return %d\n", str, result, ret);

    return 1;
}

