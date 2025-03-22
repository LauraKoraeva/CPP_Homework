#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "createDatabase.h"

void createDatabase()
{
    nlohmann::json movieDatabase = {
        {"The Beekeeper", {
            {"title", "The Beekeeper"},
            {"year", 2024},
            {"country", "United States"},
            {"release_date", "12 January 2024"},
            {"studio", "Metro-Goldwyn-Mayer, Miramax, Cedar Park Entertainment, Punch Palace Productions"},
            {"genre", "action, thriller"},
            {"director", "	David Ayer"},
            {"screenwriter", "Kurt Wimmer"},
            {"producers", {"Bill Block", "Jason Statham", "David Ayer", "Chris Long", "Kurt Wimmer"}},
            {"actors", nlohmann::json::array({
                {{"character", "Adam Clay"}, {"actor", "Jason Statham"}},
                {{"character", "Verona Parker"}, {"actor", "Emmy Raver-Lampman"}},
                {{"character", "Derek Danforth"}, {"actor", "Josh Hutcherson"}},
                {{"character", "Matt Wiley"}, {"actor", "Bobby Naderi"}},
                {{"character", "Janet Harward"}, {"actor", "Minnie Driver"}},
                {{"character", "Mickey Garnett"}, {"actor", "David Witts"}},
                {{"character", "Pettis"}, {"actor", "Michael Epp"}},
                {{"character", "Lazarus"}, {"actor", "Taylor James"}},
                {{"character", "Jessica Danforth"}, {"actor", "Jemma Redgrave"}},
                {{"character", "Rico Anzalone"}, {"actor", "Enzo Cilenti"}},
                {{"character", "Eloise Parker"}, {"actor", "Phylicia Rashad"}}
            })},
            {"plot_summary", "The film follows a retired government assassin who sets out for revenge after his kind-hearted landlady falls victim to a phishing scam."}
        }},
        {"Carry-On", {
            {"title", "Carry-On"},
            {"year", 2024},
            {"country", "United States"},
            {"release_date", "13 December 2024"},
            {"studio", "Dylan Clark Productions, DreamWorks Pictures"},
            {"genre", "thriller"},
            {"director", "	Jaume Collet-Serra"},
            {"screenwriter", "T. J. Fixman"},
            {"producers", "Dylan Clark"},
            {"actors", nlohmann::json::array({
                {{"character", "Ethan Kopek"}, {"actor", "Taron Egerton"}},
                {{"character", "The Traveler"}, {"actor", "Jason Bateman"}},
                {{"character", "Nora Parisi"}, {"actor", "Sofia Carson"}},
                {{"character", "Elena Cole"}, {"actor", "Danielle Deadwyler"}},
                {{"character", "The Watcher"}, {"actor", "Theo Rossi"}},
                {{"character", "Agent Alcott"}, {"actor", "Logan Marshall-Green"}},
                {{"character", "Phil Sarkowski"}, {"actor", "Dean Norris"}},
                {{"character", "Jason Noble"}, {"actor", "Sinqua Walls"}},
                {{"character", "Lionel Williams"}, {"actor", "Curtiss Cook"}},
                {{"character", "Herschel"}, {"actor", "Josh Brener"}},
                {{"character", "Security Director Marm Bellows"}, {"actor", "Benito Martinez"}}
            })},
            {"plot_summary", "Film's plot follows a young TSA officer who is blackmailed into allowing a nerve agent on board a flight during Christmas Eve."}
        }},
        {"Guy Ritchie's The Covenant", {
            {"title", "Guy Ritchie's The Covenant"},
            {"year", 2023},
            {"country", "United States"},
            {"release_date", "21 April 2023"},
            {"studio", "STXfilms, Toff Guy Films"},
            {"genre", "action, thriller, war"},
            {"director", "Guy Ritchie"},
            {"screenwriter", "Guy Ritchie, Ivan Atkinson, Marn Davies"},
            {"producers", {"Guy Ritchie", "Ivan Atkinson", "John Friedberg", "Josh Berger"}},
            {"actors", nlohmann::json::array({
                {{"character", "Master Sgt. John Kinley"}, {"actor", "Jake Gyllenhaal"}},
                {{"character", "Ahmed Abdullah"}, {"actor", "Dar Salim"}},
                {{"character", "Charlie \"Jizzy\" Crow"}, {"actor", "Sean Sagar"}},
                {{"character", "Joshua \"JJ\" Jung"}, {"actor", "Jason Wong"}},
                {{"character", "Tom \"Tom Cat\" Hancock"}, {"actor", "Rhys Yates"}},
                {{"character", "Eduardo \"Chow Chow\" Lopez"}, {"actor", "Christian Ochoa"}},
                {{"character", "Steve Kersher"}, {"actor", "Bobby Schofield"}},
                {{"character", "Caroline Kinley"}, {"actor", "Emily Beecham"}}
            })},
            {"plot_summary", "Film's plot follows John Kinley, a U.S. Army Green Beret Master Sergeant, and Ahmed, his Afghan interpreter, fighting the Taliban."}
        }},
        {"1917", {
            {"title", "1917"},
            {"year", 2019},
            {"country", "United Kingdom, United States"},
            {"release_date", "4 December 2019"},
            {"studio", "DreamWorks Pictures, Reliance Entertainment, New Republic Pictures, Mogambo, Neal Street Productions, Amblin Partners"},
            {"genre", "war, drama, history"},
            {"director", "Sam Mendes"},
            {"screenwriter", "Sam Mendes, Krysty Wilson-Cairns"},
            {"producers", {"Sam Mendes", "Pippa Harris", "Jayne-Ann Tenggren", "Callum McDougall", "Brian Oliver"}},
            {"actors", nlohmann::json::array({
                {{"character", "Lance Corporal William \"Will\" Schofield"}, {"actor", "George MacKay"}},
                {{"character", "Lance Corporal Thomas \"Tom\""}, {"actor", "Dean-Charles Chapman"}},
                {{"character", "Lieutenant Leslie"}, {"actor", "Andrew Scott"}},
                {{"character", "Lieutenant Joseph Blake"}, {"actor", "Richard Madden"}},
                {{"character", "General Erinmore"}, {"actor", "Colin Firth"}},
                {{"character", "Colonel Mackenzie"}, {"actor", "Benedict Cumberbatch"}},
                {{"character", "Sergeant Sanders"}, {"actor", "Daniel Mays"}}
            })},
            {"plot_summary", "The film takes place after the German retreat to the Hindenburg Line during Operation Alberich, and follows two British soldiers in their mission to deliver an important message to call off a doomed offensive attack."}
        }},
        {"Rush", {
            {"title", "Rush"},
            {"year", 2013},
            {"country", "United Kingdom, Germany, United States"},
            {"release_date", "2 September 2013"},
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
        }}
    };

    std::ofstream file("movies.json");
    if (file.is_open()) 
    {
        file << movieDatabase.dump(4); 
        file.close();
        std::cout << "JSON data written to movies.json" << std::endl;
    } else 
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}