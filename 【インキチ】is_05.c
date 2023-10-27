#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char input[128], buf[256];
    int ret = 0;
    printf("文字列を入力してください: ");
    fgets(input, sizeof(input), stdin);

    // Check for special characters and prepend ^ if found
    char* p = (char*)memchr(input, '\n', sizeof(input));
    if (p != NULL) {
        *p = '\0';
    }
    
    int len = snprintf(buf, sizeof(buf), "echo ");
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '|' || input[i] == '&' || input[i] == '<' || input[i] == '>') {
            buf[len++] = '^'; // Prepend ^ before special character
        }
        buf[len++] = input[i];
    }
    
    if (len > 0) {
        ret = system(buf);
    }
    
    return ret;
}
