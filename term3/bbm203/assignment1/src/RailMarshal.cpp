#include "RailMarshal.h"
#include "Enums.h"
#include <exception>
#include <iostream>
#include <sstream>
#include <algorithm>

RailMarshal::RailMarshal()
{
    // TODO: Initialize each track in the departure yard.
    // Each TrainTrack corresponds to one Destination.
}

RailMarshal::~RailMarshal()
{
    // TODO: Cleanup remaining trains, prevent memory leaks
}

// Getter (ready)
ClassificationYard &RailMarshal::getClassificationYard()
{
    return classificationYard;
}

// Getter (ready)
TrainTrack &RailMarshal::getDepartureYard(Destination dest)
{
    int idx = static_cast<int>(dest);
    return departureYard[idx];
}

void RailMarshal::processCommand(const std::string &line)
{
    // TODO: Parse user commands from input lines.
    
    std::stringstream ss(line);
    
    std::string cmd;
    ss>>cmd;
    
    std::cout<<cmd;
    
    if (cmd == "ADD_WAGON"){
         // if ADD_WAGON
         // Use: std::cout << "Error: Invalid ADD_WAGON parameters.\n";
         // Use: std::cout << "Wagon " << *w << " added to yard." << std::endl;
         
         // Creates a new wagon and places it into the classification yard
         // at the correct cell (Destination, CargoType). Wagons in
         // each list are sorted in descending order of weight.
         
         std::string id_str, ctype_str, dest_str, weight_str, maxCouplerLoad_str;
         
         try{
              Wagon* w = new Wagon(stoi(id_str),parseCargo(ctype_str),parseDestination(dest_str),stoi(weight_str),stoi(maxCouplerLoad_str));
         }catch(std::exception e){
              std::cout << "Error: Invalid ADD_WAGON parameters.\n";
         }
         
         
    }else if (cmd == "REMOVE_WAGON"){
         // if REMOVE_WAGON <id>
         // Use: std::cout << "Error: Invalid REMOVE_WAGON parameters.\n";
         // Use: std::cout << "Wagon " << id << " removed." << std::endl;
         // Use: std::cout << "Error: Wagon " << id << " not found." << std::endl;
         
         // Removes the wagon with the given ID from the classification
         // yard.
         
    }else if (cmd == "ASSEMBLE_TRAIN"){
         // if ASSEMBLE_TRAIN <destination>
         //  Use: std::cout << "Error: Invalid ASSEMBLE_TRAIN parameters.\n";
         //  Use: std::cout << "No wagons to assemble for " << destStr << std::endl;
         //  verify couplers and possibly split (deterministic)
         //  Keep splitting the *front* train until no more overloaded couplers found
         //  create new train with same destination and name suffix
         //  use std::cout << "Train " << newTrain->getName() << " assembled after split with "
         //  << newTrain->getWagons()<< " wagons." << std::endl;
         // use std::cout << "Train " << t->getName() << " assembled with " << t->getWagons() << " wagons." << std::endl;
         
         // Collects all wagons with the given destination, merges them
         // into a new train, and moves it to the corresponding depar-
         // ture track.
         
    }else if (cmd == "DISPATCH_TRAIN"){
         // if DISPATCH_TRAIN <destination>
         //  use: std::cout << "Error: Invalid DISPATCH parameters.\n";
         //  use: std::cout << "Error: No trains to dispatch from track " << destStr << ".\n";
         //  use:  std::cout << "Dispatching " << train->getName() << " (" << t->getTotalWeight() << " tons)." << std::endl;
         
         // Dispatches the first train from the specified track in the
         // departure yard.
         
         std::string dest;
         if (dest==""){
              use: std::cout << "Error: Invalid DISPATCH parameters.\n";
         }else{
              Destination ddest = parseDestination(dest);
              dispatchFromTrack(ddest);
         }
         
    }else if (cmd == "PRINT_YARD"){
         // if PRINT_YARD
         //  use std::cout << "--- classification Yard ---\n";
         // prints the content of both the classification yard and the departure yard.
         
         std::cout<<"--- classification Yard ---\n";
         
    }else if (cmd == "PRINT_TRACK") {
         // if PRINT_TRACK <destination>
         //  use std::cout << "Error: Invalid PRINT_TRACK parameters.\n";
         
         // Prints the trains waiting in the departure track of the given
         // destination.
         
         
    } else if (cmd == "AUTO_DISPATCH") {
         // if AUTO_DISPATCH <ON/OFF>
         // Enable or disable automatic dispatch when weight exceeds limits.
         // std::cout << "Error: Invalid AUTO_DISPATCH parameters.\n";
         // print "Auto dispatch "enabled" / "disabled"
         
         ss >> cmd;
         if (cmd == "ON"){
              departureYard->autoDispatch = true;
             std::cout<<"Auto dispatch \"enabled\"\n";
         }else if (cmd == "OFF"){
              departureYard->autoDispatch = false;
              std::cout<<"Auto dispatch \"disabled\"";
         }else{
              std::cout << "Error: Invalid AUTO_DISPATCH parameters.\n";
         }
         
    }else if (cmd == "CLEAR"){
         // if CLEAR
         // Completely reset the system (yard + departure tracks).
         // std::cout << "System cleared." << std::endl;
         
    }else{
         std::cout << "Error: Unknown command '" << cmd << "'" << std::endl;
    }
}

void RailMarshal::dispatchFromTrack(Destination track)
{
    // TODO: Dispatch the next train (frontmost) from the specified track.
    // std::cout << "Error: No trains to dispatch from Track " << destIndex << ".\n";
    /*std::cout << "Train " << t->getName()
              << " departed from Track " << destIndex
              << " (" << destinationToString(static_cast<Destination>(destIndex)) << ").\n";
     */
}

void RailMarshal::printDepartureYard() const
{
    for (int i = 0; i < NUM_DESTINATIONS_INT; ++i)
    {
        std::cout << "Track " << i << " ("
                  << destinationToString(static_cast<Destination>(i)) << "):\n"; //static cast bir veri tipini diğerine zorla dönüştürür.
        departureYard[i].printTrack();
    }
}

// Debug helper functions
void RailMarshal::printStatus() const
{
    std::cout << "--- classification Yard ---\n";
    classificationYard.print();

    std::cout << "--- Departure Yard ---\n";
    for (int i = 0; i < static_cast<int>(Destination::NUM_DESTINATIONS); ++i)
    {
        departureYard[i].printTrack();
    }
}
