#include "block_read.h"
#include <errno.h>

void *block_read(void *ptr_buffers_tab[]) {
    //  char *name = (char*)data;
    //  pointers to buffer1 & buffer2 array

    int monfd;
    //  Open /dev/monreader
    monfd = open("/dev/monreader", O_RDONLY, 0);
    if (errno != 0) {
        if errno == EBUSY {
            syslog(LOG_ERR, "ERROR: Open /dev/monreader failed. Device has already been opened by another user or you don't have permmision to read /dev/monreader. (EBUSY flag) Exiting... \n");   
        } else {
           syslog(LOG_ERR, "Unknown error during open /dev/monreder. Exiting... \n"); 
        }
        RUNNING = false;
        return NULL;
    }
    //  Read /dev/monreader to buffer

    unsigned int db_lag_counter = 0;
    int expand_time = 1;
    int i = 0;
    unsigned int current_byte = 0;
    ssize_t bytes_count = 0;
    size_t bytes_range = 0;
    __u8 *dirty_buffer = ptr_buffers_tab[i];


    while (RUNNING)
    {
        sleep(SLEEP_TIME);
        //  READ from /dev/monreader to the buffer
        bytes_count = read(monfd, &dirty_buffer, MONDCSS_SIZE - bytes_range);
        if (bytes_count > 0) {
            bytes_range += bytes_count;
            if (bytes_range > MONDCSS_SIZE) {
                syslog(LOG_ERR, "PANIC! Data from READ() jump out from buffer range. This shouldn't be happening... OMG \n");                    RUNNING = false;
                RUNNING = false;
                return NULL;
            }                
            //sleep(SLEEP_TIME);
            continue;
        } else if (bytes_count == 0) {
            if (bytes_range <= MONDCSS_SIZE) {
                //  Ready to process data from the buffer so swap them and inform second thread about it
                //  swap buffers
                switch (DB_INSERT_RUNNING)
                {
                case false:
                    ACTIVE_BUFFER = ptr_buffers_tab[i];
                    //  swap written buffer with dirty one
                    switch (i)
                    {
                    case 0:
                        i = 1;
                        break;
                    case 1:
                        i = 0;
                        break;
                    }
                    dirty_buffer = ptr_buffers_tab[i];
                    NEW_ACTIVE_BUFFER = true;   //  msg to inform about ready dataset
                    memset(dirty_buffer, 0, MONDCSS_SIZE);
                    break;
                    
                case true:
                    db_lag_counter += 1;
                    if (db_lag_counter > 10) {
                        syslog(LOG_WARNING, "Records INSERT to DB is too slow. Check your DB or call DBA. Inceasing time wait... \n");
                        expand_time = 2;
                    }
                    sleep(SLEEP_TIME * 3 * expand_time);
                    break;
                }
                
            } else {
                syslog(LOG_ERR, "PANIC! Data from READ() jump out from buffer range. This shouldn't be happening... \n");                    RUNNING = false;
                RUNNING = false;
                return NULL;
            }
        
        } else {    //  for error as fd = -1 
            if (errno == EAGAIN) {
                sleep(SLEEP_TIME);
                //continue;
            } else {
                //  (errno == EFAULT || errno == EIO || errno == EOVERFLOW)
                memset(ptr_buffers_tab[i], 0, dirty_buffer - ptr_buffers_tab[i]);
                dirty_buffer = ptr_buffers_tab[i];
                bytes_range = 0;
                sleep(SLEEP_TIME * 4);
                //continue;
            }
        }
    sleep(SLEEP_TIME);
    }

    //  Close /dev/monreader
    close(monfd);
    if (errno == -1) {
        syslog(LOG_WARNING, "Close /dev/monreader attempt failed.");
    }

    return NULL;
}
