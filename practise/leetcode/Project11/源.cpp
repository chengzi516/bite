#define _CRT_SECURE_NO_WARNINGS 1
char* mystrncpy(char* dst, const char* src, size_t n)
{
    int i;
    for (i = 0; src[i] && i < n; i++)
    {
        dst[i] = src[i];
    }

    if (i < n)
    {
        dst[i] = 0;
    }
    return dst;
}