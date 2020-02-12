/*

 * C program to illustrate how a file stored on the disk is read

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t
gf_nread (int fd, void *buf, size_t count)
{
        ssize_t  ret           = 0;
        ssize_t  read_bytes    = 0;
        int temp_count = 0;

        for (read_bytes = 0; read_bytes < count; read_bytes += ret) {
                ret = read (fd, buf + read_bytes, count - read_bytes);
                temp_count++;
                if (ret == 0) {
                        break;
                } else if (ret < 0) {
                                goto out;
                }
                printf ("%s", buf);
        }

        ret = read_bytes;
out:
        printf ("\ntemp_count:%d\n", temp_count);
        return ret;
}

int main()
{
        char  buf[32]               = {0};
        char  buffer[1000]               = {0};
        int ret = -5;
        int fptr = open("file", O_RDONLY);
        int count = 0;
        int t = 0;
        if(fptr < 0)
        return 1;
/*
                ret = read (fptr, buf, 160);
                printf ("buf:\n%s\n", buf);
                */
        for (int gfid_idx=0; ; gfid_idx++) {
                ret = gf_nread (fptr, buf, 32);
                for (int i = count*32; ;i++) {
                //printf ("\ncount:%d, i:%d, t :%d", count,i, t);
                        t++;
                        buffer[i] = buf[t];
                        if (t == 32)
                                break;
                }
                count++;
                t = 0;
                if (ret < 0)
                        goto out;
                else if (ret == 0)
                        break;
/*
                if (ret != 160) {
                        ret = -1;
                        goto out;
                }
                */
        }

out:
        //fclose(fptr);
                printf ("\ncount:%d, ret:%d", count,ret);
                printf("%s", buffer);
        return ret;
}
