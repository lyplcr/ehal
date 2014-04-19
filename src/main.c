#include <stdint.h>
#include <dev/cpu0.h>

void gpio0_irq(uint8_t v) {
}

__attribute__((used))
int main(int argc, char *argv[]) {
	cpu0_ctor();
#if 0
	gpio0_ctor();
	gpio0_in(P0);
	gpio0_out(P1);

	gpio0_set(P1);
	gpio0_clr(P1);

	gpio0_set(P1, P1);

	gpio0_irq_on_edges(P0, 0);
#endif
	return 0;
}
