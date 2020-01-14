#include "libmx.h"

static void split(char **res, const char *s, char c) {
    int count_ch;
    int i = 0;
    int j = 0;
    int k;

    while (s[i] != '\0') {
        if (s[i] == c)
            i++;
        else {
            count_ch = mx_count_ch(&s[i], c);
            res[j] = mx_strnew(count_ch);
            for (k = 0; k < count_ch; k++)
                res[j][k] = s[i++];
            j++;
        }
    }
    res[j] = NULL;
}

char **mx_strsplit(const char *s, char c) {
    char **res;

    if (!s)
        return NULL;    
    res = (char**)malloc(sizeof(char*) * (mx_count_words(s, c) + 1));
    split(res, s, c);
    return res ? res : NULL;
}
