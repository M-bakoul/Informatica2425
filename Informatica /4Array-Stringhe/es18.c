//Qual è l'output se in input fossero passati i parametri
//s = "conosco c.,sono ricco"

void mistero_3(char *s) {
    int len = strlen(s);

    int m = len / 2;
    int offset;

    if(len % 2 == 0) 
        offset = m;
    else 
        offset = m + 1;

    for (int i = 0; i < m; i++) {
        char t = s[i];
        s[i] = s[i + offset];
        s[i + offset] = t;
    }
    printf("%s", s);
}