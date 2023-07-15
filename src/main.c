
typedef __uint64_t __eu64;

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <syslog.h>
#include <mysql.h>

#include "create_tables.h"
#include "daemon_init.h"
#include "block_read.h"
#include "db_insert.h"

//no need to put mutex on it (C99) or atomic (C11)
static bool DB_INSERT_RUNNING = false; //db_insert() WRITE, block_read() READ
static bool NEW_ACTIVE_BUFFER = false; //db_insert() READ , block_read() WRITE
static __u8 *ACTIVE_BUFFER = NULL;
static __u8 *ACTIVE_BUFFER_END = NULL;
static int SLEEP_TIME = 5;
static bool RUNNING = true;
static unsigned int MONDCSS_SIZE = 0;

int main(int argc, char *argv[]) {

    if ( argc != 6 ) {
        printf(
            "Syntax: zpmd [z/VM version: default is 53] [MONDCSS segment size] [host ip] [DB User name] [DB Name] \n"
            "After that You will be asked to input password for database user \n"
            "\n"
            "This software is part of Author's BSc Thesis.\n"
            "New releases can be found on github.com\n"
            "\n"
            "z/VM Performance Monitor Daemon version 1.0.0-rc1, \n"
            "Copyright (C) 2008,2009,2023 Przemyslaw Kupisz \n"
            "z/VM Performance Monitor Daemon comes with ABSOLUTELY NO WARRANTY \n"
            "This is free software, and you are welcome \n"
            "to redistribute it under certain conditions \n"
            "See the GNU General Public License for more details. \n"
        );
        exit(1);    
    }

    short zvm_version = atoi(argv[1]);
    switch (zvm_version)
    {
        case 53:
        //
            break;
    
        default:
            printf("This version is not supported. Please, input number 53 for z/VM V5.3 release. \n");
            exit(1);
            break;
    }
    unsigned int bytes_read = atoi(argv[2]);

    char hostip[256];
    strcpy(hostip, argv[3]);

    char dbuser[256];
    strcpy(dbuser, argv[4]);

    char dbname[256];
    strcpy(dbname, argv[5]);

    char passwd[256];
    printf("Enter user password to database\n");
    scanf("%s",passwd);
    
    //  Connecting to syslog
    //  openlog(argv[0], LOG_PID | LOG_PERROR, LOG_DAEMON);
    openlog(argv[0], LOG_CONS, LOG_DAEMON);

    //  Daemonize process
    daemon_init(argv[0]);

    //  create 2 buffers in round robin style to validate DCSS
    __u8 *buffer_begin_1;
    __u8 *buffer_begin_2;
    __u8 *buffer_end_1;
    __u8 *buffer_end_2;
    
    buffer_begin_1 = (__u8*) calloc(MONDCSS_SIZE * 2, sizeof(__u8));
        if (buffer_begin_1 == NULL) {
            syslog(LOG_ERR, "No free space in memory for buffers.");
            RUNNING = false;
            return 1;
        }
    buffer_begin_2 = buffer_begin_1 + MONDCSS_SIZE + 1;
    buffer_end_1 += MONDCSS_SIZE;
    buffer_end_2 += MONDCSS_SIZE * 2;

    __u8 *ptr_buffers_tab[2];
    ptr_buffers_tab[0] = &buffer_begin_1;
    ptr_buffers_tab[1] = &buffer_begin_2;

    //  create single thread for block read from /dev/monreader
    pthread_t br_thrd;
    pthread_create(&br_thrd, NULL, block_read, ptr_buffers_tab[]);
    
    //**************************************************************************
    //  MYSQL SPACE  BEGIN
    //  MYSQL DEFINE BEGIN
    //--------------------------------------------------------------------------
    MYSQL mysql;
    //**************************************************************************
    //  MYSQL CONNECTION BEGIN
    //--------------------------------------------------------------------------
    if (!mysql_init(&mysql)) {
        syslog(LOG_ALERT, "Cannot initialize MySQL Database Connection.");
        RUNNING = false;
        return 1;
    }

    if (!mysql_real_connect(&mysql, hostip, dbuser, passwd, dbname, 0, NULL, 0)) {
        syslog(LOG_ERR, "%d: %s \n", mysql_errno(&mysql), mysql_error(&mysql));
        RUNNING = false;
        return 1;
    }
    //**************************************************************************
    //  MYSQL CREATE TABLES IF NOT EXISTS
    //**************************************************************************
    rc = create_tables(&mysql);
    if (rc == 1) {
        RUNNING = false;
        return 1;
    }
    //**************************************************************************
    //  MYSQL INIT SPACE END
    //**************************************************************************

    __u8 *last_buffer;
    int rc = 0;
    while (RUNNING)
    {
        switch (NEW_ACTIVE_BUFFER)
        {
        case true:
            DB_INSERT_RUNNING = true;
            if (ACTIVE_BUFFER == buffer_begin_1 || ACTIVE_BUFFER == buffer_begin_2) {
                if (ACTIVE_BUFFER != last_buffer) {
                    last_buffer = ACTIVE_BUFFER;
                    rc = db_insert(&mysql, ACTIVE_BUFFER);
                    switch (rc)
                    {
                        case 0:
                            //  OK
                            break;
                        case 1:
                            /* code */
                            break;
                        default:
                            break;
                    }
                }
            } else if (ACTIVE_BUFFER == NULL) {
                //  first run
                DB_INSERT_RUNNING = false;  
                sleep(SLEEP_TIME * 5);
            } else {
                //  sth gone wrong abort!
                return 1;
            }
            DB_INSERT_RUNNING = false;    
            break;
        
        case false:
            if (DB_INSERT_RUNNING == true) {
                DB_INSERT_RUNNING = false;
            }
            break;
        }
        sleep(SLEEP_TIME);
    }

    mysql_close(&mysql);
    pthread_cancel(br_thrd);
    free(buffer_begin_1);
    closelog(); 
    return 0;
}
