function drawBoard() {
    let board = document.getElementById("board");

    let w = window.innerWidth;
    let h = window.innerHeight;

    let cellSize = 100;

    let row = w / cellSize;
    let column = h / cellSize;

    for (let i = 0; i < row; i++){
        for (let j = 0; j < column; j++){
            let cell = document.createElement("div");
            cell.classList.add("cell", "cell-" + i + "-" + j);
            board.appendChild(cell);
            console.log(cell.className);
        }
    }

} 
