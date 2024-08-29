const int ESQfrente = 5;
const int ESQtras = 6;
// esquerda frente e esquerda tras = motor esquerdo

const int DIRfrente = 9;
const int DIRtras = 10;
// direita frente e direita tras = motor direito

const int AnalogEsq = A1;
const int AnalogDir = A0;
// analog esquerda e analog direita = conexoes analogicas dos sensores

const int limiar = 400;
//limiar = condiçao da leitura dos sensores, caso seja menos que 400 é 
//uma superficie bramca e caso seja maior que 400 é uma superficie preta 

void setup() {
  pinMode(ESQfrente,OUTPUT);
  pinMode(ESQtras,OUTPUT);
  pinMode(DIRfrente,OUTPUT);
  pinMode(DIRtras,OUTPUT);

  Serial.begin(9600);  //valor para inicializaçao das leituras digitais, ou seja, as leituras dos sensores
}

void loop(){
  int leituraEsq = analogRead(AnalogEsq);
  int leituraDir = analogRead(AnalogDir);

  if(leituraEsq < limiar && leituraDir < limiar){  //condiçao que faz o robo andar para frente
    AndarFrente();
  }

  else if(leituraEsq < limiar && leituraDir >= limiar){ //condiçao que faz o robo virar para a direita
    VirarDireita();
  }  

  else if(leituraEsq >= limiar && leituraDir < limiar){  // condiçao que faz o robo virar para a esquerda
    VirarEsquerda();
  }

  else if(leituraEsq >= limiar && leituraDir >= limiar){ // condiçao que faz o robo parar
    Parar();
  }

  delay(100);    // delay aplicado para reinicializar a leitura do loop sem conflito entre as leituras anteriores

}

void AndarFrente(){               // funçao que faz os motores ligarem quando eu quiser que o robo ande para frente.
  digitalWrite(ESQfrente, HIGH);
  digitalWrite(ESQtras, LOW);
  digitalWrite(DIRfrente, HIGH);
  digitalWrite(DIRtras, LOW);
}

void VirarDireita(){              // funçao que faz os motores ligarem quando eu quiser que o robo vire para a direita.
  digitalWrite(ESQfrente, HIGH);
  digitalWrite(ESQtras, LOW);
  digitalWrite(DIRfrente, LOW);
  digitalWrite(DIRtras, HIGH);
}

void VirarEsquerda(){            // funçao que faz os motores ligarem quando eu quiser que o robo vire para a esquerda.
  digitalWrite(ESQfrente, LOW);
  digitalWrite(ESQtras, HIGH);
  digitalWrite(DIRfrente, HIGH);
  digitalWrite(DIRtras, LOW);
}

void Parar(){                    // funçao que faz os motores pararem o funcionamento e deixar o robo parado poor completo.
  digitalWrite(ESQfrente, LOW);
  digitalWrite(ESQtras, LOW);
  digitalWrite(DIRfrente, LOW);
  digitalWrite(DIRtras, LOW);
}