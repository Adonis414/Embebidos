/*
   Universidad Técnica del Norte
          FICA-CIERCOM
          OPTATIVA II

   ADONIS NARVÁEZ
   08-05-2019

   REGRESIÓN LINEAL SIMPLE
*/

#include "datos.h"  //Llamamos al archivo datos.h

float prom_x, prom_y; //variables para guardar el valor del promedio de X y Y.
float sum_x, sum_y;   //cariables para guardar la sumatoria
int fila = 0; //variables oara recorrer las filas
float x1[29]; // vector para guardar la diferencia de xi-xpromedio
float y1[29]; // vector para guardar la diferencia de yi-ypromedio
float total1[29]; // vector para guardar la multiplicacion de (xi-xpromedio)*(yi-ypromedio)
float total2[29]; // vector para guardar (xi-xpromedio)^2
float SSxy; //variale para realizar la sumatoria
float SSxx; //variable para sumatoria
float m;  //pendiente
float Bo; //Ordenada al origen

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Iniciar comunicación serial
}

void loop() {

  //Ciclo para realizar la suamtoria y posteriormente el promedio
  for (; fila < 29; fila++) {
    sum_x = sum_x + matriz[fila][0];
    sum_y = sum_y + matriz[fila][1];
  }
  prom_x = sum_x / 29;
  prom_y = sum_y / 29;
  fila = 0;

  //ciclo para realizar las operaciones xi-xpromedio, yi-ypromedio
  for (; fila < 29; fila++) {
    x1[fila] = matriz[fila][0] - prom_x;
    y1[fila] = matriz[fila][1] - prom_y;
  }
  fila = 0;
  //ciclo para realizar las operaciones xi-xpromedio*yi-ypromedio , (xi-xpromedio)^2
  for (; fila < 29; fila++) {
    total1[fila] = x1[fila] * y1[fila];
    total2[fila] = pow(x1[fila], 2);
  }
  fila = 0;

  //ciclo para calular SSxy y SSxx
  for (; fila < 29; fila++) {
    SSxy = SSxy + total1[fila];
    SSxx = SSxx + total2[fila];
  }

  m = SSxy / SSxx; //calculo de la pendiente
  Bo = prom_y - m * prom_x; //claculo de la ordena al origen

Serial.print('y');
Serial.print(" = ");
Serial.print(m);
Serial.print("x");
Serial.println(Bo);

  delay(2000);
}
