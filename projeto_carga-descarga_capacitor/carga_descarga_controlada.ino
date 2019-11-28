int chave_carga=6;
int chave_descarga=7;
int pino_rele1=10;
int pino_rele2=11;

bool ligar_rele = LOW;
bool desligar_rele = ~ligar_rele;

void setup() {
  Serial.begin(9600);
  pinMode ( chave_carga, OUTPUT);
  pinMode ( chave_descarga, OUTPUT);
  digitalWrite ( chave_carga, HIGH);
  digitalWrite ( chave_descarga, HIGH);
}

void tratador(String cmd){
  /* Vai receber 2 ou mais caraceters. O primeiro indica se é carga ou descarga.
   *  Do segundo em diante é o tempo em segundos que o sistema fica ligado.
   *  Exemplo: c120
   *  c - carga
   *  120 - 120 segundos carregando
   *  Exemplo: d3
   *  d - descarga
   *  3 - 3 segundos carregado
   */
  char carga = cmd[0];
  char rele1 = cmd[1];
  char rele2 = cmd[2];
  String duracao_tempo_str = cmd.substring(3);
  int duracao_tempo = duracao_tempo_str.toInt();
  int rele_escolhido = (carga == 'c') ? chave_carga : chave_descarga;
  if(rele1 == '1'){
    digitalWrite (pino_rele1, ligar_rele);
    Serial.println("Rele 1 ligado");
  }else{
    digitalWrite (pino_rele1, desligar_rele);
    Serial.println("Rele 1 desligado");
  }
  Serial.print("Rele 1: ");
  Serial.println(rele1);


  if(rele2 == '1'){
    digitalWrite (pino_rele2, ligar_rele);
    Serial.println("Rele 2 ligado");
  }else{
    digitalWrite (pino_rele2, desligar_rele);
    Serial.println("Rele 2 desligado");
  }
  Serial.print("Rele 2: ");
  Serial.println(rele2);

  
  Serial.print("Rele escolhido: ");
  Serial.println(rele_escolhido);

 
  digitalWrite ( rele_escolhido, ligar_rele);
  delay(duracao_tempo*1000);
  digitalWrite ( rele_escolhido, desligar_rele);
}

void loop() {
  if (Serial.available() > 0) {
     String cmd = Serial.readString();
     tratador(cmd);
  }

}
