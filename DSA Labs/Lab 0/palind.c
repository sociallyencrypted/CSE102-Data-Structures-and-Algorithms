#include <stdio.h>

int main()
{
    char *f = malloc(1000000 * sizeof(char));
    scanf("%s", f);
    char *p = f;
    int l = strlen(f);
    char *q = f + l - 1;
    int x = 1;
    for (; p < f + l / 2; ++p, --q)
    {
        if (*p != *q)
        {
            x = 0;
            break;
        }
    }
    char *res = x ? "YES" : "NO";
    printf("%s", res);
}
