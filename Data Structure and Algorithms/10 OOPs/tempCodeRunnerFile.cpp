  // hero(hero &temp) // here it is passed by refrence because of infinite loop
    //                  // pass by value would have called copy constructor again and again
    // {
    //     this->health = temp.health;
    //     this->name = temp.name;
    // }