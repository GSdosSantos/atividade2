CEPeDI - Embarcateh - Moodle

Autor

Este código foi desenvolvido por Gabriel Santos dos Santos.
Matrícula: tic370101356

Descrição

Este projeto implementa um sistema de controle de LEDs utilizando um botão para iniciar um ciclo de iluminação sequencial. O código é desenvolvido para a plataforma Raspberry Pi Pico e faz uso da biblioteca pico/stdlib.h.

Funcionamento:

* O botão conectado ao GPIO 5 inicia a sequência quando pressionado.
* Os LEDs são conectados aos pinos GPIO 11 (azul), GPIO 12 (verde) e GPIO 13 (vermelho).
* O sistema segue a seguinte lógica:
* Ao pressionar o botão, todos os LEDs são acionados.
* A cada 3 segundos, um LED é apagado em sequência.
* Após apagar o LED vermelho, o sistema reinicia e espera novo acionamento.

Estrutura do Código:

* config_gpio: Inicializa os pinos GPIO para os LEDs e o botão.

* alarm_callback: Função chamada pelo temporizador que controla o desligamento sequencial dos LEDs.

* inicio: Função chamada pela interrupção do botão para iniciar a sequência de iluminação.

* main: Configura os pinos e ativa a interrupção do botão.

Requisitos:

* Placa Raspberry Pi Pico

* LEDs conectados aos GPIOs 11, 12 e 13

* Botão conectado ao GPIO 5 com pull-up interno

* Biblioteca pico/stdlib.h

* Execução no Wokwi Simulador

Para executar este código no simulador Wokwi:

* Acesse o arquivo 'diagram.json' e click no botão play (verde).

