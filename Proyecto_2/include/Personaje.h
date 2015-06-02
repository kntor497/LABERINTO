#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <iostream>
#include <math.h>
class Personaje
{
private:
    int ejeX;
    int ejeY;
    int rumbo;
    int RT;
    int GT;
    int BT;
    int extraTime;
    int gifs;
    int puntaje;
    int posicion;
    bool ayuda;

public:
    Personaje() {
    home();}
    virtual ~Personaje() {}
    void home(){
        rumbo=0;
        ejeX=350;
        ejeY=350;
        RT=0;
        GT=0;
        BT=0;
        extraTime=0;
        gifs=0;
        puntaje=0;
        posicion=1;
        ayuda=false;
    }
    void home1(){
        rumbo=0;
        ejeX=350;
        ejeY=350;
    }
    //setter modifican los atributos
    void setAyuda(bool a){
        ayuda=a;
    }
    void setColoresT(int pRT,int pGT, int pBT){
        RT=pRT;
        GT=pGT;
        BT=pBT;
    }
    void setPos(int x,int y){
        ejeX=x;
        ejeY=y;
    }
    void setX(int x){
        ejeX=x;
    }
    void setY(int y){
        ejeY=y;
    }
    void setHeading(int grados){
        rumbo=fmod((360-grados),360);
    }
    void setGifs(int gif){
        gifs+=gif;
    }
    void setExtraTime(int pTime){
        extraTime+=pTime;
    }
    void setPuntaje(int pPuntaje){
        puntaje+=pPuntaje;
    }
    void setPosicion(int pos){
        posicion=pos;
    }
    //getters solo muestran los datos no modifican
    int getGifs(){
        return gifs;
    }
    int getExtraTime(){
        return extraTime;
    }
    int getPosicion(){
        return posicion;
    }
    bool getAyuda(){
        return ayuda;
    }
    int getRT(){
        return RT;
    }
    int getGT(){
        return GT;
    }
    int getBT(){
        return BT;
    }
    int getX(){
        return ejeX;
    }
    int getY(){
        return ejeY;
    }
    int getHeading(){
        return rumbo;
    }
    int getHead(){
        return fmod((360-rumbo),360);
    }
    int getPuntaje(){
        return puntaje;
    }
    //dibuja la tortuga
void DPersonaje(int b){
    setlinestyle(6,1,3);
    if(b==1){RT=200;GT=165;BT=20;}//200,165,20
    else{RT=0;GT=255;BT=0;}
    setcolor(COLOR(RT,GT,BT));
    //cuerpo
    setfillstyle(1,COLOR(RT,GT,BT));
    //cabeza
    int x2=cos((rumbo*M_PI)/180)*17;//18
    int y2=sin((rumbo*M_PI)/180)*17;//18
    fillellipse(ejeX+x2,ejeY+y2,6,6);//8-7
    //pie Superior Izquierdo
    int rumbo2=fmod(rumbo-60,360);
    int x3=cos((rumbo2*M_PI)/180)*16;//17
    int y3=sin((rumbo2*M_PI)/180)*16;//17
    fillellipse(ejeX+x3,ejeY+y3,3,3);//5-5
    //pie Inferior Izquierdo
    int rumbo3=fmod(rumbo-130,360);
    int x4=cos((rumbo3*M_PI)/180)*16;//17
    int y4=sin((rumbo3*M_PI)/180)*16;//17
    fillellipse(ejeX+x4,ejeY+y4,3,3);//5-5
    //pie Superior Derecho
    int rumbo4=fmod(rumbo-300,360);
    int x5=cos((rumbo4*M_PI)/180)*16;//17
    int y5=sin((rumbo4*M_PI)/180)*16;//17
    fillellipse(ejeX+x5,ejeY+y5,3,3);//5-5
    //pie Inferior Derecho
    int rumbo5=fmod(rumbo-230,360);
    int x6=cos((rumbo5*M_PI)/180)*16;//18
    int y6=sin((rumbo5*M_PI)/180)*16;//18
    fillellipse(ejeX+x6,ejeY+y6,3,3);
    if(b==0){
       setfillstyle(1,COLOR(0,153,76));
    }
    else{
        setfillstyle(1,COLOR(RT,GT,BT));//100 51 25
    }
    fillellipse(ejeX,ejeY,12,11);
}

};

#endif // PERSONAJE_H