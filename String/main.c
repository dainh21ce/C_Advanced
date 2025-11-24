#include <stdio.h>
#include <string.h>

void arrange(char s1[], int index)
{
    for (int i = index; i < strlen(s1); ++i)
    {
        s1[i] = s1[i + 1];
    }
}

int main()
{
    // char str1[] = "NHD1123";
    // char *str2 = "NHD22232";

    // strcat(&str1[3], str2);

    // printf("%s", str1);
    //==============================================
    char s1[] = "Nguyen Huu Dai dep trao vkl";
    char *s2 = " ";

    char *find = strstr(s1, s2);
    while (find != NULL)
    {
        int index = find - s1;
        arrange(s1, index);
        find = strstr(s1, s2);
    }
    printf("%s\n", s1);
    return 0;
}