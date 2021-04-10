#include <sys/resource.h>

#include <iostream>

void explore(int depth) {
  using std::cout;

  char c;
  char* cp = new char;
  cout << "stack at " << static_cast<void*>(&c);
  cout << ", heap at " << static_cast<void*>(cp) << '\n';
  if (depth > 0) {
    explore(depth - 1);
  }
}

int main() {
  using std::cerr;
  using std::cout;

  cout << "Getting stack limit...\n";
  rlimit limit;
  getrlimit(RLIMIT_STACK, &limit);
  cout << "Stack limit " << limit.rlim_cur << " of " << limit.rlim_max << "\n\n";

  size_t req_size = 20 * 1024 * 1024;
  if (limit.rlim_cur < req_size) {
    cout << "Setting stack limit...\n";
    limit.rlim_cur = req_size;
    int result = setrlimit(RLIMIT_STACK, &limit);
    if (result) {
      cerr << "Error: setrlimit returned " << result << '\n';
    }
    cout << "Stack limit " << limit.rlim_cur << " of " << limit.rlim_max << "\n\n";
  }

  cout << "Exploring stack and heap addresses...\n";
  explore(10);
}
