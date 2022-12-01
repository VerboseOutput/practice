#include <stdint.h>

#define TIMER_ADDR 0x1000

uint32_t get_reg_val(uintptr_t address) {
    uint32_t volatile *reg_ptr = (uint32_t volatile *)address;

    return *reg_ptr;
}


#define ATTEMPTS 100

uint64_t get_timer_val() {
    uint32_t top_half_before;
    uint32_t top_half_after;
    uint32_t bottom_half;
    
    for(int i=0; i<ATTEMPTS; i++) {
        top_half_before = get_reg_val(TIMER_ADDR + 4);
        bottom_half = get_reg_val(TIMER_ADDR);
        top_half_after = get_reg_val(TIMER_ADDR + 4);

        if(top_half_before == top_half_after) break;
    }

    if(top_half_before != top_half_after) {
        // handle error
        return;
    }

    return ((uint64_t)top_half_after << 32) | bottom_half;
    
}