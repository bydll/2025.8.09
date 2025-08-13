#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    float a = 67.987f, b = 78.634f;
    char c[4]; // 4字节存储
    int16_t temp[2];
    const float scale = 1000.0f;

    // 压缩成 int16
    temp[0] = (int16_t)(a * scale);
    temp[1] = (int16_t)(b * scale);

    // 存入4字节数组
    memcpy(c, temp, 4);

    // 从数组提取
    int16_t read_temp[2];
    memcpy(read_temp, c, 4);

    // 还原为 float
    float a2 = read_temp[0] / scale;
    float b2 = read_temp[1] / scale;

    printf("原始值: %.6f  %.6f\n", a, b);
    printf("还原值: %.6f  %.6f\n", a2, b2);

    return 0;
}
