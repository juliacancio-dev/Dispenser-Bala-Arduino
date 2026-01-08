*-3,
/#include <Servo.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 9;       // Pino TRIG do HC-SR04
const int echoPin = 10;      // Pino ECHO do HC-SR04
const int servoPin = 6;      // Pino de controle do servo

Servo servo;  // Objeto para o servo
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variáveis de controle de estado
enum Estado {
  AGUARDANDO,           // Aguardando pessoa se aproximar
  SERVO_ATIVO,          // Servo liberando balas
  CICLO_COMPLETO        // Ciclo completo, aguardando pessoa sair
};

Estado estadoAtual = AGUARDANDO;
Estado estadoAnterior = CICLO_COMPLETO; // Para detectar mudanças
unsigned long tempoInicio = 0;
bool pessoaDetectada = false;

void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  // Conecta o servo ao pino digital
  servo.attach(servoPin);

  // Configura os pinos do sensor ultrassônico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Posição inicial do servo
  servo.write(0);

  // Mensagem inicial no LCD
  atualizarLCD();

  Serial.println("Dispenser de balas iniciado!");
}

void loop() {
  // Lê a distância do sensor ultrassônico
  float distancia = lerDistancia();

  // Verifica se há pessoa próxima (15cm ou menos)
  bool pessoaProxima = (distancia <= 15 && distancia > 0);

  // Exibe informações no monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm | Estado: ");
  Serial.println(obterNomeEstado());

  // Máquina de estados
  switch (estadoAtual) {
    case AGUARDANDO:
      if (pessoaProxima && !pessoaDetectada) {
        // Pessoa se aproximou, inicia o ciclo
        estadoAtual = SERVO_ATIVO;
        tempoInicio = millis();
        servo.write(90);  // Ativa servo para liberar balas
        pessoaDetectada = true;
        Serial.println("=== INICIANDO CICLO ===");
        Serial.println("Servo: Liberando balas...");
      }
      break;

    case SERVO_ATIVO:
      if (millis() - tempoInicio >= 1000) {  // 1 segundo de liberação
        // Para servo e completa ciclo
        servo.write(0);
        estadoAtual = CICLO_COMPLETO;
        tempoInicio = millis(); // Marca tempo para iniciar contagem da recarga
        Serial.println("Servo: Retornando à posição inicial");
        Serial.println("=== CICLO COMPLETO ===");
      }
      break;

    case CICLO_COMPLETO:
      if (millis() - tempoInicio >= 3000) {  // Espera 3 segundos de recarga
        if (!pessoaProxima) {
          // Pessoa saiu e tempo de recarga passou, pronto para novo ciclo
          estadoAtual = AGUARDANDO;
          pessoaDetectada = false;
          Serial.println("Sistema pronto para novo ciclo!");
          Serial.println("------------------------");
        }
      }
      // Se pessoa ainda estiver próxima, continua aguardando
      break;
  }

  // Atualiza LCD apenas quando o estado muda
  if (estadoAtual != estadoAnterior) {
    atualizarLCD();
    estadoAnterior = estadoAtual;
  }

  delay(50);  // Pequeno delay para evitar leituras excessivas
}

void atualizarLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);

  switch (estadoAtual) {
    case AGUARDANDO:
      lcd.print("DISPENSER PRONTO");
      lcd.setCursor(0, 1);
      lcd.print("Aproxime-se...");
      break;

    case SERVO_ATIVO:
      lcd.print("LIBERANDO BALAS");
      lcd.setCursor(0, 1);
      lcd.print("Aguarde... ");
      break;

    case CICLO_COMPLETO:
      lcd.print("PRONTO!");
      lcd.setCursor(0, 1);
      lcd.print("Retire as balas");
      break;
  }
}

float lerDistancia() {
  // Envia um pulso de 10 microsegundos para o pino TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê o tempo de resposta do pino ECHO
  long duracao = pulseIn(echoPin, HIGH);

  // Calcula a distância com base no tempo de resposta
  float distancia = duracao * 0.034 / 2;

  return distancia;
}

String obterNomeEstado() {
  switch (estadoAtual) {
    case AGUARDANDO: return "AGUARDANDO";
    case SERVO_ATIVO: return "SERVO_ATIVO";
    case CICLO_COMPLETO: return "CICLO_COMPLETO";
    default: return "DESCONHECIDO";
  }
}
