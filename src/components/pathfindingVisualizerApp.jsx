import React, { Component } from 'react'
import Container from 'react-bootstrap/Container'
import Row from 'react-bootstrap/Row'
import ButtonGroup from 'react-bootstrap/ButtonGroup'

import './pathfindingVisualizerApp.css';

import MenuButton from './menuButton/menuButton.jsx'
import Cell from './cell/cell.jsx'


// import Bfs from '../algorithms/bfs.js'


class PathfindingVisualizerApp extends Component {
	constructor(props) {
		super(props);
		
		this.initStartX = 3;
		this.initStartY = 3;
		this.initFinishX = 6;
		this.initFinishY = 8;

		this.state = {
			algorithms: ['bfs', 'dfs'],
			algorithm: 'bfs',
			boardActions: ['start', 'clear', 'reset'],
			grid: [],
			start: [this.initStartX, this.initStartY],
			finish: [this.initFinishX, this.initFinishY],
		};
		this.handleAlgorithmChange = this.handleAlgorithmChange.bind(this);
		
		this.handleStart = this.handleStart.bind(this);
		this.handleClear = this.handleClear.bind(this);
		this.handleReset = this.handleReset.bind(this);
		this.handleMouseDown = this.handleMouseDown.bind(this);
	}	

	componentDidMount() {
		let w = 10;
		let h = 10;
		let initialGrid = [];
		for (let row=0; row < h; row++){
			let tmp = []
			for (let col=0; col < w; col++){
				let cell = {
						isStart: (row === this.initStartY) && (col === this.initStartX),
						isFinish: (row === this.initFinishY) && (col === this.initFinishX),
						isWall: false,
						isVisited: false
					}
				tmp.push(cell);
			}
			initialGrid.push(tmp);
		}
		this.setState({grid: initialGrid});
	}
	
	handleAlgorithmChange(e){
		this.setState({
			algorithm: e.target.value
		});
	}

	handleStart() {
		// pass
	}

	handleClear() {
		// pass
	}

	handleReset() {
		// pass
	}

	handleMouseDown(row, col) {
		let newGrid = this.state.grid.slice();
		let cell = newGrid[row][col];
		let newCell = {
			...cell,
			isWall: !cell.isWall,
		}
		newGrid[row][col] = newCell;
		console.log(row, col, newCell)
		this.setState({grid: newGrid})
	}

	render() { 
		let grid = this.state.grid
		return (
			<Container>
				<Row>
					<h1>Pathfinding Visualizer</ h1>
				</ Row>
				{this.state.algorithms.map((algo) => (
					<Row key={'row_'+algo}>
					<label key={'label_'+algo}>
						<input type='radio' value={algo} checked={this.state.algorithm === algo} onChange={this.handleAlgorithmChange} />
						{algo}	
					</ label>
					</ Row>
				))}
				<Row>
					<ButtonGroup>
						<MenuButton name='start' onClick={this.handleClick}/>
						<MenuButton name='clear' onClick={this.handleClear}/>
						<MenuButton name='reset' onClick={this.handleReset}/>
					</ ButtonGroup>
				</ Row>
				<Row>
					<div className='grid'>
						{grid.map((row, i) => {
							return (
								<div key={i} className='row' >
									{row.map((cell, j) => {
										let { isStart, isFinish, isWall, isVisited } = cell;
										return (
										<Cell
											key={i+'_'+j}
											row={i}
											col={j}
											isStart={isStart}
											isFinish={isFinish}
											isWall={isWall}
											isVisited={isVisited}
											onMouseDown={(row, col) => this.handleMouseDown(i, j)}>
										</ Cell>
										)
									})}
								</ div>
							)
						})}
					</ div>
				</ Row>
			</ Container>
		);
	}
}

export default PathfindingVisualizerApp
