import React, { Component } from 'react'
import Cell from './cell.jsx'

class Board extends Component {
	constructor(props) {
		super(props)
		
		this.width = window.innerWidth;
		this.height = window.innerHeight;
		this.cellSize = 25;
		
		this.maxWidth = Math.floor(this.width / this.cellSize) - 1;
		this.maxHeight = Math.floor(this.height / this.cellSize) - 1;

		this.state = {
			start: [],
			finish: [],
			grid: new Array(this.maxHeight).fill(0).map(() => new Array(this.maxWidth).fill(0)) 
		}

		this.handleClick = this.handleClick.bind(this);
	}

	handleClick(x, y, e){
		e.preventDefault();
		if (e.button === 0 ) {
			// pass
		}
		console.log('clicked!: ' + x + ' ' + y);
		if (e.nativeEvent.which === 3) {
			console.log('right click')
		}

		if (this.state.start === [x, y] || this.state.finish === [x, y]) { 
			// pass
		} else {
			let newgrid = this.state.grid.slice();
			newgrid[x][y] = 1;
			this.setState({grid: newgrid});
		}
	};

	render() {
		
		let board = this.state.grid.map((row, i) => { return (
			<tr key={'row_'+i}>
				{row.map((col, j) => {
					return (<Cell handleClick={(e)=>{this.handleClick(i, j, e)}} value={this.state.grid[i][j]} x={i} y={j} key={i+'_'+j}/>)
					})
				}
			</tr>
		)})

		return (
			<table>
				<tbody>
					{board}
				</tbody>
			</table>
		); 
	}
}

export default Board
