    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <locale.h>
    #include <string.h>
 
    #define MAX_LENGTH 256
    #define LINE_CNT 200
    int first_nonspace(const char *s) {
    for(size_t i=0; *s; ++i, ++s)
        if( !isspace(*s) )
        return i;
    return -1;
    }
    int main() {
    setlocale(LC_ALL, "C");
    char** lines = malloc( LINE_CNT * sizeof(char*) );
    for(int i=0; i < LINE_CNT; ++i)
        lines[i] = malloc( MAX_LENGTH * sizeof(char) );
    char  line[MAX_LENGTH];
    size_t currLineNumb = 0;
 
    while( fgets(line, MAX_LENGTH, stdin) != NULL && currLineNumb < LINE_CNT) {
        int fns = first_nonspace(line);
        if(fns == -1)
        continue;
        else {
        char lib_prefix[4] = {'\0',}; // "lib" + '\0'
        strncpy(lib_prefix, line+fns, 3);
        lib_prefix[3] = '\0';
        if( !strcmp(lib_prefix, "lib")) // Если имя начинается с 'lib',
            strcpy(lines[currLineNumb++], line+fns); // сохраняем эту строчку
        }
    }
    // Выводим сохраненную строчку до первого пробела,
    // что и будет составлять наш soname.
    for(size_t i=0; i < currLineNumb; ++i)
        printf("%.*s\n", (int)(strchr(lines[i], ' ') - lines[i]), lines[i]);
    for(int i=0; i < LINE_CNT; ++i) free(lines[i]);
    free(lines);
    return 0;
    }
