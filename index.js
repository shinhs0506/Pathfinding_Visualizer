function drawBoard() {
    let board = document.getElementById("board");

    let w = window.innerWidth;
    let h = window.innerHeight;

    let cellSize = 100;

    let row = Math.floor(h / cellSize);
    let column = Math.floor(w / cellSize);

    console.log(row, column);

    for (let i = 0; i < row; i++){
        for (let j = 0; j < column; j++){
            let cell = document.createElement("div");
            cell.classList.add("cell","wall" , "cell-" + i + "-" + j);
            board.appendChild(cell);
            console.log(cell.className);
        }
    }

} 
