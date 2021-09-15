/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Protocol header file
*/

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

/*
** GAMES ASSETS DEFINITION
*/

/*
** [WIDTH]: define the width of the world
**
** [HEIGHT]: define the height of the world
**
** [TEAM_NAME]: define a team name
**
** [PLAYER]: define a player
**
** [FOOD]: define food:
** -> q0
**
** [ITEM]: define an item from the game, it may be one of the following:
** -> q1 -> linemate
** -> q2 -> deraumere
** -> q3 -> sibur
** -> q4 -> mendiane
** -> q5 -> phiras
** -> q6 -> thystame
**
** [OK]: define that the client request has been treated properly
**       the server response is "ok\n"
**
** [KO]: define that the client request is an unknown / wrong command
**       the server response is "ko\n"
**
** [DIRECTION]: define the facing direction of the current drone,
** it may be one of the following:
** -> 0 -> North
** -> 1 -> Est
** -> 2 -> South
** -> 3 -> West
*/

/*
** GAME INITIALIZATION
*/

// Client send request for [TEAM_NAME],
// Server response: [X] is number of clients that can still be accepted for the [TEAM-NAME].
// Example:
// CLIENT -> [TEAM-NAME]
// SERVER <- [X]

// Server send message for [WIDTH] and [HEIGHT] of the generated map
// Example:
// SERVER <- [WIDTH] [HEIGHT]

/*
** BASIC COMMANDS CALLABLE BY CLIENT
*/

// Client can send "Forward\n" to move to 1 tile forward its direction
// Example:
// CLIENT -> Forward
// SERVER <- Ok

// Client can send "Right\n" or "Left\n" to rotate 90° and change direction
// Example:
// Client -> Right
// SERVER <- Ok

// Client can send "Look around\n" to get informations of tiles in front of him
// Server response is an array of tiles separated by ','.
// An empty tile is followed by a ','
// An object on tile is followed by [PLAYER], [FOOD] or [ITEM]
// Example:
// CLIENT -> Look around
// SERVER <- [player,,,,food,,,,thystame,]

// Client can send "Inventory\n" to get informations about objects in his inventory
// Server response is an array of items [FOOD] or [ITEM], and their quantity
// Example:
// CLIENT: Inventory
// SERVER: [food 5,linemate 2,deraumere 1]

// Client can send "Broadcast [TEXT]\n" to broadcast a text to all connected drones
// Other clients get a direction of where the text is played
// Example:
// CLIENT -> Broadcast some text
// SERVER <- Ok

/*
** PLAYERS INTERACTIONS
*/

// Client can send "Connect_nbr\n" to receive number of drones that can join the game
// Example:
// CLIENT -> Number team free slots
// SERVER <- 5

// Client can send "Fork\n" to fork a player
// Example:
// CLIENT -> Fork
// SERVER <- Ok

// Client can send "Eject\n" to eject all drones on the tile he is
// Server response may be [OK] or [KO]
// Example:
// CLIENT -> Eject
// SERVER <- OK

// Client can receive "eject: [K]" when they are ejected by a drone
// [K] is the direction of the tile where the drone is coming from
// Example:
// Server <- eject: 3

// Client can receive "Dead\n" when a player die
// Example:
// SERVER <- Dead

/*
** PLAYER INTERACTIONS WITH THE WORLD
*/

// Client can send "Take object\n" to pick up an item on the ground
// Server response may be [OK] or [KO]
// Example:
// CLIENT -> Take object
// SERVER <- ok

// Client can send "Set object [ITEM]\n" to put an object on the ground
// Server response may be [OK] or [KO]
// Example:
// CLIENT -> Set object linemate
// SERVER <- ok

// Client can send "Incantation\n" to start incantation to level up
// Server response is "Elevation underway" when starting,
//                    "Current level: [X]" if incantation completed
//                     or [KO] if incantation got canceled by an other player or not enough ressources
// Example:
// CLIENT -> Incantation
// SERVER <- Elevation underway

#endif /* !PROTOCOL_H_ */
