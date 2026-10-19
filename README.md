# Stream Deck com Raspberry Pi Pico

Esse projeto é um Stream Deck feito do zero usando uma Raspberry Pi Pico, com botões físicos que enviam atalhos de teclado diretamente para o computador. A ideia é ter uma alternativa mais simples e acessível para executar comandos e facilitar algumas tarefas do dia a dia.

## Impressão da case

O projeto da case que usei é da Bianca Rene pois foi o unico que encontrei com os parafusos, entretanto achei as teclas pequenas, por isso coloquei minhas proprias teclas no projeto.

<img width="1034" height="865" alt="Keys" src="https://github.com/user-attachments/assets/5e352b47-624d-4fa9-a5a9-ad0191f25f79" />

## Digrama de Pinos

Pinagem do projeto

<img width="890" height="880" alt="Pinos" src="https://github.com/user-attachments/assets/861eed5e-2e96-4bce-8b03-422a07edbba3" />


## Código do projeto

Para rodar esse código tive uma dificuldade com a IDE do Arduino porque precisamos de uma biblioteca em especifico: Arduino-Pico (Earle F. Philhower III) para habilitar a opção Tools → USB Stack

### Antes de rodar o código:

- Abra File → Preferences
- Em Additional boards manager URLs, adicione este endereço: https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
- Clique em OK e abra novamente Tools → Board → Boards Manager.
- Pesquise pico e procure Raspberry Pi Pico/RP2040/RP2350, de Earle F. Philhower, III. Clique em Install.

### Código: 

```ccp
#include <Keyboard.h>

const uint8_t buttons[] = {5, 6, 7, 8, 9, 10, 11, 12, 13};
const uint8_t keys[] = {
  KEY_F13, KEY_F14, KEY_F15,
  KEY_F16, KEY_F17, KEY_F18,
  KEY_F19, KEY_F20, KEY_F21
};

const int NUM_BUTTONS = 9;

void setup() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  Keyboard.begin();
}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(buttons[i]) == LOW) {
      Keyboard.press(keys[i]);
    } else {
      Keyboard.release(keys[i]);
    }
  }
}
```

## Referencia

Vídeo que usei de referencia para meu projeto, feito pela JuliaLabs

Link: https://youtu.be/X_ZKeOIq-ek?is=OyblXzS_RyrFmjbt
