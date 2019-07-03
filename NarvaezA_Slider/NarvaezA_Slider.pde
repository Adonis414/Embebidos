import controlP5.*;
import processing.serial.*;
Serial port;
ControlP5 cp5;
int con=0;

int on=0;
String envio;
String dato;
int conversor;
int conversor2;

void setup() {
  size(400, 350);
  noStroke();
  background(0);
  cp5=new ControlP5(this);

  cp5.addButton("CONECTAR")
    .setPosition(40, 50)
    .setSize(80, 40);

  cp5.addSlider("CONVERSOR1")
    .setPosition(210, 50)
    .setSize(50, 175)
    .setColorForeground(color(155, 65, 56))
    ;
    
    cp5.addSlider("CONVERSOR2")
    .setPosition(300, 50)
    .setSize(50, 175)
    .setColorForeground(color(155, 65, 56))
    ;
}

void draw() {


  background(100);
  fill(0, 255, 0);
  ellipse(25, 150, 10, 10);
  fill(255, 255, 0);
  ellipse(25, 175, 10, 10);
  fill(255, 0, 0);
  ellipse(25, 200, 10, 10);
  textSize(12);
  fill(255);
  text("SEGURO (<50%)", 32, 152);
  text("PRECAUCIÓN (>50% & <75%)", 32, 177);
  text("PELIGRO (>75%)", 32, 202);

  textSize(20);
  text("UTN", 180
  , 25);
  text("Adonis Narváez", 32, 280);
  text("03-07-2019", 32, 310);


  if (con==1) {
    if (port.available()>0) {
      dato=port.readString();
      conversor=int(dato);
      conversor2=int(dato)+12;
      cp5.getController("CONVERSOR1").setValue(conversor);
      
      cp5.getController("CONVERSOR2").setValue(conversor2);

      if (conversor>0 &&conversor<50) {
        cp5.getController("CONVERSOR1").setColorForeground(color(0, 255, 0));
      } else if (conversor>50 &&conversor<75) {
        cp5.getController("CONVERSOR1").setColorForeground(color(255, 255, 0));
      } else if (conversor>75 &&conversor<=100) {
        cp5.getController("CONVERSOR1").setColorForeground(color(255, 0, 0));
      }
      
      if (conversor2>0 && conversor2<50) {
        cp5.getController("CONVERSOR2").setColorForeground(color(0, 255, 0));
      }else if (conversor2>50 &&conversor2<75) {
         cp5.getController("CONVERSOR2").setColorForeground(color(255, 255, 0));
      }else if (conversor2>75 &&conversor2<=100) {
        cp5.getController("CONVERSOR2").setColorForeground(color(255, 0, 0));
      }
    }
  }
}

void CONECTAR() {
  con=1-con;
  if (con==1) {
    port=new Serial(this, "COM14", 9600);
    cp5.getController("CONECTAR").setLabel("DESCONECTAR");
  } else {
    port.stop();
    cp5.getController("CONECTAR").setLabel("CONECTAR");
  }
}
