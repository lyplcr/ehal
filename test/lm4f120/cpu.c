#include <dev/cpu0.h>

int main(int argc, char *argv[])
{
	cpu0_ctor();
	cpu0_dtor();
	return 0;
}
