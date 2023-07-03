#include <iostream>
#include "Dish.h"
#include "List.h"
#include "workerDish.h"
#include <assert.h>


int main() {

    Dish Wok;

    assert(Wok.getName() == "Dish");
    assert(Wok.getWeight() == 100);
    assert(Wok.getContentProteins() == 20);
    assert(Wok.getContentFats() == 20);
    assert(Wok.getContentCarbons() == 20);
    assert(Wok.getContentAcids() == 20);
    assert(Wok.getContentFibers() == 20);


    Dish Pasta("Pasta",250, 300, 40, 80, 120, 30, 30);


    assert(Pasta.getName() == "Pasta");
    assert(Pasta.getWeight() == 300);
    assert(Pasta.getContentProteins() == 40);
    assert(Pasta.getContentFats() == 80);
    assert(Pasta.getContentCarbons() == 120);
    assert(Pasta.getContentAcids() == 30);
    assert(Pasta.getContentFibers() == 30);

    assert(Pasta.energyValue() == 1477);

    Pasta.setName("Bolognese");
    Pasta.setCost(280);
    Pasta.setWeight(250);
    Pasta.setContentProteins(60);
    Pasta.setContentFats(70);
    Pasta.setContentCarbons(100);
    Pasta.setContentAcids(30);
    Pasta.setContentFibers(40);

    assert(Pasta.getName() == "Bolognese");
    assert(Pasta.getWeight() == 250);
    assert(Pasta.getContentProteins() == 60);
    assert(Pasta.getContentFats() == 70);
    assert(Pasta.getContentCarbons() == 100);
    assert(Pasta.getContentAcids() == 30);
    assert(Pasta.getContentFibers() == 40);

    Dish Azu(Pasta);

    assert(Azu.getName() == "Bolognese");
    assert(Azu.getWeight() == 250);
    assert(Azu.getContentProteins() == 60);
    assert(Azu.getContentFats() == 70);
    assert(Azu.getContentCarbons() == 100);
    assert(Azu.getContentAcids() == 30);
    assert(Azu.getContentFibers() == 40);


    workerDish Something;
    assert(Something.getPrice("student") == 150);

    List List1;
    List1.from("D:\\Study\\OOP\\input.txt");
    List1.display();
    List1.search(800);
    List1.pop(2);

    List List4(List1);
    List4.display();

    List List3;
    List3.display();

    List List2;
    List2.insert(Pasta);
    List2.insert(Wok);
    List2.display();

    assert(List2.length() == 2);

    List2.save("D:\\Study\\OOP\\output.txt");

    List2.clearAll();
    List2.display();




    std::cout << "correct...\n" << std::endl;


    return 0;

}
