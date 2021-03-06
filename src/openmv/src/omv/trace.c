#include "trace.h"
#include <stdint.h>

#define TRACEBUF_SIZE   (256)
typedef struct _tracebuf_t {
    uint8_t idx;
    uint8_t buf[TRACEBUF_SIZE];
}__attribute__((aligned(8))) tracebuf_t;

static tracebuf_t tracebuf;

void trace_init()
{
    tracebuf.idx = 0;
    for (int i=0; i<TRACEBUF_SIZE; i++) {
        tracebuf.buf[i] = 0;
    }
}

void trace_insert(uint32_t x)
{
    //__disable_irq();
    if (tracebuf.idx < TRACEBUF_SIZE) {
        tracebuf.buf[tracebuf.idx++] = x;
    }
    //__enable_irq();
}
