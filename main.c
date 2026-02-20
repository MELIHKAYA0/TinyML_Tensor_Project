#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
    TYPE_FLOAT32,
    TYPE_INT8
} DataType;

typedef union {
    float* f32_ptr;
    int8_t* i8_ptr;
} TensorData;

typedef struct {
    TensorData data;
    DataType type;
    int rows;
    int cols;
} Tensor;

Tensor* create_tensor(int rows, int cols, DataType type) {
    Tensor* t = (Tensor*)malloc(sizeof(Tensor));
    t->rows = rows;
    t->cols = cols;
    t->type = type;
    int total = rows * cols;
    if (type == TYPE_FLOAT32) {
        t->data.f32_ptr = (float*)malloc(total * sizeof(float));
    } else {
        t->data.i8_ptr = (int8_t*)malloc(total * sizeof(int8_t));
    }
    return t;
}

void quantize_tensor(Tensor* f_tensor, Tensor* i_tensor) {
    for (int i = 0; i < f_tensor->rows * f_tensor->cols; i++) {
        float val = f_tensor->data.f32_ptr[i];
        i_tensor->data.i8_ptr[i] = (int8_t)(val * 127.0f);
    }
}

int main() {
    int r = 2, c = 2;
    Tensor* f_tensor = create_tensor(r, c, TYPE_FLOAT32);
    Tensor* i_tensor = create_tensor(r, c, TYPE_INT8);

    f_tensor->data.f32_ptr[0] = 0.5f;
    f_tensor->data.f32_ptr[1] = -0.8f;
    f_tensor->data.f32_ptr[2] = 0.1f;
    f_tensor->data.f32_ptr[3] = 0.9f;

    quantize_tensor(f_tensor, i_tensor);

    printf("--- Float Matris ---\n");
    for(int i=0; i<4; i++) printf("%.2f ", f_tensor->data.f32_ptr[i]);
    
    printf("\n\n--- Quantized (int8) Matris ---\n");
    for(int i=0; i<4; i++) printf("%d ", i_tensor->data.i8_ptr[i]);

    free(f_tensor->data.f32_ptr);
    free(f_tensor);
    free(i_tensor->data.i8_ptr);
    free(i_tensor);

    return 0;
}