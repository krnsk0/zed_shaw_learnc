#ifndef _ex22_h
#define _ex22_h

// makes this available in other files
extern int THE_SIZE;

// gets and sets and internal static var in ex22.c
int get_age();
void set_age(int age);

// updates a static var inside update_ratio
double update_ratio(double ratio);

void print_size();

#endif
