#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Warlock.hpp"
#include "Fireball.hpp"
#include "TargetGenerator.hpp"
#include "Fwoosh.hpp"
#include "Polymorph.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"

int main(int argc, char** argv){

  if (argc == 2){
      int option = std::atoi(argv[1]);
      if(option == 1){
        std::cout << "1 - MAIN Subject" << std::endl << std::endl;
        Warlock richard("Richard", "foo");
        richard.setTitle("Hello, I'm Richard the Warlock!");
        BrickWall model1;

        Polymorph* polymorph = new Polymorph();
        TargetGenerator tarGen;

        tarGen.learnTargetType(&model1);
        richard.learnSpell(polymorph);

        Fireball* fireball = new Fireball();

        richard.learnSpell(fireball);

        ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

        richard.introduce();
        richard.launchSpell("Polymorph", *wall);
        richard.launchSpell("Fireball", *wall);
        delete fireball;
        delete polymorph;
      } 
      else if(option == 2){
        std::cout << "2 - MAIN NO_SPELL NO_TARGET" << std::endl << std::endl;
        // Crear instancias
        Warlock warlock("Merlin", "The Enchanter");
        SpellBook spellBook;
        TargetGenerator targetGenerator;

        // Introducir al WarlockIN
        warlock.introduce();

        // Aprender hechizos
        ASpell* fireball = new Fireball();
        ASpell* fwoosh = new Fwoosh();
        warlock.learnSpell(fireball);
        warlock.learnSpell(fwoosh);

        // Obtener un objetivo del generador de objetivos
        ATarget* brickWall = new BrickWall();
        ATarget* dummy = new Dummy();
        targetGenerator.learnTargetType(brickWall);
        targetGenerator.learnTargetType(dummy);

        // Realizar lanzamientos de hechizos
        warlock.launchSpell("Fireball", *brickWall);
        warlock.launchSpell("Fwoosh", *dummy);

        // Olvidar hechizos y objetivos
        warlock.forgetSpell("Fireball");
        warlock.forgetSpell("NonExistentSpell");
        targetGenerator.forgetTargetType("Inconspicuous Red-brick Wall");
        targetGenerator.forgetTargetType("NonExistentTarget");

        // Limpiar memoria
        delete fireball;
        delete fwoosh;
        delete brickWall;
        delete dummy;

        return 0;
      } 
      else if(option == 3){
        std::cout << "3 - MAIN NO_SPELL NULL_TARGET" << std::endl << std::endl;
        // Crear instancias
        Warlock warlock("Merlin", "The Enchanter");
        SpellBook spellBook;
        TargetGenerator targetGenerator;

        // Introducir al Warlock
        warlock.introduce();

        // Aprender hechizos
        ASpell* fireball = new Fireball();
        ASpell* fwoosh = new Fwoosh();
        warlock.learnSpell(fireball);
        warlock.learnSpell(fwoosh);

        // Obtener un objetivo del generador de objetivos
        ATarget* brickWall = new BrickWall();
        ATarget* dummy = new Dummy();
        targetGenerator.learnTargetType(brickWall);
        targetGenerator.learnTargetType(dummy);

        // Realizar lanzamientos de hechizos
        warlock.launchSpell("Fireball", *brickWall);
        warlock.launchSpell("Fwoosh", *dummy);

        // Olvidar hechizos y objetivos
        warlock.forgetSpell("Fireball");
        warlock.forgetSpell("NonExistentSpell"); // Intentar olvidar un hechizo que no existe
        targetGenerator.forgetTargetType("Inconspicuous Red-brick Wall");
        targetGenerator.forgetTargetType("NonExistentTarget"); // Intentar olvidar un objetivo que no existe

        // Lanzar hechizo con objetivo nulo
        ATarget* nullTarget = NULL;
        warlock.launchSpell("Fwoosh", *nullTarget); // Intentar lanzar un hechizo con un objetivo nulo

        // Limpiar memoria
        delete fireball;
        delete fwoosh;
        delete brickWall;
        delete dummy;

        return 0;
      }
      else if(option == 4){
        std::cout << "4 - MAIN MIX_RANDOM" << std::endl << std::endl;

        // Inicializar la semilla aleatoria
        srand(time(NULL));

        // Crear instancias
        Warlock warlock("Merlin", "The Enchanter");
        SpellBook spellBook;
        TargetGenerator targetGenerator;

        // Introducir al Warlock
        warlock.introduce();

        // Aprender hechizos
        ASpell* fireball = new Fireball();
        ASpell* fwoosh = new Fwoosh();
        ASpell* polymorph = new Polymorph();
        warlock.learnSpell(fireball);
        warlock.learnSpell(fwoosh);
        warlock.learnSpell(polymorph);

        // Obtener un objetivo del generador de objetivos
        ATarget* brickWall = new BrickWall();
        ATarget* dummy = new Dummy();
        targetGenerator.learnTargetType(brickWall);
        targetGenerator.learnTargetType(dummy);

        // Realizar lanzamientos de hechizos aleatorios
        for (int i = 0; i < 10; i++) {
            // Elegir un hechizo al azar
            std::string spellName;
            int spellIndex = rand() % 4;
            switch (spellIndex) {
                case 0:
                    spellName = "Fireball";
                    break;
                case 1:
                    spellName = "Fwoosh";
                    break;
                case 2:
                    spellName = "Polymorph";
                    break;
                case 3:
                    spellName = "NonExistentSpell";
                    break;
            }

            // Elegir un objetivo al azar
            ATarget* target;
            int targetIndex = rand() % 3;
            switch (targetIndex) {
                case 0:
                    target = brickWall;
                    break;
                case 1:
                    target = dummy;
                    break;
                case 2:
                    target = NULL;
                    break;
            }

            // Intentar lanzar el hechizo sobre el objetivo
            try {
                warlock.launchSpell(spellName, *target);
            }
            catch (std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        // Limpiar memoria
        delete fireball;
        delete fwoosh;
        delete polymorph;
        delete brickWall;
        delete dummy;

        return 0;
      }
      else if(option == 5){
        std::cout << "5 - MAIN MIX_ALL" << std::endl << std::endl;
        // Crear instancias
        Warlock warlock("Merlin", "The Enchanter");
        SpellBook spellBook;
        TargetGenerator targetGenerator;

        // Introducir al Warlock
        warlock.introduce();

        // Aprender hechizos
        ASpell* fireball = new Fireball();
        ASpell* fwoosh = new Fwoosh();
        ASpell* polymorph = new Polymorph();
        warlock.learnSpell(fireball);
        warlock.learnSpell(fwoosh);
        warlock.learnSpell(polymorph);

        // Obtener un objetivo del generador de objetivos
        ATarget* brickWall = new BrickWall();
        ATarget* dummy = new Dummy();
        targetGenerator.learnTargetType(brickWall);
        targetGenerator.learnTargetType(dummy);

        // Realizar lanzamientos de hechizos con todas las combinaciones posibles
        std::string spells[] = {"Fireball", "Fwoosh", "Polymorph", "NonExistentSpell"}; 
        ATarget* targets[] = {brickWall, dummy, NULL}; 
        for (int i = 0; i < 4; i++) { 
            for (int j = 0; j < 3; j++) {
                try {
                  warlock.launchSpell(spells[i], *targets[j]);
                }
                catch (std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            }
        }

        // Limpiar memoria
        delete fireball;
        delete fwoosh;
        delete polymorph;
        delete brickWall;
        delete dummy;

        return 0;
      }
  }
  else{
    std::cerr << "BAD ARGS: TRY - > " << argv[0] << " \"number 1 to 5\"" << std::endl;
  }
}