#include "dungeon.hpp"
#include "npc_factory.hpp"
#include "observer_console.hpp"
#include "observer_file.hpp"

int main() {
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
    
    Dungeon dungeon(100.0); 

    dungeon.addObserver(&consoleLogger);
    dungeon.addObserver(&fileLogger);

    dungeon.addNPC("Dragon", "Smaug", 50, 50);
    dungeon.addNPC("Elf", "Legolas", 80, 80);  
    
    dungeon.addNPC("Druid", "Merlin", 120, 120);  

    dungeon.addNPC("Druid", "Radagast", 60, 60);  
    
    std::cout << "Before battle:" << std::endl;
    dungeon.printAll();
    
    std::cout << "\nStarting battle..." << std::endl;
    dungeon.battle();
    
    std::cout << "\nAfter battle:" << std::endl;
    dungeon.printAll();
    
    dungeon.saveToFile("dungeon_state.txt");
    
    Dungeon dungeon2(100.0);
    dungeon2.addObserver(&consoleLogger);
    dungeon2.loadFromFile("dungeon_state.txt");
    
    std::cout << "\nLoaded from file:" << std::endl;
    dungeon2.printAll();
    
    return 0;
}