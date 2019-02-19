#include <stdio.h>
#include <vector>

extern "C" {

int my_func(void) {
    std::vector<int> vec = {1, 2, 3, 4};
    int ret = 0;
    for(auto i : vec)
        ret += i;
    return ret;
}

int main(int argc, char ** argv) {
  int ret = my_func();
  printf("Hello World %d!\n", ret);
  return my_func();
}

}
