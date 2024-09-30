#ifndef ITEM_HPP
#define ITEM_HPP

#include <algoviz/SVG.hpp>

class Item{
    
    
    private:
    
    
    
    /* Item ID:
     * 0:Potion
     * 1:Diamond
     * 2:Arrow
     * 3:Bomb
     * 4:Key
     * 5:Crown
     */
    int itemId;
    Image* itemImage;
    

    
    public: 
    
    //Konstruktor unbekannte Koordinaten
    Item(int itemId, SVG *view){
        
        this->itemId = itemId;
        if(itemId == 0){
            this->itemImage = new Image("png Ordner/Objekte/Potion.png", 0, 0, 0, 0, view);
        }else if(itemId == 1){
            this->itemImage = new Image("png Ordner/Objekte/Diamant.png", 0, 0, 0, 0, view);
        }else if(itemId == 2){
            this->itemImage = new Image("png Ordner/Objekte/Pulverfass.png", 0, 0, 0, 0, view);
        }else if(itemId == 3){
            this->itemImage = new Image("png Ordner/Objekte/Bomb.png", 0, 0, 0, 0, view);
        }else if(itemId == 4){
            this->itemImage = new Image("png Ordner/Objekte/Key.png", 0, 0, 0, 0, view);
        }else if(itemId == 5){
            this->itemImage = new Image("png Ordner/Objekte/Crown.png", 0, 0, 0, 0, view);
        }
    }
    
    //Konstruktor bekannte Koordinaten
    
    Item(int itemId,int xPos,int yPos, SVG *view){
        
        this->itemId = itemId;
        if(itemId == 0){
            this->itemImage = new Image("png Ordner/Objekte/Potion.png", xPos+10, yPos+10, 20, 20, view);
        }else if(itemId == 1){
            this->itemImage = new Image("png Ordner/Objekte/Diamant.png", xPos+10, yPos+10, 20, 20, view);
        }else if(itemId == 2){
            this->itemImage = new Image("png Ordner/Objekte/Pulverfass.png", xPos+10, yPos+10, 20, 20, view);
        }else if(itemId == 3){
            this->itemImage = new Image("png Ordner/Objekte/Bomb.png", xPos+10, yPos+10, 20, 20, view);
        }else if(itemId == 4){
            this->itemImage = new Image("png Ordner/Objekte/Key.png", xPos+10, yPos+10, 20, 20, view);
        }else if(itemId == 5){
            this->itemImage = new Image("png Ordner/Objekte/Crown.png", xPos+10, yPos+10, 20, 20, view);
        }
    }
    
    
    
    ///////////
    ///Getter
    ///////////
    
    Image* getImage(){
        return itemImage;
    }
    int getItemX(){
        return itemImage->getX();
    }
    int getItemY(){
        return itemImage->getY();
    }
    int getItemId(){
        return itemId;
    }
    
    
    ///////////
    ///Setter
    ///////////
    
    void itemMoveTo(int x, int y){
        this->itemImage->moveTo(x, y);
    }
    
    void setItemSize(int x, int y){
        this->itemImage->setSize(x,y);
    }
    void rotateItem(int alpha){
        this->itemImage->rotateTo(alpha);
    }



    
    
};//End of Class Item
#endif