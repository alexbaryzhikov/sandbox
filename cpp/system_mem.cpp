#include <unistd.h>

#include <iostream>

int main() { std::cout << sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE); }
