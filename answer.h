#ifndef ANSWER_H
#define ANSWER_H

static const char OPT_HELP[]  = "help";
static const char OPT_QUIT[]  = "quit";
static const char OPT_INFO[]  = "info";
static const char OPT_SOLVE[] = "solve";

static const int ERROR = -1;

enum options
{
    HELP  = 1,
    QUIT  = 2,
    INFO  = 3
};

enum errors
{
    BUFFER_OVERFLOW = -1
};

void Answer (const int number);

#endif /* ANSWER_H */
