# Dispenser Automatizado de Bala Dadinho (Sistemas Embarcados)

Este projeto foi desenvolvido para a **XXVI Mostra Técnica da ETEC Philadelpho Golvêa Netto** e consiste em um dispenser automatizado de balas Dadinho. Utilizando um **Arduino Uno**, o sistema combina programação em C++ com a integração de componentes eletrônicos para demonstrar o controle de hardware e a interação com o usuário através de um display LCD.

## Descrição do Projeto

O Dispenser Automatizado de Bala Dadinho é uma aplicação prática de sistemas embarcados, projetado para dispensar balas de forma controlada e interativa. O projeto passou por uma fase de prototipagem no Tinkercad para validação do circuito e da lógica antes da implementação física, garantindo a robustez e funcionalidade do sistema.

## Funcionalidades Implementadas

-   **Sistema de Controle:** Baseado em Arduino Uno, programado em C++.
-   **Interface com Usuário:** Através de um display LCD, fornecendo feedback visual e instruções.
-   **Mecanismo de Dispensação:** Automatizado com um servo motor para liberar as balas.
-   **Lógica de Controle:** Gerenciamento da quantidade dispensada e feedback visual para o usuário.
-   **Detecção de Presença:** Utiliza um sensor ultrassônico (HC-SR04) para detectar a aproximação de uma pessoa e iniciar o ciclo de dispensação.

## Tecnologias e Componentes Utilizados

| Categoria         | Tecnologia/Componente                               |
| :---------------- | :-------------------------------------------------- |
| **Microcontrolador** | Arduino Uno                                         |
| **Linguagem de Programação** | C++ (Arduino IDE)                                   |
| **Sensor**        | Sensor Ultrassônico HC-SR04 (detecção de distância) |
| **Atuador**       | Servo Motor (mecanismo de dispensação)              |
| **Interface**     | Display LCD I2C (16x2)                              |
| **Ferramentas de Simulação** | Tinkercad                                           |
| **Conectividade** | Fios Jumper, Protoboard                             |

## Estrutura do Projeto

```
Dispenser-Bala-Arduino/
├── mostratecnica.ino    # Código-fonte principal do Arduino
└── README.md            # Este arquivo
```

## Como Configurar e Rodar o Projeto

Para replicar e executar este projeto, siga os passos abaixo:

### Pré-requisitos

-   **Arduino IDE:** Software para programar o Arduino Uno.
-   **Bibliotecas Arduino:**
    -   `Servo.h`: Para controle do servo motor.
    -   `LiquidCrystal_I2C.h`: Para comunicação com o display LCD I2C.
-   **Componentes Físicos:**
    -   Arduino Uno
    -   Sensor Ultrassônico HC-SR04
    -   Servo Motor
    -   Display LCD I2C (16x2)
    -   Fios Jumper
    -   Protoboard (opcional, para montagem)
    -   Fonte de alimentação para o Arduino (USB ou externa)

### Diagrama de Circuito (Conceitual)

Conecte os componentes ao Arduino Uno da seguinte forma:

-   **Sensor Ultrassônico HC-SR04:**
    -   `VCC` ao `5V` do Arduino
    -   `GND` ao `GND` do Arduino
    -   `Trig` ao pino digital `9` do Arduino
    -   `Echo` ao pino digital `10` do Arduino

-   **Servo Motor:**
    -   `VCC` ao `5V` do Arduino
    -   `GND` ao `GND` do Arduino
    -   `Sinal` ao pino digital `6` do Arduino

-   **Display LCD I2C:**
    -   `VCC` ao `5V` do Arduino
    -   `GND` ao `GND` do Arduino
    -   `SDA` ao pino `A4` (SDA) do Arduino
    -   `SCL` ao pino `A5` (SCL) do Arduino

### Passos de Instalação e Execução

1.  **Instale o Arduino IDE:** Se ainda não tiver, baixe e instale o Arduino IDE do [site oficial](https://www.arduino.cc/en/software).

2.  **Instale as Bibliotecas:**
    -   No Arduino IDE, vá em `Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...`.
    -   Procure por `Servo` e instale a biblioteca oficial.
    -   Procure por `LiquidCrystal I2C` (ou `LiquidCrystal_I2C`) e instale a versão compatível com seu display.

3.  **Abra o Código:**
    -   Abra o arquivo `mostratecnica.ino` no Arduino IDE.

4.  **Conecte o Arduino:**
    -   Conecte seu Arduino Uno ao computador via cabo USB.
    -   No Arduino IDE, selecione a placa correta em `Ferramentas > Placa > Arduino Uno`.
    -   Selecione a porta serial correta em `Ferramentas > Porta`.

5.  **Carregue o Código:**
    -   Clique no botão `Upload` (seta para a direita) no Arduino IDE para compilar e carregar o código para o seu Arduino.

Após o upload, o dispenser deve iniciar, exibindo mensagens no LCD e aguardando a detecção de uma pessoa para dispensar as balas.

## Contribuição

Contribuições são bem-vindas! Se você tiver ideias para melhorias ou quiser corrigir algo, sinta-se à vontade para abrir issues ou enviar pull requests.


## Autor

-   **Julia Cancio** - [GitHub](https://github.com/juliacancio-dev)
-   **ETEC Philadelpho Golvêa Netto**
