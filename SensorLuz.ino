// Definição dos pinos
const int pinoLDR = A0;
const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;

void setup() {
  Serial.begin(9600);
  
  // Configura os pinos dos LEDs como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  int valorLuz = analogRead(pinoLDR); // Lê o valor atual do sensor
  
  Serial.print("Nível de luz atual: ");
  Serial.println(valorLuz);

  // Primeiro, apagamos todos os LEDs para evitar que mais de um fique aceso
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  // Verifica em qual faixa a leitura se encaixa e acende o LED correspondente
  if (valorLuz >= 350) {
    // Ambiente claro (próximo aos 419)
    digitalWrite(ledVerde, HIGH);
    
  } else if (valorLuz <= 150) {
    // Ambiente escuro (próximo aos 80-85)
    digitalWrite(ledVermelho, HIGH);
    
  } else {
    // Ambiente com luz mediana (entre 151 e 349)
    digitalWrite(ledAmarelo, HIGH);
  }

  delay(200); // Pequena pausa para estabilizar as leituras
}