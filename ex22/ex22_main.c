#include "ex22.c"
#include "../dbg.h"

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
  log_info("count is %d", count);

  if (count > 10)
  {
    int count = 100; // BAD!!

    log_info("count in this scope is %d", count);
  }
  log_info("count at exit: %d", count);

  count = 3000;

  log_info("count after assign: %d", count);
}

int main(int arg, char **argv)
{
  // test out THE_AGE accessors
  log_info("My name is %s, age: %d", MY_NAME, get_age());

  set_age(100);
  log_info("My name: %s, age: %d", MY_NAME, get_age());

  // test out THE_SIZE extern
  log_info("THE_SIZE is now %d", THE_SIZE);
  print_size();

  // test ratio func static
  log_info("ratio at first: %f", update_ratio(2.0));
  log_info("ratio again: %f", update_ratio(10.0));
  log_info("ratio once more: %f", update_ratio(300.0));

  // test scope demo
  int count = 4;
  scope_demo(count);
  scope_demo(count * 20);
}
