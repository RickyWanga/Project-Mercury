#include "ObjectOnTrack.hpp"

using namespace std;

void ObjectOnTrack::updateY(){
    this->y++;
}

void ObjectOnTrack::updateY(int y){
    this->y = y;
}

// void ObjectOnTrack::stampa(){

// }

ObjectOnTrack::ObjectOnTrack(bool type=0){
    if(type) this->c = 'B';
    else this->c = 'O';
}

