O código acima configura o GPIO 22 do Raspberry Pi Pico para operar em modo PWM e controla um servo motor de um LED alterando gradualmente o duty cycle.
A variação ocorre de forma suave, aumentando e diminuindo entre um valor mínimo e máximo.


O código configura o PWM (Pulse Width Modulation) para controlar o brilho de um LED em um pino específico do Raspberry Pi Pico. 
A função `pwm_setup` realiza as seguintes etapas:

1. Define o pino como saída PWM: Configura o pino GPIO (22 no caso) para operar como uma saída de PWM.
2. Obtém o canal PWM correspondente: Identifica o "slice" PWM associado ao pino para que o controle do PWM seja aplicado corretamente.
3. Configura o divisor do clock do PWM: Ajusta a frequência do sinal PWM dividindo o clock de base, permitindo maior controle sobre a frequência do sinal PWM.
4. Define o valor de "wrap" do PWM: Estabelece o valor máximo do contador, determinando a duração do ciclo do PWM.
5. Define um duty cycle inicial: Inicializa o ciclo de trabalho do PWM com um valor de 6667, o que determina o brilho inicial do LED.
6. Habilita o PWM: Ativa o módulo PWM para começar a gerar o sinal de controle no pino.

Essa configuração permite o controle preciso da intensidade do LED, ajustando dinamicamente o duty cycle dentro de um intervalo desejado.

[🔗 Link para o vídeo do ensaio (duração máx. de 3 minutos)](https://drive.google.com/file/d/1exio7WZsGGRRmU7gCB9wktFo6baMfE-R/view?usp=drive_link)

