#include <stdio.h>
#include "utils.h"

int main() {
    unsigned char bs[] = "1010010100011100";
    unsigned char ba[8];
    int len;

    // 测试 Bitstr2ByteArr
    if (Bitstr2ByteArr(bs, ba, &len) == 0) {
        printf("Bitstr2ByteArr result: ba = \"%s\"; len = %d\n", ba, len);  // 预期输出: ba = "051C"; len = 2
    } else {
        printf("Bitstr2ByteArr failed\n");
    }

    // 测试 ByteArr2Bitstr
    unsigned char bs_out[17];  // 包括字符串结束符
    int lbs_out;
    if (ByteArr2Bitstr(ba, bs_out, &lbs_out) == 0) {
        printf("ByteArr2Bitstr result: bs = \"%s\"\n", bs_out);  // 预期输出: bs = "1010010100011100"
    } else {
        printf("ByteArr2Bitstr failed\n");
    }

    return 0;
}

