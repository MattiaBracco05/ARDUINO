//VARIABILI-COSTANTI PER IL CONTROLLO DELL'ATTIVAZIONE E DISATTIVAZIONE DELLA CONCIMATURA
const int Att_Ora_C = 12; //Ora di attivazione luci
const int Att_Min_C = 00; //Minuti di attivazione Luci
const int Att_Sec_C = 00; //Secondi di attivazione Luci

const int Dis_Ora_C = 12; //Ora di disattivazione Luci
const int Dis_Min_C = 00; //Minuti di disattivazione Luci
const int Dis_Sec_C = 10; //Secondi di disattivazione Luci

void Conc(){
  if(dt.hour == Att_Ora_C && dt.minute == Att_Min_C && dt.second == Att_Sec_C){
    digitalWrite(Rele_Conc, LOW);
    Serial.println("-- Concimatura attivata");
    lcd.setCursor(6, 3);
    lcd.print("1");
    }
  if(dt.hour == Dis_Ora_C && dt.minute == Dis_Min_C && dt.second == Dis_Sec_C){
    digitalWrite(Rele_Conc, HIGH);
    Serial.println("-- Concimatura disattivata");
    lcd.setCursor(6, 3);
    lcd.print("0");
    }
  }
