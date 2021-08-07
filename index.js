function drawBoard() {
    let board = document.getElementById("board");

    let w = window.innerWidth;
    let h = window.innerHeight;

    let cellSize = 100;

    let row = Math.floor(h / cellSize);
    let column = Math.floor(w / cellSize);

    console.log(row, column);
    let start = [5, 2];
    let finish = [5, 10];

    for (let i = 0; i < row; i++){
        for (let j = 0; j < column; j++){
            let cell = document.createElement("div");
            cell.classList.add("cell");
            cell.id = "cell-" + i + "-" + j;
            cell.draggable = true;
            if (start[0] == i && start[1] == j) {
                cell.classList.add("start");
            } else if (finish[0] == i && finish[1] == j) {
                cell.classList.add("finish");
            }
            board.appendChild(cell);
            console.log(cell.classList);
        }
    }
} 

let board = document.getElementById("board");
let isStartSelected = false;
let isFinishSelected = false;
let oldStart = null; 
let oldFinish = null; 
board.onmousedown = function(e) {
    console.log('down')
    let x = e.pageX - this.offsetLeft;
    let y = e.pageY - this.offsetTop;
    
    let cellSize = 100;
    let targetCol = Math.floor(x / 100);
    let targetRow = Math.floor(y / 100);

    let classString = "cell-" + targetRow  + "-" + targetCol;

    let target = document.getElementById(classString);
    if (target.classList.contains("start")){
        isStartSelected = true;
        oldStart = target;
    } else if (target.classList.contains("finish")){
        isFinishSelected = true;
        oldFinish = target;
    }
}

board.onmousemove = function(e) {
    console.log('drag')
}

board.ondragend = function(e) {
    console.log('up');
    let x = e.pageX - this.offsetLeft;
    let y = e.pageY - this.offsetTop;
    
    let cellSize = 100;
    let targetCol = Math.floor(x / 100);
    let targetRow = Math.floor(y / 100);

    let target = document.getElementById("cell-" + targetRow + "-" + targetCol);
    if (isStartSelected) {
        oldStart.classList.remove("start");
        target.classList.add("start");
        isStartSelected = false;
    } else if (isFinishSelected) {
        oldFinish.classList.remove("finish");
        target.classList.add("finish");
        isFinishSelected = false;
    }
}

