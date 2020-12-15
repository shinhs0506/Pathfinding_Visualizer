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
	}

	render() {
		
		let board = this.state.grid.map((row, i) => { return (
			<tr key={'row_'+i}>
				{row.map((col, j) => {
					return (<Cell key={i+'_'+j}/>)
					})
				}
			</tr>
		)})

		return (
			<div>
				{board} 	
			</div>
		); 
	}
}

export default Board
