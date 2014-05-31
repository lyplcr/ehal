#include <stdint.h>
#include <dev/gpio0.h>

__attribute__((used)) /* LTO is trying to remove main... */
int main(int argc, char *argv[]) {
	while (1);

	return 0;
}
