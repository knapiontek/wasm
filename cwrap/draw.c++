#include <emscripten/emscripten.h>
#include <stdlib.h>
#include <vector>

// em++ -std=c++11 -O3 -o draw.js draw.c++

extern "C" {

int total = 0;

void draw_begin() {
    EM_ASM(draw_begin());
}

void draw_end() {
    EM_ASM(draw_end());
}

void draw_line(int x1, int y1, int x2, int y2) {
    EM_ASM(draw_line($0, $1, $2, $3), x1, y1, x2, y2);
}

int EMSCRIPTEN_KEEPALIVE cxx_func(int size) {
    int* mem = (int*)malloc(size);
    for(int i = 0; i < size; i++)
        mem[i] = i;
    total += size;
    std::vector<int> vec = {1,2,3,4};
    for(int i = 0; i < vec.size(); i++)
        vec[vec.size()-1-i] = vec[i];

    draw_begin();
    draw_line(50, 50, 100, 100);
    draw_end();
    return total + vec[2];
}

}
