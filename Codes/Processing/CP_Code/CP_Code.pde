import controlP5.*;

ControlP5 cp5;

String[][] textfieldNames = {{"xPOSKP", "xPOSKi", "xPOSKd"},{"yPOSKP", "yPOSKi", "yPOSKd"},{"xVELKP", "xVELKi", "xVELKd"},{"yVELKP", "yVELKi", "yVELKd"}};

void setup() {
  size(700,400);

  PFont font = createFont("arial",20);

  cp5 = new ControlP5(this);

  int y = 20;
  int spacing = 60;
  int x=20;
  for(int i=1;i<4;i++){
  for(String name: textfieldNames[i]){
    cp5.addTextfield(name)
       .setPosition(x,y)
       .setSize(100,40)
       .setFont(font)
       .setFocus(true)
       .setColor(color(255,0,0))
       ;
     y += spacing;
  }
  x+=spacing*3;
  y=20;
  }
  textFont(font);
}

void draw() {
  background(0);
}

void controlEvent(ControlEvent theEvent) {
  if(theEvent.isAssignableFrom(Textfield.class)) {
    println("controlEvent: accessing a string from controller '"
            +theEvent.getName()+"': "
            +theEvent.getStringValue()
            );
  }
}
