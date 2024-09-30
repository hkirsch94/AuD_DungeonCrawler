#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <algoviz/SVG.hpp>

class Block{
    private:
    
    
    int blockId;
    Image* blockImage;
    bool breakable;
    bool hasBlock = true;
    

    //protected:
    public:
    
    
    //Konstruktor newItem
    
    Block(int blockId,int xPos,int yPos, SVG *view){
        
        this->blockId = blockId;
        if(blockId == 0){
            this->hasBlock = false;
        }else if(blockId == 1){
            this->blockImage = new Image("png Ordner/Bloecke/Brick_1.png", xPos, yPos, 20, 20, view);
            this->breakable = false;
        }else if(blockId == 2){
            this->blockImage = new Image("png Ordner/Bloecke/Door.png", xPos, yPos, 20, 20, view);
            this->breakable = false;
        }else if(blockId == 3){
            this->blockImage = new Image("png Ordner/Bloecke/Knochen.png", xPos, yPos, 20, 20, view);
            this->breakable = true;
        }else if(blockId == 4){
            this->blockImage = new Image("png Ordner/Bloecke/Spinnennetz.png", xPos, yPos, 20, 20, view);
            this->breakable = true;
        }else if(blockId == 5){
            this->blockImage = new Image("png Ordner/Bloecke/Treppe_hoch.png", xPos, yPos, 20, 20, view);
            this->breakable = false;
        }else if(blockId == 6){
            this->blockImage = new Image("png Ordner/Bloecke/Treppe_runter.png", xPos, yPos, 20, 20, view);
            this->breakable = false;
        }else if(blockId == 10){
            this->blockImage = new Image("png Ordner/Bloecke/Portal_Orange.png", xPos, yPos, 20, 20, view);
            this->breakable = false;
        }else if(blockId == 11){
            this->blockImage = new Image("png Ordner/Bloecke/Portal_Blau.png", xPos, yPos, 20, 20, view);
            this->breakable = false;
        }
    }
    
    
    
    
    ///////////
    ///Getter
    ///////////
    
    Image* getImage(){
        return blockImage;
    }
    bool hasBlockImage(){
        return hasBlock;
    }
    int getBlockX(){
        return blockImage->getX();
    }
    int getBlockY(){
        return blockImage->getY();
    }
    int getBlockId(){
        return blockId;
    }
    bool isBreakable(){
        return breakable;
    }
    
    
    ///////////
    ///Setter
    ///////////
    
    
    void blockMoveTo(int x, int y){
        this->blockImage->moveTo(x, y);
    }
    
    void setBlockSize(int x, int y){
        this->blockImage->setSize(x,y);
    }
    void rotateBlock(int alpha){
        this->blockImage->rotateTo(alpha);
    }
};//End of class Block
#endif