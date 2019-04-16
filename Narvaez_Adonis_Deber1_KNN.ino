/*
 *          Universidad Técnica del Norte
 *                 FICA_CIERCOM
 */

#include "datos.h"
int col;
int fila = 0;
float datos_entrada [5] = {5.5,4.2,1.4,0.2,1}; //vector de nuevas instancias
float promedio;
float distancia;
int k=3;
float dist_menores[2][3];
int i = 0;
int j = 0;
float aux;
float aux1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (; i < k; i++) {
    dist_menores[0][i] = 4000 + i;
    dist_menores[1][i] = 0;
  }
  i = 0;
}

void loop() {
  for (; fila < 90; fila++) {
    for (col = 0; col < 4; col++) {
      promedio = promedio + (pow(datos_entrada[col] - matriz[col][fila], 2));
    }
    distancia = sqrt(promedio);
    promedio = 0;

    if (distancia < dist_menores[0][k - 1]){
      dist_menores[0][i] = distancia;
      
    }
for (i = 0; i < k; i++) {
      for (j = i + 1; j < k; j++) {
        if (dist_menores[0][i] > dist_menores[0][j]) {
          aux = dist_menores[0][i];
          dist_menores[0][i] = dist_menores[0][j];
          dist_menores[0][j] = aux;
          aux1 = dist_menores[1][i];
          dist_menores[1][i] = dist_menores[1][j];
          dist_menores[1][j] = aux1;
        }
      }
    }
  }
}
