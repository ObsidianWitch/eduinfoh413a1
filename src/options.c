#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>

#include "options.h"

static const lopOpts_t emptyLopOpts;

lopOpts_t readOpts(int argc, char **argv) {
    char opt;
    lopOpts_t lopOpts = emptyLopOpts;

    while ((opt = getopt(argc, argv, "i:")) > 0) {
        switch (opt) {
            case 'i': /* Instance file */
                lopOpts.fileName = (char *) malloc(strlen(optarg) + 1);
                strncpy(lopOpts.fileName, optarg, strlen(optarg));
                break;
            
            default:
                fprintf(stderr, "Option %c not managed.\n", opt);
        }
    }

    if (!lopOpts.fileName) {
        printf("No instance file provided (use -i <instance_name>). Exiting.\n");
        exit(EXIT_FAILURE);
    }
    
    return lopOpts;
}
