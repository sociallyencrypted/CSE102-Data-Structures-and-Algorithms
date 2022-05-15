#include <stdio.h>

void move(int n, char src_t[], char dst_t[], char mid_t[])
{
    if (n == 0)
        return;
    move(n - 1, src_t, mid_t, dst_t);
    printf("Moving from %s to %s\n", src_t, dst_t);
    move(n - 1, mid_t, dst_t, src_t);
}

int main()
{
    move(4, "Tower1", "Tower3", "Tower2");
    return 0;
}