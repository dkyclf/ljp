#include <stdio.h>
#include <string.h>
#include "utils.h"

int Bitstr2ByteArr(unsigned char *bs, unsigned char *ba, int *lba) {
    int len = strlen((char *)bs);
    if (len % 8 != 0) {
        return -1;  // 位串长度必须是8的倍数
    }

    *lba = len / 8;
    for (int i = 0; i < len; i += 8) {
        int byte = 0;
        for (int j = 0; j < 8; j++) {
            byte = byte << 1;
            byte |= (bs[i + j] == '1') ? 1 : 0;
        }
        sprintf((char *)&ba[i / 8], "%02X", byte);
    }

    return 0;
}

int ByteArr2Bitstr(unsigned char *ba, unsigned char *bs, int *lbs) {
    int len = strlen((char *)ba);
    if (len % 2 != 0) {
        return -1;  // 字节串长度必须是偶数
    }

    *lbs = len * 4;
    for (int i = 0; i < len; i += 2) {
        int byte;
        sscanf((char *)&ba[i], "%02X", &byte);
        for (int j = 0; j < 8; j++) {
            bs[i / 2 * 8 + j] = ((byte >> (7 - j)) & 1) ? '1' : '0';
        }
    }
    bs[*lbs] = '\0';  // 添加字符串结束符

    return 0;
}

