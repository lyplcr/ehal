#include <stdint.h>
#include <dev/gpio0.h> /* P1 */
#include <dev/gpio1.h> /* P2 */

void gpio0_irq(uint8_t v) {
	gpio0_set_to(P1, ~(v & P1));
}

void gpio1_irq(uint8_t v) {
	gpio1_set_to(P1, ~(v & P1));
}

__attribute__((used)) /* LTO is trying to remove main... */
int main(int argc, char *argv[]) {
	gpio0_ctor();
	gpio1_ctor();

	gpio0_set_in(P0);
	gpio0_set_pullup(P0);
	gpio0_set_edge_irq(P0,  0);
	gpio0_set_out(P1);

	gpio1_set_in(P0);
	gpio1_set_pullup(P0);
	gpio1_set_edge_irq(P0,  0);
	gpio1_set_out(P1);

	while (1);

	return 0;
}
