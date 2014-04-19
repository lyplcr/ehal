#include <stdint.h>
#include <dev/cpu0.h>
#include <dev/gpio0.h>
#include <dev/gpio1.h>

void gpio0_irq(uint8_t v) {
	gpio0_set_to(P1, ~(gpio0_read() & P1));
}

__attribute__((used)) /* LTO is trying to remove main... */
int main(int argc, char *argv[]) {
	cpu0_ctor();
	gpio0_ctor();

	gpio0_set_in(P0);

	gpio0_set_out(P1);
	gpio0_set_edge_irq(P0,  0);

	while (1);

	return 0;
}
