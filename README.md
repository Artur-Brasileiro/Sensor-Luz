# 💡 Monitor de Luminosidade com Feedback Visual (LDR + Arduino)

Um projeto prático de sistemas embarcados que monitora o nível de luz ambiente utilizando um sensor LDR e fornece feedback visual em tempo real através de um semáforo de LEDs. 

Este projeto demonstra conceitos fundamentais de eletrônica analógica (Divisor de Tensão), leitura de conversores ADC (Analog-to-Digital Converter) e controle lógico de atuadores baseados em limiares (thresholds).

## 🛠️ Hardware Utilizado

* 1x Placa Arduino (Uno, Nano ou Mega)
* 1x Sensor de Luz LDR (Light Dependent Resistor)
* 1x Resistor de 10kΩ (Para o divisor de tensão)
* 3x LEDs (Verde, Amarelo e Vermelho)
* 3x Resistores de 220Ω ou 330Ω (Para proteção dos LEDs)
* Protoboard e Jumpers

## ⚙️ Arquitetura do Circuito

O coração da leitura analógica baseia-se em um **Divisor de Tensão**. O pino analógico (`A0`) do Arduino é conectado no nó central entre o LDR (ligado ao 5V) e o resistor pull-down de 10kΩ (ligado ao GND). 

* **Luz Alta:** A resistência do LDR cai, a tensão no nó central sobe (leitura ADC próxima a 419).
* **Luz Baixa:** A resistência do LDR sobe, a tensão no nó central cai (leitura ADC próxima a 80).

Os LEDs estão conectados nas portas digitais `8`, `9` e `10`, configurados como `OUTPUT`.

## 🚦 Lógica de Funcionamento

O sistema categoriza a luminosidade do ambiente em três faixas e aciona o LED correspondente:

1.  🟢 **LED Verde (Luz Alta):** Leitura ADC >= 350. (Ambiente totalmente iluminado).
2.  🟡 **LED Amarelo (Luz Média):** Leitura ADC entre 151 e 349. (Meia-luz ou penumbra).
3.  🔴 **LED Vermelho (Luz Baixa):** Leitura ADC <= 150. (Ambiente escuro).

## 🚀 Como Executar

1.  Monte o circuito na protoboard conforme a descrição acima.
2.  Clone este repositório ou baixe o arquivo `.ino`.
3.  Abra o código na **Arduino IDE** (totalmente compatível com ambientes Linux, Windows ou macOS).
4.  Selecione a porta serial correta (ex: `/dev/ttyACM0` ou `COM3`) e a sua placa.
5.  Faça o upload do código.
6.  Abra o **Monitor Serial** (baud rate `9600`) para acompanhar as leituras em tempo real.

---
*Desenvolvido por Artur — Estudante do 8º período de Engenharia da Computação na UEMG.*
