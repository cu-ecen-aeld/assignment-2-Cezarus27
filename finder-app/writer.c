#include <stdlib.h>
#include <syslog.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    openlog(NULL, 0, LOG_USER);
    syslog(LOG_INFO, "Start writer app...");

    if (argc < 2)
    {
        syslog(LOG_ERR, "Not enough argument passed.");
        syslog(LOG_INFO, "Expect full file path as first argument and text string as a second.");
        printf("Exit with error: %d: \n", EXIT_FAILURE);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < argc; i++) {
        // printf("Argument %d: %s\n", i, argv[i]);
        if (strlen(argv[i]) == 0)
        {
            return EXIT_FAILURE;
        }
    }

    const char* full_file_path = argv[1];
    const char* data = argv[2];

    syslog(LOG_DEBUG, "Writing %s to %s\n", data, full_file_path);

    int fd = open(full_file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        syslog(LOG_ERR, "Cannot open the file");
        close(fd);
        return fd;
    }

    int w_result = write(fd, data, strlen(data));
    if (w_result == -1)
    {
        syslog(LOG_ERR, "Cannot write to the file");
        close(fd);
        return w_result;
    }

    close(fd);

    return EXIT_SUCCESS;
}
