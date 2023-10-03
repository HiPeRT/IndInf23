#ifndef _RUNTIME_H_
#define _RUNTIME_H_

/*
 * Gets next inputs, or 'x' if no inputs available.
 * WARNING: this function shifts the input, once you call it!
 */
char nextChar();

/*this function is used to set dub string */
void debug(char str[]);
/*this function is used to write output */
void write(char str[]);

#endif
