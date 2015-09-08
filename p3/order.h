#ifndef ORDER_H
#define ORDER_H

typedef void (*t_ordering)(int*, int*, int*);

void ascending3(int*, int*, int*);

void descending3(int*, int*, int*);

t_ordering order(char);

#endif
