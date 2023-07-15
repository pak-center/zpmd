#ifndef _DB_INSERT_H
#define	_DB_INSERT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <mysql.h>

int db_insert(MYSQL *mysql, __u8 *buff);

#ifdef	__cplusplus
}
#endif

#endif
