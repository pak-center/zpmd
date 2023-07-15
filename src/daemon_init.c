#include "daemon_init.h"
#include <signal.h>

static void daemon_init(const char *name)
{
pid_t pid;
int i;

if (pid = fork() != 0) exit(0);

setsid();
signal(SIGHUP, SIG_IGN);

if ((pid = fork()) != 0) exit(0);

chdir("/");
umask(0);
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);
}
