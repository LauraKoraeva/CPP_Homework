#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

int main() {
    nlohmann::json film_data = {
        {"title", "Rush"},
        {"year", 2013},
        {"country", "United Kingdom, Germany, United States"},
        {"release_date", "2 September 2013 (London)"},
        {"studio", "Cross Creek Pictures, Exclusive Media, Working Title Films, Imagine Entertainment, Revolution Films, Egoli Tossell Film"},
        {"genre", "biography, drama, sport"},
        {"director", "Ron Howard"},
        {"screenwriter", "Peter Morgan"},
        {"producers", {"Andrew Eaton", "Eric Fellner", "Brian Oliver", "Peter Morgan", "Brian Grazer", "Ron Howard"}},
        {"actors", nlohmann::json::array({
            {{"character", "James Hunt"}, {"actor", "Chris Hemsworth"}},
            {{"character", "Niki Lauda"}, {"actor", "Daniel Brühl"}},
            {{"character", "Suzy Miller"}, {"actor", "Olivia Wilde"}},
            {{"character", "Marlene Knaus-Lauda"}, {"actor", "Alexandra Maria Lara"}},
            {{"character", "Clay Regazzoni"}, {"actor", "Pierfrancesco Favino"}},
            {{"character", "Louis Stanley"}, {"actor", "David Calder"}},
            {{"character", "Nurse Gemma"}, {"actor", "Natalie Dormer"}},
            {{"character", "Alastair Caldwell"}, {"actor", "Stephen Mangan"}},
            {{"character", "Lord Hesketh"}, {"actor", "Christian McKay"}},
            {{"character", "Stirling Moss"}, {"actor", "Alistair Petrie"}},
            {{"character", "Teddy Mayer"}, {"actor", "Colin Stinton"}},
            {{"character", "Anthony \'Bubbles\' Horsley"}, {"actor", "Julian Rhind-Tutt"}},
            {{"character", "Patrick Baladi"}, {"actor", "John Hogan"}}
        })},
        {"plot_summary", "Rush is a 2013 biographical sports film centred on the rivalry between two Formula One drivers, Briton James Hunt and the Austrian Niki Lauda, during the 1976 motor-racing season."}
    };

    std::ofstream file("rush.json");
    if (file.is_open()) 
    {
        file << film_data.dump(4); 
        file.close();
        std::cout << "JSON data written to rush.json" << std::endl;
    } else {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    return 0;
}