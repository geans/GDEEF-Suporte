int chave_carga=7;
int chave_descarga=6;

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
  String duracao_tempo_str = cmd.substring(1);
  int duracao_tempo = duracao_tempo_str.toInt();
  int rele_escolhido = (carga == 'c') ? chave_carga : chave_descarga;
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
