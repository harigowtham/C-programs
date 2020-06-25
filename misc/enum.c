#include<stdio.h>
#include<stdint.h>

enum fusedev_errno {
    ENOENT,
    ENOTDIR,
    ENODEV,
    EPERM,
    ENOMEM,
    ENOTCONN,
    ECONNREFUSED,
    EOVERFLOW,
    EBUSY,
    ENOTEMPTY,
    EMAXPLUS
};

uint8_t fusedev_errno_cnt[EMAXPLUS];

int errno_degraded = 1;
int errno_promoted = 0;
/*
void ACCOUNT_ERRNO(int eno) {
        if (errno_degraded) {
            {
                if (!fusedev_errno_cnt[eno]++) {
                    errno_promoted = 1;
                        printf("errno_promoted:%d", errno_promoted);
                }
            }
        }
    }
*/
int main() {

int errno_degraded = 1;
int errno_promoted = 0;

#define ACCOUNT_ERRNO(eno)                                                     \
    do {                                                                       \
        if (errno_degraded) {                                                  \
            {                                                                  \
                if (!++fusedev_errno_cnt[eno]) {                 \
                    errno_promoted = 1;                                    \
                        printf("errno_promoted:%d", errno_promoted);       \
                }                                                            \
            }                                                                  \
        }                                                                      \
    } while (0)
        errno_promoted;
        for(int i = 0; i < EMAXPLUS; i++) {
                printf("i:%d\t", fusedev_errno_cnt[i]);
        }
        printf("\n");
        for(int j = 0; j <259; j++) {
        ACCOUNT_ERRNO(ENOENT);
        }
        /*
        ACCOUNT_ERRNO(ENOENT);
        ACCOUNT_ERRNO(ENOENT);
        ACCOUNT_ERRNO(ENOENT);
        */
        if (errno_promoted)
                printf("promoted %d", UINT8_MAX + 1);
        else
                printf("no");
        printf("\n");
        for(int i = 0; i < EMAXPLUS; i++) {
                printf("i:%d", fusedev_errno_cnt[i]);
        }
}
