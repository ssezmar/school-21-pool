#include <math.h>
#include <stdio.h>

#include "polish_notation.h"
#include "tokenizer.h"

#define WIDTH 80
#define HEIGHT 25
#define PI 3.1415
#define min_x 0
#define max_x 12.561
#define step_x 0.159
#define min_y -1
#define max_y 1
#define step_y 0.0833333333333
#define middle 12

void draw(token_t *final_array, int n);