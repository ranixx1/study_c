#include <stdio.h>

int main()
{
    int n;
    scanf("%d\n", &n);
    int val;
    for (int i=0; i < n; i++)
    {
        scanf("%d\n", &val);
        if (val == 0)
        {
            printf("NULL\n");
        }
        else if (val > 0)
        {
            if (val % 2 == 0)
            {
                printf("EVEN POSITIVE\n");
            }
            else
            {
                printf("ODD POSITIVE\n");
            }
        }
        else if (val < 0)
        {
            if (val % 2 == 0)
            {
                printf("EVEN NEGATIVE\n");
            }
            else
            {
                printf("ODD NEGATIVE\n");
            }
        }
    }

    return 0;
}