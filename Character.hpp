#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character { 

    private:     
    
    //  Attribute      
    int characterId;
    Image* characterImage;
    int healthPoints;
    int damagePoints;
    bool status;
    
    
    public:
    
    
    //Konstruktor bei bekannten Koordinaten
    
    Character(int characterId,int xPos,int yPos, SVG *view){
        
        this->characterId = characterId;
        
        // Spieler
        if(characterId == 0){
            this->characterImage = new Image("png Ordner/Charakter/Avatar.png", xPos+10, yPos+10, 25, 25, view);
            this->healthPoints = 100;
            this->damagePoints = 2;
            this-> status = true;
            
         // Gegner   
        }else if(characterId == 1){
            this->characterImage = new Image("png Ordner/Charakter/Fledermaus_2.png", xPos+10, yPos+10, 20, 20, view);
            this->healthPoints = 20;
            this->damagePoints = 5;
            this-> status = true;
            
        }else if(characterId == 2){
            this->characterImage = new Image("png Ordner/Charakter/Spinne1.png", xPos+10, yPos+10, 20, 20, view);
            this->healthPoints = 30;
            this->damagePoints = 7;
            this-> status = true;
              
        }else if(characterId == 3){
            this->characterImage = new Image("png Ordner/Charakter/Schlange.png", xPos+10, yPos+10, 30, 30, view);
            this->healthPoints = 40;
            this->damagePoints = 10;
            this-> status = true;
            
        }else if(characterId == 4){
            this->characterImage = new Image("png Ordner/Charakter/Geist.png", xPos+10, yPos+10, 20, 20, view);
            this->healthPoints = 100;
            this->damagePoints = 30;
            this-> status = true;
        }else if(characterId == 5){
            this->characterImage = new Image("png Ordner/Charakter/Gruselgeist.png", xPos+10, yPos+10, 20, 20, view);
            this->healthPoints = 100;
            this->damagePoints = 30;
            this-> status = true;
        }
    }
    
    
    ///////////
    ///Getter
    ///////////
    
    
    int getCharacterId(){
        return characterId;
    }
    Image* getImage(){
        return characterImage;
    }
    int getHealthPoints(){
        return healthPoints;
    }
    int getDamagePoints(){
        return damagePoints;
    }
    bool getStatus(){
        return status;
    }
    int getCharacterX(){
        return characterImage->getX();
    }
    int getCharacterY(){
        return characterImage->getY();
    }
    
    
    ///////////
    ///Setter
    ///////////
    void characterMoveTo(int x, int y){
        this ->characterImage->moveTo(x,y);
    }
    
    void addHealthPoints(int hp){
        this->healthPoints += hp;
    }
    
    void setHealthPoints(int hp){
        this->healthPoints = hp;
    }
    
    void addDamagePoints(int dmg){
        this->damagePoints += dmg;
    }
    
    void rotateCharacter(int alpha){
        this->characterImage->rotateTo(alpha);
    }
    
    void kill(){
        this->characterImage->hide();
        this->characterImage->moveTo(0,0);
        this->status = false;
    }
      
    
};//End of Class character
#endif