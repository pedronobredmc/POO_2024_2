#pragma once
#include <iostream>
#include <string>
#include <iomanip>


class Grafite{
    private:
        float thickness=0;
        std::string hardness="";
        int size=0;
    public:
    Grafite(float thickness=0, std::string hardness="", int size=0){
        this->thickness = thickness;
        this->hardness = hardness;
        this->size = size;
    }
    int usagePerSheet(){
        if(this->hardness=="HB"){
            return 1;
        } else if(this->hardness=="2B"){
            return 2;
        } else if(this->hardness=="4B"){
            return 4;
        } else if(hardness=="6B"){
            return 6;
        }else{
            return 0;
        }
    }
    std::string getHardness(){
        return this->hardness;
    }
    int getSize(){
        return this->size;
    }
    float getThickness(){
        return this->thickness;
    }
    void setSize(int size){
        this->size = size;
    }
};

class Lapiseira{
    public:
    float thickness=0;
    Grafite grafite;
    Lapiseira(float thickness=0){
        this->thickness = thickness;
    }
    bool hasGrafite(){
        if(this->grafite.getHardness()!="" && this->grafite.getSize()>0 && this->grafite.getThickness()>0){
            return true;
        }else{
            return false;
        }
    }
    void remove(){
        if(hasGrafite()==false){
            std::cout << "fail: nao existe grafite" << std::endl;
        }else{
            this->grafite = Grafite(0,"",0);
        }
    }
    void writePage(){
        if(hasGrafite()==false){
            std::cout << "fail: nao existe grafite" << std::endl;
        }else if(this->grafite.getSize()<=10){
            std::cout << "fail: tamanho insuficiente" << std::endl;
        }else if(this->grafite.getSize()-1>=10 && this->grafite.getHardness()=="HB"){
            this->grafite.setSize(this->grafite.getSize()-this->grafite.usagePerSheet());
        }else if(this->grafite.getSize()-2>=10 && this->grafite.getHardness()=="2B"){
            this->grafite.setSize(this->grafite.getSize()-this->grafite.usagePerSheet());
        }else if(this->grafite.getSize()-4>=10 && this->grafite.getHardness()=="4B"){
            this->grafite.setSize(this->grafite.getSize()-this->grafite.usagePerSheet());
        }else if(this->grafite.getSize()-6>=10 && this->grafite.getHardness()=="6B"){
            this->grafite.setSize(this->grafite.getSize()-this->grafite.usagePerSheet());
        }else{
            this->grafite.setSize(this->grafite.getSize()-(this->grafite.getSize()-10));
            std::cout << "fail: folha incompleta" << std::endl;
        }
    }
    void insert(Grafite grafite){
        if(this->thickness!=grafite.getThickness()){
            std::cout << "fail: calibre incompativel" << std::endl;
        }else if(this->grafite.getHardness()!=""){
            std::cout << "fail: ja existe grafite" << std::endl;
        }else{
            this->grafite = grafite;
        }
    }
    void str(){
        if(this->grafite.getThickness()==0 && this->grafite.getHardness()=="" && this->grafite.getSize()==0){
            std::cout << std::fixed << std::setprecision(1) << "calibre: "<<this->thickness<<", grafite: null"<< std::endl;
        }else{
            std::cout << std::fixed << std::setprecision(1) << "calibre: "<<this->thickness<<", grafite: ["<<this->grafite.getThickness()<<":"<<this->grafite.getHardness()<<":"<<this->grafite.getSize()<<"]"<< std::endl;
        }
    }
};

class Student {
private:
    Lapiseira pencil;
public:
    Student(float thickness) {
        //(void) thickness;
        pencil = Lapiseira(thickness);
    };
    
    void insert(double thickness, std::string hardness, int length) {
        //(void) thickness;
        //(void) hardness;
        //(void) length;
        pencil.insert(Grafite(thickness, hardness, length));
        
    }

    void remove() {
        pencil.remove();
    }

    void writePage() {
        pencil.writePage();
    }

    void show() {
        pencil.str();
    }
};

