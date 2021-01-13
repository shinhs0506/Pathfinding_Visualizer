import React, { Component } from 'react'

import './cell.css';

class Cell extends Component {
	render() {
		let {
			row,
			col,
			isStart,
			isFinish,
			isWall,
			isVisited,
			onMouseDown,
		} = this.props
		let classname = '';
		if (isStart) {
			classname = 'cell-start';
		} else if (isFinish) {
			classname = 'cell-finish';
		} else if (isWall) {
			classname = 'cell-wall';
		}
		return (
			<div
				id={'cell-'+row+'-'+col}
				className={'cell '+classname}
				onMouseDown={() => onMouseDown(row, col)}
			>
			</ div>
		)
			
	}
}

export default Cell
