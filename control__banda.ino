int pot_velocidad = A0;
int motor_banda = 9;
int sensor_inicio = 10;
int sensor_final = 11;

void setup() {
  pinMode(motor_banda, OUTPUT);
  pinMode(pot_velocidad, INPUT);
  pinMode(sensor_inicio, INPUT);
  pinMode(sensor_final, INPUT);
}

void control_banda() {
    //Inicializacion de las variables
     int valor_sensor_inicio = 0;
     int valor_salida_pwm = 0;
     estado = digitalRead (sensor_inicio);

     //Lectura del sensor de inicio
     if (estado == LOW ){
        digitalWrite (motor, 80);
        valor_pot = analogRead(pot_velocidad);
        valor_salida_pwm = map(valor_pot, 0, 1023, 0, 255);
     }
      
      // Guardamos la lectura analogica en la variable (valor_entrada_analógica)
      valor_salida_pwm =map(valor_entrada_analogica,0, 1023,0,255); // guardamos el mapeo en la variable (valor salida)
      analogWrite(motor, valor_salida_pwm); 
      
      //Lectura sensor-final
        final = digitalRead(sensor_final);
        if(final == LOW){
          digitalWrite(motor_banda, 0);
        }
  }
  
