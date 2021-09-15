const { waitForDebugger } = require('inspector');
var net = require('net');
var client = new net.Socket();
var ip, port, name;
var p, h, n, previous, players, co, map, level;
var inventory, linemate;

level = 1;
priority = "none";
previous = "none";
linemate = 0;
map = "none";

if (process.argv.length != 8) {
    console.log("Please use this excution line : node index.js -p [port] -n [name] -h [ip]\n");
    return 84;
}

for (var i = 2; i < process.argv.length; i++) {
    if (i % 2 == 0) {
        if (process.argv[i] != "-h" && process.argv[i] != "-p" && process.argv[i] != "-n") {
            console.log("Wrong flag!\n");
            return 84;
        }
        if (process.argv[i] == "-h") {
            ip = process.argv[i + 1];
            h = h + 1;
        }
        if (process.argv[i] == "-p") {
            if ((port = check_port(process.argv[i + 1], port)) == 84)
                return 84;
            p = p + 1;
        }
        if (process.argv[i] == "-n") {
            name = process.argv[i + 1];
            n = n + 1;
        }
    }
    if (h > 1 || p > 1 || n > 1) {
        console.log("Same flag detected!\n");
        return 84;
    }
}

function check_port(po)
{
    if (isNaN(po) == true) {
        console.log("Bad port\n");
        return 84;
    }
    return po;
}

console.log(`Conected to server\nip :${ip}, port :${port}\n`);
client.connect(port, ip);

client.on('data', function command(data) {
    console.log(data.toString());
    if (data.toString() == "WELCOME\n") {
        console.log(data.toString());
        client.write(name + "\n");
        previous = "name";
    }
    if (previous == "name") {
        var players_tab = data.toString();
        players_tab = players_tab.split("\n").join('');
        if (players_tab[0] != 'W') {
            players = players_tab[0];
            players_tab = players_tab.split(players).join('').toString();
            co = players_tab;
            console.log(`players : ${players}`);
            console.log(`co : ${co}`);
            previous = "co";
        }
    }
    if (previous == "co") {
        client.write("Look\n");
        previous = "Look_around";
    }
    if (previous == "Look_around") {
        map = data.toString();
        if (map.includes("[ p") && !(map.includes("Not now !")) && !(map.includes("ok"))) {
            console.log(`map : ${map}`);
            previous = "vision";
        }
    }
    if (previous == "vision") {
        client.write("Inventory\n");
        previous = "inventory";
    }
    if (previous == "inventory" || previous == "take") {
        inventory = data.toString();
        if (inventory.includes("[ f"))
            console.log(`inventory : ${inventory}`);
            what_to_take();
    }
    if (data.toString().includes("Current")) {
        level = level + 1;
        console.log(level);
        previous = "co";
    }
    // if (data.toString() == "Egg ready" && players > 0) {
    //     players = players - 1;
    //     fork();
    // }
});

function check_level_1()
{
    var split_map = map.split(',');
    split_map = split_map.toString();
    split_map = split_map.split('[').join('');
    split_map = split_map.split(']').join('');
    split_map = split_map.split('\n').join('');
    split_map = split_map.split(',');
    previous = "co";
    if (split_map[0].includes("sibur"))
        client.write("Take sibur\n");
    if (split_map[0].includes("linemate")) {
        client.write("Take linemate\n");
        linemate = linemate + 1;
    }
    if (split_map[0].includes("deraumere"))
        client.write("Take deraumere\n");
    if (split_map[0].includes("mendiane"))
        client.write("Take mendiane\n");
    if (split_map[0].includes("phiras"))
        client.write("Take phiras\n");
    if (split_map[0].includes("thystame"))
        client.write("Take thystame\n");
    else {
        console.log(linemate);
        if(level == 1 && linemate > 0) {
            console.log("in if");
            linemate--;
            client.write("Set linemate\n");
            client.write("Incantation\n");
            previous = "incant";
        }
        else {
            client.write("Take food\n");
            console.log("in else");
            client.write("Forward\n");
            previous = "co";
        }
    }
}

function what_to_take()
{
    if (inventory.includes("[ f")) {
        if (level == 1);
            check_level_1();
    }
}

function fork()
{
    var ex = "node index.js -p " + port + " -n" + name + " -h " + ip;

    const { exec } = require('child_process');
    console.log(ex);
    exec( ex, (error, stdout, stderr) => {
    if (error) {
        console.error(`error: ${error.message}`);
        return;
    }
    if (stderr) {
        console.error(`stderr: ${stderr}`);
        return;
    }
    console.log(`stdout:\n${stdout}`);
    });
}
