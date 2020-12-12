#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

void test_func_3()
{
    void*   array[50];
    char**  messages;
    int size, i;
    void *addr =  __builtin_return_address(0);
    printf("%s : 0x%x\n\n", __FUNCTION__, addr);

    size = backtrace(array, 50);
    messages = backtrace_symbols(array, size);

    for (i = 0; i < size; i++){
        fprintf(stderr, "[bt]: (%d) %s\n", i, messages[i]);
    }

    free(messages);
}

void test_func_2()
{
    void *addr =  __builtin_return_address(0);
    printf("%s : 0x%x\n", __FUNCTION__, addr);
    test_func_3();
}

void test_func_1()
{
    void *addr =  __builtin_return_address(0);
    printf("%s : 0x%x\n", __FUNCTION__, addr);
    test_func_2();
}

int main()
{
    test_func_1();
    printf("return test \n");
    return 0;
}
