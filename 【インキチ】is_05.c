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
    
    printf("%s",input);
    return 0;

    int len=1;
    
    if (len > 0) {
        ret = system(buf);
    }
    
    return ret;
}
