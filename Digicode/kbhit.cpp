#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <iostream>
using namespace std;
 
void set_mode(int want_key)
{
	static struct termios old, cur;
	if (!want_key) {
		tcsetattr(STDIN_FILENO, TCSANOW, &old);
		return;
	}
 
	tcgetattr(STDIN_FILENO, &old);
	cur = old;
	cur.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &cur);
}
 
int _kbhit()
{
	int c = 0;
	struct timeval tv;
	set_mode(1);
	fd_set fs;
	tv.tv_usec = tv.tv_sec = 0;
 
	FD_ZERO(&fs);
	FD_SET(STDIN_FILENO, &fs);
	select(STDIN_FILENO + 1, &fs, 0, 0, &tv);
 
	if (FD_ISSET(STDIN_FILENO, &fs)) {
		c = cin.get();
		set_mode(0);
	}
	return c;
}
