#include "Item.h"
#include "json_utils.h"
#include <picojson.h>

bool Item::from_json(const std::string & filename, picojson::object & json_obj) {


	// this is where you will implement the loader for your Item
	// obviously, the item will have the common properties in GameObject, so we do that
	// super class method first

	// following from json in gameobject.cpp
	if(!has_field<bool>(json_obj, "Takeable"))
    {
        std::cerr << "Takeable: " << takeable << "does not contain a Takeable property (or it is not a bool)" << std::endl;
        return false;
    }

    if(!has_field<bool>(json_obj, "Moveable"))
    {
        std::cerr <<"Moveable: " << moveable << "does not contain a Moveable property (or it is not a bool)" << std::endl;
        return false; 
    }

	
	takeable = json_obj["Takeable"].get<bool>();
	moveable = json_obj["Moveable"].get<bool>();

	return GameObject::from_json(filename, json_obj);

	// but then, you will need to load the additional properties from json
	// for the instance variables (properties) that you have defined in Item.h 
	// as protected member variables
}