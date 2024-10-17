# ESP32 Wi-Fi Relay Control 🔥

Este projeto foi feito para quem curte automação e quer controlar dois relés usando **ESP32** e **Wi-Fi**. Simples, prático e eficiente.

## O que rola nesse projeto

- Controle **Wi-Fi** para dois relés.
- ESP32 se conectando à rede e recebe os comandos via HTTP.
- Ideal pra automação de qualquer coisa que você queira ligar/desligar, tipo lâmpadas, ventiladores, cafeteiras... ou seja, controle total na palma da mão.

## O Básico dos Componentes

- **ESP32** – o cérebro.
- **2 Módulos Relé** – os músculos.
- **Wi-Fi** – a magia que conecta tudo.

### Diagrama de Conexão

| ESP32 Pin | Relé Pin |
| --------- | -------- |
| D5        | IN1      |
| D13       | IN2      |
| GND       | GND      |
| 5V        | VCC      |

## Como Funciona

1. O ESP32 se conecta ao Wi-Fi.
2. Cria um servidor web simples.
3. Você acessa o endereço do ESP via browser e aciona os relés.

### Como usar?

Depois que subir o código e depois só acessar o IP do ESP32 no navegador.

## O que mais dá pra fazer?

- Dá pra expandir pra mais relés.
- Criar um app mobile pra facilitar.
- Usar MQTT pra integração com automação residencial..

---

_Feito com ❤️ por [me](https://github.com/joaopedro5g)_ 😎
