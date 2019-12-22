#include <stdio.h>
#include <string.h>
int getLine(char s[]);
int getWord(char w[]);
int substring(char *str1, char *str2);
int similar(char *s, char *t, int n);
void print_line(char *str);
void print_similar_words(char *str);



#define PRINT_LINE 'a'
#define PRINT_SIMILAR_WORDS 'b'

#define LINE 256
#define WORD 30

int getLine(char s[])
{
    char ch;
    int size = 0;

    while ((ch = getchar()) != EOF || size >= LINE)
    {
        if (ch == '\n')
            break;

        s[size] = ch;
        size++;
    }

    s[size] = '\0';
    if (ch == EOF && size == 0)
    {
        return EOF;
    }

    return size;
}

int getWord(char w[])
{
    char ch;
    int size = 0;
    w[0] = '\0';

    while ((ch = getchar()) != EOF || size >= WORD)
    {
        if (ch == '\n' || ch == '\t' || ch == ' ')
            break;

        w[size] = ch;
        size++;
    }

    w[size] = '\0';
    if (ch == EOF && size == 0)
    {
        return EOF;
    }

    return size;
}

int substring(char *str1, char *str2)
{
    for (int j = 0; j < strlen(str1); j++)
    {
        int i = 0;
        while (str2[i] == str1[j + i] &&
               j + i < strlen(str1) &&
               i < strlen(str2))
        {
            i++;
        }

        if (i == strlen(str2))
        {
            return 1;
        }
    }

    return 0;
}

int similar(char *s, char *t, int n)
{
    int wildcards = 0;
    int j = 0;

    if (strlen(s) - strlen(t) - n != 0)
        return 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != t[j] || j >= strlen(t))
        {
            wildcards++;
        }
        else
        {
            j++;
        }
    }

    return wildcards == n;
}

void print_line(char *str)
{
    char line[LINE];

    while (getLine(line) != EOF)
    {
        if (substring(line, str) == 1)
        {
            printf("%s\n", line);
        }
    }
}

void print_similar_words(char *str)
{
    char word[WORD];

    while (getWord(word) != EOF)
    {
        if (similar(word, str, 0) == 1 || similar(word, str, 1) == 1)
        {
            printf("%s\n", word);
        }
    }
}

int main()
{
    char search[WORD];
    char option;
    char empty[LINE];

    // word: search word
    getWord(search);

    // char: option
    option = getchar();

    // line: empty
    getLine(empty);
    getLine(empty);

    switch (option)
    {
    case PRINT_LINE:
        print_line(search);
        break;
    case PRINT_SIMILAR_WORDS:
        print_similar_words(search);
        break;
    }

    return 0;
}
