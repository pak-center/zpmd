#include "create_tables.h"
#include <mysql.h>

int create_tables(MYSQL *mysql) {
    //  MYSQL CREATE TABLES BEGIN
    //  DOMAIN-0
    //  d0r1
    if (mysql_query(&mysql, query_create_d0r1))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    return 1;
    }
    //d0r2
    if (mysql_query(&mysql, query_create_d0r2))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    return 1;
    }
    //d0r3
    if (mysql_query(&mysql, query_create_d0r3))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d0r4
    if (mysql_query(&mysql, query_create_d0r4))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d0r5
    if (mysql_query(&mysql, query_create_d0r5))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d0r6
    if (mysql_query(&mysql, query_create_d0r6))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d0r7
    if (mysql_query(&mysql, query_create_d0r7))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }

    //d0r11
    if (mysql_query(&mysql, query_create_d0r11))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d0r12
    if (mysql_query(&mysql, query_create_d0r12))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d0r13
    if (mysql_query(&mysql, query_create_d0r13))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d0r14
    if (mysql_query(&mysql, query_create_d0r14))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d0r15
    if (mysql_query(&mysql, query_create_d0r15))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d0r21
    if (mysql_query(&mysql, query_create_d0r21))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d0r22
    if (mysql_query(&mysql, query_create_d0r22))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }

    //DOMAIN-1
    //d1r1
    if (mysql_query(&mysql, query_create_d1r1))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d1r3
    if (mysql_query(&mysql, query_create_d1r3))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d1r4
    if (mysql_query(&mysql, query_create_d1r4))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d1r5
    if (mysql_query(&mysql, query_create_d1r5))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d1r9
    if (mysql_query(&mysql, query_create_d1r9))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d1r10
    if (mysql_query(&mysql, query_create_d1r10))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d1r12
    if (mysql_query(&mysql, query_create_d1r12))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d1r13
    if (mysql_query(&mysql, query_create_d1r13))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d1r17
    if (mysql_query(&mysql, query_create_d1r17))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d1r18
    if (mysql_query(&mysql, query_create_d1r18))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d1r20
    if (mysql_query(&mysql, query_create_d1r20))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }


    //DOMAIN-2
    //d2r1
    if (mysql_query(&mysql, query_create_d2r1))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d2r2
    if (mysql_query(&mysql, query_create_d2r2))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d2r3
    if (mysql_query(&mysql, query_create_d2r3))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    /*
    //d2r4
    if (mysql_query(&mysql, query_create_d2r4))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d2r5
    if (mysql_query(&mysql, query_create_d2r5))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d2r6
    if (mysql_query(&mysql, query_create_d2r6))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    */
    //d2r9
    if (mysql_query(&mysql, query_create_d2r9))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d2r10
    if (mysql_query(&mysql, query_create_d2r10))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d2r11
    if (mysql_query(&mysql, query_create_d2r11))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d2r12
    if (mysql_query(&mysql, query_create_d2r12))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }

    //DOMAIN-3
    //d3r1
    if (mysql_query(&mysql, query_create_d3r1))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r2
    if (mysql_query(&mysql, query_create_d3r2))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r3
    if (mysql_query(&mysql, query_create_d3r3))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r4
    if (mysql_query(&mysql, query_create_d3r4))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r5
    if (mysql_query(&mysql, query_create_d3r5))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r6
    if (mysql_query(&mysql, query_create_d3r6))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r7
    if (mysql_query(&mysql, query_create_d3r7))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r8
    if (mysql_query(&mysql, query_create_d3r8))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r9
    if (mysql_query(&mysql, query_create_d3r9))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r10
    if (mysql_query(&mysql, query_create_d3r10))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r11
    if (mysql_query(&mysql, query_create_d3r11))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r12
    if (mysql_query(&mysql, query_create_d3r12))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r13
    if (mysql_query(&mysql, query_create_d3r13))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r14
    if (mysql_query(&mysql, query_create_d3r14))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r15
    if (mysql_query(&mysql, query_create_d3r15))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }

    //d3r16
    if (mysql_query(&mysql, query_create_d3r16))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r17
    if (mysql_query(&mysql, query_create_d3r17))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r18
    if (mysql_query(&mysql, query_create_d3r18))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r19
    if (mysql_query(&mysql, query_create_d3r19))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d3r20
    if (mysql_query(&mysql, query_create_d3r20))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }

    //DOMAIN-4
    //d4r5
    if (mysql_query(&mysql, query_create_d4r5))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d4r6
    if (mysql_query(&mysql, query_create_d4r6))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d4r7
    if (mysql_query(&mysql, query_create_d4r7))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    /*
    //d4r9
    if (mysql_query(&mysql, query_create_d4r9))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    */
    //d4r10
    if (mysql_query(&mysql, query_create_d4r10))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }


    //DOMAIN-5
    //d5r1
    if (mysql_query(&mysql, query_create_d5r1))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d5r2
    if (mysql_query(&mysql, query_create_d5r2))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d5r3
    if (mysql_query(&mysql, query_create_d5r3))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }

    //d5r6
    if (mysql_query(&mysql, query_create_d5r6))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d5r7
    if (mysql_query(&mysql, query_create_d5r7))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d5r8
    if (mysql_query(&mysql, query_create_d5r8))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d5r9
    if (mysql_query(&mysql, query_create_d5r9))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }

    //d5r11
    if (mysql_query(&mysql, query_create_d5r11))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d5r12
    if (mysql_query(&mysql, query_create_d5r12))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }



    //DOMAIN-6
    //d6r2
    if (mysql_query(&mysql, query_create_d6r2))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r6
    if (mysql_query(&mysql, query_create_d6r6))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r7
    if (mysql_query(&mysql, query_create_d6r7))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r8
    if (mysql_query(&mysql, query_create_d6r8))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r12
    if (mysql_query(&mysql, query_create_d6r12))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r13
    if (mysql_query(&mysql, query_create_d6r13))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r14
    if (mysql_query(&mysql, query_create_d6r14))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r15
    if (mysql_query(&mysql, query_create_d6r15))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r17
    if (mysql_query(&mysql, query_create_d6r17))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r22
    if (mysql_query(&mysql, query_create_d6r22))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r23
    if (mysql_query(&mysql, query_create_d6r23))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r24
    if (mysql_query(&mysql, query_create_d6r24))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r25
    if (mysql_query(&mysql, query_create_d6r25))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r26
    if (mysql_query(&mysql, query_create_d6r26))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r27
    if (mysql_query(&mysql, query_create_d6r27))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r28
    if (mysql_query(&mysql, query_create_d6r28))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r29
    if (mysql_query(&mysql, query_create_d6r29))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d6r30
    if (mysql_query(&mysql, query_create_d6r30))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }

    //DOMAIN-7
    //d7r1
    if (mysql_query(&mysql, query_create_d7r1))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }

    //DOMAIN-8
    //d8r1
    if (mysql_query(&mysql, query_create_d8r1))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d8r2
    if (mysql_query(&mysql, query_create_d8r2))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }
    //d8r3
    if (mysql_query(&mysql, query_create_d8r3))
    {
    syslog(LOG_ERR, "%s\n", mysql_error(&mysql));
    exit(1);
    }

}
