
#include <stdio.h> 
#include "pico/stdlib.h" 
#include "hardware/pwm.h" 

#define PWM 22 //pino do LED conectado a GPIO como PWM
const uint16_t WRAP_PERIOD = 55556; //valor máximo do contador - WRAP
const float PWM_DIVISER = 45.0; //divisor do clock para o PWM
const uint16_t LED_STEP = 5; //passo de incremento/decremento para o duty cycle do LED
uint16_t led_level = 1000; //nível inicial do pwm (duty cycle)

 uint up_down = 1; //variável para controlar se o nível do LED aumenta ou diminui


//função para configurar o módulo PWM
void pwm_setup()
{
gpio_set_function(PWM, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

uint slice = pwm_gpio_to_slice_num(PWM); //obter o canal PWM da GPIO
pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM

pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap

pwm_set_gpio_level(PWM, 6667); //definir o cico de trabalho (duty cycle) do pwm

pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
}



void sweep_servo() {
    if (up_down) //condição para elevação/redução do ciclo de trabalho.
 {
 led_level += LED_STEP; // Incrementa o nível do LED
 if (led_level >= 7000)
 up_down = 0; // Muda direção para diminuir quando atingir o período máximo
 }
 else
 {
 led_level -= LED_STEP; // Decrementa o nível do LED
 if (led_level <= 1300)
 up_down = 1; // Muda direção para aumentar quando atingir o mínimo
 }
}

//função principal
int main()
{
stdio_init_all(); //inicializa o sistema padrão de I/O

pwm_setup(); //configura o PWM

sleep_ms(5000);
pwm_set_gpio_level(PWM, 4083);
sleep_ms(5000);
pwm_set_gpio_level(PWM, 1389);
sleep_ms(5000);

uint up_down = 1; //variável para controlar se o nível do LED aumenta ou diminui

//loop principal
while (true) {

    printf("Ciclo ativo:%d\n", led_level);//imprimir ciclo ativo do PWM - valor máximo é 2000

    pwm_set_gpio_level(PWM, led_level); //define o nível atual do PWM (duty cycle)
    sleep_ms(10); // Adiciona um pequeno atraso para maior suavidade na mudança
    sweep_servo();

}
    
}
