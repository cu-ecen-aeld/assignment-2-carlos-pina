#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
  openlog (argv[0], LOG_PID | LOG_CONS, LOG_USER);

  if (argc < 3)
  {
    syslog (LOG_ERR, "Two arguments required.");
    closelog ();
    return 1;
  }

  int fd = open (argv[1], O_RDWR | O_CREAT, 0644);
  if (fd == -1)
  {
    syslog (LOG_ERR, "Open failed.");
    closelog ();
    return 1;
  }

  syslog (LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

  const char *buf = argv[2];
  int nr = write (fd, buf, strlen (buf));
  if (nr == -1)
  {
    syslog (LOG_ERR, "Write failed.");
    closelog ();
    return 1;
  }

  int cl = close (fd);
  if (cl == -1)
  {
    syslog (LOG_ERR, "Close failed.");
    closelog ();
    return 1;
  }

  closelog ();
  return 0;
}
