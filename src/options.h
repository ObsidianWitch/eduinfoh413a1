#ifndef _OPTIONS_H_
#define _OPTIONS_H_

typedef struct lopOpts_t {
    char *fileName;
} lopOpts_t;

lopOpts_t readOpts(int argc, char **argv);

#endif // _OPTIONS_H_
