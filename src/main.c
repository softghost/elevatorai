#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

void print_usage(char* name) {
    char* bname = 0;

    if (name == NULL) {
        fprintf(stderr, "%s invoked with invalid name.\n", __FUNCTION__);
        return;
    }

    //basename() may modify the memory used as a parameter. We avoid destroying
    //our callers memory.
    bname = strdup(name);
    if (bname == NULL) {
        fprintf(stderr, "Failed to duplicate string\n");
        return;
    }

    fprintf(stderr, "USAGE: %s [OPTION]...\n", basename(bname));
    fprintf(stderr, "Elevator AI simulator framework.\n");
    fprintf(stderr, "\n");

    fprintf(stderr, "List of available options:\n");
    fprintf(stderr, "\t-h\tShow this help message.\n");  
    fprintf(stderr, "\n");

    fprintf(stderr, "Report %s bugs to andres@softghost.com\n", basename(bname));

    free(bname);
}

int main(int argc, char *argv[])
{
    int c;
    while ((c = getopt (argc, argv, "h")) != -1) {
        switch (c) {
            case 'h':
                print_usage(argv[0]);
                exit(0);

            default:
                print_usage(argv[0]);
                exit(-EINVAL);
        }
    }

    printf("Hello Elevator AI\n");

    return 0;
}
