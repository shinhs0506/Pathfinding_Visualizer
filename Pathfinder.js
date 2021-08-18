export default class Pathfinder {
    findPath() {
        let boardConfig = {};
        let start = document.getElementsByClassName("start");
        let finish = document.getElementsByClassName("finish");
        
        let startCoordinate = parseCoordinate(start[0].id);
        let finishCoordinate = parseCoordinate(finish[0].id);

        let walls = document.getElementsByClassName("wall");

        let wallCoordinates = [];
        for (let i = 0; i < walls.length; i++){
            wallCoordinate = parseCoordinate(walls[i].id);
            wallCoordinates.push(wallCoordinate);

        }

        boardConfig["start"] = startCoordinate;
        boardConfig["finish"] = finishCoordinate;
        boardConfig["walls"] = wallCoordinates;

        console.log(boardConfig);
    }
}

function parseCoordinate(id) {
    const parts = id.split('-'); 
    let coordinate = [];
    coordinate[0] = parseInt(parts[1], 10);
    coordinate[1] = parseInt(parts[2], 10);
    return coordinate;
}
