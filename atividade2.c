#include <stdio.h>
#include "pico/stdlib.h"

#define azul 11
#define verd 12
#define verm 13
#define botao 5

volatile bool verif0 = true; // variavel de controle do acionamento do botão
volatile bool verif  = true; // variavel de controle do callback
volatile int  cont   = 0;

void config_gpio(){
    gpio_init(verm);
    gpio_set_dir(verm,GPIO_OUT);
    gpio_init(azul);
    gpio_set_dir(azul,GPIO_OUT);
    gpio_init(verd);
    gpio_set_dir(verd,GPIO_OUT);
    gpio_init(botao);
    gpio_set_dir(botao,GPIO_IN);
    gpio_pull_up(botao);

}
int64_t alarm_callback(alarm_id_t id, __unused void *user_data) {

    if (cont == 0) {
        gpio_put(azul, false);
    }
    if (cont == 1) {
        gpio_put(verd, false);
    }
    if (cont == 2) {
        gpio_put(verm, false);
        cont = -1; // Reinicia o contador corretamente
        verif = false;
        verif0 = true;
    }
    add_alarm_in_ms(1000,alarm_callback,NULL,verif);
    cont++;
    return 0;
}
void inicio(uint gpio, uint32_t events0){
    if (verif0){
    verif0 = false;
    verif  = true;
    gpio_put(verd,true);
    gpio_put(verm,true);
    gpio_put(azul,true);
    add_alarm_in_ms(1000,alarm_callback,NULL,verif);
    }
}


int main()
{  
    config_gpio();
    gpio_set_irq_enabled_with_callback(botao,GPIO_IRQ_EDGE_FALL,true, &inicio);
    //tight_loop_contents(); // Mantém o programa rodando 
    
    
}
