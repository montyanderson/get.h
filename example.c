#include <stdio.h>
#include <string.h>
#include "get.h"

int main() {
    char data[1000000];
    get("https://raw.githubusercontent.com/montyanderson/get.h/master/README.md", data);

    printf("%s", data);

    return 0;
}
