#ifndef ITEMLIST_HPP
#define ITEMLIST_HPP

#include <algoviz/SVG.hpp>
#include "Item.hpp"
#include "Character.hpp"


class ItemList{
    
    private:
    
    SVG* ptrSVG = nullptr;
    

    //ItemList Pointer
    Item* ptr = nullptr;
    list <Item*> collectable ;
    list <int> itemSpawn;
    
    
    //Inventory Arrays
    Text* inventoryCount[6];
    Image* itemImage[6];
    int inventoryItem[2][6]={0,1,2,3,4,5};
    
    //[0][Items],[1][Anzahl]
    
    /* Item ID:
     * 0:Potion
     * 1:Diamond
     * 2:GunPowder
     * 3:Bomb
     * 4:Key
     * 5:Crown
     */    
    public:
    
    //Konstruktor Inventory + Collectable
    ItemList(SVG *ptrSVG){
        
        //Ptr auf SVG
        this->ptrSVG = ptrSVG; 
        
        //Items
        collectable;
        //List for amount of Items in a Level
        itemSpawn;
        
        //Platzierung von Text und Image auf SVG für Inventardarstellung
        
        for(int i = 0; i < 5; i ++ ){
            
            if(inventoryItem[0][i]==inventoryItem[0][0]){
                this -> itemImage[0] = new Image("png Ordner/Objekte/Heart.png",20,430,30,30,ptrSVG);
                this -> inventoryCount[0] = new Text("0",20,460,ptrSVG); 
                
            }else if(inventoryItem[0][i]==inventoryItem[0][1]){
                this -> itemImage[1] = new Image("png Ordner/Objekte/Diamant.png",80,430,40,40,ptrSVG);
                this -> inventoryCount[1] = new Text("0",80,460,ptrSVG);
                
            }else if(inventoryItem[0][i]==inventoryItem[0][2]){
                this -> itemImage[2] = new Image("png Ordner/Objekte/BombPowerUp.png",140,430,40,40,ptrSVG);
                this -> inventoryCount[2] = new Text("0",140,460,ptrSVG);
                
            }else if(inventoryItem[0][i]==inventoryItem[0][3]){
                this -> itemImage[3] = new Image("png Ordner/Objekte/Bomb.png",200,430,40,40,ptrSVG);
                this -> inventoryCount[3] = new Text("0",200,460,ptrSVG); 
                
            }else if(inventoryItem[0][i]==inventoryItem[0][4]){
                this -> itemImage[4] = new Image("png Ordner/Objekte/Key.png",260,430,40,40,ptrSVG);
                this -> inventoryCount[4] = new Text("0",260,460,ptrSVG);    
                
            }
        }
    }
    
    
    
    ///////////
    ///Getter
    ///////////
    
    int getItemAmount(int itemId){
        return inventoryItem[1][itemId];
        
    }
    list<Item*> getCollectable(){ 
        return collectable;
    }
    
    int getHealth(){
        return inventoryItem[1][0];
    }
    //Falls Inventar vom SVG gelöscht wird
    void openInventory(){
        for(int i = 0; i < 5; i ++ ){
            
            if(inventoryItem[0][i]==inventoryItem[0][0]){
                this -> itemImage[0] = new Image("png Ordner/Objekte/Heart.png",20,430,30,30,ptrSVG);
                this -> inventoryCount[0] = new Text("0",20,460,ptrSVG); 
                
            }else if(inventoryItem[0][i]==inventoryItem[0][1]){
                this -> itemImage[1] = new Image("png Ordner/Objekte/GemStone.png",80,430,40,40,ptrSVG);
                this -> inventoryCount[1] = new Text("0",80,460,ptrSVG);
                
            }else if(inventoryItem[0][i]==inventoryItem[0][2]){
                this -> itemImage[2] = new Image("png Ordner/Objekte/BombPowerUp.png",140,430,40,40,ptrSVG);
                this -> inventoryCount[2] = new Text("0",140,460,ptrSVG);
                
            }else if(inventoryItem[0][i]==inventoryItem[0][3]){
                this -> itemImage[3] = new Image("png Ordner/Objekte/Bomb.png",200,430,40,40,ptrSVG);
                this -> inventoryCount[3] = new Text("0",200,460,ptrSVG); 
                
            }else if(inventoryItem[0][i]==inventoryItem[0][4]){
                this -> itemImage[4] = new Image("png Ordner/Objekte/Key.png",260,430,40,40,ptrSVG);
                this -> inventoryCount[4] = new Text("0",260,460,ptrSVG);    
                
            }
        }
    }
    //Wenn auf Item, dann sammel Item auf
    bool onItem(Character * chara){
        for(Item *item : collectable){
            if(item->getItemX()== chara->getCharacterX() && item->getItemY()== chara->getCharacterY()){
                if(item->getItemId()== 0){
                    collectItem(10,item);
                    return true;
                }else if(item->getItemId()== 1){
                    collectItem(10,item);
                    return true;
                }else if(item->getItemId()== 2){
                    collectItem(1,item);
                    return true;
                }else if(item->getItemId()== 3){
                    collectItem(1,item);
                    return true;
                }else if(item->getItemId()== 4){
                    collectItem(1,item);
                    return true;
                }else if(item->getItemId()== 5){
                    collectItem(1,item);
                    return true;
                }
            }
        }
        return false;
    }
    
    
    ///////////
    ///Setter
    ///////////
    
    //fügt Item in die Liste und aufs SVG
    void addItem(int itemId,int xPos,int yPos){
        this->collectable.push_back(new Item(itemId, xPos, yPos, this->ptrSVG));      
    }
    
    //Sammel Item auf und lösche es von der Liste und dem SVG
    void collectItem(int amount, Item *item ){
        for( Item *helper : collectable ) {
            if(helper == item ){     
                
                this->inventoryItem[1][helper->getItemId()] += amount;
                
                if(helper->getItemId() < 5){
                    this->inventoryCount[helper->getItemId()]->setText(to_string(inventoryItem[1][helper->getItemId()]));
                }
                delete helper->getImage();
                delete helper;
                collectable.remove(helper);
                return;
            }
        }
    }
    //leert collectable und das SVG von Items
    void clearItemList(){
        for( Item *helper : collectable ) {         
            delete helper->getImage();         
        }
        this->collectable.clear();
    }
    
    
    //Items werden runtergezählt
    void useItem(int itemId){
        
        this->inventoryItem[1][itemId]--;
        this->inventoryCount[itemId]->setText(to_string(inventoryItem[1][itemId]));
    }
    
    //verändert HealthPoints und aktualisiert Anzahl im Inventar
    void setHealth(int healthPoints){
        this->inventoryItem[1][0] = healthPoints;
        this->inventoryCount[0]->setText(to_string(inventoryItem[1][0]));
    }
    
    
    
    
    
        
        
        
        
    
}; //End of Class ItemList
#endif