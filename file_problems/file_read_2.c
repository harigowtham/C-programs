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
        char  buf[320]               = {0};
        int ret = 0;
        int ret_for_read = 0;
        int fd = open("file", O_RDONLY);
        int count = 0;
        int c = 0;
        int t = 0;
        ssize_t  read_bytes    = 0;
        if(fd < 0)
        return 1;

                for (read_bytes = 0; read_bytes < 32;
                                read_bytes += ret) {
                        ret_for_read = read (fd, buf + read_bytes,
                                        32 - read_bytes);
                        printf ("======ret_for_read:%d, read_bytes:%d=======", ret_for_read, read_bytes);
                        if (ret_for_read == 0) {
                                printf ("inside if");
                                ret = read_bytes;
                                break;
                        } else if (ret_for_read < 0) {
                                printf ("inside else if");
                                goto out;
                        }
                        c++;
                printf ("%s", buf);
        }

out:
                printf ("\ncount:%d, ret:%d c:%d", count,ret,c);
        return ret;
}
