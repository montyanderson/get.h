# get.h
Simple HTTP get function written in C (with libcurl).

``` C
#include <stdio.h>
#include "get.h"

int main() {
    char data[1000000];
    get("https://raw.githubusercontent.com/montyanderson/get.h/master/README.md", data);
    printf("%s", data);

    return 0;
}

```

``` bash
$ gcc example.c -lcurl && ./a.out
# get.h
Simple HTTP get function written in C (with libcurl).
```
